#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QStandardPaths>

class DbManager
{
public:
    DbManager(const QString& path);
    ~DbManager();

    bool isOpen() const;
    bool createTables();
    bool userExists(const QString& username) const;
    bool addUser(const QString& username, const QString& password, const QString& name,
                 const QString& dob, const QString& contact);
    bool authenticateUser(const QString& username, const QString& password) const;
    int getUserId(const QString& username) const;


private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
