#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton("^_^", this);
    button->setGeometry(100, 100, 200, 200);

    // qt4用法
    // connect(button, SIGNAL(clicked(bool)), this, SLOT(close()) );

    // qt5
    // connect(button, &QPushButton::clicked, this, &Widget::close);

    connect(button, &QPushButton::clicked,
            [=]()
            {
                button->setText("123");
            }
            );
}

Widget::~Widget()
{

}
