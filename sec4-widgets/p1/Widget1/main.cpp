#include "stonehead.h""

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StoneHead sh;
    sh.setFixedSize(500, 500);
    sh.show();

    return a.exec();
}
