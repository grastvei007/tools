#ifndef GPIOWIDGET_H
#define GPIOWIDGET_H

#include <QWidget>
#include "indicator.h"

namespace Ui {
class GpioWidget;
}

class GpioWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GpioWidget(QWidget *parent = nullptr);
    ~GpioWidget();

private:
    Ui::GpioWidget *ui;

    Indicator *gpio_0_ = nullptr;
    Indicator *gpio_1_ = nullptr;
    Indicator *gpio_2_ = nullptr;
    Indicator *gpio_3_ = nullptr;
    Indicator *gpio_4_ = nullptr;
    Indicator *gpio_5_ = nullptr;
    Indicator *gpio_6_ = nullptr;
    Indicator *gpio_7_ = nullptr;

    Indicator *gpio_21_ = nullptr;
    Indicator *gpio_22_ = nullptr;
    Indicator *gpio_23_ = nullptr;
    Indicator *gpio_24_ = nullptr;
    Indicator *gpio_25_ = nullptr;
    Indicator *gpio_26_ = nullptr;
    Indicator *gpio_27_ = nullptr;
    Indicator *gpio_28_ = nullptr;
    Indicator *gpio_29_ = nullptr;
};

#endif // GPIOWIDGET_H
