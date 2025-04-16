#include "app.h"

#include <QCommandLineParser>
#include <QDebug>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QRestReply>

#include <tagsystem/tag.h>

App::App(int argc, char *argv[]) : QCoreApplication(argc, argv)
{
    nas_ = std::make_shared<QRestAccessManager>(&nasb_);
    api_ = std::make_shared<QNetworkRequestFactory>();
    api_->setBaseUrl(QUrl("http://localhost:5005/api"));

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addPositionalArgument("create", "create a tag");
    parser.addPositionalArgument("update", "update value on a tag");

    auto subsystemOption = QCommandLineOption("subsystem", "The subsystem for the tag", "subsystem");
    auto typeOption = QCommandLineOption("type", "The tag type [bool, int, double, string]", "type");
    auto nameOption = QCommandLineOption("name", "The tag name", "name");
    auto valueOption = QCommandLineOption("value", "The tag value", "value");

    parser.addOption(subsystemOption);
    parser.addOption(nameOption);
    parser.addOption(typeOption);
    parser.addOption(valueOption);

    parser.process(*this);

    const QStringList args = parser.positionalArguments();

    QString subsystem = parser.value(subsystemOption);
    QString name = parser.value(nameOption);
    QString value = parser.value(valueOption);
    QString type = parser.value(typeOption);

    if(args.contains("create"))
    {
        createTag(subsystem, name, type, value);
    }
    else if(args.contains("update"))
    {
        updateTag(subsystem, name, value);
    }
    else
        exit();
}

void App::createTag(const QString &subsystem,
                    const QString &name,
                    const QString &type,
                    const QString &value)
{
    QJsonObject obj;

    if(!type.isEmpty())
    {
        qDebug() << "Type: " << type;
        auto tagType = Tag::typeFromString(type);
        if(tagType == Tag::eUnknown)
        {
            qDebug() << "Invalid tag type";
            exit();
        }
        obj.insert("type", Tag::toString(tagType));
    }
    if(!subsystem.isEmpty())
        obj.insert("subsystem", subsystem);
    if(!name.isEmpty())
        obj.insert("name", name);
    if(!value.isEmpty())
        obj.insert("value", value);

    QJsonDocument doc(obj);
    nas_->post(api_->createRequest("/tag/create"), doc, this, [](QRestReply &reply)
    {
        qDebug() << reply.readBody();
        qDebug() << reply.errorString();
        exit();
    });
}

void App::updateTag(const QString &subsystem, const QString &name, const QString &value)
{
    QJsonObject obj;
    if(!subsystem.isEmpty())
        obj.insert("subsystem", subsystem);
    if(!name.isEmpty())
        obj.insert("name", name);
    if(!value.isEmpty())
        obj.insert("value", value);

    QJsonDocument doc(obj);
    nas_->post(api_->createRequest("/tag/update"), doc, this, [](QRestReply &reply)
   {
       qDebug() << reply.readBody();
       qDebug() << reply.errorString();
       exit();
   });
}
