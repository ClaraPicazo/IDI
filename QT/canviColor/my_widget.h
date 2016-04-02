#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>

namespace Ui {
class my_widget;
}

class my_widget : public QWidget
{
    Q_OBJECT

public:
    explicit my_widget(QWidget *parent = 0);
    ~my_widget();

private:
    Ui::my_widget *ui;
};

#endif // MY_WIDGET_H
