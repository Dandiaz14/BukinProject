#include "bukinwindow.h"
///#include "login.h"
#include "ui_bukinwindow.h"

bukinwindow::bukinwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bukinwindow)
{
    ui->setupUi(this);
}

bukinwindow::~bukinwindow()
{
    delete ui;
}

void bukinwindow::on_loginPB_clicked()
{
    emit showLogin();
    close();


}

void bukinwindow::on_createPB_clicked()
{

    emit showCreate();
    close();
}

