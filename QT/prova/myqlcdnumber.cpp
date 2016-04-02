#include "myqlcdnumber.h"



MyQLCDNumber::MyQLCDNumber(QWidget *parent){

}

void MyQLCDNumber::displayColor(int num) {

    if(num==0) {
        setStyleSheet("background-color: green");
    }else if(num%2==0) {
        setStyleSheet("background-color: blue");
    }else{
        setStyleSheet("background-color: red");
    }

    QLCDNumber::display(num);
}

void MyQLCDNumber::setToZero() {
    this->displayColor(0);
}
