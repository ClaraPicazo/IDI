#include "my_form.h"
#include "ui_my_form.h"

my_form::my_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_form)
{
    ui->setupUi(this);
}

my_form::~my_form()
{
    delete ui;
}
