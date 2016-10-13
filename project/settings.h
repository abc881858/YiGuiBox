#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QFont>
#include <QRectF>
#include <QPixmap>
#include <QBrush>
#include <QtSql>

class Settings : public QSettings
{
    Q_OBJECT

public:
    explicit Settings();
    void init();

    QSqlDatabase dbconn;
    QSqlDatabase data_base;
    QString duanxin_ip;
    int duanxin_port;

    QString man;
};

extern Settings Config;

#endif // SETTINGS_H
