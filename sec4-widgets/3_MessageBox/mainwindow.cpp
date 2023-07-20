#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    auto
//    std::shared_ptr<QPushButton> button = std::make_shared<QPushButton>(this);
    QPushButton * button = new QPushButton(this);
    button->setText("Click11 !");
    button->move(110, 110);
    connect(button, &QPushButton::clicked, [=](){
        qDebug() << "alaaaaaaaaaaaaaaaaaa";

        QMessageBox message;
        message.setWindowTitle("This is message title");
        message.setMinimumSize(300, 300);
        message.setText("You clicked");
        message.setInformativeText("Hacking started, you have done");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::Discard | QMessageBox::YesToAll | QMessageBox::Reset | QMessageBox::Apply);
        message.setDefaultButton(QMessageBox::Cancel);

        int ret = message.exec();

        if (ret == QMessageBox::Ok){
            qDebug() << "You accept the hacking";
        }else{
            qDebug() << "You did not accept the hacking but anyway ...";
        }

    });


    QPushButton * button2 = new QPushButton(this);
    button2->setText("Click22 !");
    button2->move(110, 310);
    connect(button2, &QPushButton::clicked, [=](){
        qDebug() << "alaaaa22222222222";

        int ret;
        // critical, information, question, warning
//        ret = QMessageBox::critical(this, "Title", "Text text text", QMessageBox::Abort | QMessageBox::Discard | QMessageBox::YesToAll | QMessageBox::Reset | QMessageBox::Apply);
//        ret = QMessageBox::information(this, "Title", "Text text text", QMessageBox::Abort | QMessageBox::Discard | QMessageBox::YesToAll | QMessageBox::Reset | QMessageBox::Apply);
//        ret = QMessageBox::question(this, "Title", "Text text text", QMessageBox::Abort | QMessageBox::Discard | QMessageBox::YesToAll | QMessageBox::Reset | QMessageBox::Apply);
        ret = QMessageBox::warning(this, "Title", "Text text text", QMessageBox::Abort | QMessageBox::Discard | QMessageBox::YesToAll | QMessageBox::Reset | QMessageBox::Apply);

        if (ret == QMessageBox::Ok){
            qDebug() << "You accept the hacking";
        }else{
            qDebug() << "You did not accept the hacking but anyway ...";
        }
    });

    QPushButton * button3 = new QPushButton("button 3",this);
    button3->move(250, 250);
    button->setMinimumSize(45, 90);
    connect(button3, &QPushButton::pressed, [=](){
        qDebug() << "button pressed ";

    });

    connect(button3, &QPushButton::released, [=](){
        qDebug() << "button released ";

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

