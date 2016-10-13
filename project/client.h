#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include "settings.h"

typedef char buffer_t[1024];

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent);
    QTcpSocket *socket;
    void run();
    void send(QString message);
    void processReply(char *msg);
public slots:
    void raiseError(QAbstractSocket::SocketError socket_error);
    void getMessage();
    void signup();
};

extern Client *ClientInstance;

#endif // CLIENT_H
