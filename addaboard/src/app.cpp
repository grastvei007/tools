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
		adc1Tag_ = TagList::sGetInstance().createTag("adda", "adc1", TagType::eDouble, 0.0);
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
	for (i = 0; i < 8; i++)
	{
		printf("%d %f\r\n", i, ADC[i] * 5.0 / 0x7fffff);
	}
	printf("\33[8A"); //Move the cursor up 8 lines

	if (adc1Tag_)
		adc1Tag_->setValue((double(ADC[1] * 5.0 / 0x7fffff)));
}
