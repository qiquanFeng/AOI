/********************************************************************************
** Form generated from reading UI file 'axisDebug.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXISDEBUG_H
#define UI_AXISDEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_axisDebug
{
public:
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_C0A0;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_C0A1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_C0A2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLabel *label_C1A0;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_10;
    QLabel *label_C1A1;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_11;
    QLabel *label_C1A2;
    QLabel *label;
    QComboBox *comboBox_card;
    QLabel *label_2;
    QComboBox *comboBox_axis;
    QLabel *label_3;
    QSpinBox *spinBox_speed;
    QLabel *label_4;
    QSpinBox *spinBox_target;
    QLabel *label_5;
    QComboBox *comboBox_mode;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;

    void setupUi(QDockWidget *axisDebug)
    {
        if (axisDebug->objectName().isEmpty())
            axisDebug->setObjectName(QStringLiteral("axisDebug"));
        axisDebug->resize(619, 91);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 30, 611, 34));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6, 0, Qt::AlignBottom);

        label_C0A0 = new QLabel(layoutWidget);
        label_C0A0->setObjectName(QStringLiteral("label_C0A0"));

        verticalLayout_2->addWidget(label_C0A0, 0, Qt::AlignTop);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7, 0, Qt::AlignBottom);

        label_C0A1 = new QLabel(layoutWidget);
        label_C0A1->setObjectName(QStringLiteral("label_C0A1"));

        verticalLayout_3->addWidget(label_C0A1, 0, Qt::AlignTop);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_4->addWidget(label_8, 0, Qt::AlignBottom);

        label_C0A2 = new QLabel(layoutWidget);
        label_C0A2->setObjectName(QStringLiteral("label_C0A2"));

        verticalLayout_4->addWidget(label_C0A2, 0, Qt::AlignTop);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_5->addWidget(label_9, 0, Qt::AlignBottom);

        label_C1A0 = new QLabel(layoutWidget);
        label_C1A0->setObjectName(QStringLiteral("label_C1A0"));

        verticalLayout_5->addWidget(label_C1A0, 0, Qt::AlignTop);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_6->addWidget(label_10, 0, Qt::AlignBottom);

        label_C1A1 = new QLabel(layoutWidget);
        label_C1A1->setObjectName(QStringLiteral("label_C1A1"));

        verticalLayout_6->addWidget(label_C1A1, 0, Qt::AlignTop);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_7->addWidget(label_11, 0, Qt::AlignBottom);

        label_C1A2 = new QLabel(layoutWidget);
        label_C1A2->setObjectName(QStringLiteral("label_C1A2"));

        verticalLayout_7->addWidget(label_C1A2, 0, Qt::AlignTop);


        horizontalLayout_2->addLayout(verticalLayout_7);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(2, 2, 36, 16));
        comboBox_card = new QComboBox(widget);
        comboBox_card->setObjectName(QStringLiteral("comboBox_card"));
        comboBox_card->setGeometry(QRect(44, 3, 32, 20));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(82, 2, 16, 16));
        comboBox_axis = new QComboBox(widget);
        comboBox_axis->setObjectName(QStringLiteral("comboBox_axis"));
        comboBox_axis->setGeometry(QRect(100, 3, 32, 20));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(138, 2, 24, 16));
        spinBox_speed = new QSpinBox(widget);
        spinBox_speed->setObjectName(QStringLiteral("spinBox_speed"));
        spinBox_speed->setGeometry(QRect(168, 3, 58, 20));
        spinBox_speed->setMaximum(90000);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(232, 2, 24, 16));
        spinBox_target = new QSpinBox(widget);
        spinBox_target->setObjectName(QStringLiteral("spinBox_target"));
        spinBox_target->setGeometry(QRect(262, 3, 76, 20));
        spinBox_target->setMinimum(-3000000);
        spinBox_target->setMaximum(3000000);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(344, 2, 24, 16));
        comboBox_mode = new QComboBox(widget);
        comboBox_mode->setObjectName(QStringLiteral("comboBox_mode"));
        comboBox_mode->setGeometry(QRect(374, 3, 74, 20));
        pushButton_start = new QPushButton(widget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(454, 2, 75, 23));
        pushButton_stop = new QPushButton(widget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(535, 2, 75, 23));
        axisDebug->setWidget(widget);

        retranslateUi(axisDebug);

        QMetaObject::connectSlotsByName(axisDebug);
    } // setupUi

    void retranslateUi(QDockWidget *axisDebug)
    {
        axisDebug->setWindowTitle(QApplication::translate("axisDebug", "axisDebug", Q_NULLPTR));
        label_6->setText(QApplication::translate("axisDebug", "\345\271\263\345\217\260X\350\275\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_C0A0->setToolTip(QApplication::translate("axisDebug", "card1", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_C0A0->setText(QApplication::translate("axisDebug", "C0:A0__", Q_NULLPTR));
        label_7->setText(QApplication::translate("axisDebug", "\345\271\263\345\217\260Y\350\275\264", Q_NULLPTR));
        label_C0A1->setText(QApplication::translate("axisDebug", "C0:A1__", Q_NULLPTR));
        label_8->setText(QApplication::translate("axisDebug", "\350\275\275\346\235\277\345\244\271", Q_NULLPTR));
        label_C0A2->setText(QApplication::translate("axisDebug", "C0:A2__", Q_NULLPTR));
        label_9->setText(QApplication::translate("axisDebug", "\344\270\212\346\226\231\350\275\264", Q_NULLPTR));
        label_C1A0->setText(QApplication::translate("axisDebug", "C1:A0__", Q_NULLPTR));
        label_10->setText(QApplication::translate("axisDebug", "\344\270\213\346\226\231\350\275\264", Q_NULLPTR));
        label_C1A1->setText(QApplication::translate("axisDebug", "C1:A1__", Q_NULLPTR));
        label_11->setText(QApplication::translate("axisDebug", "\346\216\250\346\235\206", Q_NULLPTR));
        label_C1A2->setText(QApplication::translate("axisDebug", "C1:A2__", Q_NULLPTR));
        label->setText(QApplication::translate("axisDebug", "\350\277\220\345\212\250\345\215\241", Q_NULLPTR));
        comboBox_card->clear();
        comboBox_card->insertItems(0, QStringList()
         << QApplication::translate("axisDebug", "0", Q_NULLPTR)
         << QApplication::translate("axisDebug", "1", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("axisDebug", "\350\275\264", Q_NULLPTR));
        comboBox_axis->clear();
        comboBox_axis->insertItems(0, QStringList()
         << QApplication::translate("axisDebug", "0", Q_NULLPTR)
         << QApplication::translate("axisDebug", "1", Q_NULLPTR)
         << QApplication::translate("axisDebug", "2", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("axisDebug", "\351\200\237\345\272\246", Q_NULLPTR));
        label_4->setText(QApplication::translate("axisDebug", "\347\233\256\346\240\207", Q_NULLPTR));
        label_5->setText(QApplication::translate("axisDebug", "\346\250\241\345\274\217", Q_NULLPTR));
        comboBox_mode->clear();
        comboBox_mode->insertItems(0, QStringList()
         << QApplication::translate("axisDebug", "\347\233\270\345\257\271\350\277\220\345\212\250", Q_NULLPTR)
         << QApplication::translate("axisDebug", "\347\273\235\345\257\271\350\277\220\345\212\250", Q_NULLPTR)
        );
        pushButton_start->setText(QApplication::translate("axisDebug", "\345\274\200\345\247\213", Q_NULLPTR));
        pushButton_stop->setText(QApplication::translate("axisDebug", "\346\200\245\345\201\234", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class axisDebug: public Ui_axisDebug {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXISDEBUG_H
