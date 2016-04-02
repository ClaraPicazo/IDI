#include "my_form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my_form w;
    w.show();

    return a.exec();
}
