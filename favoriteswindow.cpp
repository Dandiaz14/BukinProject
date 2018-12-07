#include "favoriteswindow.h"
#include "ui_favoriteswindow.h"
#include "book.h"
#include "bookwidget.h"
#include <QSize>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QRegExp>
#include <QDir>

favoriteswindow::favoriteswindow(user &u,vector<book> bookscopy,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::favoriteswindow)
{
    ui->setupUi(this);

    myUser = &u;
    bc = bookscopy;
    book b;

       string title,author,editorial,year,type;
       for(unsigned int j=0; j < u.getMyFavorite().size();j++){
           for(unsigned int i=0; i < bookscopy.size();i++){
               if(bookscopy.at(i).getTitle() == u.getMyFavorite().at(j).toStdString()){
                   QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
                   ui->listWidget->addItem(listWidgetItem);

                   title = bookscopy.at(i).getTitle();
                   b.setTitle(title);

                   author = bookscopy.at(i).getAuthor();
                   b.setAuthor(author);

                   editorial = bookscopy.at(i).getEditorial();
                   b.setEditorial(editorial);

                   year = bookscopy.at(i).getYear();
                   b.setYear(year);

                   type = bookscopy.at(i).getType();
                   b.setType(type);

                    bookwidget *myItem = new bookwidget(QString::fromStdString(title),
                                                        QString::fromStdString(author),
                                                        QString::fromStdString(editorial),
                                                        QString::fromStdString(year),
                                                        QString::fromStdString(type));
                    listWidgetItem->setSizeHint(QSize(myItem->width(),myItem->height()));
                    ui->listWidget->setItemWidget(listWidgetItem,myItem);
               }

           }
       }

}

favoriteswindow::~favoriteswindow()
{
    delete ui;
}

void favoriteswindow::on_homePB_clicked()
{
    emit returnFavorite();
    hide();
}

void favoriteswindow::on_sortPB_clicked()
{
    sortWin = new sortwindow(bc);
    sortWin->exec();

    ui->listWidget->clear();

    book b;
    vector <book> copy;
    copy = sortWin->returnSorted();

           string title,author,editorial,year,type;
           for(unsigned int i=0; i < copy.size();i++){
               for(unsigned int j=0; j < myUser->getMyBook().size();j++){
                   if(copy.at(i).getTitle() == myUser->getMyBook().at(j).toStdString()){
                       QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
                       ui->listWidget->addItem(listWidgetItem);

                       title = copy.at(i).getTitle();
                       b.setTitle(title);

                       author = copy.at(i).getAuthor();
                       b.setAuthor(author);

                       editorial = copy.at(i).getEditorial();
                       b.setEditorial(editorial);

                       year = copy.at(i).getYear();
                       b.setYear(year);

                       type = copy.at(i).getType();
                       b.setType(type);

                        bookwidget *myItem = new bookwidget(QString::fromStdString(title), QString::fromStdString(author), QString::fromStdString(editorial), QString::fromStdString(year), QString::fromStdString(type));
                        listWidgetItem->setSizeHint(QSize(myItem->width(),myItem->height()));
                        ui->listWidget->setItemWidget(listWidgetItem,myItem);
                   }

               }
           }
}
