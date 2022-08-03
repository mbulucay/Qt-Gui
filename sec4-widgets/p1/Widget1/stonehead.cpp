#include "stonehead.h"

#include <QLabel>
#include <QPushButton>

StoneHead::StoneHead(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle(QString("This is TITLE"));

    // Add a widget and manage it

    QLabel* ql = new QLabel(QString("this label placed in stonehead.cpp line 9"), this);
    ql->setMargin(10);

    QLabel* l = new QLabel(this);
    l->setText(QString("This is moving"));
    l->move(QPoint(10, 25));


    QFont serifFont("Times", 25, QFont::Bold, true);
    l->setFont(serifFont);

    QPalette color(Qt::blue);
    color.setColor(QPalette::Window, Qt::green);
    color.setColor(QPalette::WindowText, Qt::blue);

    l->setAutoFillBackground(true);
    l->setPalette(color);


    // Add Button and Connect it with a slot
    QPushButton* button = new QPushButton(this);
    button->setText(QString("BUTTON"));
    button->move(QPoint(300, 400));
    button->setPalette(QPalette(color));

    connect(button, SIGNAL(clicked()), this, SLOT(moveText()));
}


void StoneHead::moveText(){

    QWidget* l = this->childAt(10, 25);

    int newX = l->pos().x() + 10;
    int newY = l->pos().y() + 10;
    l->move(newX, newY);
}
