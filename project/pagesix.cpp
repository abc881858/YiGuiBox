#include "pagesix.h"
#include "client.h"

PageSix::PageSix() : left(0), right(10), code("0")
{
    setBackgroundBrush(QBrush(QPixmap("back.png")));

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

    cha1 = new Button("cha1.png");
    addItem(cha1);
    cha1->setPos(77,106);

//    cha2 = new Button("cha2.png");
//    addItem(cha2);
//    cha2->setPos(827,126);
//    connect(cha2,SIGNAL(clicked(QString)),this,SLOT(query(QString)));

//    cha3 = new Button("cha3.png");
//    addItem(cha3);
//    cha3->setPos(59,213);

    cha4 = new Button("cha4.png");
    addItem(cha4);
    cha4->setPos(726,625);
    connect(cha4,SIGNAL(clicked(QString)),this,SLOT(previous(QString)));

    cha5 = new Button("cha5.png");
    addItem(cha5);
    cha5->setPos(855,626);
    connect(cha5,SIGNAL(clicked(QString)),this,SLOT(next(QString)));

    cha6 = new Button("cha6.png");
    addItem(cha6);
    cha6->setPos(636,66);
    connect(cha6,SIGNAL(clicked(QString)),this,SLOT(send(QString)));

//    cha2->hide();//FIXME !!!


    model = new SqlQueryModel;
    //model->setQuery(QString("select cpname,sendMan,eptel,sendDate,orderNum,tel,boxId from Express,Addressee,Employee,Company where Company.cpid=Employee.company_id and Employee.epid=Express.epid and Addressee.adid=Express.addressee_id limit %1,%2").arg(left).arg(right),Config.data_base);
    model->setHeaderData(0,Qt::Horizontal,tr("toudigongsi"));
    model->setHeaderData(1,Qt::Horizontal,tr("toudiyuan"));
    model->setHeaderData(2,Qt::Horizontal,tr("toudiyuandianhua"));
    model->setHeaderData(3,Qt::Horizontal,tr("toujianshijian"));
    model->setHeaderData(4,Qt::Horizontal,tr("yundanhao"));
    model->setHeaderData(5,Qt::Horizontal,tr("shoujianrenshoujihao"));
    model->setHeaderData(6,Qt::Horizontal,tr("xianghao"));

    view = new QTableView;

    view->setModel(model);
    view->setFixedWidth(923);
    view->setFixedHeight(368);

    view->setFrameShape(QFrame::NoFrame);
    view->setShowGrid(false);
    view->verticalHeader()->hide();
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(view,SIGNAL(pressed(QModelIndex)),this,SLOT(press(QModelIndex)));

//    QHeaderView *qhv = (QHeaderView *)view->verticalHeader();
//    qhv->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView *qhh = (QHeaderView *)view->horizontalHeader();
    qhh->setResizeMode(QHeaderView::Stretch);

    proxy = this->addWidget(view);
    proxy->setPos(59,213);

    haoma_edit = new QLineEdit;
    haoma_edit->setStyleSheet("color: green;background-image:url(rightedit.png);background-color:rgba(255,255,255,0%);");
    haoma_edit->setFixedSize(224,82);
    haoma_edit->setFont(QFont("Times", 29, QFont::Bold));
    haoma_edit->setFrame(false);
    proxy1 = this->addWidget(haoma_edit);
    proxy1->setPos(400,100);

    haoma_edit->installEventFilter(this);
    haoma_edit->text() = QString("");

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

    layout = new QGridLayout;
    layout->addWidget(num1,0,0);
    layout->addWidget(num2,0,1);
    layout->addWidget(num3,0,2);
    layout->addWidget(num4,1,0);
    layout->addWidget(num5,1,1);
    layout->addWidget(num6,1,2);
    layout->addWidget(num7,2,0);
    layout->addWidget(num8,2,1);
    layout->addWidget(num9,2,2);
    layout->addWidget(ok,3,0);
    layout->addWidget(num0,3,1);
    layout->addWidget(del,3,2);

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

    widget = new QWidget;
    widget->setLayout(layout);
    proxy2 = this->addWidget(widget);
    proxy2->setPos(400,200);
    proxy2->hide();

}

bool PageSix::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == haoma_edit)
    {
        if(event->type()==QEvent::FocusIn)
        {
            proxy2->show();
        }
    }
    return QGraphicsScene::eventFilter(obj,event);
}

void PageSix::showNum1()
{
    haoma_edit->setText(haoma_edit->text().append("1"));
    haoma_edit->update();
}

void PageSix::showNum2()
{
    haoma_edit->setText(haoma_edit->text().append("2"));
    haoma_edit->update();
}

void PageSix::showNum3()
{
    haoma_edit->setText(haoma_edit->text().append("3"));
    haoma_edit->update();
}

void PageSix::showNum4()
{
    haoma_edit->setText(haoma_edit->text().append("4"));
    haoma_edit->update();
}

void PageSix::showNum5()
{
    haoma_edit->setText(haoma_edit->text().append("5"));
    haoma_edit->update();
}

void PageSix::showNum6()
{
    haoma_edit->setText(haoma_edit->text().append("6"));
    haoma_edit->update();
}

void PageSix::showNum7()
{
    haoma_edit->setText(haoma_edit->text().append("7"));
    haoma_edit->update();
}

void PageSix::showNum8()
{
    haoma_edit->setText(haoma_edit->text().append("8"));
    haoma_edit->update();
}

void PageSix::showNum9()
{
    haoma_edit->setText(haoma_edit->text().append("9"));
    haoma_edit->update();
}

void PageSix::showNum0()
{
    haoma_edit->setText(haoma_edit->text().append("0"));
    haoma_edit->update();
}

void PageSix::showOK()
{
    proxy2->hide();

    query();
    view->update();
    haoma_edit->clear();
}

void PageSix::showDEL()
{
    if(haoma_edit->text().size()>0)
    {
        QString str = haoma_edit->text();
        str.chop(1);
        haoma_edit->setText(str);
        haoma_edit->update();
    }
}

void PageSix::previous(QString)
{
    if(left>0)
    {
        left = left - 10;
    }
    model->setQuery(QString("select cpname,sendMan,eptel,sendDate,orderNum,tel,boxId from Express,Addressee,Employee,Company where Company.cpid=Employee.company_id and Employee.epid=Express.epid and Addressee.adid=Express.addressee_id limit %1,%2").arg(left).arg(right),Config.data_base);
}

void PageSix::next(QString)
{
    left = left + 10;
    model->setQuery(QString("select cpname,sendMan,eptel,sendDate,orderNum,tel,boxId from Express,Addressee,Employee,Company where Company.cpid=Employee.company_id and Employee.epid=Express.epid and Addressee.adid=Express.addressee_id limit %1,%2").arg(left).arg(right),Config.data_base);
}

void PageSix::query()
{
    QString str = haoma_edit->text();
    model->setQuery(QString("select cpname,sendMan,eptel,sendDate,orderNum,tel,boxId from Express,Addressee,Employee,Company where Company.cpid=Employee.company_id and Employee.epid=Express.epid and Addressee.adid=Express.addressee_id and orderNum='%1' or Company.cpid=Employee.company_id and Employee.epid=Express.epid and Addressee.adid=Express.addressee_id and tel='%1' limit %2,%3").arg(str).arg(left).arg(right),Config.data_base);
}

void PageSix::send(QString)
{
    //QString id = haoma_edit->text();

    QSqlQuery query(Config.dbconn);
    query.exec("select * from xiangzi");
    while (query.next())
    {
        QString database_password = query.value(2).toString();
        QString barcode = query.value(0).toString();
        QString telephone = query.value(3).toString();

        if(code==barcode)
        {
            ClientInstance->send(QString("tel#%1#%2#%3").arg(telephone).arg("ydxq").arg(database_password));
        }
    }
}

void PageSix::press(QModelIndex index)
{
    code = (model->record(index.row()).value(4)).toString();
}

void PageSix::end_djs()
{
    djs_int = 99;
    timer->stop();
}

void PageSix::updateSQL()
{
    model->setQuery(QString("select cpname,sendMan,eptel,sendDate,orderNum,tel,boxId from Express,Addressee,Employee,Company where Company.cpid=Employee.company_id and Employee.epid=Express.epid and Addressee.adid=Express.addressee_id limit %1,%2").arg(left).arg(right),Config.data_base);
    view->update();
    haoma_edit->clear();
}

void PageSix::update_djs()
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
