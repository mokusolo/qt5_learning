#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>

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
    QPainter p(this);
    // QPixmap 图片背景透明
    p.drawPixmap(0, 0, QPixmap(":/image/image/2.jpg"));

    // QBitmap 图片背景透明 透明处会变成黑色
    p.drawPixmap(200, 0, QBitmap(":/image/image/2.jpg"));

    // QPixmap 图片背景白色
    QPixmap pixmap;
    pixmap.load(":/image/image/2.jpg");
    p.drawPixmap(0, 200, pixmap);

    // QBitmap 图片背景白色 白色处会变成透明
    QBitmap bitmap;
    bitmap.load(":/image/image/2.jpg");
    p.drawPixmap(200, 200, bitmap);



}
