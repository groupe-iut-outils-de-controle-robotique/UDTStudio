#ifndef WINDOWWIDGETPOPUP_H
#define WINDOWWIDGETPOPUP_H

#include <QWidget>
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QPushButton"

class WindowWidgetPopup : public QWidget
{
    Q_OBJECT

public:
    WindowWidgetPopup(int, int);

private:
    QVBoxLayout *mainx;
    QVBoxLayout *objectListLayout;
    QVBoxLayout *widgetListLayout;
    QHBoxLayout *listLayout;
    QHBoxLayout *leavingButtons;

    QPushButton *okButton;
    QPushButton *cancelButton;

};


#endif // WINDOWWIDGETPOPUP_H
