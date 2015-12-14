#ifndef MYQLCDNUMBER_H
#define MYQLCDNUMBER_H

#include <QLCDNumber>

class MyQLCDNumber : public QLCDNumber
{
    Q_OBJECT
public:
    explicit MyQLCDNumber(QWidget *parent = 0);

signals:

public slots:
    void displayColor(int num);
    void setToZero();
};

#endif // MYQLCDNUMBER_H
