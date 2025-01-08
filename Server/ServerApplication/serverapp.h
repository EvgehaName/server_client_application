#ifndef SERVERAPP_H
#define SERVERAPP_H

#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QCoreApplication>
#include <QSettings>
#include <sstream>

class ServerApp : public QTcpServer
{
    Q_OBJECT
public:
    void startServerApp();
private:
    QTcpServer* tcpServer;
    QTcpSocket* tcpSocket;
    QByteArray byteData;
    QHostAddress address;


public slots:
    void newServerConnection();
    void sockReady();
    void sockDisconnection();
    void writeLogData(std::string data, std::string flag);
    //void readLogData();
    std::vector<std::string> splitElem(std::string elem);
};

#endif // SERVERAPP_H
