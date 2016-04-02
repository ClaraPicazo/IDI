/********************************************************************************
** Form generated from reading UI file 'my_widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_WIDGET_H
#define UI_MY_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "my_label.h"

QT_BEGIN_NAMESPACE

class Ui_my_widget
{
public:
    QVBoxLayout *verticalLayout_4;
    my_label *label_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QVBoxLayout *verticalLayout_3;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *my_widget)
    {
        if (my_widget->objectName().isEmpty())
            my_widget->setObjectName(QString::fromUtf8("my_widget"));
        my_widget->resize(400, 300);
        verticalLayout_4 = new QVBoxLayout(my_widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new my_label(my_widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(label_4);

        verticalSpacer = new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(my_widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(my_widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(my_widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalSlider = new QSlider(my_widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        horizontalSlider_2 = new QSlider(my_widget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_2);

        horizontalSlider_3 = new QSlider(my_widget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lcdNumber = new QLCDNumber(my_widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setNumDigits(3);

        verticalLayout_3->addWidget(lcdNumber);

        lcdNumber_2 = new QLCDNumber(my_widget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setNumDigits(3);

        verticalLayout_3->addWidget(lcdNumber_2);

        lcdNumber_3 = new QLCDNumber(my_widget);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setNumDigits(3);

        verticalLayout_3->addWidget(lcdNumber_3);


        horizontalLayout->addLayout(verticalLayout_3);

        pushButton = new QPushButton(my_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(my_widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(my_widget);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), my_widget, SLOT(close()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), label_4, SLOT(getRed(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), label_4, SLOT(getGreen(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), label_4, SLOT(getBlue(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), label_4, SLOT(updateColor()));

        QMetaObject::connectSlotsByName(my_widget);
    } // setupUi

    void retranslateUi(QWidget *my_widget)
    {
        my_widget->setWindowTitle(QApplication::translate("my_widget", "my_widget", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label->setText(QApplication::translate("my_widget", "R", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("my_widget", "G", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("my_widget", "B", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("my_widget", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("my_widget", "&Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class my_widget: public Ui_my_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_WIDGET_H
