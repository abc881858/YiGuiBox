#include "button.h"
#include <QDebug>

Button::Button()
{
    //c = Phonon::createPlayer(Phonon//cCategory,Phonon::MediaSource("anjian.wav"));
}

Button::Button(const QString &filename) : pixmap(filename)
{
    QString str(filename);
    str.remove("");
    setObjectName(str);
    setAcceptedMouseButtons(Qt::LeftButton);
    //c = Phonon::createPlayer(Phonon//cCategory,Phonon::MediaSource("anjian.wav"));
}

QRectF Button::boundingRect() const
{
    return QRectF(0,0,pixmap.width(),pixmap.height());
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0,0,pixmap);
}

void Button::setPixmap(QString filename)
{
    pixmap.load(filename);
    this->update();
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    //c->play();
    ////QSound::play("anjian.wav");
    pixmap.load(QString("To").append(objectName()));
    this->update();
}

void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    pixmap.load(QString("").append(objectName()));
    this->update();
    emit clicked(objectName());
}
