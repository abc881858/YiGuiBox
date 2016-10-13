#include "sqlquerymodel.h"

SqlQueryModel::SqlQueryModel()
{
}

//tata()改写某一个列的显示样式,对齐方式
QVariant SqlQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
//    if (role == Qt::TextColorRole && index.column() == 0)
//        return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色

//    if (role == Qt::TextAlignmentRole && index.column() == 1)
//    {
//        value = (Qt::AlignVCenter + Qt::AlignRight); // 靠右垂直居中
//    }

    if (role == Qt::TextAlignmentRole)
    {
        value = (Qt::AlignVCenter +Qt::AlignHCenter);
    }


    return value;
}
