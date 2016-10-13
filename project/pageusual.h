#ifndef PAGEUSUAL_H
#define PAGEUSUAL_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "return.h"
#include "popitem.h"

class PageUsual : public QGraphicsScene
{
    Q_OBJECT
public:
    PageUsual();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    PopItem *yejiao1;
    PopItem *yejiao3;
    Return *go_home;
signals:
    void xuanGS(QString);
    void back_home();
};

#endif // PAGEUSUAL_H
