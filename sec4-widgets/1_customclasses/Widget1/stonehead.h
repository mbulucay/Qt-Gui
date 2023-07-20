#ifndef STONEHEAD_H
#define STONEHEAD_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QDebug>
class StoneHead : public QWidget
{
    Q_OBJECT
public:
    explicit StoneHead(QWidget *parent = nullptr);

signals:

public slots:

void moveText(QLabel* ql);

private:

QSize sizeHint() const override{
    qDebug() << "size hint otomatik cagirildi";
    return QSize(750, 500);
}


};

#endif // STONEHEAD_H
