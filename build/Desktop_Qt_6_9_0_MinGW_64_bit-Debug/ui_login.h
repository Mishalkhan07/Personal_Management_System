/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(450, 380);
        Login->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Login);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold;\n"
"background-color: Yellow;\n"
"border-radius: 12px;\n"
"border: 2px solid rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font-size: 24px;\n"
"border-radius: 12px;\n"
"border: 2px solid rgb(84, 84, 84);\n"
"background-color: rgb(0, 85, 255);\n"
"color: white;\n"
"font-weight: bold;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        usernameLineEdit = new QLineEdit(Login);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(220, 220, 220);\n"
"border-radius: 12px;\n"
"padding: 12px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(Login);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid rgb(220, 220, 220);\n"
"border-radius: 12px;\n"
"padding: 12px;\n"
"font-size: 14px;"));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordLineEdit);

        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"border-radius: 8px;\n"
"border: 1px solid gray;\n"
"background-color: rgb(0, 85, 255);\n"
"color: white;\n"
"font-weight: bold;\n"
"padding: 10px;"));

        verticalLayout->addWidget(loginButton);

        registerButton = new QPushButton(Login);
        registerButton->setObjectName("registerButton");
        registerButton->setStyleSheet(QString::fromUtf8("padding: 10px;\n"
"font-size: 16px;\n"
"border-radius: 8px;\n"
"border: 1px solid gray;\n"
"background-color: red;;\n"
"color: white;\n"
"font-weight: bold;\n"
"padding: 10px;"));

        verticalLayout->addWidget(registerButton);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        label->setText(QCoreApplication::translate("Login", "Personal Management System", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Login", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("Login", "Username", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("Login", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "Login", nullptr));
        registerButton->setText(QCoreApplication::translate("Login", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
