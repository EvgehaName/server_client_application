#ifndef SERVERAPP_H
#define SERVERAPP_H

#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QCoreApplication>

class ServerApp : public QTcpServer
{
    Q_OBJECT
public:
    ServerApp();
    ~ServerApp();

private:
    QTcpServer* server;
    QTcpSocket* socket;


public slots:
    virtual void incomingConnection(qintptr discriptor);
    void sockReady();
    void sockDisc();
};

#endif // SERVERAPP_H
