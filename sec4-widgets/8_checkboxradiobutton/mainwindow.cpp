#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QButtonGroup * bg = new QButtonGroup(this);
    bg->addButton(ui->checkBox);
    bg->addButton(ui->checkBox_2);
    bg->addButton(ui->checkBox_3);

    bg->setExclusive(true);
    ui->checkBox_3->setChecked(true);

    int a = bg->checkedId();
    qDebug() << a << " the one checked";

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_2_toggled(bool checked)
{
    if(checked){
        qDebug() << "Linux normal checked";
    }else{
        qDebug() << "Linux normal unununchecked onether must be selected";
    }
}

void MainWindow::on_checkBox_7_toggled(bool checked)
{
    if(checked){
        qDebug() << "KAvurma normal checked";
    }else{
        qDebug() << "KAvurma normal unununchecked";
    }
}


void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked){
        qDebug() << "selected a radio button";
    }else{
        qDebug() << "unselect before and select a new one";
    }
}

void MainWindow::on_pushButton_clicked()
{

}

