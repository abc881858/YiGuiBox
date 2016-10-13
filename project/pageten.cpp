#include "pageten.h"

PageTen::PageTen()//管理员页面
{
    setBackgroundBrush(QBrush(QPixmap("back.png")));

//    QSqlDatabase Config.dbconn = QSqlDatabase::addDatabase("QSQLITE");
//    Config.dbconn.setDatabaseName("mytest.db");
//    Config.dbconn.open();

//    QSqlQuery query(Config.dbconn);
//    query.exec("create table IF NOT EXISTS courier(name varchar primary key, leader varchar, tel varchar, address varchar, user varchar, card varchar, phone varchar)");
//    query.exec("insert into courier values('shiyizhineng','Bosszhuang','051382222222','huakelu_180_6_202','wudongliang','320684199999999999','15298666666')");
//    query.exec("create table IF NOT EXISTS QuJian(telephone varchar, barcode varchar primary key,address varchar,photo varchar,video varchar,qutime varchar)");

//    query.exec("create table IF NOT EXISTS TouJian(ic varchar, barcode varchar primary key,address varchar,photo varchar,video varchar,toutime varchar)");
//    query.exec("insert into TouJian values('1234567','1234','222','...','...','1989-11-14')");

//    query.exec("create table JiJian(name varchar primary key, tel varchar, phone varchar,address varchar)");

    model = new QSqlQueryModel;
    model->setQuery("select * from courier",Config.dbconn);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("gongsimingcheng"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("gongsifuzeren"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("gongsidianhua"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("gongsidizhi"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("toudiyuanxingming"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("toudiyuanshenfenzheng"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("toudiyuanshouji"));

    model2 = new QSqlQueryModel;
    model2->setQuery("select * from QuJian",Config.dbconn);
    model2->setHeaderData(0,Qt::Horizontal,QObject::tr("qujianrenshoujihao"));
    model2->setHeaderData(1,Qt::Horizontal,QObject::tr("yundanhao"));
    model2->setHeaderData(2,Qt::Horizontal,QObject::tr("dizhi"));
    model2->setHeaderData(3,Qt::Horizontal,QObject::tr("paizhao"));
    model2->setHeaderData(4,Qt::Horizontal,QObject::tr("luxiang"));
    model2->setHeaderData(5,Qt::Horizontal,QObject::tr("time"));

    model3 = new QSqlQueryModel;
    model3->setQuery("select * from TouJian",Config.dbconn);
    model3->setHeaderData(0,Qt::Horizontal,QObject::tr("toujianrenICka"));
    model3->setHeaderData(1,Qt::Horizontal,QObject::tr("yundanhao"));
    model3->setHeaderData(2,Qt::Horizontal,QObject::tr("dizhi"));
    model3->setHeaderData(3,Qt::Horizontal,QObject::tr("paizhao"));
    model3->setHeaderData(4,Qt::Horizontal,QObject::tr("luxiang"));
    model3->setHeaderData(5,Qt::Horizontal,QObject::tr("time"));

    model4 = new QSqlQueryModel;
//    model4->setQuery("select * from TouJian");
//    model4->setHeaderData(0,Qt::Horizontal,QObject::tr("jijianrenxingming"));
//    model4->setHeaderData(1,Qt::Horizontal,QObject::tr("jijianrendizhi"));
//    model4->setHeaderData(2,Qt::Horizontal,QObject::tr("jijianrendianhua"));
//    model4->setHeaderData(3,Qt::Horizontal,QObject::tr("jijianrenshoujihao"));
//    model4->setHeaderData(4,Qt::Horizontal,QObject::tr("jijianrenyundanhao"));

    model5 = new QSqlQueryModel;
//    model5->setQuery("select * from TouJian");
    model5->setHeaderData(0,Qt::Horizontal,QObject::tr("toujianrenICka"));
    model5->setHeaderData(1,Qt::Horizontal,QObject::tr("yundanhao"));
    model5->setHeaderData(2,Qt::Horizontal,QObject::tr("dizhi"));
    model5->setHeaderData(3,Qt::Horizontal,QObject::tr("paizhao"));
    model5->setHeaderData(4,Qt::Horizontal,QObject::tr("luxiang"));

    view = new QTableView;
    view->setModel(model3);  // view->setColumnWidth(4,150);
    view->setFixedWidth(768);
    view->setFixedHeight(768);

    proxy = this->addWidget(view);
    proxy->setPos(256,0);

    chaxun = new Button("chaxunxiangqing.PNG");
    addItem(chaxun);
    chaxun->setPos(28,28);
    chaxun->show();
    connect(chaxun,SIGNAL(clicked(QString)),this,SLOT(changeTable(QString)));

    courier = new Button("kuaidiyuanxiangqing.PNG");
    addItem(courier);
    courier->setPos(28,100);
    courier->show();
    connect(courier,SIGNAL(clicked(QString)),this,SLOT(changeTable(QString)));

    QuJian = new Button("qujianxiangqing.PNG");
    addItem(QuJian);
    QuJian->setPos(28,262);
    QuJian->show();
    connect(QuJian,SIGNAL(clicked(QString)),this,SLOT(changeTable(QString)));

    TouJian = new Button("toujianxiangqing.PNG");
    addItem(TouJian);
    TouJian->setPos(28,414);
    TouJian->show();
    connect(TouJian,SIGNAL(clicked(QString)),this,SLOT(changeTable(QString)));

    JiJian = new Button("jijianxiangqing.PNG");
    addItem(JiJian);
    JiJian->setPos(28,566);
    JiJian->show();
    connect(JiJian,SIGNAL(clicked(QString)),this,SLOT(changeTable(QString)));

    go_home = new Return("yejiao4.png");
    addItem(go_home);
    go_home->setPos(924,668);
    connect(go_home,SIGNAL(click()),this,SIGNAL(back_home()));

    tiaoma_edit = new QLineEdit("");
    num1 = new QPushButton("1");
    num2 = new QPushButton("2");
    num3 = new QPushButton("3");
    num4 = new QPushButton("4");
    num5 = new QPushButton("5");
    num6 = new QPushButton("6");
    num7 = new QPushButton("7");
    num8 = new QPushButton("8");
    num9 = new QPushButton("9");
    ok = new QPushButton("ok");
    num0 = new QPushButton("0");
    del = new QPushButton("del");

    layout1 = new QGridLayout;
    layout1->addWidget(num1,0,0);
    layout1->addWidget(num2,0,1);
    layout1->addWidget(num3,0,2);
    layout1->addWidget(num4,1,0);
    layout1->addWidget(num5,1,1);
    layout1->addWidget(num6,1,2);
    layout1->addWidget(num7,2,0);
    layout1->addWidget(num8,2,1);
    layout1->addWidget(num9,2,2);
    layout1->addWidget(ok,3,0);
    layout1->addWidget(num0,3,1);
    layout1->addWidget(del,3,2);

    connect(num1,SIGNAL(clicked()),this,SLOT(showNum1()));
    connect(num2,SIGNAL(clicked()),this,SLOT(showNum2()));
    connect(num3,SIGNAL(clicked()),this,SLOT(showNum3()));
    connect(num4,SIGNAL(clicked()),this,SLOT(showNum4()));
    connect(num5,SIGNAL(clicked()),this,SLOT(showNum5()));
    connect(num6,SIGNAL(clicked()),this,SLOT(showNum6()));
    connect(num7,SIGNAL(clicked()),this,SLOT(showNum7()));
    connect(num8,SIGNAL(clicked()),this,SLOT(showNum8()));
    connect(num9,SIGNAL(clicked()),this,SLOT(showNum9()));
    connect(ok,SIGNAL(clicked()),this,SLOT(showOK()));
    connect(num0,SIGNAL(clicked()),this,SLOT(showNum0()));
    connect(del,SIGNAL(clicked()),this,SLOT(showDEL()));

    layout2 = new QVBoxLayout;
    layout2->addWidget(tiaoma_edit);
    layout2->addLayout(layout1);
    widget = new QWidget;
    widget->setLayout(layout2);
    proxy2 = this->addWidget(widget);
    proxy2->setPos(400,200);
    proxy2->hide();

}

void PageTen::changeTable(QString name)
{
    if(name.startsWith("kuaidiyuan"))
    {
        model->setQuery("select * from courier");
        view->setModel(model);
        view->update();
    }
    else if(name.startsWith("qujian"))
    {
        model2->setQuery("select * from QuJian");
        view->setModel(model2);
        view->update();
    }
    else if(name.startsWith("toujian"))
    {
        model3->setQuery("select * from TouJian");
        view->setModel(model3);
        view->update();
    }
    else if(name.startsWith("jijian"))
    {
        view->setModel(model4);
        view->update();
    }
    else if(name.startsWith("chaxun"))
    {
        proxy2->show();
    }
}

void PageTen::showNum1()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("1");
    tiaoma_edit->setText(num);
}

void PageTen::showNum2()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("2");
    tiaoma_edit->setText(num);
}

void PageTen::showNum3()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("3");
    tiaoma_edit->setText(num);
}

void PageTen::showNum4()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("4");
    tiaoma_edit->setText(num);
}

void PageTen::showNum5()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("5");
    tiaoma_edit->setText(num);
}

void PageTen::showNum6()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("6");
    tiaoma_edit->setText(num);
}

void PageTen::showNum7()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("7");
    tiaoma_edit->setText(num);
}

void PageTen::showNum8()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("8");
    tiaoma_edit->setText(num);
}

void PageTen::showNum9()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("9");
    tiaoma_edit->setText(num);
}

void PageTen::showOK()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString tiaoma = tiaoma_edit->text();
    if(tiaoma!=QString(""))
    {
        QSqlQuery query(Config.dbconn);
        query.prepare("select * from TouJian where barcode = :tiaoma");
        query.bindValue(":tiaoma", tiaoma);
        query.exec();
        model5->setQuery(query);
        view->setModel(model5);
    }
    tiaoma_edit->clear();
    proxy2->hide();
}

void PageTen::showNum0()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.append("0");
    tiaoma_edit->setText(num);
}

void PageTen::showDEL()
{
    //c10->play();
    //QSound::play("anjian.wav");
    QString num = tiaoma_edit->text();
    num.remove(num.length()-1,1);
    tiaoma_edit->setText(QString(num));
}
