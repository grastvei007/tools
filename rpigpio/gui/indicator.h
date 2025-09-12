#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QString>

class TagSocket;

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(const QString& tagName, QWidget *parent = nullptr);

signals:

private slots:
    void onTagSocketValueChanged(int value);

private:
    void setGpioState(bool isOn);
    QString tagName_;
    TagSocket* tagSocket_ = nullptr;
};

#endif // INDICATOR_H
