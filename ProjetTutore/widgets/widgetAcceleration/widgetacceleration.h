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

private:
    QWidget* lafenetre;
    QVBoxLayout* mainx;
    QHBoxLayout* subMainx;
    QPushButton* valid;
    QSpinBox* timeValue;
    QLineEdit* speedValue;


public:
    WidgetAcceleration(int, int);

};

#endif // WIDGETACCELERATION_H
