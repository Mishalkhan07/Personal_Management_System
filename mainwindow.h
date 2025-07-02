#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "user.h"
#include "taskmanager.h"
#include "calendarmanager.h"
#include "financemanager.h"
#include "notemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(User *user, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTabChanged(int index);

private:
    Ui::MainWindow *ui;
    User *m_user;
    TaskManager *m_taskManager;
    CalendarManager *m_calendarManager;
    FinanceManager *m_financeManager;
    NoteManager *m_noteManager;
};
#endif // MAINWINDOW_H
