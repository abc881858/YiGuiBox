#include "carousel.h"
#include <QDebug>
#include <QMouseEvent>

Carousel::Carousel() : QGLView(),isPress(false)
{
    setOption(QGLView::ObjectPicking, true);
    setOption(QGLView::CameraNavigation, false);
    resize(QSize(1024,768));

    qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
    setAutoFillBackground(false);

    animation = new QPropertyAnimation(this, "angle", this);
    animation->setStartValue(0.0f);
    animation->setEndValue(-360.0f);
    animation->setDuration(30000);
    animation->setLoopCount(-1);
    animation->start();

    showFullScreen();
}

Carousel::~Carousel()
{
    // nothing to be done here
}

void Carousel::initializeGL(QGLPainter *painter)
{
    Q_UNUSED(painter);
    qglClearColor(qtPurple.dark());

    camera()->setEye(QVector3D(200,35,0));
    camera()->setEyeSeparation(0.3);

    loading = new QGLSceneNode;

    scene1 = QGLAbstractScene::loadScene(QLatin1String("qq1.3DS"));
    button1 = scene1->mainNode();
    button1->setObjectName("button1");
    scene1->setPickable(true);
    button1->setPosition(QVector3D(0,10,42));
    rota1y = new QGraphicsRotation3D;
    rota1y->setAxis(QVector3D(0,1,0));
    rota1y->setAngle(0);
    rota1x = new QGraphicsRotation3D;
    rota1x->setAxis(QVector3D(1,0,0));
    rota1x->setAngle(0);
    scale1 = new QGraphicsScale3D;
    scale1->setScale(QVector3D(0.75,0.75,0.75));
    tran1 << rota1x << rota1y << scale1;
    button1->setTransforms(tran1);

    scene2 = QGLAbstractScene::loadScene(QLatin1String("qq2.3DS"));
    button2 = scene2->mainNode();
    button2->setObjectName("button2");
    scene2->setPickable(true);
    button2->setPosition(QVector3D(30,10,30));
    rota2y = new QGraphicsRotation3D;
    rota2y->setAxis(QVector3D(0,1,0));
    rota2y->setAngle(45);
    rota2x = new QGraphicsRotation3D;
    rota2x->setAxis(QVector3D(1,0,0));
    rota2x->setAngle(0);
    scale2 = new QGraphicsScale3D;
    scale2->setScale(QVector3D(0.75,0.75,0.75));
    tran2 << rota2x << rota2y << scale2;
    button2->setTransforms(tran2);

    scene3 = QGLAbstractScene::loadScene(QLatin1String("qq3.3DS"));
    button3 = scene3->mainNode();
    button3->setObjectName("button3");
    scene3->setPickable(true);
    button3->setPosition(QVector3D(42,10,0));
    rota3y = new QGraphicsRotation3D;
    rota3y->setAxis(QVector3D(0,1,0));
    rota3y->setAngle(90);
    rota3x = new QGraphicsRotation3D;
    rota3x->setAxis(QVector3D(1,0,0));
    rota3x->setAngle(0);
    scale3 = new QGraphicsScale3D;
    scale3->setScale(QVector3D(0.75,0.75,0.75));
    tran3 << rota3x << rota3y << scale3;
    button3->setTransforms(tran3);

    scene4 = QGLAbstractScene::loadScene(QLatin1String("qq4.3DS"));
    button4 = scene4->mainNode();
    button4->setObjectName("button4");
    scene4->setPickable(true);
    button4->setPosition(QVector3D(30,10,-30));
    rota4y = new QGraphicsRotation3D;
    rota4y->setAxis(QVector3D(0,1,0));
    rota4y->setAngle(135);
    rota4x = new QGraphicsRotation3D;
    rota4x->setAxis(QVector3D(1,0,0));
    rota4x->setAngle(0);
    scale4 = new QGraphicsScale3D;
    scale4->setScale(QVector3D(0.75,0.75,0.75));
    tran4 << rota4x << rota4y << scale4;
    button4->setTransforms(tran4);

    scene5 = QGLAbstractScene::loadScene(QLatin1String("qq5.3DS"));
    button5 = scene5->mainNode();
    button5->setObjectName("button5");
    scene5->setPickable(true);
    button5->setPosition(QVector3D(0,10,-42));
    rota5y = new QGraphicsRotation3D;
    rota5y->setAxis(QVector3D(0,1,0));
    rota5y->setAngle(180);
    rota5x = new QGraphicsRotation3D;
    rota5x->setAxis(QVector3D(1,0,0));
    rota5x->setAngle(0);
    scale5 = new QGraphicsScale3D;
    scale5->setScale(QVector3D(0.75,0.75,0.75));
    tran5 << rota5x << rota5y << scale5;
    button5->setTransforms(tran5);

    scene6 = QGLAbstractScene::loadScene(QLatin1String("qq6.3DS"));
    button6 = scene6->mainNode();
    button6->setObjectName("button6");
    scene6->setPickable(true);
    button6->setPosition(QVector3D(-30,10,-30));
    rota6y = new QGraphicsRotation3D;
    rota6y->setAxis(QVector3D(0,1,0));
    rota6y->setAngle(225);
    rota6x = new QGraphicsRotation3D;
    rota6x->setAxis(QVector3D(1,0,0));
    rota6x->setAngle(0);
    scale6 = new QGraphicsScale3D;
    scale6->setScale(QVector3D(0.75,0.75,0.75));
    tran6 << rota6x << rota6y << scale6;
    button6->setTransforms(tran6);

    scene7 = QGLAbstractScene::loadScene(QLatin1String("qq7.3DS"));
    button7 = scene7->mainNode();
    button7->setObjectName("button7");
    scene7->setPickable(true);
    button7->setPosition(QVector3D(-42,10,0));
    rota7y = new QGraphicsRotation3D;
    rota7y->setAxis(QVector3D(0,1,0));
    rota7y->setAngle(270);
    rota7x = new QGraphicsRotation3D;
    rota7x->setAxis(QVector3D(1,0,0));
    rota7x->setAngle(0);
    scale7 = new QGraphicsScale3D;
    scale7->setScale(QVector3D(0.75,0.75,0.75));
    tran7 << rota7x << rota7y << scale7;
    button7->setTransforms(tran7);

    scene8 = QGLAbstractScene::loadScene(QLatin1String("qq8.3DS"));
    button8 = scene8->mainNode();
    button8->setObjectName("button8");
    scene8->setPickable(true);
    button8->setPosition(QVector3D(-30,10,30));
    rota8y = new QGraphicsRotation3D;
    rota8y->setAxis(QVector3D(0,1,0));
    rota8y->setAngle(315);
    rota8x = new QGraphicsRotation3D;
    rota8x->setAxis(QVector3D(1,0,0));
    rota8x->setAngle(0);
    scale8 = new QGraphicsScale3D;
    scale8->setScale(QVector3D(0.75,0.75,0.75));
    tran8 << rota8x << rota8y << scale8;
    button8->setTransforms(tran8);

    registerPickableNodes();
}

void Carousel::paintGL(QGLPainter *painter)
{
    painter->modelViewMatrix().rotate(angle(), 0, 1, 0);
    button1->draw(painter);
    button2->draw(painter);
    button3->draw(painter);
    button4->draw(painter);
    button5->draw(painter);
    button6->draw(painter);
    button7->draw(painter);
    button8->draw(painter);
}

void Carousel::mousePressEvent(QMouseEvent *e)
{
    animation->stop();
    isPress = true;
    old_x = e->pos().x();

    QGLView::mousePressEvent(e);
}

void Carousel::mouseMoveEvent(QMouseEvent *e)
{
    if(isPress)
    {
        int delt_x = e->pos().x()-old_x;
        if(delt_x>0)
        {
            this->setAngle(this->angle()+1);
        }
        else
        {
            this->setAngle(this->angle()-1);
        }
    }

    //QGLView::mouseMoveEvent(e);
}

void Carousel::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);

    isPress = false;

    animation->setStartValue(this->angle());
    animation->setEndValue(this->angle()-360);
    animation->setDuration(30000);
    animation->setLoopCount(-1);
    animation->start();

    QGLView::mouseReleaseEvent(e);
}

void Carousel::registerPickableNodes()
{
    scene1->generatePickNodes();
    QList<QGLPickNode*> pickList1 = scene1->pickNodes();
    QList<QGLPickNode*>::const_iterator it1 = pickList1.constBegin();
    for ( ; it1 != pickList1.constEnd(); ++it1)
    {
        QGLPickNode *pn1 = *it1;
        pn1->disconnect(this);
        QObject::connect(pn1, SIGNAL(clicked()), this, SLOT(Toclicked1()));
        pn1->setId(1);
        registerObject(pn1->id(), pn1);
    }

    scene2->generatePickNodes();
    QList<QGLPickNode*> pickList2 = scene2->pickNodes();
    QList<QGLPickNode*>::const_iterator it2 = pickList2.constBegin();
    for ( ; it2 != pickList2.constEnd(); ++it2)
    {
        QGLPickNode *pn2 = *it2;
        pn2->disconnect(this);
        QObject::connect(pn2, SIGNAL(clicked()), this, SLOT(Toclicked2()));
        pn2->setId(2);
        registerObject(pn2->id(), pn2);
    }

    scene3->generatePickNodes();
    QList<QGLPickNode*> pickList3 = scene3->pickNodes();
    QList<QGLPickNode*>::const_iterator it3 = pickList3.constBegin();
    for ( ; it3 != pickList3.constEnd(); ++it3)
    {
        QGLPickNode *pn3 = *it3;
        pn3->disconnect(this);
        QObject::connect(pn3, SIGNAL(clicked()), this, SLOT(Toclicked3()));
        pn3->setId(3);
        registerObject(pn3->id(), pn3);
    }

    scene4->generatePickNodes();
    QList<QGLPickNode*> pickList4 = scene4->pickNodes();
    QList<QGLPickNode*>::const_iterator it4 = pickList4.constBegin();
    for ( ; it4 != pickList4.constEnd(); ++it4)
    {
        QGLPickNode *pn4 = *it4;
        pn4->disconnect(this);
        QObject::connect(pn4, SIGNAL(clicked()), this, SLOT(Toclicked4()));
        pn4->setId(4);
        registerObject(pn4->id(), pn4);
    }

    scene5->generatePickNodes();
    QList<QGLPickNode*> pickList5 = scene5->pickNodes();
    QList<QGLPickNode*>::const_iterator it5 = pickList5.constBegin();
    for ( ; it5 != pickList5.constEnd(); ++it5)
    {
        QGLPickNode *pn5 = *it5;
        pn5->disconnect(this);
        QObject::connect(pn5, SIGNAL(clicked()), this, SLOT(Toclicked5()));
        pn5->setId(5);
        registerObject(pn5->id(), pn5);
    }

    scene6->generatePickNodes();
    QList<QGLPickNode*> pickList6 = scene6->pickNodes();
    QList<QGLPickNode*>::const_iterator it6 = pickList6.constBegin();
    for ( ; it6 != pickList6.constEnd(); ++it6)
    {
        QGLPickNode *pn6 = *it6;
        pn6->disconnect(this);
        QObject::connect(pn6, SIGNAL(clicked()), this, SLOT(Toclicked6()));
        pn6->setId(6);
        registerObject(pn6->id(), pn6);
    }

    scene7->generatePickNodes();
    QList<QGLPickNode*> pickList7 = scene7->pickNodes();
    QList<QGLPickNode*>::const_iterator it7 = pickList7.constBegin();
    for ( ; it7 != pickList7.constEnd(); ++it7)
    {
        QGLPickNode *pn7 = *it7;
        pn7->disconnect(this);
        QObject::connect(pn7, SIGNAL(clicked()), this, SLOT(Toclicked7()));
        pn7->setId(7);
        registerObject(pn7->id(), pn7);
    }

    scene8->generatePickNodes();
    QList<QGLPickNode*> pickList8 = scene8->pickNodes();
    QList<QGLPickNode*>::const_iterator it8 = pickList8.constBegin();
    for ( ; it8 != pickList8.constEnd(); ++it8)
    {
        QGLPickNode *pn8 = *it8;
        pn8->disconnect(this);
        QObject::connect(pn8, SIGNAL(clicked()), this, SLOT(Toclicked8()));
        pn8->setId(8);
        registerObject(pn8->id(), pn8);
    }
}

void Carousel::Toclicked1()
{
    donghua();
    QTimer::singleShot(1000, this, SIGNAL(clicked1()));
}

void Carousel::Toclicked2()
{
    donghua();
    QTimer::singleShot(1000, this, SIGNAL(clicked2()));
}

void Carousel::Toclicked3()
{
    donghua();
    QTimer::singleShot(1000, this, SIGNAL(clicked3()));
}

void Carousel::Toclicked4()
{
    donghua();
    QTimer::singleShot(1000, this, SIGNAL(clicked4()));
}

void Carousel::Toclicked5()
{
    donghua();
    QTimer::singleShot(1000, this, SIGNAL(clicked5()));
}

void Carousel::Toclicked6()
{
    donghua();
    QTimer::singleShot(1000, this, SIGNAL(clicked6()));
}

void Carousel::Toclicked7()
{
    //donghua();
    QTimer::singleShot(1000, this, SIGNAL(clicked7()));
}

void Carousel::Toclicked8()
{
    //donghua();
    QTimer::singleShot(1000, this, SIGNAL(clicked8()));
}

void Carousel::donghua()
{
    QParallelAnimationGroup *e1;
    QParallelAnimationGroup *e2;
    QParallelAnimationGroup *e3;
    QParallelAnimationGroup *e4;
    QParallelAnimationGroup *e5;
    QParallelAnimationGroup *e6;
    QParallelAnimationGroup *e7;
    QParallelAnimationGroup *e8;

    e1 = new QParallelAnimationGroup;
    e2 = new QParallelAnimationGroup;
    e3 = new QParallelAnimationGroup;
    e4 = new QParallelAnimationGroup;
    e5 = new QParallelAnimationGroup;
    e6 = new QParallelAnimationGroup;
    e7 = new QParallelAnimationGroup;
    e8 = new QParallelAnimationGroup;

    f1 = new QSequentialAnimationGroup;
    f2 = new QSequentialAnimationGroup;
    f3 = new QSequentialAnimationGroup;
    f4 = new QSequentialAnimationGroup;
    f5 = new QSequentialAnimationGroup;
    f6 = new QSequentialAnimationGroup;
    f7 = new QSequentialAnimationGroup;
    f8 = new QSequentialAnimationGroup;

    QPropertyAnimation *a1;
    a1 = new QPropertyAnimation(rota1x, "angle", this);
    a1->setStartValue(0);
    a1->setEndValue(-90);
    a1->setDuration(400);
    a1->setLoopCount(1);
    QPropertyAnimation *b1;
    b1 = new QPropertyAnimation(rota1y, "angle", this);
    b1->setStartValue(0);
    b1->setEndValue(360);
    b1->setDuration(400);
    b1->setLoopCount(-1);
    QPropertyAnimation *c1;
    c1 = new QPropertyAnimation(button1, "x", this);
    c1->setStartValue(button1->x());
    c1->setEndValue((button1->x())*19);
    c1->setDuration(10000);
    QPropertyAnimation *d1;
    d1 = new QPropertyAnimation(button1, "z", this);
    d1->setStartValue(button1->z());
    d1->setEndValue((button1->z())*19);
    d1->setDuration(10000);

    e1->addAnimation(b1);
    e1->addAnimation(c1);
    e1->addAnimation(d1);

    f1->addAnimation(a1);
    f1->addAnimation(e1);
    f1->start();

    QPropertyAnimation *a2;
    a2 = new QPropertyAnimation(rota2x, "angle", this);
    a2->setStartValue(0);
    a2->setEndValue(-90);
    a2->setDuration(400);
    a2->setLoopCount(1);
    QPropertyAnimation *b2;
    b2 = new QPropertyAnimation(rota2y, "angle", this);
    b2->setStartValue(0);
    b2->setEndValue(360);
    b2->setDuration(400);
    b2->setLoopCount(-1);
    QPropertyAnimation *c2;
    c2 = new QPropertyAnimation(button2, "x", this);
    c2->setStartValue(button2->x());
    c2->setEndValue((button2->x())*19);
    c2->setDuration(10000);
    QPropertyAnimation *d2;
    d2 = new QPropertyAnimation(button2, "z", this);
    d2->setStartValue(button2->z());
    d2->setEndValue((button2->z())*19);
    d2->setDuration(10000);

    e2->addAnimation(b2);
    e2->addAnimation(c2);
    e2->addAnimation(d2);

    f2->addAnimation(a2);
    f2->addAnimation(e2);
    f2->start();

    QPropertyAnimation *a3;
    a3 = new QPropertyAnimation(rota3x, "angle", this);
    a3->setStartValue(0);
    a3->setEndValue(-90);
    a3->setDuration(400);
    a3->setLoopCount(1);
    QPropertyAnimation *b3;
    b3 = new QPropertyAnimation(rota3y, "angle", this);
    b3->setStartValue(0);
    b3->setEndValue(360);
    b3->setDuration(400);
    b3->setLoopCount(-1);
    QPropertyAnimation *c3;
    c3 = new QPropertyAnimation(button3, "x", this);
    c3->setStartValue(button3->x());
    c3->setEndValue((button3->x())*19);
    c3->setDuration(10000);
    QPropertyAnimation *d3;
    d3 = new QPropertyAnimation(button3, "z", this);
    d3->setStartValue(button3->z());
    d3->setEndValue(button3->z()*19);
    d3->setDuration(10000);

    e3->addAnimation(b3);
    e3->addAnimation(c3);
    e3->addAnimation(d3);

    f3->addAnimation(a3);
    f3->addAnimation(e3);
    f3->start();

    QPropertyAnimation *a4;
    a4 = new QPropertyAnimation(rota4x, "angle", this);
    a4->setStartValue(0);
    a4->setEndValue(-90);
    a4->setDuration(400);
    a4->setLoopCount(1);
    QPropertyAnimation *b4;
    b4 = new QPropertyAnimation(rota4y, "angle", this);
    b4->setStartValue(0);
    b4->setEndValue(360);
    b4->setDuration(400);
    b4->setLoopCount(-1);
    QPropertyAnimation *c4;
    c4 = new QPropertyAnimation(button4, "x", this);
    c4->setStartValue(button4->x());
    c4->setEndValue(button4->x()*19);
    c4->setDuration(10000);
    QPropertyAnimation *d4;
    d4 = new QPropertyAnimation(button4, "z", this);
    d4->setStartValue(button4->z());
    d4->setEndValue(button4->z()*19);
    d4->setDuration(10000);

    e4->addAnimation(b4);
    e4->addAnimation(c4);
    e4->addAnimation(d4);

    f4->addAnimation(a4);
    f4->addAnimation(e4);
    f4->start();

    QPropertyAnimation *a5;
    a5 = new QPropertyAnimation(rota5x, "angle", this);
    a5->setStartValue(0);
    a5->setEndValue(-90);
    a5->setDuration(400);
    a5->setLoopCount(1);
    QPropertyAnimation *b5;
    b5 = new QPropertyAnimation(rota5y, "angle", this);
    b5->setStartValue(0);
    b5->setEndValue(360);
    b5->setDuration(400);
    b5->setLoopCount(-1);
    QPropertyAnimation *c5;
    c5 = new QPropertyAnimation(button5, "x", this);
    c5->setStartValue(button5->x());
    c5->setEndValue(button5->x()*19);
    c5->setDuration(10000);
    QPropertyAnimation *d5;
    d5 = new QPropertyAnimation(button5, "z", this);
    d5->setStartValue(button5->z());
    d5->setEndValue(button5->z()*19);
    d5->setDuration(10000);

    e5->addAnimation(b5);
    e5->addAnimation(c5);
    e5->addAnimation(d5);

    f5->addAnimation(a5);
    f5->addAnimation(e5);
    f5->start();

    QPropertyAnimation *a6;
    a6 = new QPropertyAnimation(rota6x, "angle", this);
    a6->setStartValue(0);
    a6->setEndValue(-90);
    a6->setDuration(400);
    a6->setLoopCount(1);
    QPropertyAnimation *b6;
    b6 = new QPropertyAnimation(rota6y, "angle", this);
    b6->setStartValue(0);
    b6->setEndValue(360);
    b6->setDuration(400);
    b6->setLoopCount(-1);
    QPropertyAnimation *c6;
    c6 = new QPropertyAnimation(button6, "x", this);
    c6->setStartValue(button6->x());
    c6->setEndValue(button6->x()*19);
    c6->setDuration(10000);
    QPropertyAnimation *d6;
    d6 = new QPropertyAnimation(button6, "z", this);
    d6->setStartValue(button6->z());
    d6->setEndValue(button6->z()*19);
    d6->setDuration(10000);

    e6->addAnimation(b6);
    e6->addAnimation(c6);
    e6->addAnimation(d6);

    f6->addAnimation(a6);
    f6->addAnimation(e6);
    f6->start();

    QPropertyAnimation *a7;
    a7 = new QPropertyAnimation(rota7x, "angle", this);
    a7->setStartValue(0);
    a7->setEndValue(-90);
    a7->setDuration(400);
    a7->setLoopCount(1);
    QPropertyAnimation *b7;
    b7 = new QPropertyAnimation(rota7y, "angle", this);
    b7->setStartValue(0);
    b7->setEndValue(360);
    b7->setDuration(400);
    b7->setLoopCount(-1);
    QPropertyAnimation *c7;
    c7 = new QPropertyAnimation(button7, "x", this);
    c7->setStartValue(button7->x());
    c7->setEndValue(button7->x()*19);
    c7->setDuration(10000);
    QPropertyAnimation *d7;
    d7 = new QPropertyAnimation(button7, "z", this);
    d7->setStartValue(button7->z());
    d7->setEndValue(button7->z()*19);
    d7->setDuration(10000);

    e7->addAnimation(b7);
    e7->addAnimation(c7);
    e7->addAnimation(d7);

    f7->addAnimation(a7);
    f7->addAnimation(e7);
    f7->start();

    QPropertyAnimation *a8;
    a8 = new QPropertyAnimation(rota8x, "angle", this);
    a8->setStartValue(0);
    a8->setEndValue(-90);
    a8->setDuration(400);
    a8->setLoopCount(1);
    QPropertyAnimation *b8;
    b8 = new QPropertyAnimation(rota8y, "angle", this);
    b8->setStartValue(0);
    b8->setEndValue(360);
    b8->setDuration(400);
    b8->setLoopCount(-1);
    QPropertyAnimation *c8;
    c8 = new QPropertyAnimation(button8, "x", this);
    c8->setStartValue(button8->x());
    c8->setEndValue(button8->x()*19);
    c8->setDuration(10000);
    QPropertyAnimation *d8;
    d8 = new QPropertyAnimation(button8, "z", this);
    d8->setStartValue(button8->z());
    d8->setEndValue(button8->z()*19);
    d8->setDuration(10000);

    e8->addAnimation(b8);
    e8->addAnimation(c8);
    e8->addAnimation(d8);

    f8->addAnimation(a8);
    f8->addAnimation(e8);
    f8->start();
}

void Carousel::restore()
{
    animation->start();

    f1->stop();
    f2->stop();
    f3->stop();
    f4->stop();
    f5->stop();
    f6->stop();
    f7->stop();
    f8->stop();

    button1->setPosition(QVector3D(0,10,42));
    button2->setPosition(QVector3D(30,10,30));
    button3->setPosition(QVector3D(42,10,0));
    button4->setPosition(QVector3D(30,10,-30));
    button5->setPosition(QVector3D(0,10,-42));
    button6->setPosition(QVector3D(-30,10,-30));
    button7->setPosition(QVector3D(-42,10,0));
    button8->setPosition(QVector3D(-30,10,30));

    rota1y->setAngle(0);
    rota1x->setAngle(0);
    scale1->setScale(QVector3D(0.75,0.75,0.75));
    ttran1.clear();
    ttran1 << rota1x << rota1y << scale1;
    button1->setTransforms(ttran1);

    rota2y->setAngle(45);
    rota2x->setAngle(0);
    scale2->setScale(QVector3D(0.75,0.75,0.75));
    ttran2.clear();
    ttran2 << rota2x << rota2y << scale2;
    button2->setTransforms(ttran2);

    rota3y->setAngle(90);
    rota3x->setAngle(0);
    scale3->setScale(QVector3D(0.75,0.75,0.75));
    ttran3.clear();
    ttran3 << rota3x << rota3y << scale3;
    button3->setTransforms(ttran3);

    rota4y->setAngle(135);
    rota4x->setAngle(0);
    scale4->setScale(QVector3D(0.75,0.75,0.75));
    ttran4.clear();
    ttran4 << rota4x << rota4y << scale4;
    button4->setTransforms(ttran4);

    rota5y->setAngle(180);
    rota5x->setAngle(0);
    scale5->setScale(QVector3D(0.75,0.75,0.75));
    ttran5.clear();
    ttran5 << rota5x << rota5y << scale5;
    button5->setTransforms(ttran5);

    rota6y->setAngle(225);
    rota6x->setAngle(0);
    scale6->setScale(QVector3D(0.75,0.75,0.75));
    ttran6.clear();
    ttran6 << rota6x << rota6y << scale6;
    button6->setTransforms(ttran6);

    rota7y->setAngle(270);
    rota7x->setAngle(0);
    scale7->setScale(QVector3D(0.75,0.75,0.75));
    ttran7.clear();
    ttran7 << rota7x << rota7y << scale7;
    button7->setTransforms(ttran7);

    rota8y->setAngle(315);
    rota8x->setAngle(0);
    scale8->setScale(QVector3D(0.75,0.75,0.75));
    ttran8.clear();
    ttran8 << rota8x << rota8y << scale8;
    button8->setTransforms(ttran8);
}
