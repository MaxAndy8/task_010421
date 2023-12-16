#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class DigitalClock; }
QT_END_NAMESPACE

class DigitalClock : public QWidget
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);
    ~DigitalClock();

private:
    Ui::DigitalClock *ui;

private slots:
    void showTime();


};
#endif // DIGITALCLOCK_H
