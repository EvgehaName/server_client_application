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
    void startServerApp();
private:
    QTcpServer* tcpServer;
    QTcpSocket* tcpSocket;
    QByteArray byteData;


public slots:
    void newServerConnection();
    void sockReady();
    void sockDisconnection();
};

#endif // SERVERAPP_H
