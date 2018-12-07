#include "categorytemplate.h"
#include "ui_categorytemplate.h"
#include <qdebug.h>
#include <QMessageBox>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
categorytemplate::categorytemplate(string name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categorytemplate)
{
    ui->setupUi(this);
    ui->catTitleLE->setText(QString::fromStdString(name));

    QFile ruta("C://Users//dandi//Desktop//Seminario Algoritmia//Practica1//Practica1//bukin.json");
    if(!ruta.open(QIODevice::ReadOnly)){
        return;
    }
    QByteArray saveData = ruta.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonObject libros = loadDoc.object();
    QJsonArray array = libros["books"].toArray();
       book b;
       QString foo;
       QString title,author,editorial,year,type;
       foreach (const QJsonValue & v, array){
           type = v.toObject().value("type").toString();
               if(type.toStdString() == name){
               QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
               ui->listWidget->addItem(listWidgetItem);

               ///qDebug() << v.toObject().value("title");
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

               bookwidget *myItem = new bookwidget(title,author,editorial,year,type);
               listWidgetItem->setSizeHint(QSize(myItem->width(),myItem->height()));
               ui->listWidget->setItemWidget(listWidgetItem,myItem);
             }
        }
}

categorytemplate::~categorytemplate()
{
    delete ui;
}
