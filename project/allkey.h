#ifndef ALLKEY_H
#define ALLKEY_H

#include "button.h"

class AllKey : public QGraphicsObject
{
    Q_OBJECT
public:
    AllKey();
    virtual QRectF boundingRect() const;
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    Button *num1;
    Button *num2;
    Button *num3;
    Button *num4;
    Button *num5;
    Button *num6;
    Button *num7;
    Button *num8;
    Button *num9;
    Button *num0;

    Button *q;
    Button *w;
    Button *e;
    Button *r;
    Button *t;
    Button *y;
    Button *u;
    Button *i;
    Button *o;
    Button *p;

    Button *a;
    Button *s;
    Button *d;
    Button *f;
    Button *g;
    Button *h;
    Button *j;
    Button *k;
    Button *l;

    Button *z;
    Button *x;
    Button *c;
    Button *v;
    Button *b;
    Button *n;
    Button *m;

    Button *del;
signals:
    void clickedkey(QString);
};

#endif // ALLKEY_H
