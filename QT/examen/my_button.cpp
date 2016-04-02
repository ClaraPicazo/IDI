#include "my_button.h"

my_button::my_button(QWidget *parent) :
    QPushButton(parent)
{
    setStyleSheet("background-color: green");
    lliure = true;
    ocupats = 0;
    verds = 4;
}


void my_button::changeState(){

    if(lliure == false){
        setStyleSheet("background-color: green");
        lliure = true;
        emit ocupat(ocupats-1);
        emit lliures(verds +1);
    }

    else{
        setStyleSheet("background-color: red");
        lliure = false;
        emit ocupat(ocupats+1);
        emit lliures(verds-1);
    }
}

void my_button::getOcupats(int n){
    ocupats = n;
}

void my_button::getLliures(int v){
    verds = v;
}
