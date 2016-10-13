#include "pageone.h"

PageOne::PageOne()
{
    setBackgroundBrush(QBrush(QPixmap("PageOneBack.png")));

    yejiao2 = new PopItem("yejiao2.png");
    addItem(yejiao2);
    yejiao2->setPos(929,10);

    yejiao3 = new PopItem("yejiao3.png");
    addItem(yejiao3);
    yejiao3->setPos(218,697);

    showPlace = 1;
    my_password = QString("");

    KeyNum1 = new QGraphicsPixmapItem;
    addItem(KeyNum1);
    KeyNum1->setPos(66,211);

    KeyNum2 = new QGraphicsPixmapItem;
    addItem(KeyNum2);
    KeyNum2->setPos(182,172);

    KeyNum3 = new QGraphicsPixmapItem;
    addItem(KeyNum3);
    KeyNum3->setPos(302,148);

    KeyNum4 = new QGraphicsPixmapItem;
    addItem(KeyNum4);
    KeyNum4->setPos(421,141);

    KeyNum5 = new QGraphicsPixmapItem;
    addItem(KeyNum5);
    KeyNum5->setPos(539,138);

    KeyNum6 = new QGraphicsPixmapItem;
    addItem(KeyNum6);
    KeyNum6->setPos(658,154);

    KeyNum7 = new QGraphicsPixmapItem;
    addItem(KeyNum7);
    KeyNum7->setPos(772,182);

    KeyNum8 = new QGraphicsPixmapItem;
    addItem(KeyNum8);
    KeyNum8->setPos(882,225);

    djs_text = new QGraphicsTextItem;
    addItem(djs_text);
    djs_text->setFont(QFont("Times", 18, QFont::Bold));
    djs_text->setDefaultTextColor(QColor(Qt::white));
    djs_text->setPos(946,23);

    allkey = new AllKey();
    addItem(allkey);
    allkey->setPos(0,0);
    connect(allkey,SIGNAL(clickedkey(QString)),this,SLOT(showKeyNum(QString)));

    go_home = new Return("yejiao4.png");
    addItem(go_home);
    go_home->setPos(888,690);
    connect(go_home,SIGNAL(click()),this,SIGNAL(back_home()));

    pop_item = new PopItem("mimayou.png");
    addItem(pop_item);
    pop_item->setPos(312,349);
    pop_item->hide();

    pop_thank = new PopItem("qingguanshang.png");
    addItem(pop_thank);
    pop_thank->setPos(312,349);
    pop_thank->hide();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_djs()));
    timer->stop();

    djs_int = 99;
}

void PageOne::end_djs()
{
    djs_int = 99;
    timer->stop();
}

void PageOne::update_djs()
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

void PageOne::showKeyNum(QString key)
{
    djs_int = 99;

    if(key=="Delete.png")
    {
        my_password.chop(1);

        switch (showPlace)
        {
        case 2:
            KeyNum1->setPixmap(QString("default.png"));
            this->update();
            showPlace--;
            break;
        case 3:
            KeyNum2->setPixmap(QString("default.png"));
            this->update();
            showPlace--;
            break;
        case 4:
            KeyNum3->setPixmap(QString("default.png"));
            this->update();
            showPlace--;
            break;
        case 5:
            KeyNum4->setPixmap(QString("default.png"));
            this->update();
            showPlace--;
            break;
        case 6:
            KeyNum5->setPixmap(QString("default.png"));
            this->update();
            showPlace--;
            break;
        case 7:
            KeyNum6->setPixmap(QString("default.png"));
            this->update();
            showPlace--;
            break;
        case 8:
            KeyNum7->setPixmap(QString("default.png"));
            this->update();
            showPlace--;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (showPlace)
        {
        case 1:
            KeyNum1->setPixmap(QString("key1").append(key));
            showPlace++;
            my_password.append(english(key));
            break;
        case 2:
            KeyNum2->setPixmap(QString("key2").append(key));
            showPlace++;
            my_password.append(english(key));

            //cam.startVideo(QString(QDateTime::currentDateTime().toString("yyyyMMddhhmmss")).append(".avi"));
            //QTimer::singleShot(10000,this,SLOT(stopMyVideo()));

            emit toCam();

            break;
        case 3:
            KeyNum3->setPixmap(QString("key3").append(key));
            showPlace++;
            my_password.append(english(key));
            break;
        case 4:
            KeyNum4->setPixmap(QString("key4").append(key));
            showPlace++;
            my_password.append(english(key));
            break;
        case 5:
            KeyNum5->setPixmap(QString("key5").append(key));
            showPlace++;
            my_password.append(english(key));
            break;
        case 6:
            KeyNum6->setPixmap(QString("key6").append(key));
            showPlace++;
            my_password.append(english(key));
            break;
        case 7:
            KeyNum7->setPixmap(QString("key7").append(key));
            showPlace++;
            my_password.append(english(key));
            break;
        case 8:
            KeyNum8->setPixmap(QString("key8").append(key));
            showPlace=1;
            my_password.append(english(key));
            showYesNo();
            break;
        default:
            break;
        }
    }
}

QString PageOne::english(QString key)
{
    return QString(key.at(0));
}

void PageOne::initKeyNum()
{
    KeyNum1->setPixmap(QString("default.png"));
    KeyNum2->setPixmap(QString("default.png"));
    KeyNum3->setPixmap(QString("default.png"));
    KeyNum4->setPixmap(QString("default.png"));
    KeyNum5->setPixmap(QString("default.png"));
    KeyNum6->setPixmap(QString("default.png"));
    KeyNum7->setPixmap(QString("default.png"));
    KeyNum8->setPixmap(QString("default.png"));
}

void PageOne::showYesNo()
{
    initKeyNum();

    /////shu ju ku cao zuo
    QSqlQuery query(Config.dbconn);
    query.exec("select * from xiangzi");
    while (query.next())
    {
        QString database_password = query.value(2).toString();
        QString barcode = query.value(0).toString();
        QString telephone = query.value(3).toString();/////int?
        //dan xin chong fu mi ma
        qDebug() << "data_password" << database_password;
        if(database_password == my_password)
        {
            int door_id = query.value(1).toInt();
            qDebug() <<"door number:"<< door_id;
            //jian cha men shi fou da kai
            //ser->openDoor(door_id);
            query.prepare("delete from xiangzi where password = :pass");
            query.bindValue(":pass", my_password);
            query.exec();

            QString qujianshijian = QDateTime::currentDateTime().toString();
            query.prepare("INSERT INTO QuJian (telephone, barcode, address, photo, video, qutime) VALUES (:telephone, :barcode, :address, :photo, :video, :qutime)");
            query.bindValue(":telephone", telephone);
            query.bindValue(":barcode", barcode);
            query.bindValue(":address", "yidaxiaoqu");
            query.bindValue(":photo", "...");
            query.bindValue(":video", "...");
            query.bindValue(":qutime", qujianshijian);
            query.exec();

            qDebug() << my_password;

            my_password.clear();
            emit one_to(door_id);

            pop_thank->show();
            QTimer::singleShot( 1500, this, SLOT(hide_thank()));

            return;
        }
    }

    my_password.clear();

    pop_item->show();
    QTimer::singleShot( 1500, this, SLOT(hide_item()));
}

void PageOne::hide_thank()
{
    pop_thank->hide();
}

void PageOne::hide_item()
{
    pop_item->hide();
}

//void PageOne::stopMyVideo()
//{
//    cam.capturePic(QString(QDateTime::currentDateTime().toString("yyyyMMddhhmmss")).append(".jpeg"));
//    cam.stopVideo();
//    ///jiayiju delete free *p
//}
