/********************************************************************************
** Form generated from reading UI file 'aoi.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AOI_H
#define UI_AOI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AOIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AOIClass)
    {
        if (AOIClass->objectName().isEmpty())
            AOIClass->setObjectName(QStringLiteral("AOIClass"));
        AOIClass->resize(600, 400);
        menuBar = new QMenuBar(AOIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        AOIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AOIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AOIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AOIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AOIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AOIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AOIClass->setStatusBar(statusBar);

        retranslateUi(AOIClass);

        QMetaObject::connectSlotsByName(AOIClass);
    } // setupUi

    void retranslateUi(QMainWindow *AOIClass)
    {
        AOIClass->setWindowTitle(QApplication::translate("AOIClass", "AOI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AOIClass: public Ui_AOIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AOI_H
