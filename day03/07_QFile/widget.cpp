#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>

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

void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Open", "../", "TXT(*.txt)");
    if (path.isEmpty() == false)
    {
        // 文件对象
        QFile file(path);

        // 打开文件，只读方式
        bool isOK = file.open(QIODevice::ReadOnly);
        if (isOK == true)
        {
#if 0
            // 读文件，默认只识别utf8编码
            QByteArray array = file.readAll();
            // 显示到编辑区
            // ui->textEdit->setText(QString(array));
            ui->textEdit->setText(array);
#endif

            QByteArray array;
            while (file.atEnd() == false)
            {
                // 读一行
                array += file.readLine();
            }
            ui->textEdit->setText(array);

        }

        // 关闭文件
        file.close();
    }
}
