#include "pagetwo.h"

PageTwo::PageTwo()
{
    setBackgroundBrush(QBrush(QPixmap("two.png")));

//    yejiao2 = new PopItem("yejiao2.png");
//    addItem(yejiao2);
//    yejiao2->setPos(929,10);

//    yejiao2 = new PopItem("yejiao2.png");
//    addItem(yejiao2);
//    yejiao2->setPos(929,10);

//    yejiao3 = new PopItem("yejiao3.png");
//    addItem(yejiao3);
//    yejiao3->setPos(218,697);

    go_home = new Return("yejiao4.png");
    addItem(go_home);
    go_home->setPos(924,668);
    connect(go_home,SIGNAL(click()),this,SIGNAL(back_home()));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_djs()));
    timer->stop();

    djs_int = 99;
}

void PageTwo::end_djs()
{
    djs_int = 99;
    timer->stop();
}

void PageTwo::update_djs()
{
    if(djs_int==1)
    {
        end_djs();
        emit back_home();
    }

    djs_int--;
}
