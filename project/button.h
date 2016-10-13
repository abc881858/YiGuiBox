#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsObject>
#include <QPixmap>
#include <QPainter>
////#include <QSound>

class Button : public QGraphicsObject
{
    Q_OBJECT
public:
    Button();
    Button(const QString &filename);
    virtual QRectF boundingRect() const;
    QPixmap pixmap;
    //non::MediaObject *c;
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
    void setPixmap(QString filename);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked(QString);
};

#endif // BUTTON_H
