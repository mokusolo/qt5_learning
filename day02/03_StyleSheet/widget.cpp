#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setStyleSheet("QLabel{color: rgb(0, 255, 255); "
                             "background-color: red"
                             "} ");

    ui->label->setStyleSheet("QLabel{color: rgb(0, 255, 255); "
                             "background-color: blue;"
                             "border-image:url(:/new/prefix1/image/2.jpg);"
                             "} ");
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border-image:url(:/new/prefix1/image/1.jpg);"
                                  "}"
                                  "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/image/2.jpg);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "border-image:url(:/new/prefix1/image/3.jpg);"
                                  "}"
                                  );
}

Widget::~Widget()
{
    delete ui;
}
