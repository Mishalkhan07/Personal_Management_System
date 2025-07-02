#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include "dbmanager.h"

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    ~User();

    bool login(const QString &username, const QString &password);
    bool registerUser(const QString &username, const QString &password,
                      const QString &name, const QString &dob, const QString &contact);
    int getUserId() const;
    QString getUsername() const;
    QString getName() const;
    QString getDob() const;
    QString getContact() const;

private:
    DbManager* m_db;
    int m_userId;
    QString m_username;
    QString m_name;
    QString m_dob;
    QString m_contact;
};

#endif // USER_H
