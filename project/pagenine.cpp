#include "pagenine.h"
#include "client.h"

PageNine::PageNine()
{
    qsrand( QDateTime::currentDateTime().toTime_t() );
    setBackgroundBrush(QBrush(QPixmap("PageNineBack.png")));
    //c9 = Phonon::createPlayer(Phonon//cCategory,Phonon::MediaSource("Touch.wav"));

    xiangzi_id = 0;
    tiaoma_id = QString("");

    go_home = new Return("yejiao4.png");
    addItem(go_home);
    go_home->setPos(888,690);
    connect(go_home,SIGNAL(click()),this,SLOT(backHome()));

    dajian = new Button("upDa.png");
    addItem(dajian);
    dajian->setPos(126,81);
    connect(dajian,SIGNAL(clicked(QString)),this,SLOT(dakaixiangzi(QString)));

    zhongjian = new Button("upZhong.png");
    addItem(zhongjian);
    zhongjian->setPos(377,118);
    connect(zhongjian,SIGNAL(clicked(QString)),this,SLOT(dakaixiangzi(QString)));

    xiaojian = new Button("upXiao.png");
    addItem(xiaojian);
    xiaojian->setPos(576,135);
    connect(xiaojian,SIGNAL(clicked(QString)),this,SLOT(dakaixiangzi(QString)));

    texiaojian = new Button("upTeXiao.png");
    addItem(texiaojian);
    texiaojian->setPos(768,135);
    connect(texiaojian,SIGNAL(clicked(QString)),this,SLOT(dakaixiangzi(QString)));

    //Todo: xiao guo tu
    xiangzi0 = new QGraphicsPixmapItem(QString("left0.png"));
    addItem(xiangzi0);
    xiangzi0->setPos(47,247);

    xiangzi1 = new QGraphicsPixmapItem(QString("left1.png"));
    addItem(xiangzi1);
    xiangzi1->setPos(47,270);

    xiangzi2 = new QGraphicsPixmapItem(QString("left2.png"));
    addItem(xiangzi2);
    xiangzi2->setPos(47,247);

    xiangzi3 = new QGraphicsPixmapItem(QString("left3.png"));
    addItem(xiangzi3);
    xiangzi3->setPos(47,247);

    xiangzi4 = new QGraphicsPixmapItem(QString("left4.png"));
    addItem(xiangzi4);
    xiangzi4->setPos(47,247);

    xiangzi5 = new QGraphicsPixmapItem(QString("left5.png"));
    addItem(xiangzi5);
    xiangzi5->setPos(47,247);

    xiangzi6 = new QGraphicsPixmapItem(QString("left6.png"));
    addItem(xiangzi6);
    xiangzi6->setPos(47,247);

    xiangzi7 = new QGraphicsPixmapItem(QString("left7.png"));
    addItem(xiangzi7);
    xiangzi7->setPos(47,247);

    xiangzi8 = new QGraphicsPixmapItem(QString("left8.png"));
    addItem(xiangzi8);
    xiangzi8->setPos(47,247);

    xiangzi9 = new QGraphicsPixmapItem(QString("left9.png"));
    addItem(xiangzi9);
    xiangzi9->setPos(47,247);

    xiangzi10 = new QGraphicsPixmapItem(QString("left10.png"));
    addItem(xiangzi10);
    xiangzi10->setPos(47,247);

    xiangzi11 = new QGraphicsPixmapItem(QString("left11.png"));
    addItem(xiangzi11);
    xiangzi11->setPos(47,247);

    xiangzi12 = new QGraphicsPixmapItem(QString("left12.png"));
    addItem(xiangzi12);
    xiangzi12->setPos(47,247);

    xiangzi13 = new QGraphicsPixmapItem(QString("left13.png"));
    addItem(xiangzi13);
    xiangzi13->setPos(47,247);

    xiangzi14 = new QGraphicsPixmapItem(QString("left14.png"));
    addItem(xiangzi14);
    xiangzi14->setPos(47,247);

    xiangzi15 = new QGraphicsPixmapItem(QString("left15.png"));
    addItem(xiangzi15);
    xiangzi15->setPos(47,247);

    xiangzi16 = new QGraphicsPixmapItem(QString("left16.png"));
    addItem(xiangzi16);
    xiangzi16->setPos(47,247);

    xiangzi17 = new QGraphicsPixmapItem(QString("left17.png"));
    addItem(xiangzi17);
    xiangzi17->setPos(47,247);

    xiangzi18 = new QGraphicsPixmapItem(QString("left18.png"));
    addItem(xiangzi18);
    xiangzi18->setPos(47,247);

    xiangzi19 = new QGraphicsPixmapItem(QString("left19.png"));
    addItem(xiangzi19);
    xiangzi19->setPos(47,247);

    xiangzi20 = new QGraphicsPixmapItem(QString("left20.png"));
    addItem(xiangzi20);
    xiangzi20->setPos(47,247);

    xiangzi21 = new QGraphicsPixmapItem(QString("left21.png"));
    addItem(xiangzi21);
    xiangzi21->setPos(47,247);

    xiangzi22 = new QGraphicsPixmapItem(QString("left22.png"));
    addItem(xiangzi22);
    xiangzi22->setPos(47,247);

    xiangzi23 = new QGraphicsPixmapItem(QString("left23.png"));
    addItem(xiangzi23);
    xiangzi23->setPos(47,247);

    xiangzi24 = new QGraphicsPixmapItem(QString("left24.png"));
    addItem(xiangzi24);
    xiangzi24->setPos(47,247);

    xiangzi25 = new QGraphicsPixmapItem(QString("left25.png"));
    addItem(xiangzi25);
    xiangzi25->setPos(47,247);

    xiangzi26 = new QGraphicsPixmapItem(QString("left26.png"));
    addItem(xiangzi26);
    xiangzi26->setPos(47,247);

    xiangzi27 = new QGraphicsPixmapItem(QString("left27.png"));
    addItem(xiangzi27);
    xiangzi27->setPos(47,247);

    xiangzi28 = new QGraphicsPixmapItem(QString("left28.png"));
    addItem(xiangzi28);
    xiangzi28->setPos(47,247);

    xiangzi29 = new QGraphicsPixmapItem(QString("left29.png"));
    addItem(xiangzi29);
    xiangzi29->setPos(47,247);

    xiangzi30 = new QGraphicsPixmapItem(QString("left30.png"));
    addItem(xiangzi30);
    xiangzi30->setPos(47,247);

    xiangzi31 = new QGraphicsPixmapItem(QString("left31.png"));
    addItem(xiangzi31);
    xiangzi31->setPos(47,247);

    xiangzi32 = new QGraphicsPixmapItem(QString("left32.png"));
    addItem(xiangzi32);
    xiangzi32->setPos(47,247);

    xiangzi33 = new QGraphicsPixmapItem(QString("left33.png"));
    addItem(xiangzi33);
    xiangzi33->setPos(47,247);

    xiangzi34 = new QGraphicsPixmapItem(QString("left34.png"));
    addItem(xiangzi34);
    xiangzi34->setPos(47,247);

    xiangzi35 = new QGraphicsPixmapItem(QString("left35.png"));
    addItem(xiangzi35);
    xiangzi35->setPos(47,247);

    xiangzi36 = new QGraphicsPixmapItem(QString("left36.png"));
    addItem(xiangzi36);
    xiangzi36->setPos(47,247);

    xiangzi37 = new QGraphicsPixmapItem(QString("left37.png"));
    addItem(xiangzi37);
    xiangzi37->setPos(47,247);

    xiangzi38 = new QGraphicsPixmapItem(QString("left38.png"));
    addItem(xiangzi38);
    xiangzi38->setPos(47,247);

    xiangzi39 = new QGraphicsPixmapItem(QString("left39.png"));
    addItem(xiangzi39);
    xiangzi39->setPos(47,247);

    xiangzi40 = new QGraphicsPixmapItem(QString("left40.png"));
    addItem(xiangzi40);
    xiangzi40->setPos(47,247);

    xiangzi41 = new QGraphicsPixmapItem(QString("left41.png"));
    addItem(xiangzi41);
    xiangzi41->setPos(47,247);

    xiangzi42 = new QGraphicsPixmapItem(QString("left42.png"));
    addItem(xiangzi42);
    xiangzi42->setPos(47,247);

    xiangzi43 = new QGraphicsPixmapItem(QString("left43.png"));
    addItem(xiangzi43);
    xiangzi43->setPos(47,247);

    xiangzi44 = new QGraphicsPixmapItem(QString("left44.png"));
    addItem(xiangzi44);
    xiangzi44->setPos(47,247);

    xiangzi45 = new QGraphicsPixmapItem(QString("left46.png"));
    addItem(xiangzi45);
    xiangzi45->setPos(47,247);

    xiangzi46 = new QGraphicsPixmapItem(QString("left47.png"));
    addItem(xiangzi46);
    xiangzi46->setPos(47,247);

    xiangzi47 = new QGraphicsPixmapItem(QString("left48.png"));
    addItem(xiangzi47);
    xiangzi47->setPos(47,247);

    xiangzi48 = new QGraphicsPixmapItem(QString("left49.png"));
    addItem(xiangzi48);
    xiangzi48->setPos(47,247);

    xiangzi49 = new QGraphicsPixmapItem(QString("left50.png"));
    addItem(xiangzi49);
    xiangzi49->setPos(47,247);

    xiangzi50 = new QGraphicsPixmapItem(QString("left50.png"));
    addItem(xiangzi50);
    xiangzi50->setPos(47,247);

    xiangzi51 = new QGraphicsPixmapItem(QString("left51.png"));
    addItem(xiangzi51);
    xiangzi51->setPos(47,247);

    xiangzi52 = new QGraphicsPixmapItem(QString("left52.png"));
    addItem(xiangzi52);
    xiangzi52->setPos(47,247);

    xiangzi53 = new QGraphicsPixmapItem(QString("left53.png"));
    addItem(xiangzi53);
    xiangzi53->setPos(47,247);

    xiangzi54 = new QGraphicsPixmapItem(QString("left54.png"));
    addItem(xiangzi54);
    xiangzi54->setPos(47,247);

    xiangzi55 = new QGraphicsPixmapItem(QString("left55.png"));
    addItem(xiangzi55);
    xiangzi55->setPos(47,247);

    xiangzi56 = new QGraphicsPixmapItem(QString("left56.png"));
    addItem(xiangzi56);
    xiangzi56->setPos(47,247);

    xiangzi57 = new QGraphicsPixmapItem(QString("left57.png"));
    addItem(xiangzi57);
    xiangzi57->setPos(47,247);

    xiangzi58 = new QGraphicsPixmapItem(QString("left58.png"));
    addItem(xiangzi58);
    xiangzi58->setPos(47,247);

    xiangzi59 = new QGraphicsPixmapItem(QString("left59.png"));
    addItem(xiangzi59);
    xiangzi59->setPos(47,247);

    xiangzi60 = new QGraphicsPixmapItem(QString("left60.png"));
    addItem(xiangzi60);
    xiangzi60->setPos(47,247);

    xiangzi61 = new QGraphicsPixmapItem(QString("left61.png"));
    addItem(xiangzi61);
    xiangzi61->setPos(47,247);

    xiangzi62 = new QGraphicsPixmapItem(QString("left62.png"));
    addItem(xiangzi62);
    xiangzi62->setPos(47,247);

    xiangzi63 = new QGraphicsPixmapItem(QString("left63.png"));
    addItem(xiangzi63);
    xiangzi63->setPos(47,247);

    xiangzi64 = new QGraphicsPixmapItem(QString("left64.png"));
    addItem(xiangzi64);
    xiangzi64->setPos(47,247);

    xiangzi65 = new QGraphicsPixmapItem(QString("left65.png"));
    addItem(xiangzi65);
    xiangzi65->setPos(47,247);

    xiangzi1->hide();
    xiangzi2->hide();
    xiangzi3->hide();
    xiangzi4->hide();
    xiangzi5->hide();
    xiangzi6->hide();
    xiangzi7->hide();
    xiangzi8->hide();
    xiangzi9->hide();
    xiangzi10->hide();
    xiangzi11->hide();
    xiangzi12->hide();
    xiangzi13->hide();
    xiangzi14->hide();
    xiangzi15->hide();
    xiangzi16->hide();
    xiangzi17->hide();
    xiangzi18->hide();
    xiangzi19->hide();
    xiangzi20->hide();
    xiangzi21->hide();
    xiangzi22->hide();
    xiangzi23->hide();
    xiangzi24->hide();
    xiangzi25->hide();
    xiangzi26->hide();
    xiangzi27->hide();
    xiangzi28->hide();
    xiangzi29->hide();
    xiangzi30->hide();
    xiangzi31->hide();
    xiangzi32->hide();
    xiangzi33->hide();
    xiangzi34->hide();
    xiangzi35->hide();
    xiangzi36->hide();
    xiangzi37->hide();
    xiangzi38->hide();
    xiangzi39->hide();
    xiangzi40->hide();
    xiangzi41->hide();
    xiangzi42->hide();
    xiangzi43->hide();
    xiangzi44->hide();
    xiangzi45->hide();
    xiangzi46->hide();
    xiangzi47->hide();
    xiangzi48->hide();
    xiangzi49->hide();
    xiangzi50->hide();
    xiangzi51->hide();
    xiangzi52->hide();
    xiangzi53->hide();
    xiangzi54->hide();
    xiangzi55->hide();
    xiangzi56->hide();
    xiangzi57->hide();
    xiangzi58->hide();
    xiangzi59->hide();
    xiangzi60->hide();
    xiangzi61->hide();
    xiangzi62->hide();
    xiangzi63->hide();
    xiangzi64->hide();
    xiangzi65->hide();

    ser = new doorCtr;
    connect(ser,SIGNAL(doorStatus(int,QString)),this,SLOT(jiance(int,QString)));

    // pop please scanf
    scanMode *scan =  new scanMode;
    connect(scan,SIGNAL(sendData(QString)),this,SLOT(open_door(QString)));
//     ci chu QString == tiao_ma_id

    da_jian_15 = true;
    da_jian_25 = true;
    da_jian_55 = true;
    da_jian_35 = true;
    da_jian_45 = true;
    zhong_jian_32 = true;
    zhong_jian_33 = true;
    zhong_jian_34 = true;
    zhong_jian_22 = true;
    zhong_jian_23 = true;
    zhong_jian_24 = true;
    zhong_jian_42 = true;
    zhong_jian_43 = true;
    zhong_jian_44 = true;
    zhong_jian_52 = true;
    zhong_jian_53 = true;
    zhong_jian_54 = true;
    xiaojian_26 = true;
    xiaojian_27 = true;
    xiaojian_28 = true;
    xiaojian_29 = true;
    xiaojian_30 = true;
    xiaojian_31 = true;
    xiaojian_16 = true;
    xiaojian_17 = true;
    xiaojian_18 = true;
    xiaojian_19 = true;
    xiaojian_20 = true;
    xiaojian_21 = true;
    xiaojian_36 = true;
    xiaojian_37 = true;
    xiaojian_38 = true;
    xiaojian_39 = true;
    xiaojian_40 = true;
    xiaojian_41 = true;
    xiaojian_46 = true;
    xiaojian_47 = true;
    xiaojian_48 = true;
    xiaojian_49 = true;
    xiaojian_50 = true;
    xiaojian_51 = true;
    texiaojian_01 = true;
    texiaojian_02 = true;
    texiaojian_03 = true;
    texiaojian_04 = true;
    texiaojian_05 = true;
    texiaojian_06 = true;
    texiaojian_07 = true;
    texiaojian_08 = true;
    texiaojian_09 = true;
    texiaojian_10 = true;
    texiaojian_11 = true;
    texiaojian_12 = true;
    texiaojian_13 = true;
    texiaojian_14 = true;

    item_back = new QGraphicsPixmapItem(QString("rightback.png"));
    addItem(item_back);
    item_back->setPos(630,217);

    item_shang = new QGraphicsPixmapItem(QString("rightshang.png"));
    addItem(item_shang);
    item_shang->setPos(670,258);

    item_xia = new QGraphicsPixmapItem(QString("rightxia.png"));
    addItem(item_xia);
    item_xia->setPos(670,456);

    yundan1 = new QGraphicsPixmapItem(QString("yundan1.png"));
    addItem(yundan1);
    yundan1->setPos(682,270);

    yundan2_edit = new QLineEdit;
    yundan2_edit->setStyleSheet("color: white;background-image:url(yundan2.png);background-color:rgba(255,255,255,0%);");
    yundan2_edit->setFixedSize(169,49);
    yundan2_edit->setFont(QFont("Times", 16, QFont::Bold));
    yundan2_edit->setFrame(false);
    yundan2_edit->setAlignment(Qt::AlignHCenter);
    proxy2 = this->addWidget(yundan2_edit);
    proxy2->setPos(746,258);

    item_zhong = new QGraphicsPixmapItem(QString("rightzhong.png"));
    addItem(item_zhong);
    item_zhong->setPos(670,307);
    item_zhong->show();

    haoma_edit = new QLineEdit;
    haoma_edit->setStyleSheet("color: white;background-image:url(rightedit.png);background-color:rgba(255,255,255,0%);");
    haoma_edit->setFixedSize(224,82);
    haoma_edit->setFont(QFont("Times", 29, QFont::Bold));
    haoma_edit->setFrame(false);
    proxy1 = this->addWidget(haoma_edit);
    proxy1->setPos(681,336);

    label = new QLabel;
    label->setFixedSize(247,149);
    label->setStyleSheet("background-color: transparent;");
    proxy3 = this->addWidget(label);
    proxy3->setPos(670,307);

    movie = new QMovie("send.gif");
    label->setMovie(movie);
    movie->stop();

    num1 = new Button("rightnum1.png");
    num2 = new Button("rightnum2.png");
    num3 = new Button("rightnum3.png");
    num4 = new Button("rightnum4.png");
    num5 = new Button("rightnum5.png");
    num6 = new Button("rightnum6.png");
    num7 = new Button("rightnum7.png");
    num8 = new Button("rightnum8.png");
    num9 = new Button("rightnum9.png");
    item_ok = new Button("rightok.png");
    num0 = new Button("rightnum0.png");
    item_del = new Button("rightdel.png");

    addItem(num1);
    addItem(num2);
    addItem(num3);
    addItem(num4);
    addItem(num5);
    addItem(num6);
    addItem(num7);
    addItem(num8);
    addItem(num9);
    addItem(item_ok);
    addItem(num0);
    addItem(item_del);

    num1->setPos(673,465);
    num2->setPos(753,465);
    num3->setPos(835,465);
    num4->setPos(673,518);
    num5->setPos(752,518);
    num6->setPos(835,518);
    num7->setPos(673,570);
    num8->setPos(752,570);
    num9->setPos(835,570);
    item_ok->setPos(673,621);
    num0->setPos(752,624);
    item_del->setPos(835,624);

    connect(num1,SIGNAL(clicked(QString)),this,SLOT(showNum1(QString)));
    connect(num2,SIGNAL(clicked(QString)),this,SLOT(showNum2(QString)));
    connect(num3,SIGNAL(clicked(QString)),this,SLOT(showNum3(QString)));
    connect(num4,SIGNAL(clicked(QString)),this,SLOT(showNum4(QString)));
    connect(num5,SIGNAL(clicked(QString)),this,SLOT(showNum5(QString)));
    connect(num6,SIGNAL(clicked(QString)),this,SLOT(showNum6(QString)));
    connect(num7,SIGNAL(clicked(QString)),this,SLOT(showNum7(QString)));
    connect(num8,SIGNAL(clicked(QString)),this,SLOT(showNum8(QString)));
    connect(num9,SIGNAL(clicked(QString)),this,SLOT(showNum9(QString)));
    connect(item_ok,SIGNAL(clicked(QString)),this,SLOT(showOK(QString)));
    connect(num0,SIGNAL(clicked(QString)),this,SLOT(showNum0(QString)));
    connect(item_del,SIGNAL(clicked(QString)),this,SLOT(showDEL(QString)));

    pop_item = new PopItem("qingxuanze.png");
    addItem(pop_item);
    pop_item->setPos(316,217);

    pop_item2 = new PopItem("qingsaomiao.png");
    addItem(pop_item2);
    pop_item2->setPos(312,349);
    pop_item2->hide();

    pop_item3 = new PopItem("qingbabao.png");
    addItem(pop_item3);
    pop_item3->setPos(312,349);
    pop_item3->hide();

    pop_item4 = new PopItem("qingshuru.png");
    addItem(pop_item4);
    pop_item4->setPos(112,349);
    pop_item4->hide();

    pop_dajian = new PopItem("dajianyi.png");
    addItem(pop_dajian);
    pop_dajian->setPos(312,349);
    pop_dajian->hide();

    pop_zhongjian = new PopItem("zhongjianyi.png");
    addItem(pop_zhongjian);
    pop_zhongjian->setPos(312,349);
    pop_zhongjian->hide();

    pop_xiaojian = new PopItem("xiaojianyi.png");
    addItem(pop_xiaojian);
    pop_xiaojian->setPos(312,349);
    pop_xiaojian->hide();

    pop_texiaojian = new PopItem("texiaoyi.png");
    addItem(pop_texiaojian);
    pop_texiaojian->setPos(312,349);
    pop_texiaojian->hide();

    pop_item5 = new PopItem("duanxinyi.png");
    addItem(pop_item5);
    pop_item5->setPos(312,349);
    pop_item5->hide();

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
}

void PageNine::showNum1(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("1");
    haoma_edit->setText(num);
}

void PageNine::showNum2(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("2");
    haoma_edit->setText(num);
}

void PageNine::showNum3(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("3");
    haoma_edit->setText(num);
}

void PageNine::showNum4(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("4");
    haoma_edit->setText(num);
}

void PageNine::showNum5(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("5");
    haoma_edit->setText(num);
    movie->stop();
    label->hide();
    proxy3->hide();
}

void PageNine::showNum6(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("6");
    haoma_edit->setText(num);
}

void PageNine::showNum7(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("7");
    haoma_edit->setText(num);
}

void PageNine::showNum8(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("8");
    haoma_edit->setText(num);
}

void PageNine::showNum9(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("9");
    haoma_edit->setText(num);
}

void PageNine::showOK(QString)
{
    //c9->play();
//    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    else
    {
//        djs_int = 30;
//        init_djs();
        timer->start();

        pop_item4->hide();
    }

    QString num = haoma_edit->text();
    if(num.size()!=11)
    {
        pop_item4->show();
        return;
    }
    QString pswdStr("QWERTYUIOPASDFGHJKLZXCVBNM0123456789");

    // chs 用于存放密码的字符 .
    QChar *chs = new QChar[8];
    for( int i=0 ; i <8 ; i++ )
    {
        int strIdx = qrand()%36;

        chs[ i ] = pswdStr.at( strIdx );
    }
    for( int i=0 ; i <1000 ; i++ )
    {
        int idx1 = ( int )( qrand() % 8 );
        int idx2 = ( int )( qrand() % 8 );

        if( idx1 == idx2 )
        {
            continue ;
        }

        QChar tempChar = chs[ idx1 ] ;
        chs[ idx1 ] = chs[ idx2 ] ;
        chs[ idx2 ] = tempChar ;
    }

    QString pswd;
    for (int var = 0; var < 8; ++var)
    {
        pswd.append(chs[var]);
    }
    QString phone_num = num;

    // fa song duan xin ,
    // cha ru shu ju ku .
    // mi ma yao yu xiang zi 'id' bang ding

    tiaoma_id = tiaoma_id.trimmed();
    int addressee_id;

    QSqlQuery query2(Config.data_base);

//    query2.exec(QString("select xpid from Addressee where tel='%1'").arg(phone_num));
//    while (query2.next())
//    {
//        addressee_id = query2.value(0).toInt();
//    }

    query2.prepare(QString("insert into Addressee(password,tel) values(:password,:tel)"));
    query2.bindValue(":password",pswd);
    query2.bindValue(":tel",phone_num);
    query2.exec();

    query2.exec(QString("select * from Addressee where password='%1'").arg(pswd));
    while (query2.next())
    {
        addressee_id = query2.value(0).toInt();
    }

    query2.prepare("insert into Express(orderNum,state,isCome,sendMan,sendDate,fetDate,backTime,epid,boxId,boxLocation,addressee_id) values(:orderNum,:state,:isCome,:sendMan,:sendDate,:fetDate,:backTime,:epid,:boxId,:boxLocation,:addressee_id)");
    query2.bindValue(":orderNum",tiaoma_id);
    query2.bindValue(":state",1);
    query2.bindValue(":isCome",1);
    query2.bindValue(":sendMan","unkonwn_user");
    query2.bindValue(":sendDate",QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss"));
    query2.bindValue(":fetDate","none");
    query2.bindValue(":backTime","none");
    query2.bindValue(":epid",Config.man);
    query2.bindValue(":boxId",111);
    query2.bindValue(":boxLocation",xiangzi_id);
    query2.bindValue(":addressee_id",addressee_id);//shoujianren
    query2.exec();

    query2.prepare("insert into Addressee(password,name,tel,address,fetTime,photo,vedio) values(:password,:name,:tel,:address,:fetTime,:photo,,:vedio)");
    query2.bindValue(":password",pswd);
    query2.bindValue(":name","none");
    query2.bindValue(":tel",phone_num);
    query2.bindValue(":address","none");
    query2.bindValue(":fetTime","none");
    query2.bindValue(":photo","none");
    query2.bindValue(":vedio","none");
    query2.exec();



    //////////////////////////////////////

    QSqlQuery query(Config.dbconn);
    query.prepare("insert into xiangzi (tiaoma, id, password, phone) values (:tiaoma,:id,:password,:phone)");
    query.bindValue(":tiaoma",tiaoma_id);
    query.bindValue(":id", xiangzi_id);
    query.bindValue(":password",pswd);
    query.bindValue(":phone",phone_num);
    query.exec();

    QString ic="1234567890";
    QString toujianshijian = QDateTime::currentDateTime().toString();
    query.prepare("INSERT INTO TouJian (ic, barcode, address, photo, video, toutime) VALUES (:ic, :barcode, :address, :photo, :video, :toutime)");
    query.bindValue(":ic", ic);
    query.bindValue(":barcode", tiaoma_id);
    query.bindValue(":address", "yidaxiaoqu");
    query.bindValue(":photo", "...");
    query.bindValue(":video", "...");
    query.bindValue(":toutime", toujianshijian);
    query.exec();

    qDebug() << pswd;

    movie->start();
    label->show();
    QTimer::singleShot(4000, this, SLOT(hide_label()));

    ClientInstance->send(QString("tel#%1#%2#%3").arg(phone_num).arg("ydxq").arg(pswd));

    haoma_edit->setText("");
    pop_item5->show();

    tiaoma_id = QString("");
    xiangzi_id = 0;
    pswd = QString("");
    num = QString("");

    go_home->setEnabled(true);
}

void PageNine::showNum0(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    if(!(pop_item4->isVisible()))
    {
        return;
    }
    QString num = haoma_edit->text();
    num.append("0");
    haoma_edit->setText(num);
}

void PageNine::showDEL(QString)
{
    //c9->play();
    //QSound::play("anjian.wav");
    QString num = haoma_edit->text();
    num.remove(num.length()-1,1);

    haoma_edit->setText(QString(num));
}

void PageNine::dakaixiangzi(QString str)
{
    pop_item->hide();
    pop_item2->hide();
    pop_item5->hide();

    if(pop_item3->isVisible() || pop_item4->isVisible())
    {
        return;
    }
    else
    {
        djs_int = 30;
        init_djs();
    }

    if(str.startsWith("upDa"))
    {
        tu_an = QString("dajian");
        if(da_jian_15)
        {
           pop_item2->show();
        }
        else if(da_jian_25)
        {
            pop_item2->show();
        }
        else if(da_jian_35)
        {
            pop_item2->show();
        }
        else if(da_jian_45)
        {
            pop_item2->show();
        }
        else if(da_jian_55)
        {
            pop_item2->show();
        }
        else
        {
            pop_dajian->show();
            tu_an.clear();
            QTimer::singleShot( 1000, this, SLOT(hide_dajian()));
        }
    }
    if(str.startsWith("upZhong"))
    {
        tu_an = QString("zhongjian");
        if(zhong_jian_22)
        {
            pop_item2->show();
        }
        else if(zhong_jian_23)
        {
            pop_item2->show();
        }
        else if(zhong_jian_24)
        {
            pop_item2->show();
        }
        else if(zhong_jian_32)
        {
            pop_item2->show();
        }
        else if(zhong_jian_33)
        {
            pop_item2->show();
        }
        else if(zhong_jian_34)
        {
            pop_item2->show();
        }
        else if(zhong_jian_42)
        {
            pop_item2->show();
        }
        else if(zhong_jian_43)
        {
            pop_item2->show();
        }
        else if(zhong_jian_44)
        {
            pop_item2->show();
        }
        else if(zhong_jian_52)
        {
            pop_item2->show();
        }
        else if(zhong_jian_53)
        {
            pop_item2->show();
        }
        else if(zhong_jian_54)
        {
            pop_item2->show();
        }
        else
        {
           pop_zhongjian->show();
           tu_an.clear();
           QTimer::singleShot( 1000, this, SLOT(hide_zhongjian()));
        }
    }
    if(str.startsWith("upXiao"))
    {
        tu_an = QString("xiaojian");
        if(xiaojian_16)
        {
            pop_item2->show();
        }
        else if(xiaojian_17)
        {
            pop_item2->show();
        }
        else if(xiaojian_18)
        {
            pop_item2->show();
        }
        else if(xiaojian_19)
        {
            pop_item2->show();
        }
        else if(xiaojian_20)
        {
            pop_item2->show();
        }
        else if(xiaojian_21)
        {
            pop_item2->show();
        }
        else if(xiaojian_26)
        {
            pop_item2->show();
        }
        else if(xiaojian_27)
        {
            pop_item2->show();
        }
        else if(xiaojian_28)
        {
            pop_item2->show();
        }
        else if(xiaojian_29)
        {
            pop_item2->show();
        }
        else if(xiaojian_30)
        {
            pop_item2->show();
        }
        else if(xiaojian_31)
        {
            pop_item2->show();
        }
        else if(xiaojian_36)
        {
            pop_item2->show();
        }
        else if(xiaojian_37)
        {
            pop_item2->show();
        }
        else if(xiaojian_38)
        {
            pop_item2->show();
        }
        else if(xiaojian_39)
        {
            pop_item2->show();
        }
        else if(xiaojian_40)
        {
            pop_item2->show();
        }
        else if(xiaojian_41)
        {
            pop_item2->show();
        }
        else if(xiaojian_46)
        {
            pop_item2->show();
        }
        else if(xiaojian_47)
        {
            pop_item2->show();
        }
        else if(xiaojian_48)
        {
            pop_item2->show();
        }
        else if(xiaojian_49)
        {
            pop_item2->show();
        }
        else if(xiaojian_50)
        {
            pop_item2->show();
        }
        else if(xiaojian_51)
        {
            pop_item2->show();
        }
        else
        {
            pop_xiaojian->show();
            tu_an.clear();
            QTimer::singleShot( 1000, this, SLOT(hide_xiaojian()));
        }
    }
    if(str.startsWith("upTeXiao"))
    {
        tu_an = QString("texiaojian");
        if(texiaojian_01)
        {
            pop_item2->show();
        }
        else if(texiaojian_02)
        {
            pop_item2->show();
        }
        else if(texiaojian_03)
        {
            pop_item2->show();
        }
        else if(texiaojian_04)
        {
            pop_item2->show();
        }
        else if(texiaojian_05)
        {
            pop_item2->show();
        }
        else if(texiaojian_06)
        {
            pop_item2->show();
        }
        else if(texiaojian_07)
        {
            pop_item2->show();
        }
        else if(texiaojian_08)
        {
            pop_item2->show();
        }
        else if(texiaojian_09)
        {
            pop_item2->show();
        }
        else if(texiaojian_10)
        {
            pop_item2->show();
        }
        else if(texiaojian_11)
        {
            pop_item2->show();
        }
        else if(texiaojian_12)
        {
            pop_item2->show();
        }
        else if(texiaojian_13)
        {
            pop_item2->show();
        }
        else if(texiaojian_14)
        {
            pop_item2->show();
        }
        else
        {
            pop_texiaojian->show();
            tu_an.clear();
            QTimer::singleShot( 1000, this, SLOT(hide_texiaojian()));
        }
    }

}

void PageNine::open_door(QString str)
{
    if(tu_an == "")
    {
//        //shuo ming mei dian da jian
//        //huo zhe yi jing sao miao guo 1 ge
//        if(pop_item->isVisible())
//        {
//            //bu gei ta sao miao
//            return;
//        }
        return;
    }
    else
    {
        djs_int = 30;
        init_djs();
    }

    pop_item2->hide();
    pop_item3->show();

    //////////////////
    timer->stop();
    go_home->setEnabled(false);

    tiaoma_id = str;//FIXME: must be trimeed

    yundan2_edit->setText(str);



    if(tu_an == "dajian")
    {
        tu_an = QString("");
        if(da_jian_15)
        {
            ser->openDoor(15);
            xiangzi_id = 15;
            da_jian_15 = false;
            return;
        }
        else if(da_jian_25)
        {
            ser->openDoor(25);
            xiangzi_id = 25;
            da_jian_25 = false;
            return;
        }
        else if(da_jian_35)
        {
            ser->openDoor(35);
            xiangzi_id = 35;
            da_jian_35 = false;
            return;
        }
        else if(da_jian_45)
        {
            ser->openDoor(45);
            xiangzi_id = 45;
            da_jian_45 = false;
            return;
        }
        else if(da_jian_55)
        {
            ser->openDoor(55);
            xiangzi_id = 55;
            da_jian_55 = false;
            return;
        }
        else
        {
            pop_dajian->show();
            QTimer::singleShot( 1000, this, SLOT(hide_dajian()));
        }
    }
    else if(tu_an == "zhongjian")
    {

        tu_an = QString("");
        if(zhong_jian_22)
        {
            ser->openDoor(22);
            xiangzi_id = 22;
            zhong_jian_22 = false;
            return;
        }
        else if(zhong_jian_23)
        {
            ser->openDoor(23);
            xiangzi_id = 23;
            zhong_jian_23 = false;
            return;
        }
        else if(zhong_jian_24)
        {
            ser->openDoor(24);
            xiangzi_id = 24;
            zhong_jian_24 = false;
            return;
        }
        else if(zhong_jian_32)
        {
            ser->openDoor(32);
            xiangzi_id = 32;
            zhong_jian_32 = false;
            return;
        }
        else if(zhong_jian_33)
        {
            ser->openDoor(33);
            xiangzi_id = 33;
            zhong_jian_33 = false;
            return;
        }
        else if(zhong_jian_34)
        {
            ser->openDoor(34);
            xiangzi_id = 34;
            zhong_jian_34 = false;
            return;
        }
        else if(zhong_jian_42)
        {
            ser->openDoor(42);
            xiangzi_id = 42;
            zhong_jian_42 = false;
            return;
        }
        else if(zhong_jian_43)
        {
            ser->openDoor(43);
            xiangzi_id = 43;
            zhong_jian_43 = false;
            return;
        }
        else if(zhong_jian_44)
        {
            ser->openDoor(44);
            xiangzi_id = 44;
            zhong_jian_44 = false;
            return;
        }
        else if(zhong_jian_52)
        {
            ser->openDoor(52);
            xiangzi_id = 52;
            zhong_jian_52 = false;
            return;
        }
        else if(zhong_jian_53)
        {
            ser->openDoor(53);
            xiangzi_id = 53;
            zhong_jian_53 = false;
            return;
        }
        else if(zhong_jian_54)
        {
            ser->openDoor(54);
            xiangzi_id = 54;
            zhong_jian_54 = false;
            return;
        }
        else
        {
           pop_zhongjian->show();
           QTimer::singleShot( 1500, this, SLOT(hide_zhongjian()));
        }
    }
    else if(tu_an == "xiaojian")
    {
        tu_an = QString("");
        if(xiaojian_16)
        {
            ser->openDoor(16);
            xiangzi_id = 16;
            xiaojian_16 = false;
            return;
        }
        else if(xiaojian_17)
        {
            ser->openDoor(17);
            xiangzi_id = 17;
            xiaojian_17 = false;
            return;
        }
        else if(xiaojian_18)
        {
            ser->openDoor(18);
            xiangzi_id = 18;
            xiaojian_18 = false;
            return;
        }
        else if(xiaojian_19)
        {
            ser->openDoor(19);
            xiangzi_id = 19;
            xiaojian_19 = false;
            return;
        }
        else if(xiaojian_20)
        {
            ser->openDoor(20);
            xiangzi_id = 20;
            xiaojian_20 = false;
            return;
        }
        else if(xiaojian_21)
        {
            ser->openDoor(21);
            xiangzi_id = 21;
            xiaojian_21 = false;
            return;
        }
        else if(xiaojian_26)
        {
            ser->openDoor(26);
            xiangzi_id = 26;
            xiaojian_26 = false;
            return;
        }
        else if(xiaojian_27)
        {
            ser->openDoor(27);
            xiangzi_id = 27;
            xiaojian_27 = false;
            return;
        }
        else if(xiaojian_28)
        {
            ser->openDoor(28);
            xiangzi_id = 28;
            xiaojian_28 = false;
            return;
        }
        else if(xiaojian_29)
        {
            ser->openDoor(29);
            xiangzi_id = 29;
            xiaojian_29 = false;
            return;
        }
        else if(xiaojian_30)
        {
            ser->openDoor(30);
            xiangzi_id = 30;
            xiaojian_30 = false;
            return;
        }
        else if(xiaojian_31)
        {
            ser->openDoor(31);
            xiangzi_id = 31;
            xiaojian_31 = false;
            return;
        }
        else if(xiaojian_36)
        {
            ser->openDoor(36);
            xiangzi_id = 36;
            xiaojian_36 = false;
            return;
        }
        else if(xiaojian_37)
        {
            ser->openDoor(37);
            xiangzi_id = 37;
            xiaojian_37 = false;
            return;
        }
        else if(xiaojian_38)
        {
            ser->openDoor(38);
            xiangzi_id = 38;
            xiaojian_38 = false;
            return;
        }
        else if(xiaojian_39)
        {
            ser->openDoor(39);
            xiangzi_id = 39;
            xiaojian_39 = false;
            return;
        }
        else if(xiaojian_40)
        {
            ser->openDoor(40);
            xiangzi_id = 40;
            xiaojian_40 = false;
            return;
        }
        else if(xiaojian_41)
        {
            ser->openDoor(41);
            xiangzi_id = 41;
            xiaojian_41 = false;
            return;
        }
        else if(xiaojian_46)
        {
            ser->openDoor(46);
            xiangzi_id = 46;
            xiaojian_46 = false;
            return;
        }
        else if(xiaojian_47)
        {
            ser->openDoor(47);
            xiangzi_id = 47;
            xiaojian_47 = false;
            return;
        }
        else if(xiaojian_48)
        {
            ser->openDoor(48);
            xiangzi_id = 48;
            xiaojian_48 = false;
            return;
        }
        else if(xiaojian_49)
        {
            ser->openDoor(49);
            xiangzi_id = 49;
            xiaojian_49 = false;
            return;
        }
        else if(xiaojian_50)
        {
            ser->openDoor(50);
            xiangzi_id = 50;
            xiaojian_50 = false;
            return;
        }
        else if(xiaojian_51)
        {
            ser->openDoor(51);
            xiangzi_id = 51;
            xiaojian_51 = false;
            return;
        }
        else
        {
            pop_xiaojian->show();
            QTimer::singleShot( 1500, this, SLOT(hide_xiaojian()));
        }
    }
    else if(tu_an == "texiaojian")
    {
        tu_an = QString("");
        if(texiaojian_01)
        {
            ser->openDoor(1);
            xiangzi_id = 1;
            texiaojian_01 = false;
            return;
        }
        else if(texiaojian_02)
        {
            ser->openDoor(2);
            xiangzi_id = 2;
            texiaojian_02 = false;
            return;
        }
        else if(texiaojian_03)
        {
            ser->openDoor(3);
            xiangzi_id = 3;
            texiaojian_03 = false;
            return;
        }
        else if(texiaojian_04)
        {
            ser->openDoor(4);
            xiangzi_id = 4;
            texiaojian_04 = false;
            return;
        }
        else if(texiaojian_05)
        {
            ser->openDoor(5);
            xiangzi_id = 5;
            texiaojian_05 = false;
            return;
        }
        else if(texiaojian_06)
        {
            ser->openDoor(6);
            xiangzi_id = 6;
            texiaojian_06 = false;
            return;
        }
        else if(texiaojian_07)
        {
            ser->openDoor(7);
            xiangzi_id = 7;
            texiaojian_07 = false;
            return;
        }
        else if(texiaojian_08)
        {
            ser->openDoor(8);
            xiangzi_id = 8;
            texiaojian_08 = false;
            return;
        }
        else if(texiaojian_09)
        {
            ser->openDoor(9);
            xiangzi_id = 9;
            texiaojian_09 = false;
            return;
        }
        else if(texiaojian_10)
        {
            ser->openDoor(10);
            xiangzi_id = 10;
            texiaojian_10 = false;
            return;
        }
        else if(texiaojian_11)
        {
            ser->openDoor(11);
            xiangzi_id = 11;
            texiaojian_11 = false;
            return;
        }
        else if(texiaojian_12)
        {
            ser->openDoor(12);
            xiangzi_id = 12;
            texiaojian_12 = false;
            return;
        }
        else if(texiaojian_13)
        {
            ser->openDoor(13);
            xiangzi_id = 13;
            texiaojian_13 = false;
            return;
        }
        else if(texiaojian_14)
        {
            ser->openDoor(14);
            xiangzi_id = 14;
            texiaojian_14 = false;
            return;
        }
        else
        {
            pop_texiaojian->show();
            QTimer::singleShot( 1500, this, SLOT(hide_texiaojian()));
        }
    }
}

void PageNine::jiance(int num,QString status)
{
//    qDebug() << "......";
//    qDebug() << num << status;

    if(num==xiangzi_id && status=="close")
    {
        djs_int = 30;
        init_djs();

        pop_item4->show();
        pop_item3->hide();

        //QTimer::singleShot( 1500, this, SLOT(xiaoshi()));
    }
}

void PageNine::backHome()
{
    pop_item->hide();
    pop_item2->hide();
    pop_item3->hide();
    pop_item4->hide();
    pop_item5->hide();
    pop_dajian->hide();
    pop_zhongjian->hide();
    pop_xiaojian->hide();
    pop_texiaojian->hide();
    emit back_home();
}

void PageNine::to_nine(int id)
{
    switch(id)
    {
    case 15:
        da_jian_15 = true;
        break;
    case 25:
        da_jian_25 = true;
        break;
    case 55:
        da_jian_55 = true;
        break;
    case 35:
        da_jian_35 = true;
        break;
    case 45:
        da_jian_45 = true;
        break;
    case 32:
        zhong_jian_32 = true;
        break;
    case 33:
        zhong_jian_33 = true;
        break;
    case 34:
        zhong_jian_34 = true;
        break;
    case 22:
        zhong_jian_22 = true;
        break;
    case 23:
        zhong_jian_23 = true;
        break;
    case 24:
        zhong_jian_24 = true;
        break;
    case 42:
        zhong_jian_42 = true;
        break;
    case 43:
        zhong_jian_43 = true;
        break;
    case 44:
        zhong_jian_44 = true;
        break;
    case 52:
        zhong_jian_52 = true;
        break;
    case 53:
        zhong_jian_53 = true;
        break;
    case 54:
        zhong_jian_54 = true;
        break;
    case 26:
        xiaojian_26 = true;
        break;
    case 27:
        xiaojian_27 = true;
        break;
    case 28:
        xiaojian_28 = true;
        break;
    case 29:
        xiaojian_29 = true;
        break;
    case 30:
        xiaojian_30 = true;
        break;
    case 31:
        xiaojian_31 = true;
        break;
    case 16:
        xiaojian_16 = true;
        break;
    case 17:
        xiaojian_17 = true;
        break;
    case 18:
        xiaojian_18 = true;
        break;
    case 19:
        xiaojian_19 = true;
        break;
    case 20:
        xiaojian_20 = true;
        break;
    case 21:
        xiaojian_21 = true;
        break;
    case 36:
        xiaojian_36 = true;
        break;
    case 37:
        xiaojian_37 = true;
        break;
    case 38:
        xiaojian_38 = true;
        break;
    case 39:
        xiaojian_39 = true;
        break;
    case 40:
        xiaojian_40 = true;
        break;
    case 41:
        xiaojian_41 = true;
        break;
    case 46:
        xiaojian_46 = true;
        break;
    case 47:
        xiaojian_47 = true;
        break;
    case 48:
        xiaojian_48 = true;
        break;
    case 49:
        xiaojian_49 = true;
        break;
    case 50:
        xiaojian_50 = true;
        break;
    case 51:
        xiaojian_51 = true;
        break;
    case 1:
        texiaojian_01 = true;
        break;
    case 2:
        texiaojian_02 = true;
        break;
    case 3:
        texiaojian_03 = true;
        break;
    case 4:
        texiaojian_04 = true;
        break;
    case 5:
        texiaojian_05 = true;
        break;
    case 6:
        texiaojian_06 = true;
        break;
    case 7:
        texiaojian_07 = true;
        break;
    case 8:
        texiaojian_08 = true;
        break;
    case 9:
        texiaojian_09 = true;
        break;
    case 10:
        texiaojian_10 = true;
        break;
    case 11:
        texiaojian_11 = true;
        break;
    case 12:
        texiaojian_12 = true;
        break;
    case 13:
        texiaojian_13 = true;
        break;
    case 14:
        texiaojian_14 = true;
        break;
    default:
        //bu ke neng
        break;
    }

    ser->openDoor(id);
}

void PageNine::hide_dajian()
{
    pop_dajian->hide();
}

void PageNine::hide_zhongjian()
{
    pop_zhongjian->hide();
}

void PageNine::hide_xiaojian()
{
    pop_xiaojian->hide();
}

void PageNine::hide_texiaojian()
{
    pop_texiaojian->hide();
}

void PageNine::init_djs()
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

    yundan2_edit->clear();
}

void PageNine::end_djs()
{
    djs_int = 30;
    timer->stop();
}

void PageNine::update_djs()
{
    if(djs_int==1)
    {
        end_djs();
        backHome();
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

void PageNine::hide_label()
{
    movie->stop();
    label->hide();
}
