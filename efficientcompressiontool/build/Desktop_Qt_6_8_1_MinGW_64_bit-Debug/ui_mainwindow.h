/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *browseButton;
    QTextBrowser *textBrowser;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *compressButton;
    QPushButton *decompressButton;
    QSpacerItem *verticalSpacer;
    QProgressBar *progressBar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 1100);
        MainWindow->setStyleSheet(QString::fromUtf8("/* General Styles */\n"
"* {\n"
"    font-family: \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Push Buttons */\n"
"QPushButton#browseButton, QPushButton#compressButton, QPushButton#decompressButton {\n"
"    background-color: #1e2f3a; /* Dark Blue Background */\n"
"    color: #ffffff; /* White Text */\n"
"    border: 2px solid #1a5a87; /* Border to complement the color scheme */\n"
"    border-radius: 8px; /* Rounded Corners */\n"
"    padding: 8px 16px; /* Padding for better appearance */\n"
"}\n"
"\n"
"QPushButton#browseButton:hover, QPushButton#compressButton:hover, QPushButton#decompressButton:hover {\n"
"    background-color: #1a5a87; /* Lighter blue on hover */\n"
"}\n"
"\n"
"QPushButton#browseButton:pressed, QPushButton#compressButton:pressed, QPushButton#decompressButton:pressed {\n"
"    background-color: #123d5c; /* Even darker blue when pressed */\n"
"}\n"
"\n"
"/* Heading Label */\n"
"QLabel {\n"
"    font-size: 24px; /* Larger font size for the heading */\n"
"    font-weight: "
                        "bold;\n"
"    color: #1e2f3a; /* Dark Blue Text */\n"
"    background-color: transparent; /* No background for text label */\n"
"    text-align: center;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    background-color: #d9e6f2; /* Light Blue Background */\n"
"    border: 2px solid #1e2f3a; /* Dark Blue Border */\n"
"    border-radius: 8px;\n"
"    text-align: center;\n"
"    color: #1e2f3a; /* Dark Blue Text */\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #1a5a87; /* Darker Blue for the progress chunk */\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"/* Text Browser */\n"
"QTextBrowser {\n"
"    background-color: #f8f9fa; /* Light Gray Background */\n"
"    border: 2px solid #1e2f3a; /* Dark Blue Border */\n"
"    border-radius: 8px;\n"
"    padding: 8px;\n"
"    color: #1e2f3a; /* Dark Blue Text */\n"
"}\n"
"\n"
"QTextBrowser QScrollBar:vertical, QTextBrowser QScrollBar:horizontal {\n"
"    background-color: #d9e6f2; /* Light Blue Scrollbar Background */\n"
"    border: 1px solid #1"
                        "e2f3a; /* Dark Blue Border */\n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QTextBrowser QScrollBar::handle {\n"
"    background-color: #1a5a87; /* Dark Blue Scrollbar Handle */\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QTextBrowser QScrollBar::handle:hover {\n"
"    background-color: #123d5c; /* Darker Blue Handle on Hover */\n"
"}\n"
"\n"
"QTextBrowser QScrollBar::add-line, QTextBrowser QScrollBar::sub-line {\n"
"    background-color: #1e2f3a; /* Dark Blue Arrows */\n"
"    border: none;\n"
"}\n"
"\n"
"QTextBrowser QScrollBar::add-line:hover, QTextBrowser QScrollBar::sub-line:hover {\n"
"    background-color: #1a5a87; /* Hover State for Arrows */\n"
"}\n"
"\n"
"QTextBrowser QScrollBar::up-arrow, QTextBrowser QScrollBar::down-arrow,\n"
"QTextBrowser QScrollBar::left-arrow, QTextBrowser QScrollBar::right-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    background: #ffffff; /* White Arrows */\n"
"}\n"
"\n"
"QTextBrowser QScrollBar::add-page, QTextBrowser QScrollBar::sub-page {\n"
"    bac"
                        "kground: none; /* Transparent pages */\n"
"}\n"
"/* MessageBox Styles */\n"
"QMessageBox {\n"
"    background-color: #f8f9fa; /* Light Gray Background */\n"
"    color: #1e2f3a; /* Dark Blue Text */\n"
"}\n"
"\n"
"/* MessageBox Text */\n"
"QMessageBox QLabel {\n"
"    color: #1e2f3a; /* Ensure text color is dark blue */\n"
"}\n"
"\n"
"/* MessageBox Button */\n"
"QMessageBox QPushButton {\n"
"    background-color: #1e2f3a; /* Dark Blue Background for buttons */\n"
"    color: #ffffff; /* White Text */\n"
"    border: 2px solid #1a5a87; /* Dark Blue Border */\n"
"    border-radius: 8px; /* Rounded Corners */\n"
"    padding: 8px 16px; /* Padding for buttons */\n"
"}\n"
"\n"
"QMessageBox QPushButton:hover {\n"
"    background-color: #1a5a87; /* Lighter blue on hover */\n"
"}\n"
"\n"
"QMessageBox QPushButton:pressed {\n"
"    background-color: #123d5c; /* Even darker blue when pressed */\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"#centralwidget {\n"
"border-image: url(:/Pictures/MainWinBack.jpg);\n"
"}\n"
""));
        browseButton = new QPushButton(centralwidget);
        browseButton->setObjectName("browseButton");
        browseButton->setGeometry(QRect(630, 830, 151, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        browseButton->setFont(font);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(110, 260, 671, 561));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 70, 591, 171));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 920, 671, 104));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        compressButton = new QPushButton(widget);
        compressButton->setObjectName("compressButton");

        horizontalLayout->addWidget(compressButton);

        decompressButton = new QPushButton(widget);
        decompressButton->setObjectName("decompressButton");

        horizontalLayout->addWidget(decompressButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", " Browse", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Efficient Compression and Decompression System", nullptr));
        compressButton->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        decompressButton->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
