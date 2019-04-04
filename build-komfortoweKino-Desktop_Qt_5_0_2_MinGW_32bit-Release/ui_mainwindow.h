/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QCustomPlot *widget;
    QCustomPlot *widget_2;
    QCustomPlot *widget_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QTableWidget *tableWidget;
    QLabel *label_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_10;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QLabel *label_8;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QLabel *label_15;
    QLineEdit *lineEdit_6;
    QLabel *label_13;
    QLineEdit *lineEdit_7;
    QLabel *label_14;
    QLineEdit *lineEdit_8;
    QLabel *label_16;
    QLineEdit *lineEdit_9;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_11;
    QLineEdit *lineEdit_5;
    QLabel *label_17;
    QLineEdit *lineEdit_11;
    QLabel *label_18;
    QLineEdit *lineEdit_12;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QLabel *label_10;
    QLineEdit *lineEdit_4;
    QTableWidget *tableWidget_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 650);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(390, 500, 201, 50));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 560, 160, 25));
        widget = new QCustomPlot(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 50, 300, 300));
        widget_2 = new QCustomPlot(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(450, 50, 300, 300));
        widget_3 = new QCustomPlot(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(850, 50, 300, 300));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(49, 10, 1158, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(250);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(100, 0, 100, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 410, 221, 181));
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(2);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setStretchLastSection(false);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 380, 121, 20));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(236, 409, 151, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        lineEdit_10 = new QLineEdit(verticalLayoutWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        verticalLayout->addWidget(lineEdit_10);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setScaledContents(false);
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout->addWidget(label_6);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(400, 410, 161, 41));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_2->addWidget(label_7);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(390, 460, 201, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(990, 390, 71, 31));
        label_8->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(1069, 359, 121, 221));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_3->addWidget(label_12);

        label_15 = new QLabel(verticalLayoutWidget_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_3->addWidget(label_15);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        verticalLayout_3->addWidget(lineEdit_6);

        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_3->addWidget(label_13);

        lineEdit_7 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        verticalLayout_3->addWidget(lineEdit_7);

        label_14 = new QLabel(verticalLayoutWidget_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_3->addWidget(label_14);

        lineEdit_8 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        verticalLayout_3->addWidget(lineEdit_8);

        label_16 = new QLabel(verticalLayoutWidget_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_3->addWidget(label_16);

        lineEdit_9 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        verticalLayout_3->addWidget(lineEdit_9);

        verticalLayoutWidget_4 = new QWidget(centralWidget);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(600, 369, 151, 221));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(verticalLayoutWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_4->addWidget(label_11);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        verticalLayout_4->addWidget(lineEdit_5);

        label_17 = new QLabel(verticalLayoutWidget_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_4->addWidget(label_17);

        lineEdit_11 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        verticalLayout_4->addWidget(lineEdit_11);

        label_18 = new QLabel(verticalLayoutWidget_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_18);

        lineEdit_12 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        verticalLayout_4->addWidget(lineEdit_12);

        pushButton_6 = new QPushButton(verticalLayoutWidget_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_4->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(verticalLayoutWidget_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout_4->addWidget(pushButton_7);

        verticalLayoutWidget_5 = new QWidget(centralWidget);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(990, 435, 71, 91));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(verticalLayoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_5->addWidget(label_9);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_5->addWidget(lineEdit_3);

        label_10 = new QLabel(verticalLayoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_5->addWidget(label_10);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_5);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_5->addWidget(lineEdit_4);

        tableWidget_2 = new QTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(760, 370, 221, 221));
        tableWidget_2->setColumnCount(3);
        tableWidget_2->verticalHeader()->setStretchLastSection(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Komfortowe kino", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Pole na komunikaty, przyk\305\202adowo: brak danych, niew\305\202a\305\233ciwe dane, zako\305\204czenie symulacji, b\305\202\304\231dy.</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Uruchom symulacj\304\231", 0));
        label_3->setText(QApplication::translate("MainWindow", "Przebieg temperatury", 0));
        label_2->setText(QApplication::translate("MainWindow", "Przebieg wilgotno\305\233ci", 0));
        label->setText(QApplication::translate("MainWindow", "Przebieg st\304\231\305\274enia CO2", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "SP", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Moc", 0));
        label_4->setText(QApplication::translate("MainWindow", "Jednostki klimatyzacyjne", 0));
        label_5->setText(QApplication::translate("MainWindow", "Temperatura zadana\n"
"klimatyzatora", 0));
        label_6->setText(QApplication::translate("MainWindow", "Moc jednostki", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Dodaj now\304\205 jednostk\304\231", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Usu\305\204 zaznaczon\304\205 jednostk\304\231", 0));
        label_7->setText(QApplication::translate("MainWindow", "Liczba ludzi w pomieszczeniu", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Dodaj osob\304\231", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Usu\305\204 osob\304\231", 0));
        label_8->setText(QApplication::translate("MainWindow", "Warunki\n"
"zewn\304\231trzne", 0));
        label_12->setText(QApplication::translate("MainWindow", "Warunki pocz\304\205tkowe", 0));
        label_15->setText(QApplication::translate("MainWindow", "Temperatura", 0));
        label_13->setText(QApplication::translate("MainWindow", "Wilgotno\305\233\304\207", 0));
        label_14->setText(QApplication::translate("MainWindow", "St\304\231\305\274enie CO2", 0));
        label_16->setText(QApplication::translate("MainWindow", "Obj\304\231to\305\233\304\207 pomieszczenia", 0));
        label_11->setText(QApplication::translate("MainWindow", "D\305\202ugo\305\233\304\207 trasy\n"
"powietrza", 0));
        label_17->setText(QApplication::translate("MainWindow", "Pole przekroju\n"
"wentylacji", 0));
        label_18->setText(QApplication::translate("MainWindow", "Pr\304\231dko\305\233c powietrza", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Dodaj wentylacje", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Usun wentylacje", 0));
        label_9->setText(QApplication::translate("MainWindow", "Temperatura", 0));
        label_10->setText(QApplication::translate("MainWindow", "Wilgotno\305\233\304\207", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "D\305\202ugo\305\233\304\207", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Przekr\303\263j", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Pr\304\231dko\305\233\304\207", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
