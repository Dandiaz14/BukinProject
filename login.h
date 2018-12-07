#ifndef LOGIN_H
#define LOGIN_H

    #include <QWidget>
    #include <QDialog>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    void enableLogPB();

signals:

    void validateUser(QString name, QString password);

private slots:
    void on_LoginPB_clicked();

    void on_usuarioLE_textChanged(const QString &arg1);

    void on_passLE_textChanged(const QString &arg1);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
