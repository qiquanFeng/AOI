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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_axisDebug
{
public:
    QWidget *widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
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
        axisDebug->resize(1019, 86);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1011, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_card = new QComboBox(horizontalLayoutWidget);
        comboBox_card->setObjectName(QStringLiteral("comboBox_card"));

        horizontalLayout->addWidget(comboBox_card);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox_axis = new QComboBox(horizontalLayoutWidget);
        comboBox_axis->setObjectName(QStringLiteral("comboBox_axis"));

        horizontalLayout->addWidget(comboBox_axis);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        spinBox_speed = new QSpinBox(horizontalLayoutWidget);
        spinBox_speed->setObjectName(QStringLiteral("spinBox_speed"));
        spinBox_speed->setMaximum(90000);

        horizontalLayout->addWidget(spinBox_speed);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        spinBox_target = new QSpinBox(horizontalLayoutWidget);
        spinBox_target->setObjectName(QStringLiteral("spinBox_target"));
        spinBox_target->setMaximum(3000000);

        horizontalLayout->addWidget(spinBox_target);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        comboBox_mode = new QComboBox(horizontalLayoutWidget);
        comboBox_mode->setObjectName(QStringLiteral("comboBox_mode"));

        horizontalLayout->addWidget(comboBox_mode);

        pushButton_start = new QPushButton(horizontalLayoutWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));

        horizontalLayout->addWidget(pushButton_start);

        pushButton_stop = new QPushButton(horizontalLayoutWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));

        horizontalLayout->addWidget(pushButton_stop);

        axisDebug->setWidget(widget);

        retranslateUi(axisDebug);

        QMetaObject::connectSlotsByName(axisDebug);
    } // setupUi

    void retranslateUi(QDockWidget *axisDebug)
    {
        axisDebug->setWindowTitle(QApplication::translate("axisDebug", "axisDebug", Q_NULLPTR));
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
