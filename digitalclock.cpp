#include "digitalclock.h"
#include "ui_digitalclock.h"
#include <QTimer>
#include <QTime>

DigitalClock::DigitalClock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DigitalClock)
{
    ui->setupUi(this);

    ui->lcdNumber->setSegmentStyle(QLCDNumber::Filled);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
    timer->start(1000);

    showTime();

    setWindowTitle(tr("Digital Clock"));
    resize(150, 60);
}

DigitalClock::~DigitalClock()
{
    delete ui;
}

void DigitalClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);
}

