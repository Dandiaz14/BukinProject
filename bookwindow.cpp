#include "bookwindow.h"
#include "ui_bookwindow.h"
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

bookwindow::bookwindow(user &u, vector<book> bookscopy, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookwindow)
{
    ui->setupUi(this);
    myUser = &u;
    bc = bookscopy;
    showBooks();

}

bookwindow::~bookwindow()
{
    delete ui;
}

void bookwindow::showBooks()
{
    book b;

       string title,author,editorial,year,type;
           for(unsigned int i=0; i < bc.size();i++){
                   QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
                   ui->listWidget->addItem(listWidgetItem);

                   title = bc.at(i).getTitle();
                   b.setTitle(title);

                   author = bc.at(i).getAuthor();
                   b.setAuthor(author);

                   editorial = bc.at(i).getEditorial();
                   b.setEditorial(editorial);

                   year = bc.at(i).getYear();
                   b.setYear(year);

                   type = bc.at(i).getType();
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

void bookwindow::on_searchLE_textChanged(const QString &arg1)
{
    ui->listWidget->clear();

    QFile ruta("C://Users//dandi//Desktop//Seminario Algoritmia//Practica1//Practica1//bukin.json");
    if(!ruta.open(QIODevice::ReadOnly)){
        return;
    }
    QTextStream in(&ruta);
    QByteArray saveData = ruta.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonObject libros = loadDoc.object();
    QJsonArray array = libros["books"].toArray();
       book b;

       QString title,author,editorial,year,type;
       foreach (const QJsonValue & v, array){

           QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
           ui->listWidget->addItem(listWidgetItem);

           title = v.toObject().value("title").toString();
           b.setTitle(title.toStdString());

           author = v.toObject().value("author").toString();
           b.setAuthor(author.toStdString());

           editorial = v.toObject().value("editorial").toString();
           b.setEditorial(editorial.toStdString());

           year = v.toObject().value("year").toString();
           b.setYear(year.toStdString());

           type = v.toObject().value("type").toString();
           b.setType(type.toStdString());

          if(title.contains(arg1,Qt::CaseInsensitive) or author.contains(arg1,Qt::CaseInsensitive)){
               bookwidget *myItem = new bookwidget(title, author, editorial,  year, type);
               listWidgetItem->setSizeHint(QSize(myItem->width(),myItem->height()));
               ui->listWidget->setItemWidget(listWidgetItem,myItem);
          }
       }
       ruta.close();
}

void bookwindow::on_homePB_clicked()
{
    emit returnBook();
}

void bookwindow::on_addmybookPB_clicked()
{
    ///qDebug() << QString::fromStdString(bc.at(ui->listWidget->currentRow()).getTitle());
    myUser->setMyBook(QString::fromStdString(bc.at(ui->listWidget->currentRow()).getTitle()));
    QMessageBox message;
    message.setText("Book added to MyBooks");
    message.setWindowTitle("Bukin");
    message.exec();

    ///reset.createRecomendations();
}

void bookwindow::on_sortPB_clicked()
{
    sortWin = new sortwindow(bc);
    sortWin->exec();

    ui->listWidget->clear();

    book b;
    bc = sortWin->returnSorted();
       string title,author,editorial,year,type;
           for(unsigned int i=0; i < bc.size();i++){
                   QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
                   ui->listWidget->addItem(listWidgetItem);

                   title = bc.at(i).getTitle();
                   b.setTitle(title);

                   author = bc.at(i).getAuthor();
                   b.setAuthor(author);

                   editorial = bc.at(i).getEditorial();
                   b.setEditorial(editorial);

                   year = bc.at(i).getYear();
                   b.setYear(year);

                   type = bc.at(i).getType();
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


