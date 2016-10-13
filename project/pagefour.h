#ifndef PAGEFOUR_H
#define PAGEFOUR_H

#include "return.h"
#include <QtSql>
#include <QGraphicsScene>
#include <QTimer>
#include "button.h"
#include "popitem.h"

class PageFour : public QGraphicsScene
{
    Q_OBJECT
private:
    PopItem *yejiao1;
    PopItem *yejiao2;
    PopItem *yejiao3;
    Return *go_home;
    QGraphicsTextItem* djs_text;
public:
    PageFour();    
    QTimer *timer;
    int djs_int;

    Button *A;
    Button *B;
    Button *C;
    Button *D;
    Button *F;
    Button *G;
    Button *H;
    Button *J;
    Button *K;
    Button *L;
    Button *M;
    Button *N;
    Button *O;
    Button *P;
    Button *Q;
    Button *R;
    Button *S;
    Button *T;
    Button *U;
    Button *W;
    Button *X;
    Button *Y;
    Button *Z;
    Button *Other;
    Button *Usual;

    void end_djs();
public slots:
    void update_djs();

signals:
    void back_home();
    void goPageA(QString);
    void goPageB(QString);
    void goPageC(QString);
    void goPageD(QString);
    void goPageF(QString);
    void goPageG(QString);
    void goPageH(QString);
    void goPageJ(QString);
    void goPageK(QString);
    void goPageL(QString);
    void goPageM(QString);
    void goPageN(QString);
    void goPageO(QString);
    void goPageP(QString);
    void goPageQ(QString);
    void goPageR(QString);
    void goPageS(QString);
    void goPageT(QString);
    void goPageU(QString);
    void goPageW(QString);
    void goPageX(QString);
    void goPageY(QString);
    void goPageZ(QString);
    void goPageUsual(QString);
    void goPageOther(QString);

};

#endif // PAGEFOUR_H
