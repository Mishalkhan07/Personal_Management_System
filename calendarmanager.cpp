#include "calendarmanager.h"
#include "ui_calendarmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>

CalendarManager::CalendarManager(User *user, QWidget *parent) :
    QWidget(parent), ui(new Ui::CalendarManager), m_user(user)
{
    ui->setupUi(this);
    setupModel();
    setupUI();
    refreshEvents();
}

CalendarManager::~CalendarManager()
{
    delete ui;
}

void CalendarManager::setupModel()
{
    m_eventModel = new QSqlTableModel(this);
    m_eventModel->setTable("Calendar");
    m_eventModel->setFilter(QString("userID = %1").arg(m_user->getUserId()));
    m_eventModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_eventModel->setHeaderData(2, Qt::Horizontal, tr("Title"));
    m_eventModel->setHeaderData(3, Qt::Horizontal, tr("Description"));
    m_eventModel->setHeaderData(4, Qt::Horizontal, tr("Date"));
    m_eventModel->setHeaderData(5, Qt::Horizontal, tr("Time"));
    m_eventModel->setHeaderData(6, Qt::Horizontal, tr("Reminder"));
}

void CalendarManager::setupUI()
{
    ui->eventsTableView->setModel(m_eventModel);
    ui->eventsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->eventsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->eventsTableView->setColumnHidden(0, true); // Hide eventID
    ui->eventsTableView->setColumnHidden(1, true); // Hide userID
    ui->eventsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->eventsTableView->resizeColumnsToContents();

    ui->eventDateEdit->setDate(QDate::currentDate());
    ui->eventTimeEdit->setTime(QTime::currentTime());

    connect(ui->addButton, &QPushButton::clicked, this, &CalendarManager::onAddEvent);
    connect(ui->deleteButton, &QPushButton::clicked, this, &CalendarManager::onDeleteEvent);
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &CalendarManager::onCalendarClicked);
    connect(ui->eventsTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &CalendarManager::onEventSelectionChanged);
}

void CalendarManager::refreshEvents()
{
    m_eventModel->select();
    ui->eventsTableView->resizeColumnsToContents();
}

void CalendarManager::onAddEvent()
{
    QString title = ui->titleLineEdit->text().trimmed();
    QString description = ui->descriptionTextEdit->toPlainText().trimmed();
    QDate eventDate = ui->eventDateEdit->date();
    QTime eventTime = ui->eventTimeEdit->time();
    bool reminder = ui->reminderCheckBox->isChecked();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Error", "Title cannot be empty");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Calendar (userID, eventTitle, eventDescription, eventDate, eventTime, reminder) "
                  "VALUES (:userID, :title, :description, :date, :time, :reminder)");
    query.bindValue(":userID", m_user->getUserId());
    query.bindValue(":title", title);
    query.bindValue(":description", description);
    query.bindValue(":date", eventDate.toString("yyyy-MM-dd"));
    query.bindValue(":time", eventTime.toString("hh:mm"));
    query.bindValue(":reminder", reminder ? 1 : 0);

    if (query.exec()) {
        refreshEvents();
        ui->titleLineEdit->clear();
        ui->descriptionTextEdit->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add event: " + query.lastError().text());
    }
}

void CalendarManager::onDeleteEvent()
{
    QModelIndexList selected = ui->eventsTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Error", "No event selected");
        return;
    }

    int eventId = m_eventModel->data(m_eventModel->index(selected.first().row(), 0)).toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM Calendar WHERE eventID = :eventID");
    query.bindValue(":eventID", eventId);

    if (query.exec()) {
        refreshEvents();
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete event: " + query.lastError().text());
    }
}

void CalendarManager::onCalendarClicked(const QDate &date)
{
    ui->eventDateEdit->setDate(date);
    m_eventModel->setFilter(QString("userID = %1 AND eventDate = '%2'")
                                .arg(m_user->getUserId())
                                .arg(date.toString("yyyy-MM-dd")));
    m_eventModel->select();
}

void CalendarManager::onEventSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    ui->deleteButton->setEnabled(!selected.isEmpty());
}
