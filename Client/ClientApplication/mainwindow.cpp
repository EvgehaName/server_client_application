#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socketClient = new QTcpSocket(this);

    connect(socketClient, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socketClient, SIGNAL(disconnected()), this, SLOT(disconnectedClient()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    socketClient->connectToHost("127.0.0.1", 8888);
}

void MainWindow::disconnectedClient()
{
    std::cout << "disconnection client" << std::endl;
    socketClient->close();
}

void MainWindow::socketReady()
{
    if(socketClient->waitForConnected(500))
    {
        socketClient->waitForReadyRead(500);
        Data = socketClient->readAll();
        std::cout << Data.toStdString() << std::endl;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    std::cout << "disconnection...." << std::endl;
    socketClient->disconnectFromHost();
}


void MainWindow::on_pushButton_3_clicked()
{
    if(socketClient->state() == QTcpSocket::ConnectedState)
    {
        socketClient->write("Hello server");
        socketClient->waitForBytesWritten(500);
        socketClient->flush();
    }
    else
    {
        std::cout << "No connection to server!" << std::endl;
    }
}

