#include "registerwindow.h"
#include "mainwindow.h"
#include "ui_registerwindow.h"

registerWindow::registerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);
}

registerWindow::~registerWindow()
{
    delete ui;
}

void registerWindow::enableCreatePB()
{
    if(ui->newUserLE->text().length() > 0 && ui->newPassLE->text().length() > 0 &&
            ui->newMailLE->text().length() > 0)
    {

        ui->createPB->setEnabled(true);
    }
    else{
        ui->createPB->setEnabled(false);
    }
}

void registerWindow::on_newUserLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);

    enableCreatePB();
}


void registerWindow::on_newPassLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);

    enableCreatePB();
}


void registerWindow::on_newMailLE_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);

    enableCreatePB();
}

void registerWindow::on_createPB_clicked()
{
    emit createUser(ui->newUserLE->text(),
                    ui->newPassLE->text(),
                    ui->newMailLE->text());
}
