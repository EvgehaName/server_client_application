/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QTToggleButton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetEnterApp;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_EnterApp;
    QLabel *label_IP;
    QLineEdit *lineEdit_IP;
    QLabel *label_Port;
    QLineEdit *lineEdit_Port;
    QPushButton *pushButton_Enter;
    QCheckBox *checkBox_Config;
    QWidget *widgetMainApp;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_Antenna;
    QLineEdit *lineEdit_AntennaEnter;
    QPushButton *pushButton_Antenna;
    QLabel *label_Radiation;
    QLineEdit *lineEdit_RadiationEnter;
    QPushButton *pushButton_Radiation;
    QLabel *label_OnOffAntenna;
    QTToggleButton *pushButton_CheckBox;
    QPushButton *pushButton_Disconnected;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(598, 480);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widgetEnterApp = new QWidget(centralwidget);
        widgetEnterApp->setObjectName(QString::fromUtf8("widgetEnterApp"));
        horizontalLayout_3 = new QHBoxLayout(widgetEnterApp);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_EnterApp = new QVBoxLayout();
        verticalLayout_EnterApp->setObjectName(QString::fromUtf8("verticalLayout_EnterApp"));
        label_IP = new QLabel(widgetEnterApp);
        label_IP->setObjectName(QString::fromUtf8("label_IP"));

        verticalLayout_EnterApp->addWidget(label_IP);

        lineEdit_IP = new QLineEdit(widgetEnterApp);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));

        verticalLayout_EnterApp->addWidget(lineEdit_IP);

        label_Port = new QLabel(widgetEnterApp);
        label_Port->setObjectName(QString::fromUtf8("label_Port"));

        verticalLayout_EnterApp->addWidget(label_Port);

        lineEdit_Port = new QLineEdit(widgetEnterApp);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));

        verticalLayout_EnterApp->addWidget(lineEdit_Port);

        pushButton_Enter = new QPushButton(widgetEnterApp);
        pushButton_Enter->setObjectName(QString::fromUtf8("pushButton_Enter"));

        verticalLayout_EnterApp->addWidget(pushButton_Enter);

        checkBox_Config = new QCheckBox(widgetEnterApp);
        checkBox_Config->setObjectName(QString::fromUtf8("checkBox_Config"));

        verticalLayout_EnterApp->addWidget(checkBox_Config);


        horizontalLayout_3->addLayout(verticalLayout_EnterApp);


        horizontalLayout->addWidget(widgetEnterApp, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        widgetMainApp = new QWidget(centralwidget);
        widgetMainApp->setObjectName(QString::fromUtf8("widgetMainApp"));
        widgetMainApp->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(widgetMainApp);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_Antenna = new QLabel(widgetMainApp);
        label_Antenna->setObjectName(QString::fromUtf8("label_Antenna"));

        verticalLayout->addWidget(label_Antenna, 0, Qt::AlignHCenter);

        lineEdit_AntennaEnter = new QLineEdit(widgetMainApp);
        lineEdit_AntennaEnter->setObjectName(QString::fromUtf8("lineEdit_AntennaEnter"));

        verticalLayout->addWidget(lineEdit_AntennaEnter);

        pushButton_Antenna = new QPushButton(widgetMainApp);
        pushButton_Antenna->setObjectName(QString::fromUtf8("pushButton_Antenna"));

        verticalLayout->addWidget(pushButton_Antenna);

        label_Radiation = new QLabel(widgetMainApp);
        label_Radiation->setObjectName(QString::fromUtf8("label_Radiation"));

        verticalLayout->addWidget(label_Radiation, 0, Qt::AlignHCenter);

        lineEdit_RadiationEnter = new QLineEdit(widgetMainApp);
        lineEdit_RadiationEnter->setObjectName(QString::fromUtf8("lineEdit_RadiationEnter"));

        verticalLayout->addWidget(lineEdit_RadiationEnter);

        pushButton_Radiation = new QPushButton(widgetMainApp);
        pushButton_Radiation->setObjectName(QString::fromUtf8("pushButton_Radiation"));

        verticalLayout->addWidget(pushButton_Radiation);

        label_OnOffAntenna = new QLabel(widgetMainApp);
        label_OnOffAntenna->setObjectName(QString::fromUtf8("label_OnOffAntenna"));

        verticalLayout->addWidget(label_OnOffAntenna, 0, Qt::AlignHCenter);

        pushButton_CheckBox = new QTToggleButton(widgetMainApp);
        pushButton_CheckBox->setObjectName(QString::fromUtf8("pushButton_CheckBox"));

        verticalLayout->addWidget(pushButton_CheckBox);

        pushButton_Disconnected = new QPushButton(widgetMainApp);
        pushButton_Disconnected->setObjectName(QString::fromUtf8("pushButton_Disconnected"));

        verticalLayout->addWidget(pushButton_Disconnected);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(widgetMainApp, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 598, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_IP->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 IP \320\240\320\233\320\241", nullptr));
        label_Port->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\276\321\200\321\202 \320\240\320\233\320\241", nullptr));
        lineEdit_Port->setText(QString());
        pushButton_Enter->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
        checkBox_Config->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\321\217\321\202\321\214 \320\272\320\276\320\275\321\204\320\270\320\263?", nullptr));
        label_Antenna->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\260\320\275\321\202\320\265\320\275\320\275\321\213", nullptr));
        pushButton_Antenna->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\275\320\260 \320\240\320\233\320\241", nullptr));
        label_Radiation->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        pushButton_Radiation->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\275\320\260 \320\240\320\233\320\241", nullptr));
        label_OnOffAntenna->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265/\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\260\320\275\321\202\320\265\320\275\320\275\321\213", nullptr));
        pushButton_CheckBox->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\260\321\202\320\265\320\273\321\214", nullptr));
        pushButton_Disconnected->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217 \320\276\321\202 \320\240\320\233\320\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
