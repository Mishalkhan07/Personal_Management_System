#include "mainwindow.h"
#include "user.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include <QMessageBox>
#include <QDialog>
#include "ui_login.h"
#include "ui_register.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Correct order: first define dbPath

    // Setup SQLite database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QDir::currentPath() + "/pms_db.db";
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return -1;
    }

    // Login Dialog setup
    QDialog loginDialog;
    Ui::Login loginUi;
    loginUi.setupUi(&loginDialog);
    loginDialog.setWindowTitle("Personal Management System - Login");

    // Register Dialog setup
    QDialog registerDialog;
    Ui::Register registerUi;
    registerUi.setupUi(&registerDialog);
    registerDialog.setWindowTitle("Register New Account");

    // User object
    User user;

    // Connect login signals
    QObject::connect(loginUi.loginButton, &QPushButton::clicked, [&]() {
        QString username = loginUi.usernameLineEdit->text();
        QString password = loginUi.passwordLineEdit->text();

        if (user.login(username, password)) {
            loginDialog.accept();
        } else {
            QMessageBox::warning(&loginDialog, "Error", "Invalid username or password");
        }
    });

    // Open register dialog
    QObject::connect(loginUi.registerButton, &QPushButton::clicked, [&]() {
        registerUi.usernameLineEdit->clear();
        registerUi.passwordLineEdit->clear();
        registerUi.nameLineEdit->clear();
        registerUi.dobDateEdit->setDate(QDate::currentDate());
        registerUi.contactLineEdit->clear();
        registerDialog.exec();
    });

    // Register new user
    QObject::connect(registerUi.registerButton, &QPushButton::clicked, [&]() {
        QString username = registerUi.usernameLineEdit->text();
        QString password = registerUi.passwordLineEdit->text();
        QString name = registerUi.nameLineEdit->text();
        QString dob = registerUi.dobDateEdit->date().toString("yyyy-MM-dd");
        QString contact = registerUi.contactLineEdit->text();

        if (username.isEmpty() || password.isEmpty() || name.isEmpty()) {
            QMessageBox::warning(&registerDialog, "Error", "Username, password, and name are required");
            return;
        }

        if (user.registerUser(username, password, name, dob, contact)) {
            QMessageBox::information(&registerDialog, "Success", "Registration successful. Please login.");
            registerDialog.close();
        } else {
            QMessageBox::warning(&registerDialog, "Error", "Registration failed. Username may already exist.");
        }
    });

    QObject::connect(registerUi.backButton, &QPushButton::clicked, &registerDialog, &QDialog::close);

    // Show login window
    if (loginDialog.exec() == QDialog::Accepted) {
        MainWindow w(&user);
        w.show();
        return a.exec();
    }

    return 0;
}
