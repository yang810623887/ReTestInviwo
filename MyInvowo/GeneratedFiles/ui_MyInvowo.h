/********************************************************************************
** Form generated from reading UI file 'MyInvowo.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYINVOWO_H
#define UI_MYINVOWO_H

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

class Ui_MyInvowoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyInvowoClass)
    {
        if (MyInvowoClass->objectName().isEmpty())
            MyInvowoClass->setObjectName(QStringLiteral("MyInvowoClass"));
        MyInvowoClass->resize(600, 400);
        menuBar = new QMenuBar(MyInvowoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyInvowoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyInvowoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyInvowoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyInvowoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyInvowoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyInvowoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyInvowoClass->setStatusBar(statusBar);

        retranslateUi(MyInvowoClass);

        QMetaObject::connectSlotsByName(MyInvowoClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyInvowoClass)
    {
        MyInvowoClass->setWindowTitle(QApplication::translate("MyInvowoClass", "MyInvowo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyInvowoClass: public Ui_MyInvowoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYINVOWO_H
