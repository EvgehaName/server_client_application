#ifndef QTToggleButton_H
#define QTToggleButton_H

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class QTToggleButton : public QPushButton
{
public:
    QTToggleButton(QWidget* parent = nullptr);
    void setTextToggle(QString textOnToggle, QString textOffToggle);
    void setPixmapToggle(QString pathPixmapOn, QString pathPixmapOff);
    void setCheck(bool cheked);

protected:
    virtual void mousePressEvent(QMouseEvent* event);

private:
    // Load Pixmap Icons Button
    void loadPixmap();
    // Text Button Toggle
    QString textOnButton;
    QString textOffButton;
    // Label (Icons) Image
    QLabel *iconsOff = new QLabel();
    QLabel *iconsOn = new QLabel();

    QString pathPixampToggleOn;
    QString pathPixampToggleOff;

};

#endif // QTToggleButton_H
