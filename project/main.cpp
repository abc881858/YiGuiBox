#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QTranslator>
#include "qdeclarativeview3d.h"
#include "settings.h"

int main(int argc, char *argv[])
{
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    Config.init();

    QApplication a(argc, argv);
    a.setApplicationName("YiGuiBao");

    QTranslator translator;
    translator.load( "app_zh_CN.qm", "." );
    a.installTranslator( &translator );
    a.setFont(QFont("宋体", 10));

    MainWindow w;
    return a.exec();
}
