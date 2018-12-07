#ifndef BOOKWINDOW_H
#define BOOKWINDOW_H

#include <QDialog>
#include "user.h"
#include "book.h"
#include "sortwindow.h"
#include "mainwindow.h"

namespace Ui {
class bookwindow;
}

class bookwindow : public QDialog
{
    Q_OBJECT

public:
    explicit bookwindow(user &u,vector <book> bookscopy,QWidget *parent = nullptr);
    ~bookwindow();

    void showBooks();

signals:
    void returnBook();

private slots:
    void on_searchLE_textChanged(const QString &arg1);

    void on_addmybookPB_clicked();

    void on_sortPB_clicked();

    void on_homePB_clicked();

private:
    Ui::bookwindow *ui;
    user* myUser;
    sortwindow* sortWin;
    vector <book> bc;
    QStringList myList;
    ///MainWindow reset;
};

#endif // BOOKWINDOW_H
