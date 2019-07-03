/********************************************************************************
** Form generated from reading UI file 'aboutdia.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIA_H
#define UI_ABOUTDIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutDia
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *aboutDia)
    {
        if (aboutDia->objectName().isEmpty())
            aboutDia->setObjectName(QStringLiteral("aboutDia"));
        aboutDia->resize(609, 213);
        verticalLayoutWidget = new QWidget(aboutDia);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 601, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        retranslateUi(aboutDia);

        QMetaObject::connectSlotsByName(aboutDia);
    } // setupUi

    void retranslateUi(QDialog *aboutDia)
    {
        aboutDia->setWindowTitle(QApplication::translate("aboutDia", "aboutDia", Q_NULLPTR));
        label->setText(QApplication::translate("aboutDia", "<html><head/><body><p>AOI (Automatic Optical Inspection)</p><p>Version: 1.0.0</p><p><span style=\" font-family:'arial'; color:#333333; background-color:#ffffff;\">\302\2512019 JSL<br/><br/></span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:14px; font-weight:600; font-style:italic; color:#0000ff;\">J</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:14px; font-weight:600; font-style:italic; color:#9f9ea3;\">oying</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:14px; font-weight:600; font-style:italic; color:#0000ff;\">\302\240S</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:14px; font-weight:600; font-style:italic; color:#9f9ea3;\">haring</span><span style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:14px; font-weight:600; font-style:italic; color:#0000ff;\">\302\240L</span><span style=\" font-fami"
                        "ly:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:14px; font-weight:600; font-style:italic; color:#9f9ea3;\">earning</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aboutDia: public Ui_aboutDia {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIA_H
