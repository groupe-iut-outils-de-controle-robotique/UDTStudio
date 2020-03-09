#ifndef APPWIDGET_H
#define APPWIDGET_H

#include "QBoxLayout"
#include "QPushButton"


class AppWidget : public QWidget
{
    Q_OBJECT

public:
    AppWidget(int, int);

private:
    QHBoxLayout* mainx;
    QVBoxLayout* widgetTable;
    QPushButton* pushAddWidget;

public slots:
    void openPopup();
};

#endif // APPWIDGET_H
