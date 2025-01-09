#ifndef SERVERAPP_H
#define SERVERAPP_H

#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QCoreApplication>
#include <QSettings>
#include <sstream>
#include <filesystem>

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
    void sendToData(const char* data);

public slots:
    void newServerConnection();
    void sockReady();
    void sockDisconnection();
    void writeLogData(std::string data, std::string flag);
    void readToSendLogData();
    std::vector<std::string> splitElem(std::string elem);
};

#endif // SERVERAPP_H
