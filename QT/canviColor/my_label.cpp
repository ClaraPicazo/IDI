#include "my_label.h"

my_label::my_label(QWidget *parent) :
    QLabel(parent)
{
    setStyleSheet("background-color: black");
    red = 0;
    green = 0;
    blue = 0;
}

    void my_label::getRed(int r){
        red = r;
    }

    void my_label::getGreen(int g){
        green = g;
    }

    void my_label::getBlue(int b){
        blue = b;
    }

    void my_label::updateColor(){
        setStyleSheet("background:rgb(" + QString::number(red) + "," + QString::number(green) + "," + QString::number(blue)+")");
    }

