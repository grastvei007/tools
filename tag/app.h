#ifndef APP_H
#define APP_H

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QRestAccessManager>
#include <QNetworkRequestFactory>

class App : public QCoreApplication
{
public:
    App(int argc, char *argv[]);

private:
    void createTag(const QString &subsystem, const QString &name, const QString &type, const QString &value);
    void updateTag(const QString &subsystem, const QString &name, const QString &value);

    QNetworkAccessManager nasb_;
    std::shared_ptr<QRestAccessManager> nas_;
    std::shared_ptr<QNetworkRequestFactory> api_;
};

#endif // APP_H
