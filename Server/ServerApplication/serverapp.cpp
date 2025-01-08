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
    tcpSocket->write("Connection Client!");

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(sockDisconnection()));

}

void ServerApp::sockReady()
{
    byteData = tcpSocket->readAll();
    tcpSocket->waitForBytesWritten(500);
    std::vector<std::string> arrayData = splitElem(byteData.toStdString());
    std::cout << "Check: " << arrayData[0] << " " << arrayData[1] << std::endl;
    writeLogData(arrayData[1], arrayData[0]);
    std::cout << byteData.toStdString() << std::endl;
}

void ServerApp::sockDisconnection()
{
    std::cout << "Disconnected...." << std::endl;
    tcpSocket->close();
    tcpSocket->deleteLater();
}

void ServerApp::writeLogData(std::string data, std::string flag)
{
    QSettings configServer("configRLC.ini", QSettings::IniFormat);
    configServer.beginGroup("Config RLC");
    configServer.setValue(flag.c_str(), data.c_str());
    configServer.endGroup();
}

// void ServerApp::readLogData()
// {

// }

std::vector<std::string> ServerApp::splitElem(std::string elem)
{
    std::string array;
    std::vector<std::string> vector_array;
    std::stringstream elemData(elem);
    while (getline(elemData, array, ' ')) {
        vector_array.push_back(array);
    }
    return vector_array;
}

// void ServerApp::checkFlags(QString flag)
// {
//     if(flag == "")
// }
