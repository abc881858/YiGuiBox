#ifndef PAGEFLIPVIEW_H
#define PAGEFLIPVIEW_H

#include <QTimer>
#include <QMouseEvent>
#include "qglpainter.h"
#include "qglabstracteffect.h"
#include "qgltexture2d.h"
#include "pageflipmath.h"
#include "pageflipgradienteffect.h"

class PageFlipView : public QGLWidget
{
    Q_OBJECT
public:
    PageFlipView(QWidget *parent = 0);
    ~PageFlipView();
    QTimer *timer;

    void setBlend(bool value) { blend = value; }

protected:
    void resizeGL(int width, int height);
    void initializeGL();
    void paintGL();
    void mousePressEvent(QMouseEvent *e);

private slots:
    void animate();

private:
    bool blend;

    qreal posn;     // Position within the animation - 0...1
    QSize pageSize; // Size of a page within the window.

    QRect pageRect1;
    QRect pageRect2;

    QColor colors[4];
    int colorIndex;

    QGLTexture2D textures[4];

    QGLTexture2D gradientTexture;

    PageFlipMath pageFlipMath;

    PageFlipGradientEffect *effect;

    void setAlphaValue(QGLPainter *painter, GLfloat value);
};

#endif // PAGEFLIPVIEW_H
