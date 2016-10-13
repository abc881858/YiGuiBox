#include "pageflipview.h"

PageFlipView::PageFlipView(QWidget *parent) : QGLWidget(parent)
{
//    setWindowFlags(Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground);

//    setAutoFillBackground(true);
//    QPalette palette= this->palette();
//    palette.setBrush(QPalette::Window,QPixmap("back.png"));
//    setPalette(palette);
    posn = 0.0f;
    blend = true;

    colors[0] = QColor(0, 192, 192, 255);
    colors[1] = QColor(192, 0, 0, 255);
    colors[2] = QColor(192, 192, 0, 255);
    colors[3] = QColor(128, 128, 0, 255);
    colorIndex = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->setInterval(40);
    timer->stop();

    effect = new PageFlipGradientEffect();
}

PageFlipView::~PageFlipView()
{
    delete effect;
}

void PageFlipView::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void PageFlipView::initializeGL()
{
    QGLPainter painter(this);

    pageSize = QSize(472, 688);

    textures[0].setImage(QImage(QLatin1String("qqpage1.png")));
    textures[1].setImage(QImage(QLatin1String("qqpage2.png")));
    textures[2].setImage(QImage(QLatin1String("qqpage3.png")));
    textures[3].setImage(QImage(QLatin1String("qqpage4.png")));

    gradientTexture.setImage(QImage(QLatin1String("gradient.png")));

    if (painter.hasOpenGLFeature(QOpenGLFunctions::BlendColor))
        painter.glBlendColor(0, 0, 0, 0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    if (painter.hasOpenGLFeature(QOpenGLFunctions::BlendEquation))
        painter.glBlendEquation(GL_FUNC_ADD);
    else if (painter.hasOpenGLFeature(QOpenGLFunctions::BlendEquationSeparate))
        painter.glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);

    glEnable(GL_BLEND);

//    setGeometry(0, 0, 1024, 768);//设置窗口初始位置和大小
//    glShadeModel(GL_FLAT);//设置阴影平滑模式
//    glClearColor(1.0, 1.0, 1.0, 0);//改变窗口的背景颜色
//    glClearDepth(1.0);//设置深度缓存
//    glEnable(GL_DEPTH_TEST);//允许深度测试
//    glDepthFunc(GL_LEQUAL);//设置深度测试类型
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//进行透视校正

    pageFlipMath.setStartCorner(PageFlipMath::BottomRight);
}

void PageFlipView::paintGL()
{
    QGLPainter painter(this);

    QRect rect(0,0,1024,768);
//    int midx = 512;
//    int topy = (768 - 688) / 2; // = 40

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    QMatrix4x4 projm;
    projm.ortho(rect);
    painter.projectionMatrix() = projm;
    painter.modelViewMatrix().setToIdentity();

    pageRect1 = QRect(40, 40, 472, 688);
    pageRect2 = QRect(512, 40, 472, 688);

    pageFlipMath.setPageRect(pageRect2);
    pageFlipMath.setShowPageReverse(false);
    pageFlipMath.compute(posn);

    QGLAttributeValue positions(2, GL_FLOAT, pageFlipMath.stride(), pageFlipMath.vertexArray());
    QGLAttributeValue texCoords(2, GL_FLOAT, pageFlipMath.stride(), pageFlipMath.vertexArray() + 2);
    QGLAttributeValue gradientCoords(1, GL_FLOAT, pageFlipMath.stride(), pageFlipMath.vertexArray() + 4);

    if (painter.isFixedFunction())
    {
        painter.setStandardEffect(QGL::FlatReplaceTexture2D);
    }
    else
    {
        painter.setUserEffect(effect);
    }

    painter.setColor(colors[colorIndex]);
    painter.glActiveTexture(GL_TEXTURE0);
    textures[colorIndex].bind();

    if (!painter.isFixedFunction())
    {
        painter.glActiveTexture(GL_TEXTURE1);
        gradientTexture.bind();
    }

    painter.clearAttributes();
    painter.setVertexAttribute(QGL::Position, positions);
    painter.setVertexAttribute(QGL::TextureCoord0, texCoords);
    painter.setVertexAttribute(QGL::CustomVertex0, gradientCoords);
    setAlphaValue(&painter, 1.0f);
    painter.update();
    pageFlipMath.drawPage(0);

    painter.setColor(colors[(colorIndex + 1) % 4]);
    painter.glActiveTexture(GL_TEXTURE0);
    textures[(colorIndex + 1) % 4].bind();
    setAlphaValue(&painter, 1.0f);
    painter.update();
    pageFlipMath.drawPage(1);

    painter.setColor(colors[(colorIndex + 2) % 4]);
    if (!pageFlipMath.showPageReverse())
    {
        textures[(colorIndex + 2) % 4].bind();
    }
    if (blend)
    {
        setAlphaValue(&painter, 0.75f);
    }
    else
    {
        setAlphaValue(&painter, 1.0f);
    }
    painter.update();
    pageFlipMath.drawPage(2);

    painter.setColor(colors[(colorIndex + 3) % 4]);
    textures[(colorIndex + 3) % 4].bind();
    setAlphaValue(&painter, 1.0f);
    painter.update();
    pageFlipMath.drawPage(3);

    glBindTexture(GL_TEXTURE_2D, 0);
    painter.glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, 0);

    painter.setStandardEffect(QGL::FlatColor);
    painter.clearAttributes();
    painter.setVertexAttribute(QGL::Position, positions);
    painter.setVertexAttribute(QGL::TextureCoord0, texCoords);
    painter.setVertexAttribute(QGL::CustomVertex0, gradientCoords);
    painter.setColor(QColor(0, 0, 0, 255));
    painter.update();
    pageFlipMath.drawOutline(2);
}

void PageFlipView::mousePressEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();

    if (x > 512 && x < 984 && y > 40 && y < 384)
    {
        pageFlipMath.setStartCorner(PageFlipMath::TopRight);
    }
    else if (x > 512 && x < 984 && y > 384 && y < 728)
    {
        pageFlipMath.setStartCorner(PageFlipMath::BottomRight);
    }

    timer->start();

    QGLWidget::mousePressEvent(e);
}

void PageFlipView::animate()
{
    posn += 0.04f;
    if (posn >= 1.0f)
    {
        posn = 0.0f;
        colorIndex = (colorIndex + 2) % 4;
        timer->stop();
    }
    updateGL();
}

void PageFlipView::setAlphaValue(QGLPainter *painter, GLfloat value)
{
    if (!painter->isFixedFunction())
    {
        effect->setAlphaValue(value);
    }
}

//void PageFlipView::loadImage(QImage &img)
//{
//////    width_img=img.width();
//////    height_img=img.height();

////    /* Create texture object */
//////    if(!bTextureCreated)
//////    {
////    glGenTextures(1, &texture);
//////        bTextureCreated=true;
//////    }

////    /* Now upload pixels */
////    if(img.format()!=QImage::Format_RGB32)
////    {
////        img=img.convertToFormat(QImage::Format_RGB32);
////    }
////    qDebug()<<"Color count:"<<img.colorCount();
////    qDebug()<<"Depth:"<<img.depth();
////    qDebug()<<"Format"<<img.format();
////    qDebug()<<"Has Alpha channel:"<<img.hasAlphaChannel();

////    QImage tex_image;
////    tex_image = QGLWidget::convertToGLFormat(img);

////    //make sure its not null
//////    if(tex_image.isNull())
//////    {
//////        QMessageBox::warning(this, tr("Error"),
//////                             tr("failed to transform image to opengl format."));
//////        return ;
//////    }
////    glBindTexture(GL_TEXTURE_2D, texture);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

////    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
////                 tex_image.width(), tex_image.height(), 0,
////                 GL_RGB, GL_UNSIGNED_BYTE, tex_image.bits());

//////    bImageConnected=true;

////    // Update scene
////    updateGL();
////    return;
//}

//void PageFlipView::loadImage(const QString &filename)
//{
////    QImage img;
////    img.load(filename);
//////    if(img.isNull())
//////    {
//////        QMessageBox::warning(this, tr("Error"),
//////                             tr("Can not open specified file <%1>").arg(filename),
//////                             QMessageBox::Ok);
//////        return;
//////    }
//////    else
//////    {
////    loadImage(img);
////    return;
//////    }
//}
