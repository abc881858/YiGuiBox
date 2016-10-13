#include "pagefour3.h"
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QComboBox>

PageFour3::PageFour3()
{
    setBackgroundBrush(QBrush(QPixmap("ZC36.png")));

    go_home = new Return("yejiao4.png");
    addItem(go_home);
    go_home->setPos(888,690);
    connect(go_home,SIGNAL(click()),this,SIGNAL(back_home()));

    allkey = new AllKey();
    addItem(allkey);
    allkey->setPos(0,50);
    connect(allkey,SIGNAL(clickedkey(QString)),this,SLOT(showKeyNum(QString)));

//    toudiyuan_edit = new QLineEdit;
//    toudiyuan_edit->setStyleSheet("color: black;background-image:url(ZC31.png);background-color:rgba(255,255,255,0%);");
//    toudiyuan_edit->setFixedSize(263,67);
//    toudiyuan_edit->setFont(QFont("Times", 16, QFont::Bold));
//    toudiyuan_edit->setFrame(false);
//    proxy1 = this->addWidget(toudiyuan_edit);
//    proxy1->setPos(268,129);

//    mima_edit = new QLineEdit;
//    mima_edit->setStyleSheet("color: black;background-image:url(TJ2.png);background-color:rgba(255,255,255,0%);");
//    mima_edit->setFixedSize(257,59);
//    mima_edit->setFont(QFont("Times", 16, QFont::Bold));
//    mima_edit->setFrame(false);
//    proxy2 = this->addWidget(mima_edit);
//    proxy2->setPos(276,213);

//    button_denglu = new Button("TJ3.png");
//    addItem(button_denglu);
//    button_denglu->setPos(274,282);

//    connect(button_denglu,SIGNAL(clicked(QString)),this,SLOT(denglu(QString)));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_djs()));
    timer->stop();

    djs_int = 30;

    toudiyuan_mima = 0;
    toudiyuan_edit->installEventFilter(this);
    mima_edit->installEventFilter(this);
}

bool PageFour3::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type()==QEvent::FocusIn)
    {
        if (obj == toudiyuan_edit)
        {
            toudiyuan_mima = 1;
        }
        else if (obj == mima_edit)
        {
            toudiyuan_mima = 2;
        }
    }
    return QGraphicsScene::eventFilter(obj,event);
}

void PageFour3::showKeyNum(QString key)
{
    if(toudiyuan_mima == 1)
    {
        if(key.startsWith("Delete"))
        {
            if(toudiyuan_edit->text().size()>0)
            {
                toudiyuan_edit->text().chop(1);
                toudiyuan_edit->setText(toudiyuan_edit->text());
                toudiyuan_edit->update();
            }
        }
        else
        {
            toudiyuan_edit->setText(toudiyuan_edit->text().append(key.at(0)));
            toudiyuan_edit->update();
        }
    }
    else if(toudiyuan_mima == 2)
    {
        if(key.startsWith("Delete"))
        {
            if(mima_edit->text().size()>0)
            {
                mima_edit->text().chop(1);
                mima_edit->setText(mima_edit->text());
                mima_edit->update();
            }
        }
        else
        {
            mima_edit->setText(mima_edit->text().append(key.at(0)));
            mima_edit->update();
        }
    }
}

void PageFour3::denglu(QString str)
{

}

void PageFour3::denglu2(QString str)
{

}


void PageFour3::init_djs()
{
    toudiyuan_edit->clear();
    mima_edit->clear();
}

void PageFour3::end_djs()
{
    djs_int = 30;
    timer->stop();
}

void PageFour3::update_djs()
{
    if(djs_int==1)
    {
        end_djs();
        emit back_home();
    }

    djs_int--;

}
