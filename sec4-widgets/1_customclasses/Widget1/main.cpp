#include "stonehead.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StoneHead sh;
//    sh.setFixedSize(500, 500);


//class icinde asagidaki metod otomatik olarak cagiriliyor
//    disardan girmek istemdiginde sabit pencere boyutunu belirleyebilirsin
//    private:

//    QSize sizeHint() const override{
//        return QSize(750, 500);
//    }

    sh.show();

    return a.exec();
}
