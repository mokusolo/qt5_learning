#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);
    QMenu *menu = mBar->addMenu("对话框");
    QAction *p1 = menu->addAction("模态对话框");

    connect(p1, &QAction::triggered,
            [=]()
            {
                QDialog dlg;
                dlg.exec();
                qDebug() << "11111";
            }

            );

    QAction *p2 = menu->addAction("非模态对话框");

    connect(p2, &QAction::triggered,
            [=]()
            {
//                dlg.show();
//                qDebug() << "11111";

//                QDialog *p = new QDialog(this);
//                p->show();

                QDialog *p = new QDialog;
                p->setAttribute(Qt::WA_DeleteOnClose);
                p->show();
            }

            );


}

MainWindow::~MainWindow()
{

}
