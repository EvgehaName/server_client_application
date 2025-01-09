#include "serverapp.h"

void ServerApp::startServerApp()
{
    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);
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

void ServerApp::sendToData(const char *data)
{
    if(tcpSocket->state() == QTcpSocket::ConnectedState)
    {
        tcpSocket->waitForBytesWritten(500);
        tcpSocket->write(data);
        tcpSocket->flush();
    }
}

void ServerApp::newServerConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    readToSendLogData();
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
    configServer.beginGroup("ConfigRLC");
    configServer.setValue(flag.c_str(), data.c_str());
    configServer.endGroup();
}

void ServerApp::readToSendLogData()
{
    std::cout << "read file for new connection" << std::endl;
    if(std::filesystem::exists("configRLC.ini"))
    {
        QString valueAntenna;
        QString valueRadiation;
        QString valueTrigger;
        QSettings configServer("configRLC.ini", QSettings::IniFormat);
        configServer.beginGroup("ConfigRLC");
        valueAntenna = configServer.value("ValueAntenna", "").toString();
        valueRadiation = configServer.value("ValueRadiation", "").toString();
        valueTrigger = configServer.value("ValueTrigger", "").toString();
        configServer.endGroup();
        sendToData((valueAntenna.toStdString() + " ").c_str());
        sendToData((valueRadiation.toStdString() + " ").c_str());
        sendToData((valueTrigger.toStdString() + " ").c_str());
    }
    else
    {
        return;
    }
}

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


