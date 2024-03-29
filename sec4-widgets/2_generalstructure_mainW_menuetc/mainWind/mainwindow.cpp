﻿#include "mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QPushButton * pb = new QPushButton("BTTN", this);
    setCentralWidget(pb);

    QMenu* fileMenu = menuBar()->addMenu("File");

    QAction* action1 = new QAction("Quit");
    fileMenu->addAction(action1);

    connect(action1, &QAction::triggered, [=](){
        QApplication::quit();
    });


    QMenu* editMenu = menuBar()->addMenu("Edit");

    editMenu->addAction("edit 1");
    editMenu->addAction("edit 2");
    editMenu->addAction("edit 3");


    QMenu* settingMenu = menuBar()->addMenu("Setting");

    QAction* action2 = new QAction("deneme");
    settingMenu->addAction(action2);


    menuBar()->addMenu("View");
    menuBar()->addMenu("Help");
    menuBar()->addMenu("About");

    statusBar()->showMessage("Uploading File or Someting else.. .... . .", 2000); // delay 2000 ms
    //statusBar()->clearMessage();

    connect(action2, SIGNAL(triggered()), this, SLOT(printSlot()));

    //setFixedHeight(150);
    //setFixedWidth(600);
}

MainWindow::~MainWindow()
{ }

void MainWindow::printSlot(){
    qDebug() << "aksdlasdlakjsdlksajd";
}

QSize MainWindow::sizeHint() const{
    return QSize(750, 250);
}
