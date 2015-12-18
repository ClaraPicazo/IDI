#ifndef MY_BUTTON_H
#define MY_BUTTON_H

#include <QPushButton>

class my_button : public QPushButton
{
    Q_OBJECT
private:
    bool lliure;
    int ocupats;
    int verds;
public:
    explicit my_button(QWidget *parent = 0);

signals:
    void ocupat(int);
    void lliures(int);

public slots:
    void changeState();
    void getOcupats(int n);
    void getLliures(int v);

};

#endif // MY_BUTTON_H
