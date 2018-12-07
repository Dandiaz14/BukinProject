#ifndef BUKINWINDOW_H
#define BUKINWINDOW_H

#include <QDialog>
#include "login.h"
#include "registerwindow.h"

namespace Ui {
class bukinwindow;
}

class bukinwindow : public QDialog
{
    Q_OBJECT

public:
    explicit bukinwindow(QWidget *parent = nullptr);
    ~bukinwindow();

signals:
    void showLogin();
    void showCreate();

private slots:
    void on_loginPB_clicked();

    void on_createPB_clicked();

private:
    Ui::bukinwindow *ui;

};

#endif // BUKINWINDOW_H
