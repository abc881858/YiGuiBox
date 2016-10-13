#include "settings.h"
#include <QFontDatabase>
#include <QStringList>
#include <QFile>
#include <QMessageBox>
#include <QApplication>
#include <QNetworkInterface>
#include <QDateTime>

Settings Config;

Settings::Settings() : QSettings("config.ini", QSettings::IniFormat)
{
    man = QString("");
}

void Settings::init()
{
    duanxin_ip = "112.124.112.10";
    duanxin_port = 2223;

    dbconn = QSqlDatabase::addDatabase("QSQLITE","connection_name_sqlite");
    dbconn.setDatabaseName("mytest.db");
    if(!dbconn.open())
    {
        qDebug()<<"failed sqlite";
    }
    else
    {
        qDebug() <<"success sqlite";
        QSqlQuery query(dbconn);
        query.exec("create table IF NOT EXISTS xiangzi(tiaoma varchar primary key,id int,password varchar(8),phone varchar)");
    }

    data_base = QSqlDatabase::addDatabase("QMYSQL","connection_name_mysql");
    data_base.setHostName(duanxin_ip);  //设置主机地址
    data_base.setPort(3306);  //设置端口
    data_base.setDatabaseName("hibernate3day2");  //设置数据库名称
    data_base.setUserName("root");  //设置用户名
    data_base.setPassword("1234");  //设置密码
    if(!data_base.open())
    {
        qDebug()<<"failed mysql";
    }
    else
    {
        qDebug()<<"success mysql";
    }

}
