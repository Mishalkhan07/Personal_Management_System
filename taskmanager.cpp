#include "taskmanager.h"
#include "ui_taskmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>

TaskManager::TaskManager(User *user, QWidget *parent) :
    QWidget(parent), ui(new Ui::TaskManager), m_user(user)
{
    ui->setupUi(this);
    setupModel();
    setupUI();
    refreshTasks();
}

TaskManager::~TaskManager()
{
    delete ui;
}

void TaskManager::setupModel()
{
    m_taskModel = new QSqlTableModel(this);
    m_taskModel->setTable("Tasks");
    m_taskModel->setFilter(QString("userID = %1").arg(m_user->getUserId()));
    m_taskModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_taskModel->setHeaderData(2, Qt::Horizontal, tr("Title"));
    m_taskModel->setHeaderData(3, Qt::Horizontal, tr("Description"));
    m_taskModel->setHeaderData(4, Qt::Horizontal, tr("Due Date"));
    m_taskModel->setHeaderData(5, Qt::Horizontal, tr("Priority"));
    m_taskModel->setHeaderData(6, Qt::Horizontal, tr("Completed"));
}

void TaskManager::setupUI()
{
    ui->tasksTableView->setModel(m_taskModel);
    ui->tasksTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tasksTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tasksTableView->setColumnHidden(0, true); // Hide taskID
    ui->tasksTableView->setColumnHidden(1, true); // Hide userID
    ui->tasksTableView->horizontalHeader()->setStretchLastSection(true);
    ui->tasksTableView->resizeColumnsToContents();

    ui->priorityComboBox->addItem("Low", 1);
    ui->priorityComboBox->addItem("Medium", 2);
    ui->priorityComboBox->addItem("High", 3);

    ui->dueDateEdit->setDate(QDate::currentDate());
    ui->dueDateEdit->setMinimumDate(QDate::currentDate());

    connect(ui->addButton, &QPushButton::clicked, this, &TaskManager::onAddTask);
    connect(ui->deleteButton, &QPushButton::clicked, this, &TaskManager::onDeleteTask);
    connect(ui->completeButton, &QPushButton::clicked, this, &TaskManager::onTaskComplete);
    connect(ui->tasksTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &TaskManager::onTaskSelectionChanged);
}

void TaskManager::refreshTasks()
{
    m_taskModel->select();
    ui->tasksTableView->resizeColumnsToContents();
}

void TaskManager::onAddTask()
{
    QString title = ui->titleLineEdit->text().trimmed();
    QString description = ui->descriptionTextEdit->toPlainText().trimmed();
    QDate dueDate = ui->dueDateEdit->date();
    int priority = ui->priorityComboBox->currentData().toInt();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Error", "Title cannot be empty");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Tasks (userID, title, description, dueDate, priority) "
                  "VALUES (:userID, :title, :description, :dueDate, :priority)");
    query.bindValue(":userID", m_user->getUserId());
    query.bindValue(":title", title);
    query.bindValue(":description", description);
    query.bindValue(":dueDate", dueDate.toString("yyyy-MM-dd"));
    query.bindValue(":priority", priority);

    if (query.exec()) {
        refreshTasks();
        ui->titleLineEdit->clear();
        ui->descriptionTextEdit->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add task: " + query.lastError().text());
    }
}

void TaskManager::onDeleteTask()
{
    QModelIndexList selected = ui->tasksTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Error", "No task selected");
        return;
    }

    int taskId = m_taskModel->data(m_taskModel->index(selected.first().row(), 0)).toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM Tasks WHERE taskID = :taskID");
    query.bindValue(":taskID", taskId);

    if (query.exec()) {
        refreshTasks();
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete task: " + query.lastError().text());
    }
}

void TaskManager::onTaskComplete()
{
    QModelIndexList selected = ui->tasksTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Error", "No task selected");
        return;
    }

    int taskId = m_taskModel->data(m_taskModel->index(selected.first().row(), 0)).toInt();

    QSqlQuery query;
    query.prepare("UPDATE Tasks SET completed = 1 WHERE taskID = :taskID");
    query.bindValue(":taskID", taskId);

    if (query.exec()) {
        refreshTasks();
    } else {
        QMessageBox::critical(this, "Error", "Failed to mark task as complete: " + query.lastError().text());
    }
}

void TaskManager::onTaskSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    ui->deleteButton->setEnabled(!selected.isEmpty());
    ui->completeButton->setEnabled(!selected.isEmpty());
}
