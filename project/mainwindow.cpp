#include "mainwindow.h"
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QDebug>
#include <client.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    Client *client = new Client(this);
    client->run();

    carousel = new Carousel;
    connect(carousel,SIGNAL(clicked1()),this,SLOT(change_page1()));
    connect(carousel,SIGNAL(clicked2()),this,SLOT(change_page2()));
    connect(carousel,SIGNAL(clicked3()),this,SLOT(change_page3()));
    connect(carousel,SIGNAL(clicked4()),this,SLOT(change_page4()));
    connect(carousel,SIGNAL(clicked5()),this,SLOT(change_page5()));
    connect(carousel,SIGNAL(clicked6()),this,SLOT(change_page6()));

    fitview = new QGraphicsView();
    fitview->setFixedSize(QSize(1024,768));
    fitview->setSceneRect(0,0,1024,768);
    fitview->setRenderHint(QPainter::Antialiasing, true);
    fitview->setFrameStyle(QFrame::NoFrame);

    flipview = new PageFlipView;
    flipview->resize(1024,768);
    flipview->move(0,0);
    flipview->hide();
//    flipview->loadImage(":/back.png");

    page1 = new PageOne;
    page2 = new PageTwo;
    page3 = new PageThree;
    page4 = new PageFour;
    page5 = new PageFive;
    page6 = new PageSix;
    page9 = new PageNine;
    page10 = new PageTen;

    connect(page1,SIGNAL(back_home()),this,SLOT(go_home1()));
    connect(page2,SIGNAL(back_home()),this,SLOT(go_home2()));
    connect(page3,SIGNAL(back_home()),this,SLOT(go_home3()));
    connect(page3,SIGNAL(turn_nine()),this,SLOT(go_nine()));
    connect(page4,SIGNAL(back_home()),this,SLOT(go_home4()));
    connect(page5,SIGNAL(back_home()),this,SLOT(go_home5()));
    connect(page5,SIGNAL(turn_ten()),this,SLOT(go_ten()));
    connect(page6,SIGNAL(back_home()),this,SLOT(go_home6()));
    connect(page9,SIGNAL(back_home()),this,SLOT(go_home9()));
    connect(page10,SIGNAL(back_home()),this,SLOT(go_home10()));
    connect(page1,SIGNAL(one_to(int)),page9,SLOT(to_nine(int)));
    connect(page1,SIGNAL(toCam()),page3,SLOT(to_Cam()));

    carousel->show();
    fitview->hide();
    this->hide();

    pagea = new PageA;
    pageb = new PageB;
    pagec = new PageC;
    paged = new PageD;
    pagef = new PageF;
    pageg = new PageG;
    pageh = new PageH;
    pagej = new PageJ;
    pagek = new PageK;
    pagel = new PageL;
    pagem = new PageM;
    pagen = new PageN;
    pageo = new PageO;
    pagep = new PageP;
    pageq = new PageQ;
    pager = new PageR;
    pages = new PageS;
    paget = new PageT;
    pageu = new PageU;
    pagew = new PageW;
    pagex = new PageX;
    pagey = new PageY;
    pagez = new PageZ;
    pageusual = new PageUsual;
    pageother = new PageOther;

    connect(pagea,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pageb,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagec,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(paged,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagef,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pageg,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pageh,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagej,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagek,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagel,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagem,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagen,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pageo,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagep,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pageq,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pager,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pages,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(paget,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pageu,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pageusual,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagew,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagex,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagey,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pagez,SIGNAL(back_home()),this,SLOT(change_page4()));
    connect(pageother,SIGNAL(back_home()),this,SLOT(change_page4()));

    connect(page4,SIGNAL(goPageA(QString)),this,SLOT(go_PageA(QString)));
    connect(page4,SIGNAL(goPageB(QString)),this,SLOT(go_PageB(QString)));
    connect(page4,SIGNAL(goPageC(QString)),this,SLOT(go_PageC(QString)));
    connect(page4,SIGNAL(goPageD(QString)),this,SLOT(go_PageD(QString)));
    connect(page4,SIGNAL(goPageF(QString)),this,SLOT(go_PageF(QString)));
    connect(page4,SIGNAL(goPageG(QString)),this,SLOT(go_PageG(QString)));
    connect(page4,SIGNAL(goPageH(QString)),this,SLOT(go_PageH(QString)));
    connect(page4,SIGNAL(goPageJ(QString)),this,SLOT(go_PageJ(QString)));
    connect(page4,SIGNAL(goPageK(QString)),this,SLOT(go_PageK(QString)));
    connect(page4,SIGNAL(goPageL(QString)),this,SLOT(go_PageL(QString)));
    connect(page4,SIGNAL(goPageM(QString)),this,SLOT(go_PageM(QString)));
    connect(page4,SIGNAL(goPageN(QString)),this,SLOT(go_PageN(QString)));
    connect(page4,SIGNAL(goPageO(QString)),this,SLOT(go_PageO(QString)));
    connect(page4,SIGNAL(goPageP(QString)),this,SLOT(go_PageP(QString)));
    connect(page4,SIGNAL(goPageQ(QString)),this,SLOT(go_PageQ(QString)));
    connect(page4,SIGNAL(goPageR(QString)),this,SLOT(go_PageR(QString)));
    connect(page4,SIGNAL(goPageS(QString)),this,SLOT(go_PageS(QString)));
    connect(page4,SIGNAL(goPageT(QString)),this,SLOT(go_PageT(QString)));
    connect(page4,SIGNAL(goPageU(QString)),this,SLOT(go_PageU(QString)));
    connect(page4,SIGNAL(goPageW(QString)),this,SLOT(go_PageW(QString)));
    connect(page4,SIGNAL(goPageX(QString)),this,SLOT(go_PageX(QString)));
    connect(page4,SIGNAL(goPageY(QString)),this,SLOT(go_PageY(QString)));
    connect(page4,SIGNAL(goPageZ(QString)),this,SLOT(go_PageZ(QString)));
    connect(page4,SIGNAL(goPageOther(QString)),this,SLOT(go_PageOther(QString)));
    connect(page4,SIGNAL(goPageUsual(QString)),this,SLOT(go_PageUsual(QString)));

}

MainWindow::~MainWindow()
{

}

void MainWindow::change_page1()
{
    qDebug() << "page1";
    fitview->setScene(page1);
    fitview->showFullScreen();
    page1->timer->start(1000);
}

void MainWindow::change_page2()
{
//    qDebug() << "page2";
//    fitview->setScene(page2);
//    fitview->showFullScreen();
//    page2->timer->start(1000);
    flipview->showFullScreen();
    //flipview->loadImage(":/back.png");
}

void MainWindow::change_page3()
{
    qDebug() << "page3";
    fitview->setScene(page3);
    fitview->showFullScreen();
    page3->init_djs();
    page3->timer->start(1000);
}

void MainWindow::change_page4()
{
    qDebug() << "page4";
    fitview->setScene(page4);
    fitview->update();
    fitview->showFullScreen();

    page4->timer->start(1000);
}

void MainWindow::change_page5()
{
    qDebug() << "page5";
    fitview->setScene(page5);
    fitview->showFullScreen();
    page5->timer->start(1000);
}

void MainWindow::change_page6()
{
    qDebug() << "page6";
    fitview->setScene(page6);
    fitview->showFullScreen();
    page6->timer->start(1000);
    page6->updateSQL();
}

void MainWindow::go_home()
{
    qDebug() << "home";
    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_home1()
{
    page1->end_djs();
    page1->initKeyNum();
    page1->showPlace=1;

    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_home2()
{
    page2->end_djs();

    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_home3()
{
    page3->end_djs();
    page3->can_read = false;

    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_home4()
{
    page4->end_djs();

    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_home5()
{
    page5->end_djs();

    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_home6()
{
    page6->end_djs();
//    page6->yundanxiangqing->setText("");
//    page6->bianma_edit->setText("");
//    page6->cell_id = false;

    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_home9()
{
    page9->end_djs();
    page3->can_read = false;

    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_home10()
{
    carousel->restore();
    carousel->showFullScreen();
    fitview->hide();
}

void MainWindow::go_nine()
{
    page3->end_djs();
    page3->can_read = false;

    fitview->setScene(page9);
    fitview->showFullScreen();
    page9->init_djs();
    page9->pop_item->show();
    page9->timer->start(1000);
}

void MainWindow::go_ten()
{
    page5->end_djs();

    fitview->setScene(page10);
    fitview->showFullScreen();
}

void MainWindow::go_PageA(QString str)
{
    page4->end_djs();
    fitview->setScene(pagea);
}

void MainWindow::go_PageB(QString str)
{
    page4->end_djs();
    fitview->setScene(pageb);
}

void MainWindow::go_PageC(QString str)
{
    page4->end_djs();
    fitview->setScene(pagec);
}

void MainWindow::go_PageD(QString str)
{
    page4->end_djs();
    fitview->setScene(paged);
}

void MainWindow::go_PageF(QString str)
{
    page4->end_djs();
    fitview->setScene(pagef);
}

void MainWindow::go_PageG(QString str)
{
    page4->end_djs();
    fitview->setScene(pageg);
}

void MainWindow::go_PageH(QString str)
{
    page4->end_djs();
    fitview->setScene(pageh);
}

void MainWindow::go_PageJ(QString str)
{
    page4->end_djs();
    fitview->setScene(pagej);
}

void MainWindow::go_PageK(QString str)
{
    page4->end_djs();
    fitview->setScene(pagek);
}

void MainWindow::go_PageL(QString str)
{
    page4->end_djs();
    fitview->setScene(pagel);
}

void MainWindow::go_PageM(QString str)
{
    page4->end_djs();
    fitview->setScene(pagem);
}

void MainWindow::go_PageN(QString str)
{
    page4->end_djs();
    fitview->setScene(pagen);
}

void MainWindow::go_PageO(QString str)
{
    page4->end_djs();
    fitview->setScene(pageo);
}

void MainWindow::go_PageP(QString str)
{
    page4->end_djs();
    fitview->setScene(pagep);
}

void MainWindow::go_PageQ(QString str)
{
    page4->end_djs();
    fitview->setScene(pageq);
}

void MainWindow::go_PageR(QString str)
{
    page4->end_djs();
    fitview->setScene(pager);
}

void MainWindow::go_PageS(QString str)
{
    page4->end_djs();
    fitview->setScene(pages);
}

void MainWindow::go_PageT(QString str)
{
    page4->end_djs();
    fitview->setScene(paget);
}

void MainWindow::go_PageU(QString str)
{
    page4->end_djs();
    fitview->setScene(pageu);
}

void MainWindow::go_PageW(QString str)
{
    page4->end_djs();
    fitview->setScene(pagew);
}

void MainWindow::go_PageX(QString str)
{
    page4->end_djs();
    fitview->setScene(pagex);
}

void MainWindow::go_PageY(QString str)
{
    page4->end_djs();
    fitview->setScene(pagey);
}

void MainWindow::go_PageZ(QString str)
{
    page4->end_djs();
    fitview->setScene(pagez);
}

void MainWindow::go_PageUsual(QString str)
{
    page4->end_djs();
    fitview->setScene(pageusual);
}

void MainWindow::go_PageOther(QString str)
{
    page4->end_djs();
    fitview->setScene(pageother);
}
