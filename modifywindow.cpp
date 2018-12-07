#include "modifywindow.h"
#include "ui_modifywindow.h"
#include "QtDebug"

modifywindow::modifywindow(user *u, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifywindow)
{
    ui->setupUi(this);
    dansito = u;
}


modifywindow::~modifywindow()
{
    delete ui;
}

void modifywindow::on_changePB_clicked()
{
    QString mail,name,password;

    name = ui->nameLE->text();
    password = ui->passwordLE->text();
    mail = ui->mailLE->text();

    dansito->setNickName(name.toStdString());
    dansito->setPassword(password.toStdString());
    dansito->setMail(mail.toStdString());

    close();

}
