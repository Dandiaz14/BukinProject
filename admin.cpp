#include "admin.h"
#include <QMessageBox>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include "user.h"

admin::admin(QObject *parent) : QObject(parent)
{
    bukin = new bukinwindow();
    regis = new registerWindow();
    log = new Login();
    category = new categoryWindow();
    ///bookwin = new bookwindow();


    QObject::connect(bukin, SIGNAL(showLogin()),this,SLOT(showLoginWindow()));

    QObject::connect(bukin, SIGNAL(showCreate()),this,SLOT(showCreateWindow()));

    QObject::connect(log, SIGNAL(validateUser(QString,QString)),this,SLOT(findUser(QString,QString)));

    QObject::connect(regis, SIGNAL(createUser(QString,QString,QString)),this,SLOT(addUser(QString,QString,QString)));

    QObject::connect(category, SIGNAL(showBooks()),this,SLOT(showBooksWindow()));

    QObject::connect(category, SIGNAL(returnCategories()),this,SLOT(returnCategoriesWindow()));

    ///QObject::connect(bookwin, SIGNAL(returnBook()),this,SLOT(returnBookWindow()));

    readFromJsonUser();
    readFromJsonBooks();
    createGraph();
}

admin::~admin()
{
    ///Tengo que poner el escribir a archivo JSon de todos los atributos y poder sobreescribirlo
    writeToJson();
}


void admin::start()
{
    bukin->show();
}

void admin::findUser(QString name, QString password)
{
    unsigned int i;
    for(i=0; i < users.size();i++)
    {
        if(name.toStdString() == users.at(i).getNickName())
        {
            if(password.toStdString() == users.at(i).getPassword())
            {
                auxId = i;
                profile = new profilewindow(users.at(i));
                favorite = new favoriteswindow(users.at(i),books);
                mybookwin = new mybookwindow(users.at(i),books);
                mainWindow = new MainWindow(users.at(i),books,grafo);
                bookwin = new bookwindow(users.at(i),books);
                mainWindow->show();
                log->hide();
                ///Aqui se tiene que hacer la conexión porque aqui te crea el apuntador
                QObject::connect(profile, SIGNAL(returnProfile()),this,SLOT(returnProfileWindow()));
                QObject::connect(favorite, SIGNAL(returnFavorite()),this,SLOT(returnFavoriteWindow()));
                QObject::connect(mybookwin, SIGNAL(returnMyBooks()),this,SLOT(returnMyBooksWindow()));
                QObject::connect(bookwin, SIGNAL(returnBook()),this,SLOT(returnBookWindow()));
                QObject::connect(mainWindow, SIGNAL(showFavorites()),this,SLOT(showFavoritesWindow()));
                QObject::connect(mainWindow, SIGNAL(showMyBooks()),this,SLOT(showMyBooksWindow()));
                QObject::connect(mainWindow, SIGNAL(showCategories()),this,SLOT(showCategoriesWindow()));

                QObject::connect(mainWindow, SIGNAL(showProfile()),this,SLOT(showProfileWindow()));
            }
            else{
                //Mensaje de error
                QMessageBox message;
                message.setText("Invalid username or password");
                message.setWindowTitle("Error");
                message.exec();
            }
            return;
        }
    }
    if(i == users.size()){
        //Mensaje de error
        QMessageBox message;
        message.setText("Invalid username or password");
        message.setWindowTitle("Error");
        message.exec();
    }
}

void admin::addUser(QString name, QString password, QString mail){
    user u;

    u.setNickName(name.toStdString());
    u.setPassword(password.toStdString());
    if(verifyMail(mail.toStdString()) ==  true){
        if(verifyMailExisted(mail.toStdString()) == false and verifyUserExisted(name.toStdString()) == false){
            u.setMail(mail.toStdString());

            users.push_back(u);
            ///writeToJsonUser();
            writeToJson();

            QMessageBox message;
            message.setText("New User Created");
            message.setWindowTitle("Create");
            message.exec();

            log->show();
            regis->hide();
        }
        else{

            QMessageBox message;
            message.setText("Mail Ocuppied");
            message.setWindowTitle("Error");
            message.exec();
        }
    }
    else{

        QMessageBox message;
        message.setText("Invalid Mail");
        message.setWindowTitle("Error");
        message.exec();
    }
}

void admin::showLoginWindow(){
    log->show();
}

void admin::showCreateWindow(){
    regis->show();
}

void admin::showCategoriesWindow(){
    category->show();
    ///mainWindow->hide();
}

void admin::showProfileWindow()
{
    profile->show();
}

void admin::showBooksWindow()
{
    bookwin->show();
    category->hide();
}

void admin::showFavoritesWindow()
{
    favorite->show();
}

void admin::showMyBooksWindow()
{
    mybookwin->show();
}



void admin::modifyData()
{
    QFile ruta("C://Users//dandi//Desktop//Seminario Algoritmia//Practica1//Practica1//bukin.json");
    if(ruta.open(QIODevice::WriteOnly)){
        QJsonArray usuarios;
        QJsonObject usuario, objeto;
        foreach(user u,users){
            usuario.insert("mail",QJsonValue::fromVariant(QString::fromStdString(u.getMail())));
            usuario.insert("name",QJsonValue::fromVariant(QString::fromStdString(u.getNickName())));
            usuario.insert("password",QJsonValue::fromVariant(QString::fromStdString(u.getPassword())));
            usuarios.push_back(usuario);
        }
        objeto["users"] = usuarios;
        ///mainwindo apunta al metodo de escribir de books
        QJsonDocument myFile(objeto);
        ruta.write(myFile.toJson());
    }
    else{
        qDebug() << "JSON Can´t Be Open";
    }
    ruta.close();
}

void admin::returnProfileWindow()
{
   profile->hide();
   mainWindow->show();
}

void admin::returnCategoriesWindow()
{
    category->hide();
    mainWindow->show();
}

void admin::returnBookWindow()
{
    bookwin->hide();
    grafo.clear();
    arista.clear();
    createGraph();
    mainWindow->~MainWindow();
    mainWindow = new MainWindow(users.at(auxId),books,grafo);
    ///mainWindow->createRecomendations();
    mainWindow->show();

    QObject::connect(mainWindow, SIGNAL(showFavorites()),this,SLOT(showFavoritesWindow()));
    QObject::connect(mainWindow, SIGNAL(showMyBooks()),this,SLOT(showMyBooksWindow()));
    QObject::connect(mainWindow, SIGNAL(showCategories()),this,SLOT(showCategoriesWindow()));
    QObject::connect(mainWindow, SIGNAL(showProfile()),this,SLOT(showProfileWindow()));
}

void admin::returnFavoriteWindow()
{
    favorite->hide();
    mainWindow->show();
}

void admin::returnMyBooksWindow()
{
    mybookwin->hide();
    mainWindow->show();
}

bool admin::verifyMail(string mail){
    auto beg=mail.begin(), _end=mail.end();

        if((beg=find(beg, _end, '@')) != _end && find(beg, _end, '.') != _end){
            return true;
        }
        return false;
}

bool admin::verifyMailExisted(string mail){
    foreach(user u,users){
        if(u.getMail() == mail){
            return true;
        }
    }
    return false;
}

bool admin::verifyUserExisted(string nickname){
    foreach(user u,users){
        if(u.getNickName() == nickname){
            return true;
        }
    }
    return false;
}

void admin::writeToJsonUser(){
    QFile ruta("C://Users//dandi//Desktop//Seminario Algoritmia//Practica1//Practica1//bukin.json");
    if(ruta.open(QIODevice::WriteOnly)){
        QJsonArray usuarios;
        QJsonObject usuario, objeto;
        foreach(user u,users){
            usuario.insert("mail",QJsonValue::fromVariant(QString::fromStdString(u.getMail())));
            usuario.insert("name",QJsonValue::fromVariant(QString::fromStdString(u.getNickName())));
            usuario.insert("password",QJsonValue::fromVariant(QString::fromStdString(u.getPassword())));
            usuarios.push_back(usuario);
        }
        objeto["users"] = usuarios;
        ///mainwindo apunta al metodo de escribir de books
        QJsonDocument myFile(objeto);
        ruta.write(myFile.toJson());
    }
    else{
        qDebug() << "JSON Can´t Be Open";
    }
    ruta.close();
}

void admin::writeToJson()
{
    QFile ruta("C://Users//dandi//Desktop//Seminario Algoritmia//Practica1//Practica1//bukin.json");
    if(ruta.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        QJsonArray usuarios, libros, misLibros, favoritos;

        QJsonObject userObject, bookObject, myObject, myBookObject, favoriteObject;

        foreach(user u, users){
            userObject.insert("mail",QJsonValue::fromVariant(QString::fromStdString(u.getMail())));
            userObject.insert("name",QJsonValue::fromVariant(QString::fromStdString(u.getNickName())));
            userObject.insert("password",QJsonValue::fromVariant(QString::fromStdString(u.getPassword())));

            foreach(QString value, u.getMyBook()){
                myBookObject.insert("title",value);
                misLibros.push_back(myBookObject);
                myBookObject.remove(value);
            }
            foreach(QString value, u.getMyFavorite()){
                favoriteObject.insert("title",value);
                favoritos.push_back(favoriteObject);
                favoriteObject.remove(value);
            }

            userObject.insert("myBooks",misLibros);
            userObject.insert("favorites",favoritos);
            usuarios.push_back(userObject);
            while(misLibros.count()){
                misLibros.pop_back();
            }
            while (favoritos.count()) {
                favoritos.pop_back();
            }
        }

        foreach(book b, books){
            bookObject.insert("title",QJsonValue::fromVariant(QString::fromStdString(b.getTitle())));
            bookObject.insert("author",QJsonValue::fromVariant(QString::fromStdString(b.getAuthor())));
            bookObject.insert("editorial",QJsonValue::fromVariant(QString::fromStdString(b.getEditorial())));
            bookObject.insert("year",QJsonValue::fromVariant(QString::fromStdString(b.getYear())));
            bookObject.insert("type",QJsonValue::fromVariant(QString::fromStdString(b.getType())));
            libros.push_back(bookObject);
        }
        myObject["users"] = usuarios;
        myObject["books"] = libros;

        QJsonDocument myBookFile(myObject);
        ruta.write(myBookFile.toJson());
    }
    else{
        qDebug() << "JSON Can´t Be Open";
    }
    ruta.close();

}

void admin::readFromJsonUser(){
    QFile ruta("C://Users//dandi//Desktop//Seminario Algoritmia//Practica1//Practica1//bukin.json");
    if(!ruta.open(QIODevice::ReadOnly)){
        return;
    }
    QByteArray saveData = ruta.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonObject usuarios = loadDoc.object();

    QJsonArray UserArray = usuarios["users"].toArray();

       user u;
       QString foo;
       foreach (const QJsonValue & v, UserArray){
           foo = v.toObject().value("password").toString();
           u.setPassword(foo.toStdString());
           foo = v.toObject().value("name").toString();
           u.setNickName(foo.toStdString());
           foo = v.toObject().value("mail").toString();
           u.setMail(foo.toStdString());

           foreach(const QJsonValue & b, v.toObject().value("myBooks").toArray()){
                foo = b.toObject().value("title").toString();
                u.setMyBook(foo);
           }
           ///Inserta los libros al grafo solo por estar en mis libros
           /*for(unsigned int i=0; i < u.getMyBook().size();i++){
               for(unsigned int j=i+1; j < u.getMyBook().size();j++){
                   arista.insert(u.getMyBook().at(j),1);
                   ///qDebug() << "---------------------" << u.getMyBook().at(i) << "con: " << u.getMyBook().at(j) << "----------------------";

               }
               grafo.insert(u.getMyBook().at(i),arista);
               arista.clear();
               break;
           }
           QHash<QString, QHash<QString, int> >::iterator origen;
               for(origen = grafo.begin(); origen != grafo.end(); ++origen){
                   QHash<QString, int>::iterator destino;
                   for(destino = origen.value().begin(); destino != origen.value().end(); destino++){
                       qDebug() << "(" << origen.key() <<" -> "<< destino.key() << " ) = " << destino.value();
                   }
               }*/

           foreach(const QJsonValue & f, v.toObject().value("favorites").toArray()){
                foo = f.toObject().value("title").toString();
                u.setMyFavorite(foo);
           }

           users.push_back(u);
           u.clearArray();
       }

}

void admin::readFromJsonBooks()
{
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
       foreach (const QJsonValue & v, array){

           ///qDebug() << v.toObject().value("title");
           foo = v.toObject().value("title").toString();
           b.setTitle(foo.toStdString());

           foo = v.toObject().value("author").toString();
           b.setAuthor(foo.toStdString());

           foo = v.toObject().value("editorial").toString();
           b.setEditorial(foo.toStdString());

           foo = v.toObject().value("year").toString();
           b.setYear(foo.toStdString());

           foo = v.toObject().value("type").toString();
           b.setType(foo.toStdString());

           books.push_back(b);
       }
}

void admin::createGraph()
{

    int valor;
    grafoFavoritos.clear();
    aristaFavoritos.clear();
    grafoAux.clear();
    aristaAux.clear();
    foreach(user usuario, users){
        for(unsigned int i = 0; i < usuario.getMyBook().size(); i++){
            QString origen1 = usuario.getMyBook().at(i);
            for(unsigned int j = 0; j < usuario.getMyBook().size(); j++){
                if(!grafo.contains(origen1)){
                    if(origen1.compare(usuario.getMyBook().at(j)) != 0){
                        arista.insert(usuario.getMyBook().at(j),0);
                    }
                }
            }
            grafo.insert(usuario.getMyBook().at(i),arista);
            arista.clear();
        }
    }

    bool mexicanFlag=true;
    foreach(user usuario, users){
        for(unsigned int i = 0; i < usuario.getMyBook().size(); i++){
            QString origen = usuario.getMyBook().at(i);
            for(unsigned int j = 0; j < usuario.getMyBook().size(); j++){
                if(!grafo.contains(origen)){
                    if(origen.compare(usuario.getMyBook().at(j)) != 0){
                        if(!arista.contains(usuario.getMyBook().at(j))){
                            arista.insert(usuario.getMyBook().at(j),1);
                            mexicanFlag = true;
                        }
                        else{
                            if(!aristaAux.contains(usuario.getMyBook().at(j))){///Lo acabo de añadir
                                valor = grafo[origen].value(usuario.getMyBook().at(j));
                                grafo[origen][usuario.getMyBook().at(j)]=valor+1;
                                mexicanFlag=false;
                            }
                        }
                    }
                }
                else{
                    valor = grafo[origen].value(usuario.getMyBook().at(j));
                    if(origen.compare(usuario.getMyBook().at(j)) != 0){
                        if(!aristaFavoritos.contains(usuario.getMyBook().at(j))){
                            if(!aristaAux.contains(usuario.getMyBook().at(j))){///Este también
                                grafo[origen][usuario.getMyBook().at(j)]=valor+1;
                                mexicanFlag=false;
                                aristaAux.insert(usuario.getMyBook().at(j),valor+1);
                            }
                        }
                    }
                }
            }
            if(mexicanFlag==true){
                grafo.insert(usuario.getMyBook().at(i),arista);
                arista.clear();
            }
            ///qDebug() << QString::fromStdString(usuario.getNickName());
            if(validEdge(origen,usuario.getNickName()) == true){
                for(unsigned int k = 0; k < usuario.getMyFavorite().size(); k++){
                    if(grafo.contains(origen)){
                        if(origen.compare(usuario.getMyFavorite().at(k)) != 0){
                            if(!aristaFavoritos.contains(usuario.getMyFavorite().at(k))){
                                valor = grafo[origen].value(usuario.getMyFavorite().at(k));
                                ///qDebug() << origen <<" -> "<< usuario.getMyFavorite().at(k) << "= " << valor;
                                grafo[origen][usuario.getMyFavorite().at(k)]=valor+5;
                                aristaFavoritos.insert(usuario.getMyFavorite().at(k),valor+5);
                           }
                        }
                    }
                }
            }
            grafoFavoritos.insert(usuario.getMyBook().at(i),aristaFavoritos);
            aristaFavoritos.clear();
            grafoAux.insert(usuario.getMyBook().at(i),aristaAux);
            aristaAux.clear();
        }
    }

        /*QHash<QString, QHash<QString, int> >::iterator origen;
        for(origen = grafo.begin(); origen != grafo.end(); ++origen){
            QHash<QString, int>::iterator destino;
            for(destino = origen.value().begin(); destino != origen.value().end(); destino++){
                qDebug() << origen.key() <<" -> "<< destino.key() << "= " << destino.value();
            }
        }*/
}

bool admin::validEdge(QString origen, string myStr)
{
    foreach(user usuario, users){
        for(unsigned int i = 0; i < usuario.getMyFavorite().size(); i++){
            if(usuario.getMyFavorite().at(i) == origen && usuario.getNickName() == myStr){

                return true;
            }
        }
    }
    return false;
}

