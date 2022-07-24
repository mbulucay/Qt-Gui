#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(nullptr));
    randomNumber = rand() % 100 + 1;
    counter = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GuessButton_clicked()
{
    int guessNumber = ui->Input->text().toInt();

    if(guessNumber == randomNumber){
        ui->Message->setText(QString("Congratulations! You find the correct Number"));
        ui->GuessButton->setDisabled(true);
    }
    else if(guessNumber < randomNumber){
        ui->Message->setText(QString("The Number bigger than that"));
    }
    else{
        ui->Message->setText(QString("The Number lower than that"));
    }
    ui->Counter->setText(QString::number(counter++));
}


void MainWindow::on_RestartButton_clicked()
{
    randomNumber = rand() % 100 + 1;
    ui->Message->setText(QString("Random number Regenerated"));
}

