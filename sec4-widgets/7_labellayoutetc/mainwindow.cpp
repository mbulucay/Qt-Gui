#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->text_label, &QLabel::destroyed, [=](){

    });

    QPixmap img(":/new/prefix1/images/img.jpg");
    ui->img_label->setPixmap(img.scaled(100, 100));

}

MainWindow::~MainWindow()
{
    delete ui;
}

