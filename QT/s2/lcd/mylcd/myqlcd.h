#ifndef MYQLCD_H
#define MYQLCD_H

#include <QLCDNumber>

class MyQlcd : public QLCDNumber
{
    Q_OBJECT

public:
    MyQlcd(QWidget *parent = 0);

public slots:
    void ChangeToZero();
};

#endif
