#include "gpiowidget.h"
#include "ui_gpiowidget.h"

GpioWidget::GpioWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GpioWidget)
{
    ui->setupUi(this);

    gpio_0_ = new Indicator("gpio_0_out", ui->indicator_0);
    gpio_1_ = new Indicator("gpio_1_out", ui->indicator_1);
    gpio_2_ = new Indicator("gpio_2_out", ui->indicator_2);
    gpio_3_ = new Indicator("gpio_3_out", ui->indicator_3);
    gpio_4_ = new Indicator("gpio_4_out", ui->indicator_4);
    gpio_5_ = new Indicator("gpio_5_out", ui->indicator_5);
    gpio_6_ = new Indicator("gpio_6_out", ui->indicator_6);
    gpio_7_ = new Indicator("gpio_7_out", ui->indicator_7);

    gpio_21_ = new Indicator("gpio_21_out", ui->indicator_21);
    gpio_22_ = new Indicator("gpio_22_out", ui->indicator_22);
    gpio_23_ = new Indicator("gpio_23_out", ui->indicator_23);
    gpio_24_ = new Indicator("gpio_24_out", ui->indicator_24);
    gpio_25_ = new Indicator("gpio_25_out", ui->indicator_25);
    gpio_26_ = new Indicator("gpio_26_out", ui->indicator_26);
    gpio_27_ = new Indicator("gpio_27_out", ui->indicator_27);
    gpio_28_ = new Indicator("gpio_28_out", ui->indicator_28);
    gpio_29_ = new Indicator("gpio_29_out", ui->indicator_29);
}

GpioWidget::~GpioWidget()
{
    delete ui;
}
