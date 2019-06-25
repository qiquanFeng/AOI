/********************************************************************************
** Form generated from reading UI file 'LabelEx.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELEX_H
#define UI_LABELEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_LabelEx
{
public:

    void setupUi(QLabel *LabelEx)
    {
        if (LabelEx->objectName().isEmpty())
            LabelEx->setObjectName(QStringLiteral("LabelEx"));
        LabelEx->resize(400, 300);

        retranslateUi(LabelEx);

        QMetaObject::connectSlotsByName(LabelEx);
    } // setupUi

    void retranslateUi(QLabel *LabelEx)
    {
        LabelEx->setWindowTitle(QApplication::translate("LabelEx", "LabelEx", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LabelEx: public Ui_LabelEx {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELEX_H
