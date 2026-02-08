#include "app.h"

#include "ADS1256.h"
#include "stdio.h"
#include <signal.h> //signal()
#include <stdlib.h> //exit()
#include <time.h>

#include <string.h>

#include <tagsystem/taglist.h>

void Handler(int signo)
{
	//System Exit
	printf("\r\nEND                  \r\n");
	DEV_ModuleExit();

	exit(0);
}

App::App(int argc, char *argv[])
	: QCoreApplication(argc, argv)
{
	TagList::sGetInstance().setClientName("adc");
	TagList::sGetInstance().connectToServer("localhost", 5000);
	connect(&TagList::sGetInstance(), &TagList::connected, this, [this]() {
		adc0Tag_ = TagList::sGetInstance().createTag("adda", "adc0", TagType::eDouble, 0.0);
		adc1Tag_ = TagList::sGetInstance().createTag("adda", "adc1", TagType::eDouble, 0.0);
		adc2Tag_ = TagList::sGetInstance().createTag("adda", "adc2", TagType::eDouble, 0.0);
		adc3Tag_ = TagList::sGetInstance().createTag("adda", "adc3", TagType::eDouble, 0.0);
		adc4Tag_ = TagList::sGetInstance().createTag("adda", "adc4", TagType::eDouble, 0.0);
		adc5Tag_ = TagList::sGetInstance().createTag("adda", "adc5", TagType::eDouble, 0.0);
		adc6Tag_ = TagList::sGetInstance().createTag("adda", "adc6", TagType::eDouble, 0.0);
		adc7Tag_ = TagList::sGetInstance().createTag("adda", "adc7", TagType::eDouble, 0.0);
	});

	printf("demo\r\n");
	DEV_ModuleInit();

	// Exception handling:ctrl + c
	signal(SIGINT, Handler);

	if (ADS1256_init() == 1)
	{
		printf("\r\nEND                  \r\n");
		DEV_ModuleExit();
		exit(0);
	}

	QTimer *timer = new QTimer(this);
	timer->setInterval(1000);
	connect(timer, &QTimer::timeout, this, &App::read);
	timer->start();
	//return 0;
}

void App::read()
{
	UDOUBLE ADC[8], i;
	ADS1256_GetAll(ADC);
	/*for (i = 0; i < 8; i++)
	{
		printf("%d %f\r\n", i, ADC[i] * 5.0 / 0x7fffff);
	}
	printf("\33[8A"); //Move the cursor up 8 lines
    */

	if (adc0Tag_)
		adc0Tag_->setValue((double(ADC[0] * 5.0 / 0x7fffff)));
	if (adc1Tag_)
		adc1Tag_->setValue((double(ADC[1] * 5.0 / 0x7fffff)));
	if (adc2Tag_)
		adc2Tag_->setValue((double(ADC[2] * 5.0 / 0x7fffff)));
	if (adc3Tag_)
		adc3Tag_->setValue((double(ADC[3] * 5.0 / 0x7fffff)));
	if (adc4Tag_)
		adc4Tag_->setValue((double(ADC[4] * 5.0 / 0x7fffff)));
	if (adc5Tag_)
		adc5Tag_->setValue((double(ADC[5] * 5.0 / 0x7fffff)));
	if (adc6Tag_)
		adc6Tag_->setValue((double(ADC[6] * 5.0 / 0x7fffff)));
	if (adc7Tag_)
		adc7Tag_->setValue((double(ADC[7] * 5.0 / 0x7fffff)));
}
