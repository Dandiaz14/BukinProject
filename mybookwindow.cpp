#include "mybookwindow.h"
#include "ui_mybookwindow.h"
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

mybookwindow::mybookwindow(user &u, vector<book> bookscopy, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mybookwindow)
{
    ui->setupUi(this);
    myUser = &u;
    bc = bookscopy;
    showBooks();
    /*book b;

       string title,author,editorial,year,type;
       for(unsigned int j=0; j < u.getMyBook().size();j++){
           for(unsigned int i=0; i < bookscopy.size();i++){
               if(bookscopy.at(i).getTitle() == u.getMyBook().at(j).toStdString()){
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

                    bookwidget *myItem = new bookwidget(QString::fromStdString(title), QString::fromStdString(author), QString::fromStdString(editorial), QString::fromStdString(year), QString::fromStdString(type));
                    listWidgetItem->setSizeHint(QSize(myItem->width(),myItem->height()));
                    ui->listWidget->setItemWidget(listWidgetItem,myItem);
               }

           }
       }*/
}

mybookwindow::~mybookwindow()
{
    delete ui;
}

void mybookwindow::showBooks()
{
    book b;

           string title,author,editorial,year,type;
           for(unsigned int j=0; j < myUser->getMyBook().size();j++){
               for(unsigned int i=0; i < bc.size();i++){
                   if(bc.at(i).getTitle() == myUser->getMyBook().at(j).toStdString()){
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

                        bookwidget *myItem = new bookwidget(QString::fromStdString(title), QString::fromStdString(author), QString::fromStdString(editorial), QString::fromStdString(year), QString::fromStdString(type));
                        listWidgetItem->setSizeHint(QSize(myItem->width(),myItem->height()));
                        ui->listWidget->setItemWidget(listWidgetItem,myItem);
                   }

               }
           }
}

void mybookwindow::on_homePB_clicked()
{
    emit returnMyBooks();
    hide();
}

void mybookwindow::on_pushButton_clicked()
{
    vector <QString> copy;
    int valor = ui->listWidget->currentRow();
    copy = myUser->getMyBook();
    myUser->setMyFavorite(copy.at(valor));
    QMessageBox message;
    message.setText("Book added to Favorites");
    message.setWindowTitle("Bukin");
    message.exec();
}



void mybookwindow::on_sortPB_clicked()
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
