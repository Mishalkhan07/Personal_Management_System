#include "user.h"

User::User(QObject *parent) : QObject(parent),
    m_db(new DbManager(QDir::currentPath() + "/pms_db.db")),
    m_userId(-1)
{
}

User::~User()
{
    delete m_db;
}

bool User::login(const QString &username, const QString &password)
{
    if (m_db->authenticateUser(username, password)) {
        m_userId = m_db->getUserId(username);

        QSqlQuery query;
        query.prepare("SELECT name, DOB, contact FROM User WHERE userID = (:userID)");
        query.bindValue(":userID", m_userId);

        if (query.exec() && query.next()) {
            m_username = username;
            m_name = query.value(0).toString();
            m_dob = query.value(1).toString();
            m_contact = query.value(2).toString();
            return true;
        }
    }
    return false;
}

bool User::registerUser(const QString &username, const QString &password,
                        const QString &name, const QString &dob, const QString &contact)
{
    return m_db->addUser(username, password, name, dob, contact);
}

int User::getUserId() const
{
    return m_userId;
}

QString User::getUsername() const
{
    return m_username;
}

QString User::getName() const
{
    return m_name;
}

QString User::getDob() const
{
    return m_dob;
}

QString User::getContact() const
{
    return m_contact;
}
