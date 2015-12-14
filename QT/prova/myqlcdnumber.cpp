#include "myqlcdnumber.h"



MyQLCDNumber::MyQLCDNumber(QWidget *parent){

}

void MyQLCDNumber::displayColor(int num) {

    QPalette Pal(palette());

    if(num==0) {
        Pal.setColor(QPalette::WindowText, Qt::green);
    }else if(num%2==0) {
        Pal.setColor(QPalette::WindowText, Qt::blue);
    }else{
        Pal.setColor(QPalette::WindowText, Qt::red);
    }

    this->setPalette(Pal);

    QLCDNumber::display(num);
}

void MyQLCDNumber::setToZero() {
    this->display(0);
}
