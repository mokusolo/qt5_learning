#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    timerId = this->startTimer(1000); // 毫秒为单位，每隔1s触发一次定时器
    timerId2 = this->startTimer(500);

    connect(ui->pushButton, &MyButton::clicked,
            [=]()
            {
                qDebug() << "按钮被按下";
            }
            );
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

void MyWidget::mousePressEvent(QMouseEvent *)
{
    qDebug() << "++++++";
}

void MyWidget::closeEvent(QCloseEvent *e)
{
    int ret = QMessageBox::question(this, "question", "是否需要关闭窗口");
    if(ret == QMessageBox::Yes)
    {
        // 关闭窗口
        // 处理关闭窗口事件，接收事件，事件就不会再往下传递
        e->accept();
    }
    else
    {
        // 不关闭窗口
        // 忽略事件，事件继续给父组件传递
        e->ignore();
    }
}
