#ifndef PAGEW_H
#define PAGEW_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "return.h"
#include "popitem.h"

class PageW : public QGraphicsScene
{
    Q_OBJECT
public:
    PageW();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    PopItem *yejiao1;
    PopItem *yejiao3;
    Return *go_home;
signals:
    void xuanGS(QString);
    void back_home();
};

#endif // PAGEW_H
