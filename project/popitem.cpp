#include "popitem.h"

PopItem::PopItem()
{
}

PopItem::PopItem(const QString &filename) : pixmap(filename)
{
    QString str(filename);
    str.remove("");
    setObjectName(str);
    setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF PopItem::boundingRect() const
{
    return QRectF(0,0,pixmap.width(),pixmap.height());
}

void PopItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0,0,pixmap);
}

void PopItem::setPixmap(QString filename)
{
    pixmap.load(filename);
    this->update();
}

void PopItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
//    pixmap.load(QString("To").append(objectName()));
//    this->update();
    //this->hide();
}

void PopItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
//    pixmap.load(objectName());
//    this->update();
//    emit clicked(objectName());
}
