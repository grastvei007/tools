#include "app.h"

App::App(int argc, char *argv[])
    : QApplication(argc, argv)
{
    gpioWidget = std::make_unique<GpioWidget>();
    gpioWidget->show();
}
