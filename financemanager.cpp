#include "financemanager.h"
#include "ui_financemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include <QStyledItemDelegate>

// Custom delegate for colored transaction types
class TransactionTypeDelegate : public QStyledItemDelegate {
public:
    TransactionTypeDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);

        QString type = index.data().toString();
        if(type == "Income") {
            opt.palette.setColor(QPalette::Text, QColor(0, 128, 0)); // Green for income
        } else if(type == "Expense") {
            opt.palette.setColor(QPalette::Text, QColor(200, 0, 0)); // Red for expense
        }

        QStyledItemDelegate::paint(painter, opt, index);
    }
};

FinanceManager::FinanceManager(User *user, QWidget *parent) :
    QWidget(parent), ui(new Ui::FinanceManager), m_user(user)
{
    ui->setupUi(this);
    setupModel();
    setupUI();
    refreshTransactions();
}

FinanceManager::~FinanceManager()
{
    delete ui;
}

void FinanceManager::setupModel()
{
    m_transactionModel = new QSqlTableModel(this);
    m_transactionModel->setTable("Finance");
    m_transactionModel->setFilter(QString("userID = %1").arg(m_user->getUserId()));
    m_transactionModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_transactionModel->setHeaderData(2, Qt::Horizontal, tr("Type"));
    m_transactionModel->setHeaderData(3, Qt::Horizontal, tr("Amount"));
    m_transactionModel->setHeaderData(4, Qt::Horizontal, tr("Date"));
    m_transactionModel->setHeaderData(5, Qt::Horizontal, tr("Category"));
    m_transactionModel->setHeaderData(6, Qt::Horizontal, tr("Description"));
}

void FinanceManager::setupUI()
{
    // Setup Table View
    ui->transactionsTableView->setModel(m_transactionModel);
    ui->transactionsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->transactionsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->transactionsTableView->setColumnHidden(0, true); // Hide transactionID
    ui->transactionsTableView->setColumnHidden(1, true); // Hide userID
    ui->transactionsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->transactionsTableView->setItemDelegateForColumn(2, new TransactionTypeDelegate(this));
    ui->transactionsTableView->setSortingEnabled(true);

    // Setup Combo Boxes
    ui->typeComboBox->clear();
    ui->typeComboBox->addItem("Income");
    ui->typeComboBox->addItem("Expense");

    QStringList categories;
    categories << "Salary" << "Bonus" << "Investment" << "Other"
               << "Food" << "Transport" << "Housing" << "Entertainment" << "Utilities";
    ui->categoryComboBox->addItems(categories);

    // Setup Date Fields
    QDate today = QDate::currentDate();
    ui->dateEdit->setDate(today);
    ui->fromDateEdit->setDate(today.addMonths(-1));
    ui->toDateEdit->setDate(today);


    // Connect Signalsh
    connect(ui->addButton, &QPushButton::clicked, this, &FinanceManager::onAddTransaction);
    connect(ui->deleteButton, &QPushButton::clicked, this, &FinanceManager::onDeleteTransaction);
    connect(ui->reportButton, &QPushButton::clicked, this, &FinanceManager::onGenerateReport);
    connect(ui->clearButton, &QPushButton::clicked, this, &FinanceManager::onClearForm);
    connect(ui->transactionsTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &FinanceManager::onTransactionSelectionChanged);
    if (ui->clearButton) { // This checks if the button exists
        connect(ui->clearButton, &QPushButton::clicked, this, &FinanceManager::onClearForm);
    }

    // Set tooltips
    ui->addButton->setToolTip("Add a new transaction");
    ui->deleteButton->setToolTip("Delete selected transaction");
    ui->clearButton->setToolTip("Clear form fields");
    ui->reportButton->setToolTip("Generate financial report");
}

void FinanceManager::onClearForm()
{
    ui->amountDoubleSpinBox->setValue(0);
    ui->descriptionLineEdit->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->typeComboBox->setCurrentIndex(0);
    ui->categoryComboBox->setCurrentIndex(0);
}


void FinanceManager::refreshTransactions()
{
    m_transactionModel->select();
    ui->transactionsTableView->resizeColumnsToContents();
    ui->transactionsTableView->sortByColumn(4, Qt::DescendingOrder); // Sort by date
}

void FinanceManager::onAddTransaction()
{
    // 1. Get all values from UI
    QString type = ui->typeComboBox->currentText();  // Changed from currentData() to currentText()
    double amount = ui->amountDoubleSpinBox->value();
    QDate date = ui->dateEdit->date();
    QString category = ui->categoryComboBox->currentText();
    QString description = ui->descriptionLineEdit->text().trimmed();

    // 2. Validate inputs
    if (amount <= 0) {
        QMessageBox::warning(this, "Error", "Amount must be greater than 0");
        return;
    }

    if (type.isEmpty()) {  // Additional validation
        QMessageBox::warning(this, "Error", "Transaction type must be selected");
        return;
    }

    // 3. Debug output (optional)
    qDebug() << "Adding transaction - Type:" << type
             << "Amount:" << amount
             << "Date:" << date
             << "Category:" << category;

    // 4. Prepare and execute query
    QSqlQuery query;
    query.prepare("INSERT INTO Finance (userID, type, amount, date, category, description) "
                  "VALUES (:userID, :type, :amount, :date, :category, :description)");
    query.bindValue(":userID", m_user->getUserId());
    query.bindValue(":type", type);
    query.bindValue(":amount", amount);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    query.bindValue(":category", category);
    query.bindValue(":description", description);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to add transaction:\n%1\nQuery: %2")
                                  .arg(query.lastError().text())
                                  .arg(query.lastQuery()));
    } else {
        refreshTransactions();
        ui->amountDoubleSpinBox->setValue(0);
        ui->descriptionLineEdit->clear();
    }
}
void FinanceManager::onDeleteTransaction()
{
    QModelIndexList selected = ui->transactionsTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Error", "No transaction selected");
        return;
    }

    int transactionId = m_transactionModel->data(m_transactionModel->index(selected.first().row(), 0)).toInt();

    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Confirm Delete",
                                                                "Are you sure you want to delete this transaction?",
                                                                QMessageBox::Yes|QMessageBox::No);

    if (confirm == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM Finance WHERE transactionID = :transactionID");
        query.bindValue(":transactionID", transactionId);

        if (query.exec()) {
            refreshTransactions();
        } else {
            QMessageBox::critical(this, "Error",
                                  QString("Failed to delete transaction:\n%1").arg(query.lastError().text()));
        }
    }
}

void FinanceManager::onGenerateReport()
{
    QDate fromDate = ui->fromDateEdit->date();
    QDate toDate = ui->toDateEdit->date();

    if (fromDate > toDate) {
        QMessageBox::warning(this, "Error", "From date must be before To date");
        return;
    }

    // Calculate total income
    QSqlQuery incomeQuery;
    incomeQuery.prepare("SELECT SUM(amount) FROM Finance "
                        "WHERE userID = :userID AND type = 'Income' "
                        "AND date BETWEEN :fromDate AND :toDate");
    incomeQuery.bindValue(":userID", m_user->getUserId());
    incomeQuery.bindValue(":fromDate", fromDate.toString("yyyy-MM-dd"));
    incomeQuery.bindValue(":toDate", toDate.toString("yyyy-MM-dd"));

    double totalIncome = 0;
    if (incomeQuery.exec() && incomeQuery.next()) {
        totalIncome = incomeQuery.value(0).toDouble();
    }

    // Calculate total expenses
    QSqlQuery expenseQuery;
    expenseQuery.prepare("SELECT SUM(amount) FROM Finance "
                         "WHERE userID = :userID AND type = 'Expense' "
                         "AND date BETWEEN :fromDate AND :toDate");
    expenseQuery.bindValue(":userID", m_user->getUserId());
    expenseQuery.bindValue(":fromDate", fromDate.toString("yyyy-MM-dd"));
    expenseQuery.bindValue(":toDate", toDate.toString("yyyy-MM-dd"));

    double totalExpense = 0;
    if (expenseQuery.exec() && expenseQuery.next()) {
        totalExpense = expenseQuery.value(0).toDouble();
    }

    // Calculate balance and savings rate
    double balance = totalIncome - totalExpense;
    double savingsRate = (totalIncome > 0) ? ((balance) / totalIncome * 100) : 0;

    // Show report
    QString report = QString(
                         "<h3>Financial Report (%1 to %2)</h3>"
                         "<table width='100%'>"
                         "<tr><td><b>Total Income:</b></td><td align='right'>$%3</td></tr>"
                         "<tr><td><b>Total Expenses:</b></td><td align='right'>$%4</td></tr>"
                         "<tr><td><b>Balance:</b></td><td align='right'>$%5</td></tr>"
                         "<tr><td><b>Savings Rate:</b></td><td align='right'>%6%</td></tr>"
                         "</table>")
                         .arg(fromDate.toString("MMM d, yyyy"))
                         .arg(toDate.toString("MMM d, yyyy"))
                         .arg(totalIncome, 0, 'f', 2)
                         .arg(totalExpense, 0, 'f', 2)
                         .arg(balance, 0, 'f', 2)
                         .arg(savingsRate, 0, 'f', 1);

    QMessageBox msgBox;
    msgBox.setWindowTitle("Financial Report");
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText(report);
    msgBox.exec();
}

void FinanceManager::onTransactionSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    ui->deleteButton->setEnabled(!selected.isEmpty());

    // Optional: Load selected transaction into form for editing
    if (!selected.isEmpty()) {
        int row = selected.first().top();
        ui->typeComboBox->setCurrentText(m_transactionModel->data(m_transactionModel->index(row, 2)).toString());
        ui->amountDoubleSpinBox->setValue(m_transactionModel->data(m_transactionModel->index(row, 3)).toDouble());
        ui->dateEdit->setDate(QDate::fromString(m_transactionModel->data(m_transactionModel->index(row, 4)).toString(), "yyyy-MM-dd"));
        ui->categoryComboBox->setCurrentText(m_transactionModel->data(m_transactionModel->index(row, 5)).toString());
        ui->descriptionLineEdit->setText(m_transactionModel->data(m_transactionModel->index(row, 6)).toString());
    }
}
