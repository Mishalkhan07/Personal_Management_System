#include "dbmanager.h"
#include <QMessageBox>

DbManager::DbManager(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qCritical() << "Database connection error:" << m_db.lastError().text();
        QMessageBox::critical(nullptr, "Database Error",
                              "Cannot open database: " + m_db.lastError().text());
    } else {
        qDebug() << "Database connected:" << path;
        createTables();
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createTables()
{
    if (!m_db.isOpen()) {
        qCritical() << "Database not open for table creation";
        return false;
    }

    QSqlQuery query;
    bool success = true;

    // Enable foreign key support
    if (!query.exec("PRAGMA foreign_keys = ON")) {
        qCritical() << "Couldn't enable foreign keys:" << query.lastError();
        success = false;
    }

    // Create tables in a transaction
    if (!m_db.transaction()) {
        qCritical() << "Couldn't start transaction:" << m_db.lastError();
        return false;
    }

    // User table
    if (!query.exec("CREATE TABLE IF NOT EXISTS User ("
                    "userID INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "username TEXT UNIQUE NOT NULL, "
                    "password TEXT NOT NULL, "
                    "name TEXT, "
                    "DOB TEXT, "
                    "contact TEXT)")) {
        qCritical() << "Couldn't create User table:" << query.lastError();
        success = false;
    }

    // Tasks table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Tasks ("
                    "taskID INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "userID INTEGER NOT NULL, "
                    "title TEXT NOT NULL, "
                    "description TEXT, "
                    "dueDate TEXT, "
                    "priority INTEGER, "
                    "completed INTEGER DEFAULT 0, "
                    "FOREIGN KEY(userID) REFERENCES User(userID) ON DELETE CASCADE)")) {
        qCritical() << "Couldn't create Tasks table:" << query.lastError();
        success = false;
    }

    // Calendar table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Calendar ("
                    "eventID INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "userID INTEGER NOT NULL, "
                    "eventTitle TEXT NOT NULL, "
                    "eventDescription TEXT, "
                    "eventDate TEXT, "
                    "eventTime TEXT, "
                    "reminder INTEGER DEFAULT 0, "
                    "FOREIGN KEY(userID) REFERENCES User(userID) ON DELETE CASCADE)")) {
        qCritical() << "Couldn't create Calendar table:" << query.lastError();
        success = false;
    }

    // Finance table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Finance ("
                    "transactionID INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "userID INTEGER NOT NULL, "
                    "type TEXT NOT NULL, "
                    "amount REAL NOT NULL, "
                    "date TEXT, "
                    "category TEXT, "
                    "description TEXT, "
                    "FOREIGN KEY(userID) REFERENCES User(userID) ON DELETE CASCADE)")) {
        qCritical() << "Couldn't create Finance table:" << query.lastError();
        success = false;
    }

    // Notes table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Notes ("
                    "noteID INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "userID INTEGER NOT NULL, "
                    "title TEXT NOT NULL, "
                    "content TEXT, "
                    "category TEXT, "
                    "date TEXT, "
                    "FOREIGN KEY(userID) REFERENCES User(userID) ON DELETE CASCADE)")) {
        qCritical() << "Couldn't create Notes table:" << query.lastError();
        success = false;
    }

    if (success) {
        if (!m_db.commit()) {
            qCritical() << "Couldn't commit transaction:" << m_db.lastError();
            success = false;
        }
    } else {
        if (!m_db.rollback()) {
            qCritical() << "Couldn't rollback transaction:" << m_db.lastError();
        }
    }

    return success;
}

bool DbManager::userExists(const QString& username) const
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("SELECT username FROM User WHERE username = (:username)");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}

bool DbManager::addUser(const QString& username, const QString& password,
                        const QString& name, const QString& dob, const QString& contact)
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO User (username, password, name, DOB, contact) "
                  "VALUES (:username, :password, :name, :DOB, :contact)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":name", name);
    query.bindValue(":DOB", dob);
    query.bindValue(":contact", contact);

    if (!query.exec()) {
        qCritical() << "Add user error:" << query.lastError();
        return false;
    }
    return true;
}

bool DbManager::authenticateUser(const QString& username, const QString& password) const
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("SELECT username FROM User WHERE username = (:username) AND password = (:password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        return true;
    }
    qDebug() << "Authentication failed:" << query.lastError();
    return false;
}

int DbManager::getUserId(const QString& username) const
{
    if (!m_db.isOpen()) return -1;

    QSqlQuery query;
    query.prepare("SELECT userID FROM User WHERE username = (:username)");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}
