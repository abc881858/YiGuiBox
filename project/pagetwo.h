#ifndef PAGETWO_H
#define PAGETWO_H

#include <QGraphicsScene>
#include <QBrush>
#include <QPixmap>
#include "return.h"
#include <QTimer>

class PageTwo : public QGraphicsScene
{
    Q_OBJECT
public:
    PageTwo();
    QTimer *timer;
    int djs_int;

public slots:
    void update_djs();
    void end_djs();

private:
    Return *go_home;
signals:
    void back_home();
};

#endif // PAGETWO_H
