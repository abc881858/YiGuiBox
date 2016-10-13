#ifndef PAGEONE_H
#define PAGEONE_H

#include "button.h"
#include "allkey.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QBrush>
#include <QPixmap>
#include "return.h"
#include "doorctr.h"
#include "popitem.h"
#include <QtSql>
#include <QDebug>
#include <QTimer>
#include "settings.h"

class PageOne : public QGraphicsScene
{
    Q_OBJECT
public:
    PageOne();
    QString english(QString key);
    void showYesNo();
    PopItem *pop_thank;
    QTimer *timer;
    void initKeyNum();
    int showPlace;
    //camera cam;
private:
    QString my_password;

    QGraphicsPixmapItem *pass1;//all is background
    QGraphicsPixmapItem *pass2;
    QGraphicsPixmapItem *pass3;
    QGraphicsPixmapItem *pass4;
    QGraphicsPixmapItem *pass5;
    QGraphicsPixmapItem *pass6;
    QGraphicsPixmapItem *pass7;
    QGraphicsPixmapItem *pass8;
    QGraphicsPixmapItem *pass9;
    QGraphicsPixmapItem *pass0;

    QGraphicsPixmapItem *KeyNum1;
    QGraphicsPixmapItem *KeyNum2;
    QGraphicsPixmapItem *KeyNum3;
    QGraphicsPixmapItem *KeyNum4;
    QGraphicsPixmapItem *KeyNum5;
    QGraphicsPixmapItem *KeyNum6;
    QGraphicsPixmapItem *KeyNum7;
    QGraphicsPixmapItem *KeyNum8;
    QGraphicsPixmapItem *KeyNum9;
    QGraphicsPixmapItem *KeyNum0;

    QGraphicsTextItem *djs_text;

    int djs_int;

    AllKey *allkey;
    Return *go_home;
    PopItem *pop_item;
    PopItem *yejiao2;
    PopItem *yejiao3;

    //doorCtr * ser;

signals:
    void back_home();
    void one_to(int);
    void toCam();

public slots:
    void showKeyNum(QString key);
    void hide_thank();
    void hide_item();
    void update_djs();
    void end_djs();
    //void stopMyVideo();
};

#endif // PAGEONE_H
