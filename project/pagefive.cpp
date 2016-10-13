#include "pagefive.h"
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QComboBox>

PageFive::PageFive()
{
    setBackgroundBrush(QBrush(QPixmap("PageFiveBack.png")));
    //c5 = Phonon::createPlayer(Phonon//cCategory,Phonon::MediaSource("Touch.wav"));
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

    guanliyuan_edit = new QLineEdit;
    guanliyuan_edit->setStyleSheet("color: black;background-image:url(TJ1.png);background-color:rgba(255,255,255,0%);");
    guanliyuan_edit->setFixedSize(263,67);
    guanliyuan_edit->setFont(QFont("Times", 16, QFont::Bold));
    guanliyuan_edit->setFrame(false);
    proxy1 = this->addWidget(guanliyuan_edit);
    proxy1->setPos(420,129);

    mima_edit = new QLineEdit;
    mima_edit->setStyleSheet("color: black;background-image:url(TJ2.png);background-color:rgba(255,255,255,0%);");
    mima_edit->setFixedSize(257,59);
    mima_edit->setFont(QFont("Times", 16, QFont::Bold));
    mima_edit->setFrame(false);
    proxy2 = this->addWidget(mima_edit);
    proxy2->setPos(428,213);

    queren_button = new Button("TJ3.png");
    addItem(queren_button);
    queren_button->setPos(426,282);

    allkey = new AllKey();
    addItem(allkey);
    allkey->setPos(0,50);
    //connect(allkey,SIGNAL(clickedkey(QString)),this,SLOT(showKeyNum(QString)));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_djs()));
    timer->stop();
    djs_int = 99;
}

void PageFive::queren()
{
//    QSqlQuery query(Config.dbconn);
//    query.exec("create table IF NOT EXISTS user(name varchar primary key,password varchar)");
//    query.exec("insert into user values('abc881858','abc001017')");
//    query.exec("select * from user");
//    while (query.next())
//    {
//        QString name = query.value(0).toString();
//        QString password = query.value(1).toString();
//        if (name==guanliyuan_edit->text() && password==mima_edit->text())
//        {
//            emit turn_ten();
//        }
//    }
}

void PageFive::end_djs()
{
    djs_int = 99;
    timer->stop();
}

void PageFive::update_djs()
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
