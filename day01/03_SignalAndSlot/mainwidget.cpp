#include "mainwidget.h"

#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100, 100);

    b2 = new QPushButton(this);
    b2->setText("abc");

    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
    /* &b1：信号发出者，指针类型
     * &QPushButton::pressed：处理的信号， &发送者的类名::信号名字
     * this：信号接收者
     * &MainWidget::close 槽函数，信号处理函数，   &接收的类名::槽函数名字
     */

    /* 自定义槽，普通函数的用法
     * Qt5:任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数，返回值）
     * 由于信号都是没有返回值，所以槽函数一定没有返回值
     */

     connect(b2, &QPushButton::released, this, &MainWidget::myslot);

     connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

     /* 信号：短信
      * 槽函数：接收短信的手机
      */

     setWindowTitle("11111");
     // this.setWindowTitle("11111");

     b3.setParent(this);
     b3.setText("切换到22222窗口");
     b3.move(50, 50);

     // 显示子窗口
     // w.show();

     connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);

     // 处理子窗口的信号
//     void(SubWidget::*funSignal)() = &SubWidget::mySignal;
//     connect(&subWin, funSignal, this, &MainWidget::dealSub);
//     void(SubWidget::*testSignal)(int, QString) = &SubWidget::mySignal;
//     connect(&subWin, testSignal, this, &MainWidget::dealSlot);

    // Qt4信号连接
    // Qt4槽函数必须有slots关键字来修饰
    connect(&subWin, SIGNAL(mySignal()), this, SLOT(dealSub()));
    connect(&subWin, SIGNAL(mySignal(int,QString)), this, SLOT(dealSlot(int,QString)));

    // SIGNAL SLOT 将函数名字 -> 字符串 不进行错误检查

    // Lambda表达式，匿名函数对象
    // C++增加的新特性，项目文件： CONFIG += C++11
    // Qt配合信号一起使用，非常方便

    QPushButton *b4 = new QPushButton(this);
    b4->setText("Lambda表达式");
    b4->move(150, 150);

    int a = 10, b = 100;
    connect(b4, &QPushButton::released,
            // = ：把外部所有局部变量 类中所有成员以值传递方式传递
            // this ：类中所有成员以值传递方式传递
            // & ：把外部所有局部变量，引用符号
            [=]() mutable
            {
                b4->setText("123321");
                qDebug() << "11111";
                qDebug() << a << b;
                // 没有mutable的话a就是只可读不可写
                a = 11;
            }
            );

    resize(400, 300);
}

void MainWidget::myslot()
{
    b2->setText("123");
}

void MainWidget::changeWin()
{
    // 子窗口显示
    subWin.show();
    // 本窗口隐藏
    this->close();
}

void MainWidget::dealSub()
{
    // 子窗口隐藏
    subWin.close();
    // 本窗口显示
    show();
}

void MainWidget::dealSlot(int a, QString b)
{
    // b.toUtf8() -> 字节数组QByteArray
    // ...data() -> QByteArray -> char*
    qDebug() << a << b.toUtf8().data() << endl;
}

MainWidget::~MainWidget()
{

}
