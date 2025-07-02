/********************************************************************************
** Form generated from reading UI file 'calendarmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARMANAGER_H
#define UI_CALENDARMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarManager
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *titleLineEdit;
    QLabel *label_2;
    QDateEdit *eventDateEdit;
    QLabel *label_3;
    QTimeEdit *eventTimeEdit;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QTextEdit *descriptionTextEdit;
    QCheckBox *reminderCheckBox;
    QTableView *eventsTableView;
    QPushButton *deleteButton;

    void setupUi(QWidget *CalendarManager)
    {
        if (CalendarManager->objectName().isEmpty())
            CalendarManager->setObjectName("CalendarManager");
        CalendarManager->resize(600, 500);
        verticalLayout = new QVBoxLayout(CalendarManager);
        verticalLayout->setObjectName("verticalLayout");
        calendarWidget = new QCalendarWidget(CalendarManager);
        calendarWidget->setObjectName("calendarWidget");

        verticalLayout->addWidget(calendarWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(CalendarManager);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        titleLineEdit = new QLineEdit(CalendarManager);
        titleLineEdit->setObjectName("titleLineEdit");

        horizontalLayout->addWidget(titleLineEdit);

        label_2 = new QLabel(CalendarManager);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        eventDateEdit = new QDateEdit(CalendarManager);
        eventDateEdit->setObjectName("eventDateEdit");
        eventDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(eventDateEdit);

        label_3 = new QLabel(CalendarManager);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        eventTimeEdit = new QTimeEdit(CalendarManager);
        eventTimeEdit->setObjectName("eventTimeEdit");

        horizontalLayout->addWidget(eventTimeEdit);

        addButton = new QPushButton(CalendarManager);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(CalendarManager);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        descriptionTextEdit = new QTextEdit(CalendarManager);
        descriptionTextEdit->setObjectName("descriptionTextEdit");

        horizontalLayout_2->addWidget(descriptionTextEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        reminderCheckBox = new QCheckBox(CalendarManager);
        reminderCheckBox->setObjectName("reminderCheckBox");

        verticalLayout->addWidget(reminderCheckBox);

        eventsTableView = new QTableView(CalendarManager);
        eventsTableView->setObjectName("eventsTableView");

        verticalLayout->addWidget(eventsTableView);

        deleteButton = new QPushButton(CalendarManager);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setEnabled(false);

        verticalLayout->addWidget(deleteButton);


        retranslateUi(CalendarManager);

        QMetaObject::connectSlotsByName(CalendarManager);
    } // setupUi

    void retranslateUi(QWidget *CalendarManager)
    {
        label->setText(QCoreApplication::translate("CalendarManager", "Event Title:", nullptr));
        label_2->setText(QCoreApplication::translate("CalendarManager", "Date:", nullptr));
        label_3->setText(QCoreApplication::translate("CalendarManager", "Time:", nullptr));
        addButton->setText(QCoreApplication::translate("CalendarManager", "Add Event", nullptr));
        label_4->setText(QCoreApplication::translate("CalendarManager", "Description:", nullptr));
        reminderCheckBox->setText(QCoreApplication::translate("CalendarManager", "Set Reminder", nullptr));
        deleteButton->setText(QCoreApplication::translate("CalendarManager", "Delete Event", nullptr));
        (void)CalendarManager;
    } // retranslateUi

};

namespace Ui {
    class CalendarManager: public Ui_CalendarManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARMANAGER_H
