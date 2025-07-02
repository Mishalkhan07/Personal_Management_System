#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include "user.h"

namespace Ui {
class FinanceManager;
}

class FinanceManager : public QWidget
{
    Q_OBJECT

public:
    explicit FinanceManager(User *user, QWidget *parent = nullptr);
    ~FinanceManager();

public slots:
    void refreshTransactions();

private slots:
    void onAddTransaction();
    void onDeleteTransaction();
    void onGenerateReport();
    void onClearForm();
    void onTransactionSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::FinanceManager *ui;
    User *m_user;
    QSqlTableModel *m_transactionModel;

    void setupModel();
    void setupUI();
    void setupThemes();
};

#endif // FINANCEMANAGER_H
