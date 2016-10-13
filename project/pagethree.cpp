#include "pagethree.h"
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QComboBox>

PageThree::PageThree() :can_read(false)
{
    setBackgroundBrush(QBrush(QPixmap("PageThreeBack.png")));

    go_home = new Return("yejiao4.png");
    addItem(go_home);
    go_home->setPos(888,690);
    connect(go_home,SIGNAL(click()),this,SIGNAL(back_home()));

    allkey = new AllKey();
    addItem(allkey);
    allkey->setPos(0,50);
    connect(allkey,SIGNAL(clickedkey(QString)),this,SLOT(showKeyNum(QString)));

    toudiyuan_edit = new QLineEdit;
    toudiyuan_edit->setStyleSheet("color: black;background-image:url(TJ1.png);background-color:rgba(255,255,255,0%);");
    toudiyuan_edit->setFixedSize(263,67);
    toudiyuan_edit->setFont(QFont("Times", 16, QFont::Bold));
    toudiyuan_edit->setFrame(false);
    proxy1 = this->addWidget(toudiyuan_edit);
    proxy1->setPos(268,129);

    mima_edit = new QLineEdit;
    mima_edit->setStyleSheet("color: black;background-image:url(TJ2.png);background-color:rgba(255,255,255,0%);");
    mima_edit->setFixedSize(257,59);
    mima_edit->setFont(QFont("Times", 16, QFont::Bold));
    mima_edit->setFrame(false);
    proxy2 = this->addWidget(mima_edit);
    proxy2->setPos(276,213);

    button_denglu = new Button("TJ3.png");
    addItem(button_denglu);
    button_denglu->setPos(274,282);

    reader = new ICReader;
    connect(button_denglu,SIGNAL(clicked(QString)),this,SLOT(denglu(QString)));
    connect(reader,SIGNAL(iCData(QString)),this,SLOT(denglu2(QString)));

//    pop_item = new PopItem("youhuiyuan.png");
//    addItem(pop_item);
//    pop_item->setPos(312,349);

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("mytest.db"); // 数据库名与路径, 此时是放在同目录下
//    db.open(); // 连接数据库, 然后就可以使用了
//    QSqlQuery query(Config.dbconn);
//    query.exec("create table IF NOT EXISTS user(name varchar primary key,password varchar)");
//    query.exec("create table IF NOT EXISTS iccard(id varchar primary key)");
//    query.exec("create table IF NOT EXISTS tiaoma(id varchar primary key)");
//    query.exec("insert into user values('abc881858','abc001017')");

    djs1 = new QGraphicsPixmapItem(QPixmap("djs1.png"));
    addItem(djs1);
    djs1->setPos(924,30);

    djs2 = new QGraphicsPixmapItem(QPixmap("djs2.png"));
    addItem(djs2);
    djs2->setPos(924,30);

    djs3 = new QGraphicsPixmapItem(QPixmap("djs3.png"));
    addItem(djs3);
    djs3->setPos(924,30);

    djs4 = new QGraphicsPixmapItem(QPixmap("djs4.png"));
    addItem(djs4);
    djs4->setPos(924,30);

    djs5 = new QGraphicsPixmapItem(QPixmap("djs5.png"));
    addItem(djs5);
    djs5->setPos(924,30);

    djs6 = new QGraphicsPixmapItem(QPixmap("djs6.png"));
    addItem(djs6);
    djs6->setPos(924,30);

    djs7 = new QGraphicsPixmapItem(QPixmap("djs7.png"));
    addItem(djs7);
    djs7->setPos(924,30);

    djs8 = new QGraphicsPixmapItem(QPixmap("djs8.png"));
    addItem(djs8);
    djs8->setPos(924,30);

    djs9 = new QGraphicsPixmapItem(QPixmap("djs9.png"));
    addItem(djs9);
    djs9->setPos(924,30);

    djs10 = new QGraphicsPixmapItem(QPixmap("djs10.png"));
    addItem(djs10);
    djs10->setPos(924,30);

    djs11 = new QGraphicsPixmapItem(QPixmap("djs11.png"));
    addItem(djs11);
    djs11->setPos(924,30);

    djs12 = new QGraphicsPixmapItem(QPixmap("djs12.png"));
    addItem(djs12);
    djs12->setPos(924,30);

    djs13 = new QGraphicsPixmapItem(QPixmap("djs13.png"));
    addItem(djs13);
    djs13->setPos(924,30);

    djs14 = new QGraphicsPixmapItem(QPixmap("djs14.png"));
    addItem(djs14);
    djs14->setPos(924,30);

    djs15 = new QGraphicsPixmapItem(QPixmap("djs15.png"));
    addItem(djs15);
    djs15->setPos(924,30);

    djs16 = new QGraphicsPixmapItem(QPixmap("djs16.png"));
    addItem(djs16);
    djs16->setPos(924,30);

    djs17 = new QGraphicsPixmapItem(QPixmap("djs17.png"));
    addItem(djs17);
    djs17->setPos(924,30);

    djs18 = new QGraphicsPixmapItem(QPixmap("djs18.png"));
    addItem(djs18);
    djs18->setPos(924,30);

    djs19 = new QGraphicsPixmapItem(QPixmap("djs19.png"));
    addItem(djs19);
    djs19->setPos(924,30);

    djs20 = new QGraphicsPixmapItem(QPixmap("djs20.png"));
    addItem(djs20);
    djs20->setPos(924,30);

    djs21 = new QGraphicsPixmapItem(QPixmap("djs21.png"));
    addItem(djs21);
    djs21->setPos(924,30);

    djs22 = new QGraphicsPixmapItem(QPixmap("djs22.png"));
    addItem(djs22);
    djs22->setPos(924,30);

    djs23 = new QGraphicsPixmapItem(QPixmap("djs23.png"));
    addItem(djs23);
    djs23->setPos(924,30);

    djs24 = new QGraphicsPixmapItem(QPixmap("djs24.png"));
    addItem(djs24);
    djs24->setPos(924,30);

    djs25 = new QGraphicsPixmapItem(QPixmap("djs25.png"));
    addItem(djs25);
    djs25->setPos(924,30);

    djs26 = new QGraphicsPixmapItem(QPixmap("djs26.png"));
    addItem(djs26);
    djs26->setPos(924,30);

    djs27 = new QGraphicsPixmapItem(QPixmap("djs27.png"));
    addItem(djs27);
    djs27->setPos(924,30);

    djs28 = new QGraphicsPixmapItem(QPixmap("djs28.png"));
    addItem(djs28);
    djs28->setPos(924,30);

    djs29 = new QGraphicsPixmapItem(QPixmap("djs29.png"));
    addItem(djs29);
    djs29->setPos(924,30);

    djs30 = new QGraphicsPixmapItem(QPixmap("djs30.png"));
    addItem(djs30);
    djs30->setPos(924,30);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_djs()));
    timer->stop();

    djs_int = 30;

    toudiyuan_mima = 0;
    toudiyuan_edit->installEventFilter(this);
    mima_edit->installEventFilter(this);
}

bool PageThree::eventFilter(QObject *obj, QEvent *event)
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

void PageThree::showKeyNum(QString key)
{
    if(toudiyuan_mima == 1)
    {
        if(key.startsWith("Delete"))
        {
            if(toudiyuan_edit->text().size()>0)
            {
                QString str = toudiyuan_edit->text();
                str.chop(1);
                toudiyuan_edit->setText(str);
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
                QString str = mima_edit->text();
                str.chop(1);
                mima_edit->setText(str);
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

void PageThree::denglu(QString str)
{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("mytest.db"); // 数据库名与路径, 此时是放在同目录下
//    db.open(); // 连接数据库, 然后就可以使用了
//    QSqlQuery query(Config.dbconn);
//    query.exec("select * from user");
//    while (query.next())
//    {
//        QString name = query.value(0).toString();
//        QString password = query.value(1).toString();
//        if (name==toudiyuan_edit->text() && password==mima_edit->text())
//        {
//            emit turn_nine();
//        }
//    }

//    cam.startVideo(QString(QDateTime::currentDateTime().toString("yyyyMMddhhmmss")).append(".avi"));
//    QTimer::singleShot(10000,this,SLOT(stopMyVideo()));


    //tong guo shu ru zhanghao mima jinru

    QSqlQuery query(Config.data_base);
    query.exec("select * from Employee");
    while (query.next())
    {
        QString epuser = query.value(1).toString();
        QString epassword = query.value(3).toString();
        if (epuser==toudiyuan_edit->text() && epassword==mima_edit->text())
        {
            Config.man = query.value(0).toString();//FIXME epid
            emit turn_nine();
        }
    }

    toudiyuan_edit->clear();
    mima_edit->clear();

}

void PageThree::denglu2(QString str)
{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("mytest.db");
//    db.open();
//    QSqlQuery query(Config.dbconn);
//    query.prepare("insert into iccard (id) values (:id)");
//    query.bindValue(":id", (int)str);
//    query.exec();

    // tong guo shua ka jin ru

    qDebug()<<str<<".....";
    if(can_read)
    {
        can_read = false;
        //FIXME need adding!
        emit turn_nine();
    }
}

void PageThree::stopMyVideo()
{
    cam.capturePic(QString(QDateTime::currentDateTime().toString("yyyyMMddhhmmss")).append(".jpeg"));
    cam.stopVideo();
    ///jiayiju delete free *p
}

void PageThree::init_djs()
{
    djs1->show();
    djs2->show();
    djs3->show();
    djs4->show();
    djs5->show();
    djs6->show();
    djs7->show();
    djs8->show();
    djs9->show();
    djs10->show();
    djs11->show();
    djs12->show();
    djs13->show();
    djs14->show();
    djs15->show();
    djs16->show();
    djs17->show();
    djs18->show();
    djs19->show();
    djs20->show();
    djs21->show();
    djs22->show();
    djs23->show();
    djs24->show();
    djs25->show();
    djs26->show();
    djs27->show();
    djs28->show();
    djs29->show();
    djs30->show();

    can_read = true;
    reader->startReader();

    toudiyuan_edit->clear();
    mima_edit->clear();
}

void PageThree::end_djs()
{
    djs_int = 30;
    reader->stopReader();

    timer->stop();
}

void PageThree::update_djs()
{
    if(djs_int==1)
    {
        end_djs();
        emit back_home();
    }

    switch (djs_int)
    {
    case 1:
        djs1->hide();
        break;
    case 2:
        djs2->hide();
        break;
    case 3:
        djs3->hide();
        break;
    case 4:
        djs4->hide();
        break;
    case 5:
        djs5->hide();
        break;
    case 6:
        djs6->hide();
        break;
    case 7:
        djs7->hide();
        break;
    case 8:
        djs8->hide();
        break;
    case 9:
        djs9->hide();
        break;
    case 10:
        djs10->hide();
        break;
    case 11:
        djs11->hide();
        break;
    case 12:
        djs12->hide();
        break;
    case 13:
        djs13->hide();
        break;
    case 14:
        djs14->hide();
        break;
    case 15:
        djs15->hide();
        break;
    case 16:
        djs16->hide();
        break;
    case 17:
        djs17->hide();
        break;
    case 18:
        djs18->hide();
        break;
    case 19:
        djs19->hide();
        break;
    case 20:
        djs20->hide();
        break;
    case 21:
        djs21->hide();
        break;
    case 22:
        djs22->hide();
        break;
    case 23:
        djs23->hide();
        break;
    case 24:
        djs24->hide();
        break;
    case 25:
        djs25->hide();
        break;
    case 26:
        djs26->hide();
        break;
    case 27:
        djs27->hide();
        break;
    case 28:
        djs28->hide();
        break;
    case 29:
        djs29->hide();
        break;
    case 30:
        djs30->hide();
        break;
    default:
        break;
    }

    djs_int--;

}

void PageThree::to_Cam()
{
    cam.capturePic(QString(QDateTime::currentDateTime().toString("yyyyMMddhhmmss")).append(".jpeg"));
    cam.stopVideo();
}
