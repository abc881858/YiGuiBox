#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QMainWindow>
#include "carousel.h"
#include "pageone.h"
#include "pagetwo.h"
#include "pagethree.h"
#include "pagefour.h"
#include "pagefive.h"
#include "pagesix.h"
#include "pagenine.h"
#include "pageten.h"
#include <QGraphicsView>
#include "pageflipview.h"
#include "pagea.h"
#include "pageb.h"
#include "pagec.h"
#include "paged.h"
#include "pagef.h"
#include "pageg.h"
#include "pageh.h"
#include "pagej.h"
#include "pagek.h"
#include "pagel.h"
#include "pagem.h"
#include "pagen.h"
#include "pageo.h"
#include "pagep.h"
#include "pageq.h"
#include "pager.h"
#include "pages.h"
#include "paget.h"
#include "pageu.h"
#include "pagew.h"
#include "pagex.h"
#include "pagey.h"
#include "pagez.h"
#include "pageusual.h"
#include "pageother.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    PageOne *page1;
    PageTwo *page2;
    PageThree *page3;
    PageFour *page4;
    PageFive *page5;
    PageSix *page6;
    PageNine *page9;
    PageTen *page10;
    Carousel *carousel;
    QGraphicsView *fitview;

    PageFlipView *flipview;

    PageA *pagea;
    PageB *pageb;
    PageC *pagec;
    PageD *paged;
    PageF *pagef;
    PageG *pageg;
    PageH *pageh;
    PageJ *pagej;
    PageK *pagek;
    PageL *pagel;
    PageM *pagem;
    PageN *pagen;
    PageO *pageo;
    PageP *pagep;
    PageQ *pageq;
    PageR *pager;
    PageS *pages;
    PageT *paget;
    PageU *pageu;
    PageW *pagew;
    PageX *pagex;
    PageY *pagey;
    PageZ *pagez;
    PageUsual *pageusual;
    PageOther *pageother;

public slots:
    void change_page1();
    void change_page2();
    void change_page3();
    void change_page4();
    void change_page5();
    void change_page6();
    void go_home();
    void go_home1();
    void go_home2();
    void go_home3();
    void go_home4();
    void go_home5();
    void go_home6();
    void go_home9();
    void go_home10();
    void go_nine();
    void go_ten();
    void go_PageA(QString str);
    void go_PageB(QString str);
    void go_PageC(QString str);
    void go_PageD(QString str);
    void go_PageF(QString str);
    void go_PageG(QString str);
    void go_PageH(QString str);
    void go_PageJ(QString str);
    void go_PageK(QString str);
    void go_PageL(QString str);
    void go_PageM(QString str);
    void go_PageN(QString str);
    void go_PageO(QString str);
    void go_PageP(QString str);
    void go_PageQ(QString str);
    void go_PageR(QString str);
    void go_PageS(QString str);
    void go_PageT(QString str);
    void go_PageU(QString str);
    void go_PageW(QString str);
    void go_PageX(QString str);
    void go_PageY(QString str);
    void go_PageZ(QString str);
    void go_PageUsual(QString str);
    void go_PageOther(QString str);
};

#endif // MAINWINDOW_H
