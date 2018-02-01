#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>

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

    // QLabel设置文本内容
    ui->labelText->setText("^_^");

    // 设置图片
    ui->labelImage->setPixmap(QPixmap("://image/2.jpg"));

    // 让图片自动适应label大小
    ui->labelImage->setScaledContents(true);

    // 创建动画
    QMovie *myMovie = new QMovie(":/image/1.gif");

    // 设置动画
    ui->labelGif->setMovie(myMovie);

    // 启动动画
    myMovie->start();
    ui->labelGif->setScaledContents(true);

    // 设置html
    ui->labelUrl->setText("<h1><a href=\"https:www.baidu.com\">baidu</h1>");
    ui->labelUrl->setOpenExternalLinks(true);

    // 数码管
    // 设置内容
    ui->lcdNumber->display(123);

    // 进度条
    // 设置最小值
    ui->progressBar->setMinimum(0);
    // 设置最大值
    ui->progressBar->setMaximum(200);
    // 设置当前值
    ui->progressBar->setValue(100);

    ui->webView->load(QUrl("http://www.baidu.com"));

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
