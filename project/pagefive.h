#ifndef PAGEFIVE_H
#define PAGEFIVE_H

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
#include <QTimer>
#include "button.h"
#include "popitem.h"
#include "settings.h"

class PageFive : public QGraphicsScene
{
    Q_OBJECT
public:
    PageFive();
    //Phonon::MediaObject//c5;

    QTimer *timer;
    int djs_int;
    AllKey *allkey;
    void end_djs();

public slots:
    void update_djs();

    void queren();
private:
    PopItem *yejiao1;
    PopItem *yejiao2;
    PopItem *yejiao3;
    Return *go_home;
    QGraphicsTextItem* djs_text;

    QLineEdit *guanliyuan_edit;

    QLineEdit *mima_edit;
    Button *queren_button;

    QGraphicsProxyWidget *proxy1;
    QGraphicsProxyWidget *proxy2;
signals:
    void back_home();
    void turn_ten();
};

#endif // PAGEFIVE_H
