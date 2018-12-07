#include "mainwindow.h"
#include "profilewindow.h"
#include "ui_mainwindow.h"
#include "bookwidget.h"

MainWindow::MainWindow(user &u, vector<book> bookscopy, QHash<QString, QHash<QString, int> > &g, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    usr = u;
    bc = bookscopy;
    myGraph = g;
    createRecomendations();
    /*ui ->nameLE->setText(QString::fromStdString(usr.getNickName()));
    ui->passwordLE->setText(QString::fromStdString(usr.getPassword()));
    ui->mailLE->setText(QString::fromStdString(usr.getMail()));*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createRecomendations()
{
    ui->listWidget->clear();
    for(unsigned int i=0; i < usr.getMyBook().size();i++){
        QString myLibro = usr.getMyBook().at(i);
        QHash<QString, QHash<QString, int> >::iterator origen;
        for(origen = myGraph.begin(); origen != myGraph.end(); ++origen){
            QHash<QString, int>::iterator destino;
            for(destino = origen.value().begin(); destino != origen.value().end(); destino++){
                if(origen.key() == myLibro){
                    if(validEdge(destino.key())==false){
                        myNode.setDestiny(destino.key().toStdString());
                         myNode.setWeight(destino.value());
                         myRecommendatios.push_back(myNode);
                    }
                }
            }
        }
    }
      std::sort(myRecommendatios.begin(), myRecommendatios.end(), sortVector());
      showRecomendations();
}

void MainWindow::showRecomendations()
{
  string title,author,editorial,year,type;
  int cont = 0;
  if(usr.getMyBook().size()!=0){
      for(unsigned int j=0; j < myRecommendatios.size();j++){
          for(unsigned int i=0; i < bc.size();i++){
              if(cont == 3){break;}
              if(bc.at(i).getTitle() == myRecommendatios.at(j).getDestiny()){
              qDebug() << "Libro =" << QString::fromStdString(myRecommendatios.at(j).getDestiny()) << " -> " << myRecommendatios.at(j).getWeight();

                  QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
                  ui->listWidget->addItem(listWidgetItem);

                  title = bc.at(i).getTitle();
                  author = bc.at(i).getAuthor();
                  editorial = bc.at(i).getEditorial();
                  year = bc.at(i).getYear();
                  type = bc.at(i).getType();

                   bookwidget *myItem = new bookwidget(QString::fromStdString(title), QString::fromStdString(author), QString::fromStdString(editorial), QString::fromStdString(year), QString::fromStdString(type));
                   listWidgetItem->setSizeHint(QSize(myItem->width(),myItem->height()));
                   ui->listWidget->setItemWidget(listWidgetItem,myItem);
                   cont++;
              }

          }
      }
  }
  else{
      for(unsigned int i=0; i < bc.size();i++){
          if(cont == 3){break;}
          ///qDebug() << "Libro =" << QString::fromStdString(myRecommendatios.at(j).getDestiny()) << " -> " << myRecommendatios.at(j).getWeight();

          QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);
          ui->listWidget->addItem(listWidgetItem);

          title = bc.at(i).getTitle();
          author = bc.at(i).getAuthor();
          editorial = bc.at(i).getEditorial();
          year = bc.at(i).getYear();
          type = bc.at(i).getType();

           bookwidget *myItem = new bookwidget(QString::fromStdString(title), QString::fromStdString(author), QString::fromStdString(editorial), QString::fromStdString(year), QString::fromStdString(type));
           listWidgetItem->setSizeHint(QSize(myItem->width(),myItem->height()));
           ui->listWidget->setItemWidget(listWidgetItem,myItem);
           cont++;
      }
  }
}

bool MainWindow::validEdge(QString origen)
{
        for(unsigned int i = 0; i < usr.getMyBook().size(); i++){
            if(usr.getMyBook().at(i) == origen){
                return true;
            }
        }
        return false;
}

void MainWindow::on_categoriesPB_clicked()
{
    emit showCategories();
    hide();
}

void MainWindow::on_profilePB_clicked()
{
    emit showProfile();
    hide();
}

void MainWindow::on_favoritesPB_clicked()
{
    emit showFavorites();
    hide();
}

void MainWindow::on_myBooksPB_clicked()
{
    emit showMyBooks();
    hide();
}
