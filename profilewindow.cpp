#include "profilewindow.h"
#include "ui_profilewindow.h"

profilewindow::profilewindow(user &u, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::profilewindow)
{
    ui->setupUi(this);
    myUser = &u;

        ui->nameLE->setText(QString::fromStdString(u.getNickName()));
        ui->passwordLE->setText(QString::fromStdString(u.getPassword()));
        ui->mailLE->setText(QString::fromStdString(u.getMail()));
}

profilewindow::~profilewindow()
{
    delete ui;
}

void profilewindow::on_changePB_clicked()
{
    modify = new modifywindow(myUser);  
    modify->exec();

    ui->nameLE->setText(QString::fromStdString(myUser->getNickName()));
    ui->passwordLE->setText(QString::fromStdString(myUser->getPassword()));
    ui->mailLE->setText(QString::fromStdString(myUser->getMail()));
}

void profilewindow::on_backPB_clicked()
{
    emit returnProfile();
}
