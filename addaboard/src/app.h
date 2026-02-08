#ifndef APP_H
#define APP_H

#include <QCoreApplication>
#include <QTimer>

#include <tagsystem/tag.h>

class App : public QCoreApplication
{
  public:
	explicit App(int argc, char *argv[]);

  protected slots:
	void read();

  private:
	Tag *adc1Tag_ = nullptr;
};

#endif // APP_H
