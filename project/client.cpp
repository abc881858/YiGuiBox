#include "client.h"

Client *ClientInstance = NULL;

Client::Client(QObject *parent):QObject(parent)
{
    ClientInstance = this;

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(getMessage()));
    connect(socket, SIGNAL(connected()), this, SLOT(signup()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(raiseError(QAbstractSocket::SocketError)));
}

void Client::run()
{
    socket->connectToHost(QHostAddress(Config.duanxin_ip), Config.duanxin_port);
}

void Client::signup()
{
    qDebug() << "congratulation";

    //send(QString("courier@name_value|leader_value|tel_value|address_value|user_value|card_value|phone_value"));
}

void Client::getMessage()
{
    while(socket->canReadLine())
    {
        buffer_t msg;
        socket->readLine(msg, sizeof(msg));
        processReply(msg);
    }
}

void Client::raiseError(QAbstractSocket::SocketError socket_error)
{
    QString reason;
    switch(socket_error)
    {
    case QAbstractSocket::ConnectionRefusedError:
        reason = "Connection was refused or timeout";
        break;
    case QAbstractSocket::RemoteHostClosedError:
        reason = "Remote host close this connection";
        break;
    case QAbstractSocket::HostNotFoundError:
        reason = "Host not found";
        break;
    case QAbstractSocket::SocketAccessError:
        reason = "Socket access error";
        break;
    case QAbstractSocket::NetworkError:
        reason = "Server's' firewall blocked the connection or the network cable was plugged out";
        break;
    default: reason = "Unknow error";
        break;
    }

    qDebug() << QString("Connection failed, error code = %1\n reason:\n %2").arg(socket_error).arg(reason);
}

void Client::send(QString message)
{
//    socket->write(message.);
//    socket->write("\n");

    socket->write(message.toLatin1());
    socket->write("\n");

//    QByteArray block;
//    block=block.append("hello");
//    socket->write(block);
}

void Client::processReply(char* msg)
{
    QString m(msg);
    qDebug() << m.trimmed();
}
