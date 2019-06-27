/********************************************************************************
** Form generated from reading UI file 'DialogEx.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEX_H
#define UI_DIALOGEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogEx
{
public:

    void setupUi(QDialog *DialogEx)
    {
        if (DialogEx->objectName().isEmpty())
            DialogEx->setObjectName(QStringLiteral("DialogEx"));
        DialogEx->resize(392, 293);

        retranslateUi(DialogEx);

        QMetaObject::connectSlotsByName(DialogEx);
    } // setupUi

    void retranslateUi(QDialog *DialogEx)
    {
        DialogEx->setWindowTitle(QApplication::translate("DialogEx", "DialogEx", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogEx: public Ui_DialogEx {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEX_H
