#ifndef MYQLCD_H
#define MYQLCD_H

#include <QWidget>

class myqlcd : public QLCDNumber
{
    Q_OBJECT
public:
    explicit myqlcd(QWidget *parent = 0);

signals:

public slots:
     void hangeToZero();

};

#endif // MYQLCD_H
