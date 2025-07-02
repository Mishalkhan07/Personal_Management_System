#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(User *user, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_user(user)
{
    ui->setupUi(this);

    setWindowTitle("Personal Management System - " + m_user->getName());

    // Initialize managers
    m_taskManager = new TaskManager(m_user, this);
    m_calendarManager = new CalendarManager(m_user, this);
    m_financeManager = new FinanceManager(m_user, this);
    m_noteManager = new NoteManager(m_user, this);

    // Add tabs
    ui->tabWidget->addTab(m_taskManager, QIcon(":/icons/task.png"), "Tasks");
    ui->tabWidget->addTab(m_calendarManager, QIcon(":/icons/calendar.png"), "Calendar");
    ui->tabWidget->addTab(m_financeManager, QIcon(":/icons/finance.png"), "Finance");
    ui->tabWidget->addTab(m_noteManager, QIcon(":/icons/notes.png"), "Notes");

    // Connect tab change signal
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTabChanged(int index)
{
    switch(index) {
    case 0: // Tasks
        m_taskManager->refreshTasks();
        break;
    case 1: // Calendar
        m_calendarManager->refreshEvents();
        break;
    case 2: // Finance
        m_financeManager->refreshTransactions();
        break;
    case 3: // Notes
        m_noteManager->refreshNotes();
        break;
    }
}
