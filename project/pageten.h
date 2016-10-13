#ifndef PAGETEN_H
#define PAGETEN_H

#include <QGraphicsScene>
#include <QBrush>
#include <QPixmap>
#include "return.h"
#include <QtSql>
#include <QGraphicsProxyWidget>
#include <QTableView>
#include <button.h>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include "settings.h"

class PageTen : public QGraphicsScene
{
    Q_OBJECT
public:
    PageTen();
    //Phonon::MediaObject *c10;
    Button *courier;//kuaidiyuan xiangqing
    Button *QuJian;//kuaidiyuan xiangqing
    Button *TouJian;//kuaidiyuan xiangqing
    Button *JiJian;//kuaidiyuan xiangqing
    Button *chaxun;
    QTableView *view;
    QSqlQueryModel *model;
    QSqlQueryModel *model2;
    QSqlQueryModel *model3;
    QSqlQueryModel *model4;
    QSqlQueryModel *model5;
    QGraphicsProxyWidget *proxy;

    QLineEdit *tiaoma_edit;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num6;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num9;
    QPushButton *num0;
    QPushButton *ok;
    QPushButton *del;
    QGridLayout *layout1;
    QVBoxLayout *layout2;
    QWidget *widget;
    QGraphicsProxyWidget *proxy2;
public slots:
    void changeTable(QString name);
    void showNum1();
    void showNum2();
    void showNum3();
    void showNum4();
    void showNum5();
    void showNum6();
    void showNum7();
    void showNum8();
    void showNum9();
    void showOK();
    void showNum0();
    void showDEL();
private:
    Return *go_home;
signals:
    void back_home();
};


#endif // PAGETEN_H
