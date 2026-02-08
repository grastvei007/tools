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
	Tag *adc0Tag_ = nullptr;
	Tag *adc1Tag_ = nullptr;
	Tag *adc2Tag_ = nullptr;
	Tag *adc3Tag_ = nullptr;
	Tag *adc4Tag_ = nullptr;
	Tag *adc5Tag_ = nullptr;
	Tag *adc6Tag_ = nullptr;
	Tag *adc7Tag_ = nullptr;
};

#endif // APP_H
