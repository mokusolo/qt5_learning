#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    timerId = this->startTimer(1000); // 毫秒为单位，每隔1s触发一次定时器
    timerId2 = this->startTimer(500);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << (char)e->key();

    if(e->key() == Qt::Key_A)
    {
        qDebug() << "Qt::Key_A";
    }
}

void MyWidget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == this->timerId)
    {
        static int sec = 0;
        ui->label->setText(QString("<center><h1>timer out: (%1)</h1></center>").arg(sec++));
        if(5 == sec)
        {
            // 停止定时器
            this->killTimer(this->timerId);
        }
    }else if(e->timerId() == this->timerId2)
    {
        static int sec = 0;
        ui->label_2->setText(QString("<center><h1>timer out: (%1)</h1></center>").arg(sec++));
    }

}
