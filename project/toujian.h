#ifndef TOUJIAN_H
#define TOUJIAN_H

#include <QGraphicsScene>
#include <QBrush>
#include <QPixmap>
#include "return.h"

class TouJian : public QGraphicsScene
{
    Q_OBJECT
public:
    TouJian();
private:
    Return *go_home;
signals:
    void back_home();
};

#endif // TOUJIAN_H
