#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(400, 300);

    int Y_pos = 20;
    int Y_inc = 40;

    QFont font = QFont("Times", 10, QFont::Bold);
    QPalette color = QPalette(Qt::GlobalColor::lightGray);

    QLabel * name_label = new QLabel("Name: ", this);
    name_label->setMinimumSize(70, 20);
    name_label->move(50, Y_pos);

    QLineEdit * name_line = new QLineEdit("Write Your Name", this);
    name_line->move(150, Y_pos);
    name_line->setMinimumSize(200, 10);
    name_line->setFont(font);
    name_line->setPalette(color);

    connect(name_line, &QLineEdit::textChanged, [name_line](const QString& str){
        qDebug() << "Text Changed" << str;
        if(str == "Write Your Nam"){
            name_line->clear();
        }
    });

    Y_pos += Y_inc;

    QLabel * surname_label = new QLabel("Surname: ", this);
    surname_label->setMinimumSize(70, 20);
    surname_label->move(50, Y_pos);

    QAction * action = new QAction("surname");

    QLineEdit * surname_line = new QLineEdit("Write Your Surname", this);
    surname_line->move(150, Y_pos);
    surname_line->setMinimumSize(200, 10);
    surname_line->setFont(font);
    surname_line->setPalette(color);
    surname_line->addAction(action);

    connect(surname_line, &QLineEdit::cursorPositionChanged, [](int o, int n){
       qDebug() << "cursor Pos: "<< o << "  -  " << n;
    });

    connect(surname_line, &QLineEdit::editingFinished, [](){
       qDebug() << "I guess Pressed Enter";
    });

    connect(surname_line, &QLineEdit::textChanged, [surname_line](const QString& str){
        qDebug() << "Text Changed" << str;
        if(str == "Write Your Surnam"){
            surname_line->clear();
        }
    });

//    diger signaller
    &QLineEdit::returnPressed;
    &QLineEdit::selectionChanged;
    &QLineEdit::textEdited;
//    etc....


    Y_pos += Y_inc;

    QLabel * city_label = new QLabel("City: ", this);
    city_label->setMinimumSize(70, 20);
    city_label->move(50, Y_pos);

    QLineEdit * city_line = new QLineEdit(this);
    city_line->move(150, Y_pos);
    city_line->setMinimumSize(200, 10);
    city_line->setFont(font);
    city_line->setPalette(color);
    city_line->setPlaceholderText("setPlaceholderText(\"Text\");");

    connect(city_line, &QLineEdit::textChanged, [city_line](const QString& str){
        qDebug() << "Text Changed" << str;
        if(str == "Write Your Cit"){
            city_line->clear();
        }
    });


    QFont buttonfont = QFont("Times", 20, QFont::Bold, true);
    QPushButton * button = new QPushButton("Save", this);
    button->setFont(buttonfont);
    button->move(200, 200);

    connect(button, &QPushButton::clicked, [=](){

        qDebug() << "Name:    " << name_line->text();
        qDebug() << "Surname: " << surname_line->text();
        qDebug() << "City:    " << city_line->text();

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const{
    return QSize(250, 250);
}
