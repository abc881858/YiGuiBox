#ifndef PAGEA_H
#define PAGEA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "return.h"
#include "popitem.h"

class PageA : public QGraphicsScene
{
    Q_OBJECT
public:
    PageA();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    PopItem *yejiao1;
    PopItem *yejiao3;
    Return *go_home;
signals:
    void xuanGS(QString);
    void back_home();
};

#endif // PAGEA_H
