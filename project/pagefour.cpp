#include "pagefour.h"

PageFour::PageFour()
{
    setBackgroundBrush(QBrush(QPixmap("P4Back.png")));

    yejiao1 = new PopItem("yejiao1.png");
    addItem(yejiao1);
    yejiao1->setPos(34,24);

    yejiao2 = new PopItem("yejiao2.png");
    addItem(yejiao2);
    yejiao2->setPos(929,10);

    yejiao3 = new PopItem("yejiao3.png");
    addItem(yejiao3);
    yejiao3->setPos(218,697);

    go_home = new Return("yejiao4.png");
    addItem(go_home);
    go_home->setPos(888,690);
    connect(go_home,SIGNAL(click()),this,SIGNAL(back_home()));

    djs_text = new QGraphicsTextItem;
    addItem(djs_text);
    djs_text->setFont(QFont("Times", 18, QFont::Bold));
    djs_text->setDefaultTextColor(QColor(Qt::white));
    djs_text->setPos(946,23);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_djs()));
    timer->stop();
    djs_int = 99;

    A = new Button("P4A.png");
    B = new Button("P4B.png");
    C = new Button("P4C.png");
    D = new Button("P4D.png");
    F = new Button("P4F.png");
    G = new Button("P4G.png");
    H = new Button("P4H.png");
    J = new Button("P4J.png");
    K = new Button("P4K.png");
    L = new Button("P4L.png");
    M = new Button("P4M.png");
    N = new Button("P4N.png");
    O = new Button("P4O.png");
    P = new Button("P4P.png");
    Q = new Button("P4Q.png");
    R = new Button("P4R.png");
    S = new Button("P4S.png");
    T = new Button("P4T.png");
    U = new Button("P4U.png");
    W = new Button("P4W.png");
    X = new Button("P4X.png");
    Y = new Button("P4Y.png");
    Z = new Button("P4Z.png");
    Other = new Button("P4Other.png");
    Usual = new Button("P4Usual.png");

    connect(A,SIGNAL(clicked(QString)),this,SIGNAL(goPageA(QString)));
    connect(B,SIGNAL(clicked(QString)),this,SIGNAL(goPageB(QString)));
    connect(C,SIGNAL(clicked(QString)),this,SIGNAL(goPageC(QString)));
    connect(D,SIGNAL(clicked(QString)),this,SIGNAL(goPageD(QString)));
    connect(F,SIGNAL(clicked(QString)),this,SIGNAL(goPageF(QString)));
    connect(G,SIGNAL(clicked(QString)),this,SIGNAL(goPageG(QString)));
    connect(H,SIGNAL(clicked(QString)),this,SIGNAL(goPageH(QString)));
    connect(J,SIGNAL(clicked(QString)),this,SIGNAL(goPageJ(QString)));
    connect(K,SIGNAL(clicked(QString)),this,SIGNAL(goPageK(QString)));
    connect(L,SIGNAL(clicked(QString)),this,SIGNAL(goPageL(QString)));
    connect(M,SIGNAL(clicked(QString)),this,SIGNAL(goPageM(QString)));
    connect(N,SIGNAL(clicked(QString)),this,SIGNAL(goPageN(QString)));
    connect(O,SIGNAL(clicked(QString)),this,SIGNAL(goPageO(QString)));
    connect(P,SIGNAL(clicked(QString)),this,SIGNAL(goPageP(QString)));
    connect(Q,SIGNAL(clicked(QString)),this,SIGNAL(goPageQ(QString)));
    connect(R,SIGNAL(clicked(QString)),this,SIGNAL(goPageR(QString)));
    connect(S,SIGNAL(clicked(QString)),this,SIGNAL(goPageS(QString)));
    connect(T,SIGNAL(clicked(QString)),this,SIGNAL(goPageT(QString)));
    connect(U,SIGNAL(clicked(QString)),this,SIGNAL(goPageU(QString)));
    connect(W,SIGNAL(clicked(QString)),this,SIGNAL(goPageW(QString)));
    connect(X,SIGNAL(clicked(QString)),this,SIGNAL(goPageX(QString)));
    connect(Y,SIGNAL(clicked(QString)),this,SIGNAL(goPageY(QString)));
    connect(Z,SIGNAL(clicked(QString)),this,SIGNAL(goPageZ(QString)));
    connect(Usual,SIGNAL(clicked(QString)),this,SIGNAL(goPageUsual(QString)));
    connect(Other,SIGNAL(clicked(QString)),this,SIGNAL(goPageOther(QString)));

    addItem(A);
    A->setPos(239,211);
    addItem(B);
    B->setPos(348,215);
    addItem(C);
    C->setPos(460,215);
    addItem(D);
    D->setPos(578,211);
    addItem(F);
    F->setPos(693,211);
    addItem(G);
    G->setPos(236,290);
    addItem(H);
    H->setPos(349,290);
    addItem(J);
    J->setPos(464,290);
    addItem(K);
    K->setPos(578,290);
    addItem(L);
    L->setPos(693,290);
    addItem(M);
    M->setPos(236,370);
    addItem(N);
    N->setPos(348,371);
    addItem(O);
    O->setPos(461,372);
    addItem(P);
    P->setPos(578,369);
    addItem(Q);
    Q->setPos(696,371);
    addItem(R);
    R->setPos(235,445);
    addItem(S);
    S->setPos(350,452);
    addItem(T);
    T->setPos(464,448);
    addItem(U);
    U->setPos(578,448);
    addItem(W);
    W->setPos(692,445);
    addItem(X);
    X->setPos(235,529);
    addItem(Y);
    Y->setPos(346,526);
    addItem(Z);
    Z->setPos(459,530);
    addItem(Other);
    Other->setPos(573,526);
    addItem(Usual);
    Usual->setPos(692,529);

}

void PageFour::update_djs()
{
    if(djs_int==1)
    {
        end_djs();
        emit back_home();
    }

    djs_text->setPlainText(QString::number(djs_int));
    this->update();

    djs_int--;
}

void PageFour::end_djs()
{
    djs_int = 99;
    timer->stop();
}
