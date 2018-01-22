#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("22222");
    b.setParent(this);
    b.setText("切换到11111窗口");

    connect(&b, &QPushButton::clicked, this, &SubWidget::sendSlot);

    resize(400, 300);
}

void SubWidget::sendSlot()
{
    emit mySignal();
    emit mySignal(250, "我是子窗口");
}
