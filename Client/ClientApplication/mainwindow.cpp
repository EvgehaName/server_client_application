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
    socketClient->connectToHost("127.0.0.1", 5555);
}

void MainWindow::disconnectedClient()
{
    socketClient->deleteLater();
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
    socketClient->disconnected();
    //socketClient->deleteLater();
}

