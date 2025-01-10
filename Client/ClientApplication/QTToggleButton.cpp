#include "QTToggleButton.h"

QTToggleButton::QTToggleButton(QWidget* parent) : QPushButton(parent)
{
    QAbstractButton::setCheckable(true);
    QPushButton::setMinimumSize(170,70);

    QVBoxLayout *layout = new QVBoxLayout(parent);

    if(pathPixampToggleOn == nullptr || pathPixampToggleOff == nullptr)
    {
        loadPixmap();
    }

    layout->addWidget(iconsOff);
    layout->addWidget(iconsOn);
    setLayout(layout);
}

void QTToggleButton::setTextToggle(QString textOnToggle, QString textOffToggle)
{
    textOnButton = textOnToggle == nullptr ? "ON" : textOnToggle;
    textOffButton = textOffToggle == nullptr ? "OFF" : textOffToggle;
}

void QTToggleButton::setPixmapToggle(QString pathPixmapOn, QString pathPixmapOff)
{
    pathPixampToggleOn = pathPixmapOn;
    pathPixampToggleOff = pathPixmapOff;
    loadPixmap();
}

void QTToggleButton::setCheck(bool cheked)
{
    if(QAbstractButton::isChecked() == false)
    {
        QAbstractButton::setText(this->textOnButton);
        iconsOn->setEnabled(true);
        iconsOff->setEnabled(false);
        QAbstractButton::setChecked(true);
    }
    else
    {
        QAbstractButton::setText(this->textOffButton);
        iconsOn->setEnabled(false);
        iconsOff->setEnabled(true);
        QAbstractButton::setChecked(false);
    }
}

void QTToggleButton::mousePressEvent(QMouseEvent *event)
{
    QAbstractButton::mousePressEvent(event);
    if(QAbstractButton::isChecked() == false)
    {
        QAbstractButton::setText(this->textOnButton);
        iconsOn->setEnabled(true);
        iconsOff->setEnabled(false);
    }
    else
    {
        QAbstractButton::setText(this->textOffButton);
        iconsOn->setEnabled(false);
        iconsOff->setEnabled(true);
    }
}

void QTToggleButton::loadPixmap()
{
    QPixmap pixmapToggleOn(pathPixampToggleOn == nullptr ?  ":resources/images/green.png" : pathPixampToggleOn);
    iconsOn->setPixmap(pixmapToggleOn);
    iconsOn->setGeometry(15,15,30,30);
    iconsOn->setMaximumSize(30,30);
    iconsOn->setScaledContents(true);
    iconsOn->setEnabled(false);

    QPixmap pixampToggleOff(pathPixampToggleOff == nullptr ?  ":resources/images/red.png" : pathPixampToggleOff);
    iconsOff->setPixmap(pixampToggleOff);
    iconsOff->setGeometry(15,15,30,30);
    iconsOff->setMaximumSize(30,30);
    iconsOff->setScaledContents(true);
    iconsOff->setEnabled(false);
}


