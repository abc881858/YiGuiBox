#ifndef PAGETHREE_H
#define PAGETHREE_H

#include <QtSql>
#include <QGraphicsScene>
#include <QBrush>
#include <QPixmap>
#include "allkey.h"
#include "return.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QFormLayout>
#include "icreader.h"
#include "popitem.h"
#include "camera.h"
#include <QTimer>
#include "button.h"
#include "settings.h"

class PageThree : public QGraphicsScene
{
    Q_OBJECT
public:
    PageThree();
    camera cam;
    void init_djs();
    //Phonon::MediaObject *c3;
    bool can_read;

    AllKey *allkey;

    QGraphicsPixmapItem *djs1;
    QGraphicsPixmapItem *djs2;
    QGraphicsPixmapItem *djs3;
    QGraphicsPixmapItem *djs4;
    QGraphicsPixmapItem *djs5;
    QGraphicsPixmapItem *djs6;
    QGraphicsPixmapItem *djs7;
    QGraphicsPixmapItem *djs8;
    QGraphicsPixmapItem *djs9;
    QGraphicsPixmapItem *djs10;
    QGraphicsPixmapItem *djs11;
    QGraphicsPixmapItem *djs12;
    QGraphicsPixmapItem *djs13;
    QGraphicsPixmapItem *djs14;
    QGraphicsPixmapItem *djs15;
    QGraphicsPixmapItem *djs16;
    QGraphicsPixmapItem *djs17;
    QGraphicsPixmapItem *djs18;
    QGraphicsPixmapItem *djs19;
    QGraphicsPixmapItem *djs20;
    QGraphicsPixmapItem *djs21;
    QGraphicsPixmapItem *djs22;
    QGraphicsPixmapItem *djs23;
    QGraphicsPixmapItem *djs24;
    QGraphicsPixmapItem *djs25;
    QGraphicsPixmapItem *djs26;
    QGraphicsPixmapItem *djs27;
    QGraphicsPixmapItem *djs28;
    QGraphicsPixmapItem *djs29;
    QGraphicsPixmapItem *djs30;

    QTimer *timer;
    int djs_int;
    int toudiyuan_mima;

public slots:
    void update_djs();
    void end_djs();
    void denglu(QString str);
    void denglu2(QString str);
    void stopMyVideo();
    void to_Cam();
    void showKeyNum(QString key);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Return *go_home;
//    QLabel *toudiyuan_label;
    QLineEdit *toudiyuan_edit;
//    QLabel *mima_label;
    QLineEdit *mima_edit;
//    QPushButton denglu_button;
//    QWidget *widget;
    Button *button_denglu;
    QLayout *layout1;
    QLayout *layout2;
    QGraphicsProxyWidget *proxy1;
    QGraphicsProxyWidget *proxy2;
public:
    ICReader *reader;
//    PopItem *pop_item;

signals:
    void back_home();
    void turn_nine();
};

#endif // PAGETHREE_H
