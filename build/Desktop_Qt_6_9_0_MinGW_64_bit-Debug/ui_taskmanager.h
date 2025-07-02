/********************************************************************************
** Form generated from reading UI file 'taskmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

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

class Ui_TaskManager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *titleLineEdit;
    QLabel *label_2;
    QDateEdit *dueDateEdit;
    QLabel *label_3;
    QComboBox *priorityComboBox;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QTextEdit *descriptionTextEdit;
    QTableView *tasksTableView;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteButton;
    QPushButton *completeButton;

    void setupUi(QWidget *TaskManager)
    {
        if (TaskManager->objectName().isEmpty())
            TaskManager->setObjectName("TaskManager");
        TaskManager->resize(600, 400);
        verticalLayout = new QVBoxLayout(TaskManager);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(TaskManager);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        titleLineEdit = new QLineEdit(TaskManager);
        titleLineEdit->setObjectName("titleLineEdit");

        horizontalLayout->addWidget(titleLineEdit);

        label_2 = new QLabel(TaskManager);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        dueDateEdit = new QDateEdit(TaskManager);
        dueDateEdit->setObjectName("dueDateEdit");
        dueDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dueDateEdit);

        label_3 = new QLabel(TaskManager);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        priorityComboBox = new QComboBox(TaskManager);
        priorityComboBox->setObjectName("priorityComboBox");

        horizontalLayout->addWidget(priorityComboBox);

        addButton = new QPushButton(TaskManager);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_4 = new QLabel(TaskManager);
        label_4->setObjectName("label_4");

        horizontalLayout_2->addWidget(label_4);

        descriptionTextEdit = new QTextEdit(TaskManager);
        descriptionTextEdit->setObjectName("descriptionTextEdit");

        horizontalLayout_2->addWidget(descriptionTextEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        tasksTableView = new QTableView(TaskManager);
        tasksTableView->setObjectName("tasksTableView");

        verticalLayout->addWidget(tasksTableView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        deleteButton = new QPushButton(TaskManager);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setEnabled(false);

        horizontalLayout_3->addWidget(deleteButton);

        completeButton = new QPushButton(TaskManager);
        completeButton->setObjectName("completeButton");
        completeButton->setEnabled(false);

        horizontalLayout_3->addWidget(completeButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(TaskManager);

        QMetaObject::connectSlotsByName(TaskManager);
    } // setupUi

    void retranslateUi(QWidget *TaskManager)
    {
        label->setText(QCoreApplication::translate("TaskManager", "Title:", nullptr));
        label_2->setText(QCoreApplication::translate("TaskManager", "Due Date:", nullptr));
        label_3->setText(QCoreApplication::translate("TaskManager", "Priority:", nullptr));
        addButton->setText(QCoreApplication::translate("TaskManager", "Add Task", nullptr));
        label_4->setText(QCoreApplication::translate("TaskManager", "Description:", nullptr));
        deleteButton->setText(QCoreApplication::translate("TaskManager", "Delete Task", nullptr));
        completeButton->setText(QCoreApplication::translate("TaskManager", "Mark Complete", nullptr));
        (void)TaskManager;
    } // retranslateUi

};

namespace Ui {
    class TaskManager: public Ui_TaskManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
