/********************************************************************************
** Form generated from reading UI file 'widResult.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDRESULT_H
#define UI_WIDRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widResult
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_15;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_17;
    QLabel *label_18;

    void setupUi(QWidget *widResult)
    {
        if (widResult->objectName().isEmpty())
            widResult->setObjectName(QStringLiteral("widResult"));
        widResult->resize(493, 412);
        verticalLayoutWidget = new QWidget(widResult);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 491, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_6->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_6->addWidget(label_12);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_7->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_7->addWidget(label_14);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_8->addWidget(label_15);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_8->addWidget(label_16);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_9->addWidget(label_17);

        label_18 = new QLabel(verticalLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_9->addWidget(label_18);


        verticalLayout->addLayout(horizontalLayout_9);


        retranslateUi(widResult);

        QMetaObject::connectSlotsByName(widResult);
    } // setupUi

    void retranslateUi(QWidget *widResult)
    {
        widResult->setWindowTitle(QApplication::translate("widResult", "widResult", Q_NULLPTR));
        label->setText(QApplication::translate("widResult", "Result", Q_NULLPTR));
        label_2->setText(QString());
        label_9->setText(QApplication::translate("widResult", "pannel", Q_NULLPTR));
        label_10->setText(QString());
        label_11->setText(QApplication::translate("widResult", "sample position", Q_NULLPTR));
        label_12->setText(QString());
        label_13->setText(QApplication::translate("widResult", "process time", Q_NULLPTR));
        label_14->setText(QString());
        label_15->setText(QApplication::translate("widResult", "iamge path", Q_NULLPTR));
        label_16->setText(QString());
        label_17->setText(QApplication::translate("widResult", "MD5", Q_NULLPTR));
        label_18->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class widResult: public Ui_widResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDRESULT_H
