#ifndef POPITEM_H
#define POPITEM_H

#include <QGraphicsObject>
#include <QPixmap>
#include <QPainter>

class PopItem : public QGraphicsObject
{
    Q_OBJECT
public:
    PopItem();
    PopItem(const QString &filename);
    virtual QRectF boundingRect() const;
    QPixmap pixmap;
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    void setPixmap(QString filename);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked(QString);
};

#endif // POPITEM_H
