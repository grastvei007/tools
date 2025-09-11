#include "indicator.h"

#include <QPalette>

Indicator::Indicator(const QString &tagName, QWidget *parent)
    : QWidget{parent}
    , tagName_(tagName)
{
    setGpioState(false);
}

void Indicator::setGpioState(bool isOn)
{
    QPalette p = palette();
    if (isOn)
        p.setColor(QPalette::Window, Qt::green);
    else
        p.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(p);
}
