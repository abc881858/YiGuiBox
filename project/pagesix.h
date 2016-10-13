#ifndef PAGESIX_H
#define PAGESIX_H

#include <QGraphicsScene>
#include <QBrush>
#include <QPixmap>

#include <QTimer>
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QComboBox>
#include <QWidget>
#include <QTextEdit>
#include <QtSql>

#include "popitem.h"
#include "button.h"
#include "return.h"
#include "sqlquerymodel.h"

#include <QTableView>
#include <QHeaderView>
#include <QTableWidget>
#include "settings.h"

class PageSix : public QGraphicsScene
{
    Q_OBJECT
public:
    PageSix();

    QTimer *timer;
    int djs_int;
    int left;
    int right;

    QString code;

    void end_djs();

    SqlQueryModel *model;
    void updateSQL();

public slots:
    void update_djs();

    void previous(QString);
    void next(QString);
    void send(QString);
    void query();
    void press(QModelIndex index);
    void showNum1();
    void showNum2();
    void showNum3();
    void showNum4();
    void showNum5();
    void showNum6();
    void showNum7();
    void showNum8();
    void showNum9();
    void showNum0();
    void showOK();
    void showDEL();
private:
    PopItem *yejiao1;
    PopItem *yejiao2;
    PopItem *yejiao3;
    Return *go_home;
    QGraphicsTextItem* djs_text;
    Button *cha1;
    Button *cha2;
    Button *cha3;
    Button *cha4;
    Button *cha5;
    Button *cha6;

    QTableView *view;

    QGraphicsProxyWidget *proxy;

    QLineEdit *haoma_edit;
    QGraphicsProxyWidget *proxy1;

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
    QGridLayout *layout;
    QGraphicsProxyWidget *proxy2;
    QWidget *widget;

protected:
     bool eventFilter(QObject *obj, QEvent *event);

signals:
    void back_home();
};

#endif // PAGESIX_H
