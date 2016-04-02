#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QLabel>

class my_label : public QLabel
{
    Q_OBJECT
private:
    int red,green,blue;
public:
    explicit my_label(QWidget *parent = 0);

signals:

public slots:
    void getRed(int r);
    void getGreen(int g);
    void getBlue(int b);
    void updateColor();
};

#endif // MY_LABEL_H
