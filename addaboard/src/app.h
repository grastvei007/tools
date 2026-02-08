#ifndef APP_H
#define APP_H

#include <QCoreApplication>
#include <QTimer>

class App : public QCoreApplication
{
  public:
	explicit App(int argc, char *argv[]);

  protected slots:
	void read();
};

#endif // APP_H
