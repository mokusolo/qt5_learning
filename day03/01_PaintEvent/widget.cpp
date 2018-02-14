#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    // QPainter p(this);

    QPainter p; // 创建画家对象
    p.begin(this); // 指定当前窗口为绘图设备
    // 绘图操作
    // p.drawxxx();
    // 画背景图
    // p.drawPixmap(0, 0, width(), height(), QPixmap("../image/2.jpg"));
    p.drawPixmap(rect(), QPixmap("../image/2.jpg"));

    // 定义画笔
    QPen pen;
    pen.setWidth(5); // 设置线宽
    // pen.setColor(Qt::red); // 设置颜色
    pen.setColor(QColor(14, 9, 234)); // rgb设置颜色
    pen.setStyle(Qt::DashLine); // 设置风格

    // 把画笔交给画家
    p.setPen(pen);

    // 画直线
    p.drawLine(50, 50, 150, 50);
    p.drawLine(50, 50, 50, 150 );

    // 创建画刷对象
    QBrush brush;
    brush.setColor(Qt::red); // 设置颜色
    brush.setStyle(Qt::Dense1Pattern); // 设置样式

    // 把画刷交给画家
    p.setBrush(brush);

    // 画矩形
    p.drawRect(150, 150, 100, 50);

    // 画圆形
    p.drawEllipse(QPoint(150, 150), 50, 25);

    p.end();
}
