#include "toujian.h"

TouJian::TouJian()
{
    setBackgroundBrush(QBrush(QPixmap(":/two.png")));

    go_home = new Return(":/home.png");
    addItem(go_home);
    go_home->setPos(924,668);
    connect(go_home,SIGNAL(click()),this,SIGNAL(back_home()));

//    dajian = new QGraphicsPixmapItem(QPixmap("password.png"));
//    addItem(dajian);
//    dajian->setPos(40,60);

//    zhongjian = new QGraphicsPixmapItem(QPixmap("password.png"));
//    addItem(zhongjian);
//    zhongjian->setPos(132,60);

//    xiaojian = new QGraphicsPixmapItem(QPixmap("password.png"));
//    addItem(xiaojian);
//    xiaojian->setPos(224,60);

//    texiaojian = new QGraphicsPixmapItem(QPixmap("password.png"));
//    addItem(texiaojian);
//    texiaojian->setPos(316,60);
}
