/********************************************************************************
** Form generated from reading UI file 'visualizer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZER_H
#define UI_VISUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Visualizer
{
public:
    QTextBrowser *visualizerBrowser;

    void setupUi(QDialog *Visualizer)
    {
        if (Visualizer->objectName().isEmpty())
            Visualizer->setObjectName("Visualizer");
        Visualizer->resize(1200, 700);
        Visualizer->setStyleSheet(QString::fromUtf8("#visualizer{border-image: url(:/Pictures/MainWinBack.jpg);\n"
"}"));
        visualizerBrowser = new QTextBrowser(Visualizer);
        visualizerBrowser->setObjectName("visualizerBrowser");
        visualizerBrowser->setGeometry(QRect(50, 40, 1101, 621));

        retranslateUi(Visualizer);

        QMetaObject::connectSlotsByName(Visualizer);
    } // setupUi

    void retranslateUi(QDialog *Visualizer)
    {
        Visualizer->setWindowTitle(QCoreApplication::translate("Visualizer", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visualizer: public Ui_Visualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZER_H
