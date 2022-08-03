#ifndef STONEHEAD_H
#define STONEHEAD_H

#include <QObject>
#include <QWidget>

class StoneHead : public QWidget
{
    Q_OBJECT
public:
    explicit StoneHead(QWidget *parent = nullptr);

signals:

public slots:

void moveText();


};

#endif // STONEHEAD_H
