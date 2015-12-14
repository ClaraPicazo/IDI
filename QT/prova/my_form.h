#ifndef MY_FORM_H
#define MY_FORM_H

#include <QWidget>

namespace Ui {
class my_form;
}

class my_form : public QWidget
{
    Q_OBJECT

public:
    explicit my_form(QWidget *parent = 0);
    ~my_form();

private:
    Ui::my_form *ui;
};

#endif // MY_FORM_H
