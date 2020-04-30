/********************************************************************************
** Form generated from reading UI file 'ifdealer_QT.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IFDEALER_QT_H
#define UI_IFDEALER_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ifdealer_QTClass
{
public:
    QWidget *centralWidget;
    QPushButton *SelectFile;
    QPushButton *Showimage;
    QSlider *blurSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ifdealer_QTClass)
    {
        if (ifdealer_QTClass->objectName().isEmpty())
            ifdealer_QTClass->setObjectName(QString::fromUtf8("ifdealer_QTClass"));
        ifdealer_QTClass->resize(600, 400);
        centralWidget = new QWidget(ifdealer_QTClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SelectFile = new QPushButton(centralWidget);
        SelectFile->setObjectName(QString::fromUtf8("SelectFile"));
        SelectFile->setGeometry(QRect(40, 60, 75, 23));
        Showimage = new QPushButton(centralWidget);
        Showimage->setObjectName(QString::fromUtf8("Showimage"));
        Showimage->setGeometry(QRect(40, 160, 75, 23));
        blurSlider = new QSlider(centralWidget);
        blurSlider->setObjectName(QString::fromUtf8("blurSlider"));
        blurSlider->setGeometry(QRect(70, 260, 160, 22));
        blurSlider->setMinimum(0);
        blurSlider->setMaximum(30);
        blurSlider->setSingleStep(1);
        blurSlider->setPageStep(12);
        blurSlider->setValue(1);
        blurSlider->setSliderPosition(1);
        blurSlider->setOrientation(Qt::Horizontal);
        ifdealer_QTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ifdealer_QTClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        ifdealer_QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ifdealer_QTClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ifdealer_QTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ifdealer_QTClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ifdealer_QTClass->setStatusBar(statusBar);

        retranslateUi(ifdealer_QTClass);

        QMetaObject::connectSlotsByName(ifdealer_QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *ifdealer_QTClass)
    {
        ifdealer_QTClass->setWindowTitle(QApplication::translate("ifdealer_QTClass", "ifdealer_QT", nullptr));
        SelectFile->setText(QApplication::translate("ifdealer_QTClass", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        Showimage->setText(QApplication::translate("ifdealer_QTClass", "\346\230\276\347\244\272\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ifdealer_QTClass: public Ui_ifdealer_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IFDEALER_QT_H
