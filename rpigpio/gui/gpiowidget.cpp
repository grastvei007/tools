#include "gpiowidget.h"
#include "ui_gpiowidget.h"

GpioWidget::GpioWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GpioWidget)
{
    ui->setupUi(this);

    gpio_0_ = new Indicator("gpio_0", ui->indicator_0);
    gpio_1_ = new Indicator("gpio_1", ui->indicator_1);
    gpio_2_ = new Indicator("gpio_2", ui->indicator_2);
    gpio_3_ = new Indicator("gpio_3", ui->indicator_3);
    gpio_4_ = new Indicator("gpio_4", ui->indicator_4);
    gpio_5_ = new Indicator("gpio_5", ui->indicator_5);
    gpio_6_ = new Indicator("gpio_6", ui->indicator_6);
    gpio_7_ = new Indicator("gpio_7", ui->indicator_7);

    gpio_21_ = new Indicator("gpio_21", ui->indicator_21);
    gpio_22_ = new Indicator("gpio_22", ui->indicator_22);
    gpio_23_ = new Indicator("gpio_23", ui->indicator_23);
    gpio_24_ = new Indicator("gpio_24", ui->indicator_24);
    gpio_25_ = new Indicator("gpio_25", ui->indicator_25);
    gpio_26_ = new Indicator("gpio_26", ui->indicator_26);
    gpio_27_ = new Indicator("gpio_27", ui->indicator_27);
    gpio_28_ = new Indicator("gpio_28", ui->indicator_28);
    gpio_29_ = new Indicator("gpio_29", ui->indicator_29);
}

GpioWidget::~GpioWidget()
{
    delete ui;
}
