#include "notemanager.h"
#include "ui_notemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>

NoteManager::NoteManager(User *user, QWidget *parent) :
    QWidget(parent), ui(new Ui::NoteManager), m_user(user)
{
    ui->setupUi(this);
    setupModel();
    setupUI();
    refreshNotes();
}

NoteManager::~NoteManager()
{
    delete ui;
}

void NoteManager::setupModel()
{
    m_noteModel = new QSqlTableModel(this);
    m_noteModel->setTable("Notes");
    m_noteModel->setFilter(QString("userID = %1").arg(m_user->getUserId()));
    m_noteModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_noteModel->setHeaderData(2, Qt::Horizontal, tr("Title"));
    m_noteModel->setHeaderData(3, Qt::Horizontal, tr("Content"));
    m_noteModel->setHeaderData(4, Qt::Horizontal, tr("Category"));
    m_noteModel->setHeaderData(5, Qt::Horizontal, tr("Date"));
}

void NoteManager::setupUI()
{
    ui->notesTableView->setModel(m_noteModel);
    ui->notesTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->notesTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->notesTableView->setColumnHidden(0, true); // Hide noteID
    ui->notesTableView->setColumnHidden(1, true); // Hide userID
    ui->notesTableView->horizontalHeader()->setStretchLastSection(true);
    ui->notesTableView->resizeColumnsToContents();

    QStringList categories;
    categories << "Personal" << "Work" << "Ideas" << "To-Do" << "Other";
    ui->categoryComboBox->addItems(categories);

    ui->dateEdit->setDate(QDate::currentDate());

    connect(ui->addButton, &QPushButton::clicked, this, &NoteManager::onAddNote);
    connect(ui->editButton, &QPushButton::clicked, this, &NoteManager::onEditNote);
    connect(ui->deleteButton, &QPushButton::clicked, this, &NoteManager::onDeleteNote);
    connect(ui->searchButton, &QPushButton::clicked, this, &NoteManager::onSearchNotes);
    connect(ui->notesTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &NoteManager::onNoteSelectionChanged);
}

void NoteManager::refreshNotes()
{
    m_noteModel->setFilter(QString("userID = %1").arg(m_user->getUserId()));
    m_noteModel->select();
    ui->notesTableView->resizeColumnsToContents();
}

void NoteManager::onAddNote()
{
    QString title = ui->titleLineEdit->text().trimmed();
    QString content = ui->contentTextEdit->toPlainText().trimmed();
    QString category = ui->categoryComboBox->currentText();
    QDate date = ui->dateEdit->date();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Error", "Title cannot be empty");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Notes (userID, title, content, category, date) "
                  "VALUES (:userID, :title, :content, :category, :date)");
    query.bindValue(":userID", m_user->getUserId());
    query.bindValue(":title", title);
    query.bindValue(":content", content);
    query.bindValue(":category", category);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));

    if (query.exec()) {
        refreshNotes();
        ui->titleLineEdit->clear();
        ui->contentTextEdit->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add note: " + query.lastError().text());
    }
}

void NoteManager::onEditNote()
{
    QModelIndexList selected = ui->notesTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Error", "No note selected");
        return;
    }

    int noteId = m_noteModel->data(m_noteModel->index(selected.first().row(), 0)).toInt();
    QString title = ui->titleLineEdit->text().trimmed();
    QString content = ui->contentTextEdit->toPlainText().trimmed();
    QString category = ui->categoryComboBox->currentText();
    QDate date = ui->dateEdit->date();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Error", "Title cannot be empty");
        return;
    }

    QSqlQuery query;
    query.prepare("UPDATE Notes SET title = :title, content = :content, "
                  "category = :category, date = :date WHERE noteID = :noteID");
    query.bindValue(":title", title);
    query.bindValue(":content", content);
    query.bindValue(":category", category);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    query.bindValue(":noteID", noteId);

    if (query.exec()) {
        refreshNotes();
    } else {
        QMessageBox::critical(this, "Error", "Failed to update note: " + query.lastError().text());
    }
}

void NoteManager::onDeleteNote()
{
    QModelIndexList selected = ui->notesTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Error", "No note selected");
        return;
    }

    int noteId = m_noteModel->data(m_noteModel->index(selected.first().row(), 0)).toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM Notes WHERE noteID = :noteID");
    query.bindValue(":noteID", noteId);

    if (query.exec()) {
        refreshNotes();
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete note: " + query.lastError().text());
    }
}

void NoteManager::onSearchNotes()
{
    QString searchText = ui->searchLineEdit->text().trimmed();
    QString category = ui->searchCategoryComboBox->currentText();

    QString filter = QString("userID = %1").arg(m_user->getUserId());

    if (!searchText.isEmpty()) {
        filter += QString(" AND (title LIKE '%%1%' OR content LIKE '%%1%')").arg(searchText);
    }

    if (category != "All") {
        filter += QString(" AND category = '%1'").arg(category);
    }

    m_noteModel->setFilter(filter);
    m_noteModel->select();
}

void NoteManager::onNoteSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);

    bool hasSelection = !selected.isEmpty();
    ui->editButton->setEnabled(hasSelection);
    ui->deleteButton->setEnabled(hasSelection);

    if (hasSelection) {
        int row = selected.first().top();
        ui->titleLineEdit->setText(m_noteModel->data(m_noteModel->index(row, 2)).toString());
        ui->contentTextEdit->setText(m_noteModel->data(m_noteModel->index(row, 3)).toString());
        ui->categoryComboBox->setCurrentText(m_noteModel->data(m_noteModel->index(row, 4)).toString());
        ui->dateEdit->setDate(QDate::fromString(m_noteModel->data(m_noteModel->index(row, 5)).toString(), "yyyy-MM-dd"));
    }
}
