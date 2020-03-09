#ifndef WIDGETALLUMERETEINDREMOTEUR_H
#define WIDGETALLUMERETEINDREMOTEUR_H

#include <QWidget>
#include "QLabel"
#include "QRadioButton"

class WidgetAllumerEteindreMoteur : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool onOff READ getEtat WRITE setEtat NOTIFY etatChanged)

public:
    WidgetAllumerEteindreMoteur(bool);
    bool getEtat() const{ return onOff; }

public slots :
    void switchEtat();
    void setEtat(bool value)
    {
        onOff = value;
        emit etatChanged(onOff);
    }

signals:
    void etatChanged(bool onOff);

private:
    QLayout *layPrinc;
    QLabel *labelOnOff;
    QRadioButton *boutonOnOff;
    bool onOff=false;
};

#endif // WIDGETALLUMERETEINDREMOTEUR_H
