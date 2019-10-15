/********************************************************************************
** Form generated from reading UI file 'servoguic.ui'
**
** Created: Fri Jan 10 05:08:28 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVOGUIC_H
#define UI_SERVOGUIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_servoGuiC
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *servoGuiC)
    {
        if (servoGuiC->objectName().isEmpty())
            servoGuiC->setObjectName(QString::fromUtf8("servoGuiC"));
        servoGuiC->resize(534, 368);
        centralWidget = new QWidget(servoGuiC);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 160, 108, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 160, 108, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 111, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 130, 78, 20));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 30, 141, 30));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 130, 78, 20));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 0, 51, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 131, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 130, 78, 20));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(210, 160, 108, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 80, 78, 20));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 210, 381, 75));
        servoGuiC->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(servoGuiC);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 534, 28));
        servoGuiC->setMenuBar(menuBar);
        mainToolBar = new QToolBar(servoGuiC);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        servoGuiC->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(servoGuiC);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        servoGuiC->setStatusBar(statusBar);

        retranslateUi(servoGuiC);

        QMetaObject::connectSlotsByName(servoGuiC);
    } // setupUi

    void retranslateUi(QMainWindow *servoGuiC)
    {
        servoGuiC->setWindowTitle(QApplication::translate("servoGuiC", "servoGuiC by JohanpG", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("servoGuiC", "->", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("servoGuiC", "<-", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("servoGuiC", "Entry Delay:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("servoGuiC", "Right", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("servoGuiC", "Left", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("servoGuiC", "Close", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("servoGuiC", "Current Delay:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("servoGuiC", "Center", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("servoGuiC", "--", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class servoGuiC: public Ui_servoGuiC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVOGUIC_H
