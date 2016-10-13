#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H

#include <QtSql>
#include <QSqlQueryModel>
#include <QColor>

class SqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    SqlQueryModel();
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // SQLQUERYMODEL_H
