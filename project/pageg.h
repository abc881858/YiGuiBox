#ifndef PAGEG_H
#define PAGEG_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "return.h"
#include "popitem.h"

class PageG : public QGraphicsScene
{
    Q_OBJECT
public:
    PageG();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    PopItem *yejiao1;
    PopItem *yejiao3;
    Return *go_home;
signals:
    void xuanGS(QString);
    void back_home();
};

#endif // PAGEG_H
