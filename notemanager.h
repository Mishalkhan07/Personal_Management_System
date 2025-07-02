#ifndef NOTEMANAGER_H
#define NOTEMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QItemSelection>
#include "user.h"

namespace Ui {
class NoteManager;
}

class NoteManager : public QWidget
{
    Q_OBJECT

public:
    explicit NoteManager(User *user, QWidget *parent = nullptr);
    ~NoteManager();
    void refreshNotes();

private slots:
    void onAddNote();
    void onEditNote();
    void onDeleteNote();
    void onSearchNotes();
    void onNoteSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::NoteManager *ui;
    User *m_user;
    QSqlTableModel *m_noteModel;
    void setupModel();
    void setupUI();
};

#endif // NOTEMANAGER_H
