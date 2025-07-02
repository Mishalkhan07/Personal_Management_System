#ifndef CALENDARMANAGER_H
#define CALENDARMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QItemSelection>
#include "user.h"

namespace Ui {
class CalendarManager;
}

class CalendarManager : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarManager(User *user, QWidget *parent = nullptr);
    ~CalendarManager();
    void refreshEvents();

private slots:
    void onAddEvent();
    void onDeleteEvent();
    void onCalendarClicked(const QDate &date);
    void onEventSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::CalendarManager *ui;
    User *m_user;
    QSqlTableModel *m_eventModel;
    void setupModel();
    void setupUI();
};

#endif // CALENDARMANAGER_H
