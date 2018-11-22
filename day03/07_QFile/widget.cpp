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

void Widget::on_buttonWrite_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "Save", "../", "TXT(*.txt)");
    if (path.isEmpty() == false)
    {
        // 创建文件对象
        QFile file;
        // 关联文件名字
        file.setFileName(path);

        // 打开文件，只写方法
        bool isOK = file.open(QIODevice::WriteOnly);
        if (isOK == true)
        {
            // 获取编辑区内容
            QString str = ui->textEdit->toPlainText();
            // 写文件

            // QString -> QByteArray
            // file.write(str.toUtf8());

            // QString -> c++ string -> char *
            // file.write(str.toStdString().data());

            // 转换为本地平台编码 如ANSI
            file.write(str.toLocal8Bit());

            // QString -> QByteArray
            QString abc = "123";
            QByteArray a = abc.toUtf8(); // 中文，要中文必须utf8
            a = abc.toLocal8Bit(); // 本地编码

            // QByteArray -> char *
            char *b = a.data();

            // char * -> QString
            char *p = "abc";
            QString c = QString(p);
        }
        file.close();

    }

}
