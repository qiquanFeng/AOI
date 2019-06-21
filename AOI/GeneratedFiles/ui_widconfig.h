/********************************************************************************
** Form generated from reading UI file 'widconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDCONFIG_H
#define UI_WIDCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widconfig
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QListWidget *listWidget;
    QLineEdit *lineEdit_configName;
    QPushButton *pushButton_fit;
    QPushButton *pushButton_add;
    QPushButton *pushButton_del;
    QPushButton *pushButton_save;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *boxRows;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *boxPadding;
    QLabel *label_8;
    QDoubleSpinBox *boxMargin;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSpinBox *plateRows;
    QLabel *label_7;
    QSpinBox *plateCols;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDoubleSpinBox *plateRowPadding;
    QLabel *label_9;
    QDoubleSpinBox *plateColPadding;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpinBox *loadPos_X;
    QLabel *label_10;
    QSpinBox *loadSpeed_X;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QSpinBox *loadPos_Y;
    QLabel *label_12;
    QSpinBox *loadSpeed_Y;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_17;
    QSpinBox *loadPos_Z;
    QLabel *label_18;
    QSpinBox *loadSpeed_Z;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_13;
    QSpinBox *unLoadPos_X;
    QLabel *label_14;
    QSpinBox *unLoadSpeed_X;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_19;
    QSpinBox *unLoadPos_Y;
    QLabel *label_20;
    QSpinBox *unLoadSpeed_Y;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_21;
    QSpinBox *unLoadPos_Z;
    QLabel *label_22;
    QSpinBox *unLoadSpeed_Z;
    QGroupBox *groupBox_5;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_23;
    QSpinBox *testFirstPos_X;
    QLabel *label_24;
    QSpinBox *testFirstPos_Y;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_26;
    QSpinBox *testSpeed;

    void setupUi(QWidget *widconfig)
    {
        if (widconfig->objectName().isEmpty())
            widconfig->setObjectName(QStringLiteral("widconfig"));
        widconfig->resize(780, 576);
        horizontalLayoutWidget = new QWidget(widconfig);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 771, 561));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        listWidget = new QListWidget(horizontalLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_7->addWidget(listWidget);

        lineEdit_configName = new QLineEdit(horizontalLayoutWidget);
        lineEdit_configName->setObjectName(QStringLiteral("lineEdit_configName"));

        verticalLayout_7->addWidget(lineEdit_configName);

        pushButton_fit = new QPushButton(horizontalLayoutWidget);
        pushButton_fit->setObjectName(QStringLiteral("pushButton_fit"));

        verticalLayout_7->addWidget(pushButton_fit);

        pushButton_add = new QPushButton(horizontalLayoutWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        verticalLayout_7->addWidget(pushButton_add);

        pushButton_del = new QPushButton(horizontalLayoutWidget);
        pushButton_del->setObjectName(QStringLiteral("pushButton_del"));

        verticalLayout_7->addWidget(pushButton_del);

        pushButton_save = new QPushButton(horizontalLayoutWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        verticalLayout_7->addWidget(pushButton_save);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(horizontalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 491, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        boxRows = new QSpinBox(verticalLayoutWidget_2);
        boxRows->setObjectName(QStringLiteral("boxRows"));

        horizontalLayout_3->addWidget(boxRows);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        boxPadding = new QDoubleSpinBox(verticalLayoutWidget_2);
        boxPadding->setObjectName(QStringLiteral("boxPadding"));

        horizontalLayout_2->addWidget(boxPadding);

        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        boxMargin = new QDoubleSpinBox(verticalLayoutWidget_2);
        boxMargin->setObjectName(QStringLiteral("boxMargin"));

        horizontalLayout_2->addWidget(boxMargin);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(horizontalLayoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 491, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        plateRows = new QSpinBox(verticalLayoutWidget_3);
        plateRows->setObjectName(QStringLiteral("plateRows"));

        horizontalLayout_5->addWidget(plateRows);

        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        plateCols = new QSpinBox(verticalLayoutWidget_3);
        plateCols->setObjectName(QStringLiteral("plateCols"));

        horizontalLayout_5->addWidget(plateCols);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        plateRowPadding = new QDoubleSpinBox(verticalLayoutWidget_3);
        plateRowPadding->setObjectName(QStringLiteral("plateRowPadding"));
        plateRowPadding->setMaximum(9999);

        horizontalLayout_6->addWidget(plateRowPadding);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        plateColPadding = new QDoubleSpinBox(verticalLayoutWidget_3);
        plateColPadding->setObjectName(QStringLiteral("plateColPadding"));
        plateColPadding->setMaximum(9999);

        horizontalLayout_6->addWidget(plateColPadding);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(horizontalLayoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayoutWidget_4 = new QWidget(groupBox_3);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 491, 85));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        loadPos_X = new QSpinBox(verticalLayoutWidget_4);
        loadPos_X->setObjectName(QStringLiteral("loadPos_X"));
        loadPos_X->setMinimum(-10000000);
        loadPos_X->setMaximum(10000000);

        horizontalLayout_7->addWidget(loadPos_X);

        label_10 = new QLabel(verticalLayoutWidget_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_7->addWidget(label_10);

        loadSpeed_X = new QSpinBox(verticalLayoutWidget_4);
        loadSpeed_X->setObjectName(QStringLiteral("loadSpeed_X"));
        loadSpeed_X->setMaximum(100000);

        horizontalLayout_7->addWidget(loadSpeed_X);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_11 = new QLabel(verticalLayoutWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_8->addWidget(label_11);

        loadPos_Y = new QSpinBox(verticalLayoutWidget_4);
        loadPos_Y->setObjectName(QStringLiteral("loadPos_Y"));
        loadPos_Y->setMinimum(-10000000);
        loadPos_Y->setMaximum(10000000);

        horizontalLayout_8->addWidget(loadPos_Y);

        label_12 = new QLabel(verticalLayoutWidget_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_8->addWidget(label_12);

        loadSpeed_Y = new QSpinBox(verticalLayoutWidget_4);
        loadSpeed_Y->setObjectName(QStringLiteral("loadSpeed_Y"));
        loadSpeed_Y->setMaximum(100000);

        horizontalLayout_8->addWidget(loadSpeed_Y);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_17 = new QLabel(verticalLayoutWidget_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_11->addWidget(label_17);

        loadPos_Z = new QSpinBox(verticalLayoutWidget_4);
        loadPos_Z->setObjectName(QStringLiteral("loadPos_Z"));
        loadPos_Z->setMinimum(-10000000);
        loadPos_Z->setMaximum(10000000);

        horizontalLayout_11->addWidget(loadPos_Z);

        label_18 = new QLabel(verticalLayoutWidget_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_11->addWidget(label_18);

        loadSpeed_Z = new QSpinBox(verticalLayoutWidget_4);
        loadSpeed_Z->setObjectName(QStringLiteral("loadSpeed_Z"));
        loadSpeed_Z->setMaximum(100000);

        horizontalLayout_11->addWidget(loadSpeed_Z);


        verticalLayout_4->addLayout(horizontalLayout_11);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(horizontalLayoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayoutWidget_5 = new QWidget(groupBox_4);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 10, 491, 85));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_13 = new QLabel(verticalLayoutWidget_5);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_9->addWidget(label_13);

        unLoadPos_X = new QSpinBox(verticalLayoutWidget_5);
        unLoadPos_X->setObjectName(QStringLiteral("unLoadPos_X"));
        unLoadPos_X->setMinimum(-10000000);
        unLoadPos_X->setMaximum(10000000);

        horizontalLayout_9->addWidget(unLoadPos_X);

        label_14 = new QLabel(verticalLayoutWidget_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_9->addWidget(label_14);

        unLoadSpeed_X = new QSpinBox(verticalLayoutWidget_5);
        unLoadSpeed_X->setObjectName(QStringLiteral("unLoadSpeed_X"));
        unLoadSpeed_X->setMaximum(100000);

        horizontalLayout_9->addWidget(unLoadSpeed_X);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_19 = new QLabel(verticalLayoutWidget_5);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_12->addWidget(label_19);

        unLoadPos_Y = new QSpinBox(verticalLayoutWidget_5);
        unLoadPos_Y->setObjectName(QStringLiteral("unLoadPos_Y"));
        unLoadPos_Y->setMinimum(-10000000);
        unLoadPos_Y->setMaximum(10000000);

        horizontalLayout_12->addWidget(unLoadPos_Y);

        label_20 = new QLabel(verticalLayoutWidget_5);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_12->addWidget(label_20);

        unLoadSpeed_Y = new QSpinBox(verticalLayoutWidget_5);
        unLoadSpeed_Y->setObjectName(QStringLiteral("unLoadSpeed_Y"));
        unLoadSpeed_Y->setMaximum(100000);

        horizontalLayout_12->addWidget(unLoadSpeed_Y);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_21 = new QLabel(verticalLayoutWidget_5);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_13->addWidget(label_21);

        unLoadPos_Z = new QSpinBox(verticalLayoutWidget_5);
        unLoadPos_Z->setObjectName(QStringLiteral("unLoadPos_Z"));
        unLoadPos_Z->setMinimum(-10000000);
        unLoadPos_Z->setMaximum(10000000);

        horizontalLayout_13->addWidget(unLoadPos_Z);

        label_22 = new QLabel(verticalLayoutWidget_5);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_13->addWidget(label_22);

        unLoadSpeed_Z = new QSpinBox(verticalLayoutWidget_5);
        unLoadSpeed_Z->setObjectName(QStringLiteral("unLoadSpeed_Z"));
        unLoadSpeed_Z->setMaximum(100000);

        horizontalLayout_13->addWidget(unLoadSpeed_Z);


        verticalLayout_5->addLayout(horizontalLayout_13);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(horizontalLayoutWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayoutWidget_6 = new QWidget(groupBox_5);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 10, 491, 81));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_23 = new QLabel(verticalLayoutWidget_6);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_14->addWidget(label_23);

        testFirstPos_X = new QSpinBox(verticalLayoutWidget_6);
        testFirstPos_X->setObjectName(QStringLiteral("testFirstPos_X"));
        testFirstPos_X->setMinimum(-100000);
        testFirstPos_X->setMaximum(100000);

        horizontalLayout_14->addWidget(testFirstPos_X);

        label_24 = new QLabel(verticalLayoutWidget_6);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_14->addWidget(label_24);

        testFirstPos_Y = new QSpinBox(verticalLayoutWidget_6);
        testFirstPos_Y->setObjectName(QStringLiteral("testFirstPos_Y"));
        testFirstPos_Y->setMinimum(-100000);
        testFirstPos_Y->setMaximum(100000);

        horizontalLayout_14->addWidget(testFirstPos_Y);


        verticalLayout_6->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_26 = new QLabel(verticalLayoutWidget_6);
        label_26->setObjectName(QStringLiteral("label_26"));

        horizontalLayout_15->addWidget(label_26);

        testSpeed = new QSpinBox(verticalLayoutWidget_6);
        testSpeed->setObjectName(QStringLiteral("testSpeed"));
        testSpeed->setMaximum(100000);

        horizontalLayout_15->addWidget(testSpeed);


        verticalLayout_6->addLayout(horizontalLayout_15);


        verticalLayout->addWidget(groupBox_5);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(1, 20);

        retranslateUi(widconfig);

        QMetaObject::connectSlotsByName(widconfig);
    } // setupUi

    void retranslateUi(QWidget *widconfig)
    {
        widconfig->setWindowTitle(QApplication::translate("widconfig", "widconfig", Q_NULLPTR));
        pushButton_fit->setText(QApplication::translate("widconfig", "Filter", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("widconfig", "Add", Q_NULLPTR));
        pushButton_del->setText(QApplication::translate("widconfig", "Delete", Q_NULLPTR));
        pushButton_save->setText(QApplication::translate("widconfig", "Save", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("widconfig", "\345\274\271\345\244\271", Q_NULLPTR));
        label_2->setText(QApplication::translate("widconfig", "\345\274\271\345\244\271\350\275\275\346\235\277\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("widconfig", "\345\274\271\345\244\271\345\206\205\350\276\271\350\267\235", Q_NULLPTR));
        label_8->setText(QApplication::translate("widconfig", "\345\274\271\345\244\271\345\244\226\350\276\271\350\267\235", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("widconfig", "\350\275\275\346\235\277", Q_NULLPTR));
        label_4->setText(QApplication::translate("widconfig", "\350\275\275\346\235\277\350\241\214\346\225\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("widconfig", "\350\275\275\346\235\277\345\210\227\346\225\260", Q_NULLPTR));
        label_5->setText(QApplication::translate("widconfig", "\350\241\214\351\227\264\350\267\235\357\274\210\346\200\273\351\227\264\350\267\235mm\357\274\211", Q_NULLPTR));
        label_9->setText(QApplication::translate("widconfig", "\345\210\227\351\227\264\350\267\235\357\274\210\346\200\273\351\227\264\350\267\235mm\357\274\211", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("widconfig", "\344\270\212\346\226\231", Q_NULLPTR));
        label_6->setText(QApplication::translate("widconfig", "X \344\275\215\347\275\256(\346\216\250\346\235\206)", Q_NULLPTR));
        label_10->setText(QApplication::translate("widconfig", "X \351\200\237\345\272\246(\346\216\250\346\235\206)", Q_NULLPTR));
        label_11->setText(QApplication::translate("widconfig", "Y \344\275\215\347\275\256\357\274\210\345\271\263\345\217\260\357\274\211", Q_NULLPTR));
        label_12->setText(QApplication::translate("widconfig", "Y \351\200\237\345\272\246\357\274\210\345\271\263\345\217\260\357\274\211", Q_NULLPTR));
        label_17->setText(QApplication::translate("widconfig", "Z \344\275\215\347\275\256", Q_NULLPTR));
        label_18->setText(QApplication::translate("widconfig", "Z \351\200\237\345\272\246", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("widconfig", "\344\270\213\346\226\231", Q_NULLPTR));
        label_13->setText(QApplication::translate("widconfig", "X \344\275\215\347\275\256\357\274\210\345\271\263\345\217\260\357\274\211", Q_NULLPTR));
        label_14->setText(QApplication::translate("widconfig", "X \351\200\237\345\272\246\357\274\210\345\271\263\345\217\260\357\274\211", Q_NULLPTR));
        label_19->setText(QApplication::translate("widconfig", "Y \344\275\215\347\275\256\357\274\210\345\271\263\345\217\260\357\274\211", Q_NULLPTR));
        label_20->setText(QApplication::translate("widconfig", "Y \351\200\237\345\272\246\357\274\210\345\271\263\345\217\260\357\274\211", Q_NULLPTR));
        label_21->setText(QApplication::translate("widconfig", "Z \344\275\215\347\275\256", Q_NULLPTR));
        label_22->setText(QApplication::translate("widconfig", "Z \351\200\237\345\272\246", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("widconfig", "\346\265\213\350\257\225", Q_NULLPTR));
        label_23->setText(QApplication::translate("widconfig", "\351\246\226\344\270\252\344\275\215\347\275\256 X", Q_NULLPTR));
        label_24->setText(QApplication::translate("widconfig", "\351\246\226\344\270\252\344\275\215\347\275\256 Y", Q_NULLPTR));
        label_26->setText(QApplication::translate("widconfig", "Y \351\200\237\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class widconfig: public Ui_widconfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDCONFIG_H
