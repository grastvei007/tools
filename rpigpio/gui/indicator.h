#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QString>

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(const QString& tagName, QWidget *parent = nullptr);

signals:

private:
    void setGpioState(bool isOn);
    QString tagName_;
};

#endif // INDICATOR_H
