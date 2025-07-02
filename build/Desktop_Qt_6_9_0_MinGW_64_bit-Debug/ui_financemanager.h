/********************************************************************************
** Form generated from reading UI file 'financemanager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINANCEMANAGER_H
#define UI_FINANCEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FinanceManager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *addTransactionLayout;
    QComboBox *typeComboBox;
    QLineEdit *descriptionLineEdit;
    QDoubleSpinBox *amountDoubleSpinBox;
    QComboBox *categoryComboBox;
    QDateEdit *dateEdit;
    QPushButton *clearButton;
    QPushButton *addButton;
    QTableView *transactionsTableView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QDateEdit *fromDateEdit;
    QLabel *label_7;
    QDateEdit *toDateEdit;
    QPushButton *reportButton;

    void setupUi(QWidget *FinanceManager)
    {
        if (FinanceManager->objectName().isEmpty())
            FinanceManager->setObjectName("FinanceManager");
        FinanceManager->resize(876, 383);
        FinanceManager->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 214, 20);"));
        verticalLayout = new QVBoxLayout(FinanceManager);
        verticalLayout->setObjectName("verticalLayout");
        addTransactionLayout = new QHBoxLayout();
        addTransactionLayout->setObjectName("addTransactionLayout");
        typeComboBox = new QComboBox(FinanceManager);
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->setObjectName("typeComboBox");
        typeComboBox->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: yellow;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 5px;\n"
"border-radius: 4px;\n"
""));

        addTransactionLayout->addWidget(typeComboBox);

        descriptionLineEdit = new QLineEdit(FinanceManager);
        descriptionLineEdit->setObjectName("descriptionLineEdit");
        descriptionLineEdit->setStyleSheet(QString::fromUtf8("border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 4px;\n"
"border-radius: 4px;\n"
"background-color: white;\n"
"font-size: 13px;"));

        addTransactionLayout->addWidget(descriptionLineEdit);

        amountDoubleSpinBox = new QDoubleSpinBox(FinanceManager);
        amountDoubleSpinBox->setObjectName("amountDoubleSpinBox");
        amountDoubleSpinBox->setStyleSheet(QString::fromUtf8("border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 3px;\n"
"border-radius: 3px;\n"
"background-color: white;"));
        amountDoubleSpinBox->setMaximum(999999.989999999990687);

        addTransactionLayout->addWidget(amountDoubleSpinBox);

        categoryComboBox = new QComboBox(FinanceManager);
        categoryComboBox->setObjectName("categoryComboBox");
        categoryComboBox->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: yellow;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 4px;\n"
"border-radius: 4px;\n"
""));

        addTransactionLayout->addWidget(categoryComboBox);

        dateEdit = new QDateEdit(FinanceManager);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 4px;\n"
"border-radius: 4px;\n"
"background-color: white;\n"
"\n"
""));
        dateEdit->setCalendarPopup(true);

        addTransactionLayout->addWidget(dateEdit);

        clearButton = new QPushButton(FinanceManager);
        clearButton->setObjectName("clearButton");
        clearButton->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: yellow;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 4px;\n"
"border-radius: 4px;\n"
"width: 40px;\n"
""));

        addTransactionLayout->addWidget(clearButton);

        addButton = new QPushButton(FinanceManager);
        addButton->setObjectName("addButton");
        addButton->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: yellow;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 4px;\n"
"border-radius: 4px;\n"
""));

        addTransactionLayout->addWidget(addButton);


        verticalLayout->addLayout(addTransactionLayout);

        transactionsTableView = new QTableView(FinanceManager);
        transactionsTableView->setObjectName("transactionsTableView");
        transactionsTableView->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);\n"
"border-radius: 8px;\n"
"border: 1px solid black;\n"
"background-image: url(:/images/ChatGPT Image May 2, 2025, 01_52_25 PM.png);"));

        verticalLayout->addWidget(transactionsTableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        deleteButton = new QPushButton(FinanceManager);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setEnabled(false);
        deleteButton->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: yellow;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 5px;\n"
"border-radius: 4px;"));

        horizontalLayout_3->addWidget(deleteButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_6 = new QLabel(FinanceManager);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: yellow;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 5px;\n"
"border-radius: 4px;\n"
""));

        horizontalLayout_3->addWidget(label_6);

        fromDateEdit = new QDateEdit(FinanceManager);
        fromDateEdit->setObjectName("fromDateEdit");
        fromDateEdit->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: white;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 5px;\n"
"border-radius: 4px;"));
        fromDateEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(fromDateEdit);

        label_7 = new QLabel(FinanceManager);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: yellow;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 5px;\n"
"border-radius: 4px;\n"
""));

        horizontalLayout_3->addWidget(label_7);

        toDateEdit = new QDateEdit(FinanceManager);
        toDateEdit->setObjectName("toDateEdit");
        toDateEdit->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: white;\n"
"color: black;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 5px;\n"
"border-radius: 4px;"));
        toDateEdit->setCalendarPopup(true);

        horizontalLayout_3->addWidget(toDateEdit);

        reportButton = new QPushButton(FinanceManager);
        reportButton->setObjectName("reportButton");
        reportButton->setStyleSheet(QString::fromUtf8("BACKGROUND-COLOR: blue;\n"
"color: white;\n"
"font-weight: bold;\n"
"border: 0.5px solid rgb(148, 148, 148);\n"
"padding: 6px;\n"
"border-radius: 4px;\n"
"font-size: 13px;"));

        horizontalLayout_3->addWidget(reportButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(FinanceManager);

        QMetaObject::connectSlotsByName(FinanceManager);
    } // setupUi

    void retranslateUi(QWidget *FinanceManager)
    {
        FinanceManager->setWindowTitle(QCoreApplication::translate("FinanceManager", "Finance Manager", nullptr));
        typeComboBox->setItemText(0, QCoreApplication::translate("FinanceManager", "Income", nullptr));
        typeComboBox->setItemText(1, QCoreApplication::translate("FinanceManager", "Expense", nullptr));

        descriptionLineEdit->setPlaceholderText(QCoreApplication::translate("FinanceManager", "Description", nullptr));
        amountDoubleSpinBox->setPrefix(QCoreApplication::translate("FinanceManager", "$", nullptr));
#if QT_CONFIG(tooltip)
        clearButton->setToolTip(QCoreApplication::translate("FinanceManager", "Clear form fields", nullptr));
#endif // QT_CONFIG(tooltip)
        clearButton->setText(QCoreApplication::translate("FinanceManager", "Clear", nullptr));
        addButton->setText(QCoreApplication::translate("FinanceManager", "Add Transaction", nullptr));
        deleteButton->setText(QCoreApplication::translate("FinanceManager", "Delete Transaction", nullptr));
        label_6->setText(QCoreApplication::translate("FinanceManager", "From:", nullptr));
        label_7->setText(QCoreApplication::translate("FinanceManager", "To:", nullptr));
        reportButton->setText(QCoreApplication::translate("FinanceManager", "Generate Report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinanceManager: public Ui_FinanceManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCEMANAGER_H
