/********************************************************************************
** Form generated from reading UI file 'notemanager.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEMANAGER_H
#define UI_NOTEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteManager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *titleLineEdit;
    QLabel *label_2;
    QComboBox *categoryComboBox;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QPushButton *addButton;
    QPushButton *editButton;
    QTextEdit *contentTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *searchLineEdit;
    QLabel *label_5;
    QComboBox *searchCategoryComboBox;
    QPushButton *searchButton;
    QPushButton *deleteButton;
    QTableView *notesTableView;

    void setupUi(QWidget *NoteManager)
    {
        if (NoteManager->objectName().isEmpty())
            NoteManager->setObjectName("NoteManager");
        NoteManager->resize(600, 500);
        verticalLayout = new QVBoxLayout(NoteManager);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(NoteManager);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        titleLineEdit = new QLineEdit(NoteManager);
        titleLineEdit->setObjectName("titleLineEdit");

        horizontalLayout->addWidget(titleLineEdit);

        label_2 = new QLabel(NoteManager);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        categoryComboBox = new QComboBox(NoteManager);
        categoryComboBox->setObjectName("categoryComboBox");

        horizontalLayout->addWidget(categoryComboBox);

        label_3 = new QLabel(NoteManager);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        dateEdit = new QDateEdit(NoteManager);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        addButton = new QPushButton(NoteManager);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        editButton = new QPushButton(NoteManager);
        editButton->setObjectName("editButton");
        editButton->setEnabled(false);

        horizontalLayout->addWidget(editButton);


        verticalLayout->addLayout(horizontalLayout);

        contentTextEdit = new QTextEdit(NoteManager);
        contentTextEdit->setObjectName("contentTextEdit");

        verticalLayout->addWidget(contentTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(NoteManager);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        searchLineEdit = new QLineEdit(NoteManager);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout_2->addWidget(searchLineEdit);

        label_5 = new QLabel(NoteManager);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        searchCategoryComboBox = new QComboBox(NoteManager);
        searchCategoryComboBox->setObjectName("searchCategoryComboBox");

        horizontalLayout_2->addWidget(searchCategoryComboBox);

        searchButton = new QPushButton(NoteManager);
        searchButton->setObjectName("searchButton");

        horizontalLayout_2->addWidget(searchButton);

        deleteButton = new QPushButton(NoteManager);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setEnabled(false);

        horizontalLayout_2->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout_2);

        notesTableView = new QTableView(NoteManager);
        notesTableView->setObjectName("notesTableView");

        verticalLayout->addWidget(notesTableView);


        retranslateUi(NoteManager);

        QMetaObject::connectSlotsByName(NoteManager);
    } // setupUi

    void retranslateUi(QWidget *NoteManager)
    {
        label->setText(QCoreApplication::translate("NoteManager", "Title:", nullptr));
        label_2->setText(QCoreApplication::translate("NoteManager", "Category:", nullptr));
        label_3->setText(QCoreApplication::translate("NoteManager", "Date:", nullptr));
        addButton->setText(QCoreApplication::translate("NoteManager", "Add Note", nullptr));
        editButton->setText(QCoreApplication::translate("NoteManager", "Edit Note", nullptr));
        label_4->setText(QCoreApplication::translate("NoteManager", "Search:", nullptr));
        label_5->setText(QCoreApplication::translate("NoteManager", "Category:", nullptr));
        searchButton->setText(QCoreApplication::translate("NoteManager", "Search", nullptr));
        deleteButton->setText(QCoreApplication::translate("NoteManager", "Delete Note", nullptr));
        (void)NoteManager;
    } // retranslateUi

};

namespace Ui {
    class NoteManager: public Ui_NoteManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEMANAGER_H
