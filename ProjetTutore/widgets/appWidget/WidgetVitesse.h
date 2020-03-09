#ifndef WIDGETVITESSE_H
#define WIDGETVITESSE_H

#include <QWidget>
#include "QLabel"
#include "QComboBox"

class WidgetVitesse : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int vitesse READ getVitesse WRITE setVitesse NOTIFY vitesseChanged)

public:
    WidgetVitesse();
    int getVitesse() const{ return vitesse; }

public slots :
    void setVitesse(int value)
    {
        if (vitesse == value)
            return;

        vitesse = value;
        emit vitesseChanged(vitesse);
    }
    void changeVitesse(int index);

signals:
    void vitesseChanged(int vitesse);

private:
    QWidget *w;
    QLayout *layPrinc;
    QLabel *labelAffich;
    QComboBox *comboBoxListe;
    QLabel *labelVitesse;
    QStringList myOptions;
    int vitesse=3600;
};

#endif // WIDGETVITESSE_H
