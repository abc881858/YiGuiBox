#include "allkey.h"

AllKey::AllKey()
{
    num1 = new Button("1.png");
    num1->setParentItem(this);
    num1->setPos(84,372);
    connect(num1,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num2 = new Button("2.png");
    num2->setParentItem(this);
    num2->setPos(170,369);
    connect(num2,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num3 = new Button("3.png");
    num3->setParentItem(this);
    num3->setPos(261,364);
    connect(num3,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num4 = new Button("4.png");
    num4->setParentItem(this);
    num4->setPos(346,370);
    connect(num4,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num5 = new Button("5.png");
    num5->setParentItem(this);
    num5->setPos(432,369);
    connect(num5,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num6 = new Button("6.png");
    num6->setParentItem(this);
    num6->setPos(519,370);
    connect(num6,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num7 = new Button("7.png");
    num7->setParentItem(this);
    num7->setPos(604,370);
    connect(num7,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num8 = new Button("8.png");
    num8->setParentItem(this);
    num8->setPos(690,373);
    connect(num8,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num9 = new Button("9.png");
    num9->setParentItem(this);
    num9->setPos(776,374);
    connect(num9,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    num0 = new Button("0.png");
    num0->setParentItem(this);
    num0->setPos(863,376);
    connect(num0,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    ////

    q = new Button("Q.png");
    q->setParentItem(this);
    q->setPos(97,427);
    connect(q,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    w = new Button("W.png");
    w->setParentItem(this);
    w->setPos(183,428);
    connect(w,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    e = new Button("E.png");
    e->setParentItem(this);
    e->setPos(270,425);
    connect(e,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    r = new Button("R.png");
    r->setParentItem(this);
    r->setPos(354,428);
    connect(r,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    t = new Button("T.png");
    t->setParentItem(this);
    t->setPos(435,426);
    connect(t,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    y = new Button("Y.png");
    y->setParentItem(this);
    y->setPos(519,429);
    connect(y,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    u = new Button("U.png");
    u->setParentItem(this);
    u->setPos(603,426);
    connect(u,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    i = new Button("I.png");
    i->setParentItem(this);
    i->setPos(688,429);
    connect(i,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    o = new Button("O.png");
    o->setParentItem(this);
    o->setPos(770,425);
    connect(o,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    p = new Button("P.png");
    p->setParentItem(this);
    p->setPos(853,429);
    connect(p,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    ////

    a = new Button("A.png");
    a->setParentItem(this);
    a->setPos(139,483);
    connect(a,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    s = new Button("S.png");
    s->setParentItem(this);
    s->setPos(224,482);
    connect(s,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    d = new Button("D.png");
    d->setParentItem(this);
    d->setPos(307,483);
    connect(d,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    f = new Button("F.png");
    f->setParentItem(this);
    f->setPos(392,483);
    connect(f,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    g = new Button("G.png");
    g->setParentItem(this);
    g->setPos(477,483);
    connect(g,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    h = new Button("H.png");
    h->setParentItem(this);
    h->setPos(560,483);
    connect(h,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    j = new Button("J.png");
    j->setParentItem(this);
    j->setPos(646,485);
    connect(j,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    k = new Button("K.png");
    k->setParentItem(this);
    k->setPos(730,485);
    connect(k,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    l = new Button("L.png");
    l->setParentItem(this);
    l->setPos(817,484);
    connect(l,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    ////

    z = new Button("Z.png");
    z->setParentItem(this);
    z->setPos(176,546);
    connect(z,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    x = new Button("X.png");
    x->setParentItem(this);
    x->setPos(267,546);
    connect(x,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    c = new Button("C.png");
    c->setParentItem(this);
    c->setPos(350,546);
    connect(c,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    v = new Button("V.png");
    v->setParentItem(this);
    v->setPos(435,546);
    connect(v,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    b = new Button("B.png");
    b->setParentItem(this);
    b->setPos(519,546);
    connect(b,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    n = new Button("N.png");
    n->setParentItem(this);
    n->setPos(605,548);
    connect(n,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    m = new Button("M.png");
    m->setParentItem(this);
    m->setPos(689,548);
    connect(m,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));

    del = new Button("Delete.png");
    del->setParentItem(this);
    del->setPos(774,546);
    connect(del,SIGNAL(clicked(QString)),this,SIGNAL(clickedkey(QString)));
}

QRectF AllKey::boundingRect() const
{
    return QRectF(0,0,750,353);
}

void AllKey::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setRenderHint(QPainter::SmoothPixmapTransform);
    Q_UNUSED(painter)
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

