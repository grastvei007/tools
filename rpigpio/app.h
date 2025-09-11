#ifndef APP_H
#define APP_H

#include <memory>

#include <QApplication>

#include "gui/gpiowidget.h"

class App : public QApplication
{
    Q_OBJECT
public:
    App(int argc, char *argv[]);

private:
    std::unique_ptr<GpioWidget> gpioWidget;
};

#endif // APP_H
