#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class registerWindow;
}

class registerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit registerWindow(QWidget *parent = nullptr);
    ~registerWindow();

    void enableCreatePB();

signals:
    void createUser(QString name, QString password, QString mail);

private slots:
    void on_newUserLE_textChanged(const QString &arg1);

    void on_newPassLE_textChanged(const QString &arg1);

    void on_newMailLE_textChanged(const QString &arg1);

    void on_createPB_clicked();

private:
    Ui::registerWindow *ui;
};

#endif // REGISTERWINDOW_H
