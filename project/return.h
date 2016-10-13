#ifndef RETURN_H
#define RETURN_H

#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QPainter>
//#include <QSound>

class Return : public QGraphicsObject
{
    Q_OBJECT
public:
    Return();
    Return(QString name);
    //Phonon::MediaObject//cr;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QRectF boundingRect() const;
private:
    QPixmap pixmap;
signals:
    void click();
};

#endif // RETURN_H
