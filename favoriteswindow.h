#ifndef FAVORITESWINDOW_H
#define FAVORITESWINDOW_H

#include <QDialog>
#include "user.h"
#include "book.h"
#include "sortwindow.h"

namespace Ui {
class favoriteswindow;
}

class favoriteswindow : public QDialog
{
    Q_OBJECT

public:
    explicit favoriteswindow(user &u, vector<book> bookscopy, QWidget *parent = nullptr);
    ~favoriteswindow();


signals:
    void returnFavorite();

private slots:
    void on_homePB_clicked();

    void on_sortPB_clicked();

private:
    Ui::favoriteswindow *ui;
    user* myUser;
    sortwindow* sortWin;
    vector <book> bc;
};

#endif // FAVORITESWINDOW_H
