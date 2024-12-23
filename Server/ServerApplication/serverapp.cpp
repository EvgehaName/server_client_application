#include "serverapp.h"

void ServerApp::startServerApp()
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newServerConnection()));
    if(tcpServer->listen(QHostAddress::Any, 8888))
    {
        std::cout << "Server start! Listening...." << std::endl;
    }
    else
    {
        std::cout << "No start server!" << std::endl;
    }
}

void ServerApp::newServerConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(tcpSocket, SIGNAL(disconnection()), this, SLOT(sockDisconnection()));

    tcpSocket->write("Connection Client!");
    tcpSocket->waitForBytesWritten(500);

}

void ServerApp::sockReady()
{
    byteData = tcpSocket->readAll();
    tcpSocket->waitForBytesWritten(500);
    std::cout << byteData.toStdString() << std::endl;
}

void ServerApp::sockDisconnection()
{
    std::cout << "Disconnected...." << std::endl;
    tcpSocket->deleteLater();
}
