#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// For Slider Bar and Progress Bar

    connect(ui->horizontalSlider, SIGNAL(actionTriggered(int)), ui->progressBar, SLOT(update_bar()));

//    connect(ui->horizontalSlider, &QSlider::actionTriggered, ui->progressBar, &MainWindow::update_bar);

//    connect(ui->horizontalSlider, &QSlider::actionTriggered, [=](){
//        int pos = ui->horizontalSlider->sliderPosition();
//        ui->progressBar->setValue(pos);
//    });



// For button and Label

    // String Notation
//    connect(ui->button, SIGNAL(clicked()), this, SLOT(change_text_with_own_slot()));

    // Functor Notation
//    connect(ui->button, &QPushButton::clicked, this, &MainWindow::change_text_with_own_slot);

    int a = 0;
    // Functor lambda
    connect(ui->button, &QPushButton::clicked, [&](){
        ui->text->setText("IN LAMBDA");
        qDebug() << a;
        a++;
    });
    connect(ui->button, &QPushButton::clicked, [=](){
        qDebug() << a;
        qDebug() << "second lambda";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::change_text_with_own_slot(){

    int var = 0;
    qDebug() << "is it working ";
    ui->text->setText("Clicked Text" + QString::number(var));
}


void MainWindow::update_bar(){

    int pos = ui->horizontalSlider->sliderPosition();
    ui->progressBar->setValue(pos);

}
