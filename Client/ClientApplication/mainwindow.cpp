#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ipAddress = ui->lineEdit_IP;
    portAddress = ui->lineEdit_Port;
    configCheckSave = ui->checkBox_Config;
    mainAppWidget = ui->widgetMainApp;
    enterAppWidget = ui->widgetEnterApp;
    editTextAntenna = ui->lineEdit_AntennaEnter;
    editTextRadiation = ui->lineEdit_RadiationEnter;

    ui->pushButton_CheckBox->setTextToggle("Антенна включена", "Антенна выключена");

    mainAppWidget->setVisible(false);

    ConfigReadApp();

    socketClient = new QTcpSocket(this);

    connect(socketClient, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(socketClient, SIGNAL(disconnected()), this, SLOT(disconnectedClient()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ConfigReadApp()
{
    std::cout << "init config read" << std::endl;
    if(std::filesystem::exists("configApp.ini"))
    {
        std::cout << "init config read" << std::endl;
        QSettings configApp(nameConfig, QSettings::IniFormat);

        configApp.beginGroup("IP_Configuration");
        ipAddress->setText(configApp.value("IP_Address", "").toString());
        portAddress->setText(configApp.value("Port_Address", "").toString());
        configApp.endGroup();
    }
}

void MainWindow::ConfigWriteApp()
{
    std::cout << "init config write" << std::endl;
    if(ipAddress->text() != nullptr && portAddress->text() != nullptr || ipAddress->text() != "" && portAddress->text() != "")
    {
        std::cout << "init config write" << std::endl;
        QSettings configApp(nameConfig, QSettings::IniFormat);

        configApp.beginGroup("IP_Configuration");
        configApp.setValue("IP_Address", ipAddress->text());
        configApp.setValue("Port_Address", portAddress->text());
        configApp.endGroup();
    }
}

void MainWindow::SendToServerData(const char* data)
{
    if(socketClient->state() == QTcpSocket::ConnectedState)
    {
        socketClient->write(data);
        socketClient->waitForBytesWritten(500);
        socketClient->flush();
    }
    else
    {
        std::cout << "No connection to server!" << std::endl;
    }
}



void MainWindow::disconnectedClient()
{
    std::cout << "disconnection client" << std::endl;
    socketClient->close();
}

void MainWindow::sockReady()
{
    socketClient->waitForReadyRead(1000);
    Data = socketClient->readAll();
    std::vector<std::string> data = splitElem(Data.toStdString());
    valueAntenna = data[0].c_str();
    valueRadiation = data[1].c_str();
    valueTrigger = data[2].c_str();
    editTextAntenna->setText(valueAntenna);
    editTextRadiation->setText(valueRadiation);
    if(valueTrigger == "On")
    {
        ui->pushButton_CheckBox->setCheck(true);
    }
    else
    {
        ui->pushButton_CheckBox->setCheck(false);
    }
    std::cout << Data.toStdString() << std::endl;
}

std::vector<std::string> MainWindow::splitElem(std::string elem)
{
    std::string array;
    std::vector<std::string> vector_array;
    std::stringstream elemData(elem);
    while (getline(elemData, array, ' ')) {
        vector_array.push_back(array);
    }
    return vector_array;
}

// void MainWindow::on_pushButton_2_clicked()
// {
//     std::cout << "disconnection...." << std::endl;
//     socketClient->disconnectFromHost();
// }


// void MainWindow::on_pushButton_3_clicked()
// {
//     // if(socketClient->state() == QTcpSocket::ConnectedState)
//     // {
//     //     socketClient->write("Hello server");
//     //     socketClient->waitForBytesWritten(500);
//     //     socketClient->flush();
//     // }
//     // else
//     // {
//     //     std::cout << "No connection to server!" << std::endl;
//     // }
// }


void MainWindow::on_pushButton_Enter_clicked()
{
    if(configCheckSave->isChecked() == true)
    {
        ConfigWriteApp();
    }
    socketClient->connectToHost(ipAddress->text(), portAddress->text().toInt());
    if(socketClient->state() == QTcpSocket::ConnectingState)
    {
        mainAppWidget->setVisible(true);
        enterAppWidget->setVisible(false);
    }
}


void MainWindow::on_pushButton_CheckBox_toggled(bool checked)
{
    if(checked == true)
    {
        std::cout << checked << std::endl;
        //std::string data = "ValueTrigger " + "On RLC";
        SendToServerData((std::string("ValueTrigger ") + "On RLC").c_str());
    }
    else
    {
        std::cout << checked << std::endl;
        //std::string data = "ValueTrigger " + "Off RLC";
        SendToServerData((std::string("ValueTrigger ") + "Off RLC").c_str());
    }
}


void MainWindow::on_pushButton_Antenna_clicked()
{
    std::cout << (std::string("ValueAntenna ") + editTextAntenna->text().toStdString()).c_str() << std::endl;
    SendToServerData((std::string("ValueAntenna ") + editTextAntenna->text().toStdString()).c_str());
}


void MainWindow::on_pushButton_Radiation_clicked()
{
    SendToServerData((std::string("ValueRadiation ") + editTextRadiation->text().toStdString().c_str()).c_str());
}


void MainWindow::on_pushButton_Disconnected_clicked()
{
    disconnectedClient();
    mainAppWidget->setVisible(false);
    enterAppWidget->setVisible(true);
}

