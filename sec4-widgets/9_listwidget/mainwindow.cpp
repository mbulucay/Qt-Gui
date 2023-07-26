#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>
#include <QAbstractItemView>
#include <QListWidgetItem>
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->addItem("My added button item");
}


void MainWindow::on_pushButton_clicked()
{
//    ui->listWidget->takeItem(ui->listWidget->currentRow());

    QList<QListWidgetItem *> list = ui->listWidget->selectedItems();

    for (int i = 0; i< list.count(); ++i){
        qDebug() << QString::number(i) << list.at(i)->text() << " row id" << ui->listWidget->row(list.at(i));
        ui->listWidget->takeItem(ui->listWidget->row(list.at(i)));
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    QList<QListWidgetItem *> list = ui->listWidget->selectedItems();

    for (int i = 0; i< list.count(); ++i){
        qDebug() << QString::number(i) << list.at(i)->text() << " row id" << ui->listWidget->row(list.at(i));
    }
}

