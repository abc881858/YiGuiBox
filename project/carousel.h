#ifndef CAROUSEL_H
#define CAROUSEL_H

#include <QImage>
#include <QTimer>
#include "qglview.h"
#include "qglabstractscene.h"
#include "qglscenenode.h"
#include "qglpicknode.h"
#include "qgraphicsrotation3d.h"
#include "qgraphicsscale3d.h"
#include "qglbuilder.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>

class Carousel : public QGLView
{
    Q_OBJECT
    Q_PROPERTY(qreal angle READ angle WRITE setAngle)
public:
    Carousel();
    ~Carousel();
    qreal angle() const { return m_angle; }
    void setAngle(qreal angle) { m_angle = angle; update(); }
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void registerPickableNodes();
    QPropertyAnimation *animation;
    void mouseReleaseEvent(QMouseEvent *e);
    bool isPress;
    void donghua();
    void restore();

protected:
    void initializeGL(QGLPainter *painter);
    void paintGL(QGLPainter *painter);

private:
    int old_x;
    QGLAbstractScene *scene1;
    QGLAbstractScene *scene2;
    QGLAbstractScene *scene3;
    QGLAbstractScene *scene4;
    QGLAbstractScene *scene5;
    QGLAbstractScene *scene6;
    QGLAbstractScene *scene7;
    QGLAbstractScene *scene8;

    qreal m_angle;
    QColor qtPurple;

    QGLSceneNode * loading;

    QGLSceneNode *button1;
    QGLSceneNode *button2;
    QGLSceneNode *button3;
    QGLSceneNode *button4;
    QGLSceneNode *button5;
    QGLSceneNode *button6;
    QGLSceneNode *button7;
    QGLSceneNode *button8;

    QGLPickNode *picknode1;
    QGLPickNode *picknode2;
    QGLPickNode *picknode3;
    QGLPickNode *picknode4;
    QGLPickNode *picknode5;
    QGLPickNode *picknode6;
    QGLPickNode *picknode7;
    QGLPickNode *picknode8;

    QList<QGraphicsTransform3D *> tran1;
    QList<QGraphicsTransform3D *> tran2;
    QList<QGraphicsTransform3D *> tran3;
    QList<QGraphicsTransform3D *> tran4;
    QList<QGraphicsTransform3D *> tran5;
    QList<QGraphicsTransform3D *> tran6;
    QList<QGraphicsTransform3D *> tran7;
    QList<QGraphicsTransform3D *> tran8;

    QList<QGraphicsTransform3D *> ttran1;
    QList<QGraphicsTransform3D *> ttran2;
    QList<QGraphicsTransform3D *> ttran3;
    QList<QGraphicsTransform3D *> ttran4;
    QList<QGraphicsTransform3D *> ttran5;
    QList<QGraphicsTransform3D *> ttran6;
    QList<QGraphicsTransform3D *> ttran7;
    QList<QGraphicsTransform3D *> ttran8;

    QGraphicsRotation3D *rota1x;
    QGraphicsRotation3D *rota1y;
    QGraphicsRotation3D *rota2x;
    QGraphicsRotation3D *rota2y;
    QGraphicsRotation3D *rota3x;
    QGraphicsRotation3D *rota3y;
    QGraphicsRotation3D *rota4x;
    QGraphicsRotation3D *rota4y;
    QGraphicsRotation3D *rota5x;
    QGraphicsRotation3D *rota5y;
    QGraphicsRotation3D *rota6x;
    QGraphicsRotation3D *rota6y;
    QGraphicsRotation3D *rota7x;
    QGraphicsRotation3D *rota7y;
    QGraphicsRotation3D *rota8x;
    QGraphicsRotation3D *rota8y;

    QGraphicsScale3D *scale1;
    QGraphicsScale3D *scale2;
    QGraphicsScale3D *scale3;
    QGraphicsScale3D *scale4;
    QGraphicsScale3D *scale5;
    QGraphicsScale3D *scale6;
    QGraphicsScale3D *scale7;
    QGraphicsScale3D *scale8;

    QSequentialAnimationGroup *f1;
    QSequentialAnimationGroup *f2;
    QSequentialAnimationGroup *f3;
    QSequentialAnimationGroup *f4;
    QSequentialAnimationGroup *f5;
    QSequentialAnimationGroup *f6;
    QSequentialAnimationGroup *f7;
    QSequentialAnimationGroup *f8;

public slots:
    void Toclicked1();
    void Toclicked2();
    void Toclicked3();
    void Toclicked4();
    void Toclicked5();
    void Toclicked6();
    void Toclicked7();
    void Toclicked8();

signals:
    void clicked1();
    void clicked2();
    void clicked3();
    void clicked4();
    void clicked5();
    void clicked6();
    void clicked7();
    void clicked8();
};

#endif // CAROUSEL_H
