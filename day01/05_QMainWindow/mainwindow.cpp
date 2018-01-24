#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 菜单
    QMenuBar *mBar = menuBar();

    // 添加菜单
    QMenu *pFile = mBar->addMenu("文件");

    // 添加菜单项，添加动作
    QAction *pNew = pFile->addAction("新建");
    connect(pNew, &QAction::triggered,
            []()
            {
                qDebug() << "新建被按下";
            }
            );
    // 添加分割线
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("打开");

    // 工具栏，菜单项的快捷方式
    QToolBar *toolBar = addToolBar("toolBar");
    // 工具栏添加快捷键
    toolBar->addAction(pNew);

    QPushButton *b = new QPushButton(this);
    b->setText("^_^");
    // 添加小控件
    toolBar->addWidget(b);
    connect(b, &QPushButton::clicked,
            [=]()
            {
                b->setText("@_@");
            }
            );

    // 状态栏
    // 核心控件
    // 浮动窗口
}

MainWindow::~MainWindow()
{

}
