/********************************************************************************
** Form generated from reading UI file 'ImageWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWINDOW_H
#define UI_IMAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageWindow
{
public:
    QGraphicsView *ShowImage;
    QLabel *poslabel;
    QLabel *picvalue;

    void setupUi(QWidget *ImageWindow)
    {
        if (ImageWindow->objectName().isEmpty())
            ImageWindow->setObjectName(QString::fromUtf8("ImageWindow"));
        ImageWindow->resize(774, 524);
        ShowImage = new QGraphicsView(ImageWindow);
        ShowImage->setObjectName(QString::fromUtf8("ShowImage"));
        ShowImage->setGeometry(QRect(9, 9, 751, 451));
        ShowImage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        poslabel = new QLabel(ImageWindow);
        poslabel->setObjectName(QString::fromUtf8("poslabel"));
        poslabel->setGeometry(QRect(20, 490, 121, 20));
        picvalue = new QLabel(ImageWindow);
        picvalue->setObjectName(QString::fromUtf8("picvalue"));
        picvalue->setGeometry(QRect(160, 490, 121, 20));

        retranslateUi(ImageWindow);

        QMetaObject::connectSlotsByName(ImageWindow);
    } // setupUi

    void retranslateUi(QWidget *ImageWindow)
    {
        ImageWindow->setWindowTitle(QApplication::translate("ImageWindow", "ImageWindow", nullptr));
        poslabel->setText(QString());
        picvalue->setText(QApplication::translate("ImageWindow", "value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageWindow: public Ui_ImageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWINDOW_H
