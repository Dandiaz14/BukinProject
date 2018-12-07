#include "sortwindow.h"
#include "ui_sortwindow.h"
#include <stdlib.h>
#include <algorithm>    /// std::sort
#include <QDebug>

sortwindow::sortwindow(vector<book> boo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortwindow)
{
    ui->setupUi(this);
    libros = boo;
}

sortwindow::~sortwindow()
{
    delete ui;
}

vector<book> sortwindow::returnSorted()
{
    return libros;
}


void sortwindow::on_pushButton_clicked()
{
    if(ui->TitleRB->isChecked()){
       std::sort(libros.begin(), libros.end(), sortedByTitle());
    }
    else if(ui->AuthorRB->isChecked()){
        std::sort(libros.begin(), libros.end(), sortedByAuthor());
    }
    else if(ui->YearRB->isChecked()){
        std::sort(libros.begin(), libros.end(), sortedByYear());
    }
    else if(ui->EditorialRB->isChecked()){
        std::sort(libros.begin(), libros.end(), sortedByEditorial());
    }
    else if(ui->TypeRB->isChecked()){
        std::sort(libros.begin(), libros.end(), sortedByType());
    }

    close();
}

