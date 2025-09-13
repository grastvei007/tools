#include "indicator.h"

#include <QPalette>

#include <tagsystem/tagsocket.h>

Indicator::Indicator(const QString &tagName, QWidget *parent)
    : QWidget{parent}
    , tagName_(tagName)
{
    setGpioState(false);
    tagSocket_ = TagSocket::createTagSocket("client", tagName, TagSocket::eInt);
    connect(tagSocket_,
            qOverload<int>(&TagSocket::valueChanged),
            this,
            &Indicator::onTagSocketValueChanged);
    tagSocket_->hookupTag("rpi", tagName);
}

void Indicator::onTagSocketValueChanged(int value)
{
    if (value == 0)
        setGpioState(false);
    else if (value == 1)
        setGpioState(true);
    else
        setGpioState(true); // do something other with pwm?
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
