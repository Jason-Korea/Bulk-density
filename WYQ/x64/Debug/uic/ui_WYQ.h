/********************************************************************************
** Form generated from reading UI file 'WYQ.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYQ_H
#define UI_WYQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WYQClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WYQClass)
    {
        if (WYQClass->objectName().isEmpty())
            WYQClass->setObjectName(QString::fromUtf8("WYQClass"));
        WYQClass->resize(600, 400);
        menuBar = new QMenuBar(WYQClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        WYQClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WYQClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WYQClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(WYQClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        WYQClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(WYQClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WYQClass->setStatusBar(statusBar);

        retranslateUi(WYQClass);

        QMetaObject::connectSlotsByName(WYQClass);
    } // setupUi

    void retranslateUi(QMainWindow *WYQClass)
    {
        WYQClass->setWindowTitle(QCoreApplication::translate("WYQClass", "WYQ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WYQClass: public Ui_WYQClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYQ_H
