#ifndef PAGEC_H
#define PAGEC_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "return.h"
#include "popitem.h"

class PageC : public QGraphicsScene
{
    Q_OBJECT
public:
    PageC();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    PopItem *yejiao1;
    PopItem *yejiao3;
    Return *go_home;
signals:
    void xuanGS(QString);
    void back_home();
};

#endif // PAGEC_H
