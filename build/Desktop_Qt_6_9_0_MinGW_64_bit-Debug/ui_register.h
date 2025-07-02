/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *nameLineEdit;
    QDateEdit *dobDateEdit;
    QLineEdit *contactLineEdit;
    QPushButton *registerButton;
    QPushButton *backButton;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(400, 400);
        verticalLayout = new QVBoxLayout(Register);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Register);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold;"));

        verticalLayout->addWidget(label);

        usernameLineEdit = new QLineEdit(Register);
        usernameLineEdit->setObjectName("usernameLineEdit");

        verticalLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(Register);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordLineEdit);

        nameLineEdit = new QLineEdit(Register);
        nameLineEdit->setObjectName("nameLineEdit");

        verticalLayout->addWidget(nameLineEdit);

        dobDateEdit = new QDateEdit(Register);
        dobDateEdit->setObjectName("dobDateEdit");
        dobDateEdit->setCalendarPopup(true);

        verticalLayout->addWidget(dobDateEdit);

        contactLineEdit = new QLineEdit(Register);
        contactLineEdit->setObjectName("contactLineEdit");

        verticalLayout->addWidget(contactLineEdit);

        registerButton = new QPushButton(Register);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);

        backButton = new QPushButton(Register);
        backButton->setObjectName("backButton");

        verticalLayout->addWidget(backButton);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Register", nullptr));
        label->setText(QCoreApplication::translate("Register", "Register New Account", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("Register", "Username", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("Register", "Password", nullptr));
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("Register", "Full Name", nullptr));
        contactLineEdit->setPlaceholderText(QCoreApplication::translate("Register", "Contact Number", nullptr));
        registerButton->setText(QCoreApplication::translate("Register", "Register", nullptr));
        backButton->setText(QCoreApplication::translate("Register", "Back to Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
