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
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "my_button.h"

QT_BEGIN_NAMESPACE

class Ui_my_widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    my_button *pushButton;
    my_button *pushButton_2;
    QVBoxLayout *verticalLayout_2;
    my_button *pushButton_3;
    my_button *pushButton_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;

    void setupUi(QWidget *my_widget)
    {
        if (my_widget->objectName().isEmpty())
            my_widget->setObjectName(QString::fromUtf8("my_widget"));
        my_widget->resize(400, 300);
        verticalLayout_4 = new QVBoxLayout(my_widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new my_button(my_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 70));

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new my_button(my_widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(0, 70));

        verticalLayout_3->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_3 = new my_button(my_widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(0, 70));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new my_button(my_widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(0, 70));

        verticalLayout_2->addWidget(pushButton_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(my_widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        spinBox = new QSpinBox(my_widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimumSize(QSize(0, 35));
        spinBox->setValue(4);

        verticalLayout->addWidget(spinBox);

        label_2 = new QLabel(my_widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        spinBox_2 = new QSpinBox(my_widget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setEnabled(false);
        sizePolicy.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy);
        spinBox_2->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(spinBox_2);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(my_widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(my_widget);
        QObject::connect(pushButton_5, SIGNAL(clicked()), my_widget, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), pushButton, SLOT(changeState()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), pushButton_3, SLOT(changeState()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), pushButton_2, SLOT(changeState()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), pushButton_4, SLOT(changeState()));
        QObject::connect(pushButton_4, SIGNAL(ocupat(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(pushButton_3, SIGNAL(ocupat(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(pushButton_2, SIGNAL(ocupat(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(pushButton, SIGNAL(ocupat(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), pushButton_4, SLOT(getOcupats(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), pushButton_2, SLOT(getOcupats(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), pushButton_3, SLOT(getOcupats(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), pushButton, SLOT(getOcupats(int)));
        QObject::connect(pushButton, SIGNAL(lliures(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton_3, SIGNAL(lliures(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton_2, SIGNAL(lliures(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(pushButton_4, SIGNAL(lliures(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), pushButton_3, SLOT(getLliures(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), pushButton_4, SLOT(getLliures(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), pushButton, SLOT(getLliures(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), pushButton_2, SLOT(getLliures(int)));

        QMetaObject::connectSlotsByName(my_widget);
    } // setupUi

    void retranslateUi(QWidget *my_widget)
    {
        my_widget->setWindowTitle(QApplication::translate("my_widget", "my_widget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        label->setText(QApplication::translate("my_widget", "Places LLiures", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("my_widget", "PlacesOcupades", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("my_widget", "&Sortir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class my_widget: public Ui_my_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_WIDGET_H
