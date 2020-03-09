#ifndef WIDGETGESTIONVITESSEBOUTON_H
#define WIDGETGESTIONVITESSEBOUTON_H

#include <QWidget>
#include "QPushButton"
#include "QLabel"

class WidgetGestionVitesseBouton : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int pas READ getPas WRITE setPas NOTIFY pasChanged)

public:
    WidgetGestionVitesseBouton();
    int getPas() const{ return pas; }


public slots :
    void setPas(int value)
    {
        if (pas == value)
            return;

        pas = value;
        emit pasChanged(pas);
    }
    void increment();
    void decrement();

signals:
    void pasChanged(int pas);

private:
    QWidget *w;
    QLayout *layPrinc;
    QPushButton *boutonMoins;
    QPushButton *boutonPlus;
    QLabel *labelAffich;
    int pas=0;
};

#endif // WIDGETGESTIONVITESSEBOUTON_H
