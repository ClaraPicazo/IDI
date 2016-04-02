#include "myqlcd.h"

MyQlcd::MyQlcd(QWidget *parent) :
    QLCDNumber(parent)
{
}

void MyQlcd::ChangeToZero(){
    display(0);
}
