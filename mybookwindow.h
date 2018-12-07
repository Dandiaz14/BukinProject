#ifndef MYBOOKWINDOW_H
#define MYBOOKWINDOW_H

#include <QDialog>
#include "user.h"
#include "book.h"
#include "sortwindow.h"

namespace Ui {
class mybookwindow;
}

class mybookwindow : public QDialog
{
    Q_OBJECT

public:
    explicit mybookwindow(user &u,vector <book> bookscopy,QWidget *parent = nullptr);
    ~mybookwindow();

    void showBooks();
signals:
    void returnMyBooks();

private slots:
    void on_homePB_clicked();

    void on_pushButton_clicked();

    void on_sortPB_clicked();

private:
    Ui::mybookwindow *ui;
    user* myUser;
    sortwindow* sortWin;
    vector <book> bc;
};

#endif // MYBOOKWINDOW_H
