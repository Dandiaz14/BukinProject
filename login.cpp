#include "login.h"
#include "mainwindow.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::enableLogPB()
{
    if(ui->usuarioLE->text().length() > 0 && ui->passLE->text().length() > 0){
        ui->LoginPB->setEnabled(true);
    }

    else{
        ui->LoginPB->setEnabled(false);
    }
}

void Login::on_usuarioLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    enableLogPB();
}

void Login::on_passLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    enableLogPB();
}

void Login::on_LoginPB_clicked()
{
    emit validateUser(ui->usuarioLE->text(), ui->passLE->text());
    /*MainWindow* main = new MainWindow;
    main->show();*/

    ///close();
}
