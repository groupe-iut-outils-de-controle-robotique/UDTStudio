#ifndef WIDGETVITESSESPINBOX_H
#define WIDGETVITESSESPINBOX_H

#include <QMainWindow>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>

class WidgetVitesseSpinbox : public QMainWindow
{
    Q_OBJECT

public:
    WidgetVitesseSpinbox(int,int);

private:
    QWidget* lafenetre;
    QVBoxLayout* mainx;
    QHBoxLayout* subMainx;
    QPushButton* minus;
    QPushButton* plus;
    QLineEdit* step;
};

#endif // WIDGETVITESSESPINBOX_H
