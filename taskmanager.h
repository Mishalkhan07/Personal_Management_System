#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QItemSelection>
#include "user.h"

namespace Ui {
class TaskManager;
}

class TaskManager : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManager(User *user, QWidget *parent = nullptr);
    ~TaskManager();
    void refreshTasks();

private slots:
    void onAddTask();
    void onDeleteTask();
    void onTaskComplete();
    void onTaskSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::TaskManager *ui;
    User *m_user;
    QSqlTableModel *m_taskModel;
    void setupModel();
    void setupUI();
};

#endif // TASKMANAGER_H
