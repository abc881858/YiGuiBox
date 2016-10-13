#include "return.h"

Return::Return()
{

}

Return::Return(QString name) : pixmap(name)
{
    //cr = Phonon::createPlayer(Phonon//cCategory,Phonon::MediaSource("Touch.wav"));
}

void Return::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    //cr->play();
    //QSound::play("anjian.wav");
    //emit click();
}

void Return::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    emit click();
}

void Return::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0,0,pixmap);
}

QRectF Return::boundingRect() const
{
    return QRectF(0,0,pixmap.width(),pixmap.height());
}
