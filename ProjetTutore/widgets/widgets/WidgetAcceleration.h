#ifndef WIDGETACCELERATION_H
#define WIDGETACCELERATION_H

#include <QWidget>
#include <QBoxLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>


class WidgetAcceleration : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int vitesseVoulu READ getVitesse WRITE setVitesse NOTIFY vitesseChanged)
    Q_PROPERTY(int tempsVoulu READ getTemps WRITE setTemps NOTIFY tempsChanged)

public slots :
    void setVitesse(int value)
    {
        if (vitesseVoulu == value)
            return;

        vitesseVoulu = value;
        emit vitesseChanged(vitesseVoulu);
    }
    void setTemps(int value)
    {
        if (tempsVoulu == value)
            return;

        tempsVoulu = value;
        emit tempsChanged(tempsVoulu);
    }

signals:
    void vitesseChanged(int vitesseVoulu);
    void tempsChanged(int tempsVoulu);

private:
    QVBoxLayout* mainx;
    QHBoxLayout* subMainx;
    QPushButton* valid;
    QSpinBox* timeValue;
    QLineEdit* speedValue;

    QWidget *w;
    QLayout *layPrinc;
    int vitesseVoulu=0;
    int tempsVoulu=0;

public:
    WidgetAcceleration(int vitesse);
    int getVitesse() const{ return vitesseVoulu; }
    int getTemps() const{ return tempsVoulu; }

    //TypeWid getTypeAccepter() const{ return acceleration; }

};

#endif // WIDGETACCELERATION_H
