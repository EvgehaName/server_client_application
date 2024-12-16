#include "serverapp.h"

ServerApp::ServerApp() {
    if(this->listen(QHostAddress::Any, 5555))
    {
        std::cout << "Server open! Listen!" << std::endl;
    }
    else
    {
        std::cout << "Server error!" << std::endl;
    }
}

ServerApp::~ServerApp()
{
    std::cout << "Server close!" << std::endl;
    QTimer::singleShot(5000, [this](){
        socket->disconnected();
        socket->close();

        server->disconnect();
        server->close();
    });
}

void ServerApp::incomingConnection(qintptr discriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(discriptor);
    connect(socket,SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
    std::cout << "ID: " << discriptor << "Client connection" << std::endl;

    socket->write("I client connection");
}

void ServerApp::sockReady()
{

}

void ServerApp::sockDisc()
{
    std::cout << "Disconnected...." << std::endl;
    socket->deleteLater();
}
