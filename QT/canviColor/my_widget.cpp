#include "my_widget.h"
#include "ui_my_widget.h"

my_widget::my_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_widget)
{
    ui->setupUi(this);
}

my_widget::~my_widget()
{
    delete ui;
}
