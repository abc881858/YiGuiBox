#include "pageo.h"

static int x1 = 222;
static int x2 = 430;
static int x3 = 637;

static int y1 = 145;
static int y2 = 225;
static int y3 = 305;
static int y4 = 385;
static int y5 = 475;
static int y6 = 560;

static int w = 183;
static int h = 61;

static QRect r1(x1,y1,w,h);
static QRect r2(x2,y1,w,h);
static QRect r3(x3,y1,w,h);
static QRect r4(x1,y2,w,h);
static QRect r5(x2,y2,w,h);
static QRect r6(x3,y2,w,h);
static QRect r7(x1,y3,w,h);
static QRect r8(x2,y3,w,h);
static QRect r9(x3,y3,w,h);
static QRect r10(x1,y4,w,h);
static QRect r11(x2,y4,w,h);
static QRect r12(x3,y4,w,h);
static QRect r13(x1,y5,w,h);
static QRect r14(x2,y5,w,h);
static QRect r15(x3,y5,w,h);
static QRect r16(x1,y6,w,h);
static QRect r17(x2,y6,w,h);
static QRect r18(x3,y6,w,h);

PageO::PageO()
{
    setBackgroundBrush(QBrush(QPixmap("ZCO.png")));

    yejiao1 = new PopItem("yejiao1.png");
    addItem(yejiao1);
    yejiao1->setPos(34,24);

    yejiao3 = new PopItem("yejiao3.png");
    addItem(yejiao3);
    yejiao3->setPos(218,697);

    go_home = new Return("yejiao4.png");
    addItem(go_home);
    go_home->setPos(888,690);
    connect(go_home,SIGNAL(click()),this,SIGNAL(back_home()));
}

void PageO::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    int x = event->pos().x();
    int y = event->pos().y();
    QPoint p(x,y);

    if (r1.contains(p))
    {
        emit xuanGS(QString("y#1#1"));
    }
    else if (r4.contains(p))
    {
        emit xuanGS(QString("y#2#1"));
    }
    QGraphicsScene::mousePressEvent(event);
}
