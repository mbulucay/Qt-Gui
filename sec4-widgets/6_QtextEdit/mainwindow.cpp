#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(500, 500);

    QTextEdit * text_edit = new QTextEdit(this);
    text_edit->setPlaceholderText("Write text");
    text_edit->move(50,50);
    text_edit->setMinimumSize(400, 100);

    connect(text_edit, &QTextEdit::textChanged, [text_edit](){
        qDebug() << text_edit->toPlainText();
    });

    QString p("- ");
    QLabel * label = new QLabel(p, this);
    label->move(50, 400);
    label->setMinimumSize(400, 20);

    int button_x_pos = 30;
    int button_y_pos = 180;
    int button_x_l = 110;
    int button_y_l = 45;

//    button_x_pos += button_x_l;
    QPushButton * copy_button = new QPushButton("Copy", this);
    copy_button->move(button_x_pos, button_y_pos);

    connect(copy_button, &QPushButton::clicked, [=](){
        text_edit->copy();
        label->setText("Message Copied");
    });

    button_x_pos += button_x_l;
    QPushButton * cut_botton = new QPushButton("Cut", this);
    cut_botton->move(button_x_pos, button_y_pos);

    connect(cut_botton, &QPushButton::clicked, [=](){
        text_edit->cut();
        label->setText("Message Cutted");
    });

    button_x_pos += button_x_l;
    QPushButton * paste_button = new QPushButton("Paste", this);
    paste_button->move(button_x_pos, button_y_pos);

    connect(paste_button, &QPushButton::clicked, [=](){
        text_edit->paste();
        label->setText("Message Pasted");
    });

    button_x_pos += button_x_l;
    QPushButton * undo_button = new QPushButton("Undo", this);
    undo_button->move(button_x_pos, button_y_pos);

    connect(undo_button, &QPushButton::clicked, [=](){
        text_edit->undo();
        label->setText("Undo called");
    });


    button_x_pos = 30;
    button_y_pos += button_y_l;

    QPushButton * redo_button = new QPushButton("Redo", this);
    redo_button->move(button_x_pos, button_y_pos);

    connect(redo_button, &QPushButton::clicked, [=](){
        text_edit->redo();
        label->setText("Redo called");
    });

    button_x_pos += button_x_l;
    QPushButton * plaintext_button = new QPushButton("Text", this);
    plaintext_button ->move(button_x_pos, button_y_pos);

    connect(plaintext_button , &QPushButton::clicked, [=](){
        text_edit->setPlainText("----------------------------------------------------------------------||||||||||||||||||||||||||||||||||||||||||||========================================");
        label->setText("Text called");
    });

    button_x_pos += button_x_l;
    QPushButton * html_button = new QPushButton("Html", this);
    html_button->move(button_x_pos, button_y_pos);

    connect(html_button, &QPushButton::clicked, [=](){
        text_edit->setHtml("<h2>Ordered List with Numbers</h2><ol type=\"1\"><li>Coffee</li><li>Tea</li><li>Milk</li></ol>");
        label->setText("Html called");
    });

    button_x_pos += button_x_l;
    QPushButton * html2_button = new QPushButton("Html2", this);
    html2_button->move(button_x_pos, button_y_pos);

    connect(html2_button, &QPushButton::clicked, [=](){
        text_edit->setHtml("<table style=\"width:100%\"><tr><th>Firstname</th><th>Lastname</th> <th>Age</th></tr><tr><td>Jill</td><td>Smith</td><td>50</td></tr><tr><td>Eve</td><td>Jackson</td><td>94</td></tr><tr><td>John</td><td>Doe</td><td>80</td></tr></table>");
        label->setText("Html2 called");
    });

    button_x_pos = 30;
    button_y_pos += button_y_l;

    QPushButton * graptext_button = new QPushButton("GrapT", this);
    graptext_button ->move(button_x_pos, button_y_pos);

    connect(graptext_button , &QPushButton::clicked, [=](){
        qDebug() << "Grapped Text" << text_edit->grab();
        label->setText("Grab Text called");
    });

    button_x_pos += button_x_l;
    QPushButton * graphtml_button = new QPushButton("GrapH", this);
    graphtml_button ->move(button_x_pos, button_y_pos);

    connect(graphtml_button , &QPushButton::clicked, [=](){
        qDebug() << "Grapped Html" << text_edit->toHtml();
        label->setText("Grab Html called");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

