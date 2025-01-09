#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSettings>
#include <QMessageBox>
#include <QCheckBox>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTToggleButton.h>
#include <QThread>

#include <iostream>
#include <filesystem>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpSocket* socketClient;
    QByteArray Data;
    QLineEdit* ipAddress;
    QLineEdit* portAddress;
    QCheckBox* configCheckSave;
    QWidget* mainAppWidget;
    QWidget* enterAppWidget;
    QLineEdit* editTextAntenna;
    QLineEdit* editTextRadiation;
    void ConfigReadApp();
    void ConfigWriteApp();
    void SendToServerData(const char* data);
    QString nameConfig = "configApp.ini";
    std::vector<std::string> splitElem(std::string elem);
    QString valueAntenna;
    QString valueRadiation;
    QString valueTrigger;


public slots:
    void disconnectedClient();
    void sockReady();

private slots:
    void on_pushButton_Enter_clicked();
    void on_pushButton_CheckBox_toggled(bool checked);
    void on_pushButton_Antenna_clicked();
    void on_pushButton_Radiation_clicked();
    void on_pushButton_Disconnected_clicked();
};
#endif // MAINWINDOW_H
