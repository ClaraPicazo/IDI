#include "myqlcd.h"

myqlcd::myqlcd(QWidget *parent) :
    QLCDNumber(parent)
{
}

void myqlcd::changeToZero(){
    display(0);
}
