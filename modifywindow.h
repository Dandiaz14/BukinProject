#ifndef MODIFYWINDOW_H
#define MODIFYWINDOW_H

#include <QDialog>
#include "user.h"


namespace Ui {
class modifywindow;
}

class modifywindow : public QDialog
{
    Q_OBJECT

public:
    explicit modifywindow(user* u,QWidget *parent = nullptr);
    ~modifywindow();

signals:
    void closeModify();

private slots:
    void on_changePB_clicked();

private:
    Ui::modifywindow *ui;
    user* dansito;


};

#endif // MODIFYWINDOW_H
