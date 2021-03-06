#ifndef PAGEH_H
#define PAGEH_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "return.h"
#include "popitem.h"

class PageH : public QGraphicsScene
{
    Q_OBJECT
public:
    PageH();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    PopItem *yejiao1;
    PopItem *yejiao3;
    Return *go_home;
signals:
    void xuanGS(QString);
    void back_home();
};

#endif // PAGEH_H
