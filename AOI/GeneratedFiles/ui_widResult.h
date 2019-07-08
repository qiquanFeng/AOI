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
#include <QtWidgets/QPushButton>
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
    QLabel *lab_result;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLabel *lab_pannel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLabel *lab_sampleposition;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QLabel *lab_processtime;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_15;
    QPushButton *pushButton_imagepath;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_17;
    QPushButton *pushButton_MD5;

    void setupUi(QWidget *widResult)
    {
        if (widResult->objectName().isEmpty())
            widResult->setObjectName(QStringLiteral("widResult"));
        widResult->resize(499, 421);
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

        lab_result = new QLabel(verticalLayoutWidget);
        lab_result->setObjectName(QStringLiteral("lab_result"));

        horizontalLayout->addWidget(lab_result);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        lab_pannel = new QLabel(verticalLayoutWidget);
        lab_pannel->setObjectName(QStringLiteral("lab_pannel"));

        horizontalLayout_5->addWidget(lab_pannel);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_6->addWidget(label_11);

        lab_sampleposition = new QLabel(verticalLayoutWidget);
        lab_sampleposition->setObjectName(QStringLiteral("lab_sampleposition"));

        horizontalLayout_6->addWidget(lab_sampleposition);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_7->addWidget(label_13);

        lab_processtime = new QLabel(verticalLayoutWidget);
        lab_processtime->setObjectName(QStringLiteral("lab_processtime"));

        horizontalLayout_7->addWidget(lab_processtime);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_8->addWidget(label_15);

        pushButton_imagepath = new QPushButton(verticalLayoutWidget);
        pushButton_imagepath->setObjectName(QStringLiteral("pushButton_imagepath"));
        pushButton_imagepath->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_8->addWidget(pushButton_imagepath, 0, Qt::AlignLeft);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_9->addWidget(label_17);

        pushButton_MD5 = new QPushButton(verticalLayoutWidget);
        pushButton_MD5->setObjectName(QStringLiteral("pushButton_MD5"));

        horizontalLayout_9->addWidget(pushButton_MD5, 0, Qt::AlignLeft);


        verticalLayout->addLayout(horizontalLayout_9);


        retranslateUi(widResult);

        QMetaObject::connectSlotsByName(widResult);
    } // setupUi

    void retranslateUi(QWidget *widResult)
    {
        widResult->setWindowTitle(QApplication::translate("widResult", "widResult", Q_NULLPTR));
        label->setText(QApplication::translate("widResult", "Result", Q_NULLPTR));
        lab_result->setText(QString());
        label_9->setText(QApplication::translate("widResult", "pannel", Q_NULLPTR));
        lab_pannel->setText(QString());
        label_11->setText(QApplication::translate("widResult", "sample position", Q_NULLPTR));
        lab_sampleposition->setText(QString());
        label_13->setText(QApplication::translate("widResult", "process time", Q_NULLPTR));
        lab_processtime->setText(QString());
        label_15->setText(QApplication::translate("widResult", "iamge path", Q_NULLPTR));
        pushButton_imagepath->setText(QApplication::translate("widResult", "PushButton", Q_NULLPTR));
        label_17->setText(QApplication::translate("widResult", "MD5", Q_NULLPTR));
        pushButton_MD5->setText(QApplication::translate("widResult", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class widResult: public Ui_widResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDRESULT_H
