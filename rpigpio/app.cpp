#include "app.h"

#include <tagsystem/taglist.h>

App::App(int argc, char *argv[])
    : QApplication(argc, argv)
{
    TagList::sGetInstance().setClientName("RasberryPi_Gpio_widget");
    TagList::sGetInstance().connectToServer("127.0.0.1", 5000);

    gpioWidget = std::make_unique<GpioWidget>();
    gpioWidget->show();
}
