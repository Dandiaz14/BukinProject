#include "bookwidget.h"
#include "ui_bookwidget.h"

bookwidget::bookwidget(QString title, QString author, QString editorial, QString year, QString type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookwidget)
{
    ui->setupUi(this);
    ui->titleLE->setText(title);
    ui->titleLE->setReadOnly(true);

    ui->authorLE->setText(author);
    ui->authorLE->setReadOnly(true);

    ui->editorialLE->setText(editorial);
    ui->editorialLE->setReadOnly(true);

    ui->yearLE->setText(year);
    ui->yearLE->setReadOnly(true);

    ui->typeLE->setText(type);
    ui->typeLE->setReadOnly(true);
}

bookwidget::~bookwidget()
{
    delete ui;
}
