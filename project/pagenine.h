#ifndef PAGENINE_H
#define PAGENINE_H

#include <QGraphicsScene>
#include <QBrush>
#include <QPixmap>
#include "return.h"
#include "button.h"
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QComboBox>
#include <QWidget>
#include "doorctr.h"
#include "scanmode.h"
#include <QtSql>
#include "popitem.h"
#include <QTime>
#include <QtDebug>
#include <QTimer>
#include <QLabel>
#include <QMovie>
#include "settings.h"

class PageNine : public QGraphicsScene
{
    Q_OBJECT
public:
    PageNine();
    //Phonon::MediaObject *c9;
    doorCtr *ser;

    QLabel *label;
    QMovie *movie;

    int xiangzi_id;
    QString tiaoma_id;
    PopItem *pop_item;
    PopItem *pop_item2;
    PopItem *pop_item3;
    PopItem *pop_item4;
    PopItem *pop_dajian;
    PopItem *pop_zhongjian;
    PopItem *pop_xiaojian;
    PopItem *pop_texiaojian;
    PopItem *pop_item5;
    void init_djs();

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
private:
    Return *go_home;
    Button *dajian;
    Button *zhongjian;
    Button *xiaojian;
    Button *texiaojian;

    QGraphicsPixmapItem *xiangzi0;
    QGraphicsPixmapItem *xiangzi1;
    QGraphicsPixmapItem *xiangzi2;
    QGraphicsPixmapItem *xiangzi3;
    QGraphicsPixmapItem *xiangzi4;
    QGraphicsPixmapItem *xiangzi5;
    QGraphicsPixmapItem *xiangzi6;
    QGraphicsPixmapItem *xiangzi7;
    QGraphicsPixmapItem *xiangzi8;
    QGraphicsPixmapItem *xiangzi9;
    QGraphicsPixmapItem *xiangzi10;
    QGraphicsPixmapItem *xiangzi11;
    QGraphicsPixmapItem *xiangzi12;
    QGraphicsPixmapItem *xiangzi13;
    QGraphicsPixmapItem *xiangzi14;
    QGraphicsPixmapItem *xiangzi15;
    QGraphicsPixmapItem *xiangzi16;
    QGraphicsPixmapItem *xiangzi17;
    QGraphicsPixmapItem *xiangzi18;
    QGraphicsPixmapItem *xiangzi19;
    QGraphicsPixmapItem *xiangzi20;
    QGraphicsPixmapItem *xiangzi21;
    QGraphicsPixmapItem *xiangzi22;
    QGraphicsPixmapItem *xiangzi23;
    QGraphicsPixmapItem *xiangzi24;
    QGraphicsPixmapItem *xiangzi25;
    QGraphicsPixmapItem *xiangzi26;
    QGraphicsPixmapItem *xiangzi27;
    QGraphicsPixmapItem *xiangzi28;
    QGraphicsPixmapItem *xiangzi29;
    QGraphicsPixmapItem *xiangzi30;
    QGraphicsPixmapItem *xiangzi31;
    QGraphicsPixmapItem *xiangzi32;
    QGraphicsPixmapItem *xiangzi33;
    QGraphicsPixmapItem *xiangzi34;
    QGraphicsPixmapItem *xiangzi35;
    QGraphicsPixmapItem *xiangzi36;
    QGraphicsPixmapItem *xiangzi37;
    QGraphicsPixmapItem *xiangzi38;
    QGraphicsPixmapItem *xiangzi39;
    QGraphicsPixmapItem *xiangzi40;
    QGraphicsPixmapItem *xiangzi41;
    QGraphicsPixmapItem *xiangzi42;
    QGraphicsPixmapItem *xiangzi43;
    QGraphicsPixmapItem *xiangzi44;
    QGraphicsPixmapItem *xiangzi45;
    QGraphicsPixmapItem *xiangzi46;
    QGraphicsPixmapItem *xiangzi47;
    QGraphicsPixmapItem *xiangzi48;
    QGraphicsPixmapItem *xiangzi49;
    QGraphicsPixmapItem *xiangzi50;
    QGraphicsPixmapItem *xiangzi51;
    QGraphicsPixmapItem *xiangzi52;
    QGraphicsPixmapItem *xiangzi53;
    QGraphicsPixmapItem *xiangzi54;
    QGraphicsPixmapItem *xiangzi55;
    QGraphicsPixmapItem *xiangzi56;
    QGraphicsPixmapItem *xiangzi57;
    QGraphicsPixmapItem *xiangzi58;
    QGraphicsPixmapItem *xiangzi59;
    QGraphicsPixmapItem *xiangzi60;
    QGraphicsPixmapItem *xiangzi61;
    QGraphicsPixmapItem *xiangzi62;
    QGraphicsPixmapItem *xiangzi63;
    QGraphicsPixmapItem *xiangzi64;
    QGraphicsPixmapItem *xiangzi65;

    QGraphicsPixmapItem *item_back;
    QGraphicsPixmapItem *item_shang;
    QGraphicsPixmapItem *item_zhong;
    QGraphicsPixmapItem *item_xia;

    QGraphicsPixmapItem *yundan1;
    QLineEdit *yundan2_edit;
    QLineEdit *haoma_edit;

    Button *num1;
    Button *num2;
    Button *num3;
    Button *num4;
    Button *num5;
    Button *num6;
    Button *num7;
    Button *num8;
    Button *num9;
    Button *num0;
    Button *item_ok;
    Button *item_del;

//    QWidget *widget;
//    QGridLayout *layout1;
//    QFormLayout *layout2;
    QGraphicsProxyWidget *proxy1;
    QGraphicsProxyWidget *proxy2;
    QGraphicsProxyWidget *proxy3;
signals:
    void back_home();
public slots:
    void showNum1(QString);
    void showNum2(QString);
    void showNum3(QString);
    void showNum4(QString);
    void showNum5(QString);
    void showNum6(QString);
    void showNum7(QString);
    void showNum8(QString);
    void showNum9(QString);
    void showOK(QString);
    void showNum0(QString);
    void showDEL(QString);
    void dakaixiangzi(QString);
    void open_door(QString);
    void jiance(int num, QString status);
    void backHome();
    void update_djs();
    void end_djs();
public:
    QString tu_an;
    bool da_jian_15;
    bool da_jian_25;
    bool da_jian_55;
    bool da_jian_35;
    bool da_jian_45;
    bool zhong_jian_32;
    bool zhong_jian_33;
    bool zhong_jian_34;
    bool zhong_jian_22;
    bool zhong_jian_23;
    bool zhong_jian_24;
    bool zhong_jian_42;
    bool zhong_jian_43;
    bool zhong_jian_44;
    bool zhong_jian_52;
    bool zhong_jian_53;
    bool zhong_jian_54;
    bool xiaojian_26;
    bool xiaojian_27;
    bool xiaojian_28;
    bool xiaojian_29;
    bool xiaojian_30;
    bool xiaojian_31;
    bool xiaojian_16;
    bool xiaojian_17;
    bool xiaojian_18;
    bool xiaojian_19;
    bool xiaojian_20;
    bool xiaojian_21;
    bool xiaojian_36;
    bool xiaojian_37;
    bool xiaojian_38;
    bool xiaojian_39;
    bool xiaojian_40;
    bool xiaojian_41;
    bool xiaojian_46;
    bool xiaojian_47;
    bool xiaojian_48;
    bool xiaojian_49;
    bool xiaojian_50;
    bool xiaojian_51;
    bool texiaojian_01;
    bool texiaojian_02;
    bool texiaojian_03;
    bool texiaojian_04;
    bool texiaojian_05;
    bool texiaojian_06;
    bool texiaojian_07;
    bool texiaojian_08;
    bool texiaojian_09;
    bool texiaojian_10;
    bool texiaojian_11;
    bool texiaojian_12;
    bool texiaojian_13;
    bool texiaojian_14;

public slots:
    void to_nine(int id);
    //void xiaoshi();
    void hide_dajian();
    void hide_zhongjian();
    void hide_xiaojian();
    void hide_texiaojian();
    void hide_label();
};

#endif // PAGENINE_H
