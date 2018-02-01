#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QDebug>
#include <QCompleter>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->myButton->setText("123");

    // connect(ui->myButton, &QPushButton::clicked, this, &MainWindow::close);

    // 获取内容
    QString str = ui->lineEdit->text();
    qDebug() << str;

    // 设置内容
    ui->lineEdit->setText("12345678");

    // 设置内容显示间隙
    ui->lineEdit->setTextMargins(15, 0, 0, 0);

    // 设置内容显示方式
    // ui->lineEdit->setEchoMode(QLineEdit::Password);

    QStringList list;
    list << "hello" << "How are you" << "hehe";

    QCompleter *com = new QCompleter(list, this);
    // 不区分大小写
    com->setCaseSensitivity(Qt::CaseInsensitive);

    ui->lineEdit->setCompleter(com);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_change_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex( ++i % 4);
}
