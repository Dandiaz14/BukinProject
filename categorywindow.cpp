#include "categorywindow.h"
#include "ui_categorywindow.h"
#include <qdebug.h>

categoryWindow::categoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoryWindow)
{
    ui->setupUi(this);
}

categoryWindow::~categoryWindow()
{
    delete ui;
}

void categoryWindow::on_pushButton_clicked()
{
    emit showBooks();
    close();
}

void categoryWindow::on_backPB_clicked()
{
    emit returnCategories();
}

void categoryWindow::on_antologiaPB_clicked()
{
    catTemplate = new categorytemplate("Antología");
    catTemplate->show();
}

void categoryWindow::on_biografiaPB_clicked()
{
    catTemplate = new categorytemplate("Biografía");
    catTemplate->show();
}

void categoryWindow::on_dramaPB_clicked()
{
    catTemplate = new categorytemplate("Drama");
    catTemplate->show();
}

void categoryWindow::on_expositivoPB_clicked()
{
    catTemplate = new categorytemplate("Expositivo");
    catTemplate->show();
}

void categoryWindow::on_epistolarPB_clicked()
{
    catTemplate = new categorytemplate("Epistolar");
    catTemplate->show();
}

void categoryWindow::on_narrativaPB_clicked()
{
    catTemplate = new categorytemplate("Narrativa");
    catTemplate->show();
}

void categoryWindow::on_obraGraficaPB_clicked()
{
    catTemplate = new categorytemplate("Obra gráfica");
    catTemplate->show();
}

void categoryWindow::on_poesiaPB_clicked()
{
    catTemplate = new categorytemplate("Poesía");
    catTemplate->show();
}

void categoryWindow::on_referenciaPB_clicked()
{
    catTemplate = new categorytemplate("Referencia");
    catTemplate->show();
}

void categoryWindow::on_clasicoPB_clicked()
{
    catTemplate = new categorytemplate("Clásico");
    catTemplate->show();
}
