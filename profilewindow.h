#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QDialog>
#include "user.h"
#include "modifywindow.h"

namespace Ui {
class profilewindow;
}

class profilewindow : public QDialog
{
    Q_OBJECT

public:
    explicit profilewindow(user &u,QWidget *parent = nullptr);

    ~profilewindow();

signals:
    void showModify();
    void returnProfile();

private slots:
    void on_changePB_clicked();

    void on_backPB_clicked();

private:
    Ui::profilewindow *ui;
    modifywindow* modify;
    user* myUser;
};

#endif // PROFILEWINDOW_H
