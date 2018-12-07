#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include "login.h"
#include "mainwindow.h"
#include "bukinwindow.h"
#include "registerwindow.h"
#include "categorywindow.h"
#include "profilewindow.h"
#include "modifywindow.h"
#include "bookwindow.h"
#include "user.h"
#include "book.h"
#include "mybookwindow.h"
#include "favoriteswindow.h"
#include "sortwindow.h"
#include <vector>
#include <QHash>

class admin : public QObject
{
    Q_OBJECT
    public:
        explicit admin(QObject *parent = nullptr);
        ~admin();

        void start();
        void writeToJsonUser();
        void writeToJson();
        void readFromJsonUser();
        void readFromJsonBooks();
        bool verifyMail(string mail);
        bool verifyMailExisted(string mail);
        bool verifyUserExisted(string nickname);
        void createGraph();
        bool validEdge(QString origen, string myStr);

    private:
        bukinwindow* bukin;
        Login* log;
        MainWindow* mainWindow;
        registerWindow* regis;
        categoryWindow* category;
        profilewindow* profile;
        modifywindow* modify;
        bookwindow* bookwin;
        mybookwindow* mybookwin;
        favoriteswindow* favorite;
        vector <user> users;
        vector <book> books;
        QHash<QString, QHash<QString, int> > grafo;
        QHash<QString, int> arista;
        QHash<QString, QHash<QString, int> > grafoFavoritos;
        QHash<QString, int> aristaFavoritos;
        QHash<QString, QHash<QString, int> > grafoAux;
        QHash<QString, int> aristaAux;
        unsigned int auxId;

private slots:
        void showLoginWindow();
        void showCreateWindow();
        void showCategoriesWindow();
        void showProfileWindow();
        void showBooksWindow();
        void showMyBooksWindow();
        void showFavoritesWindow();
        void modifyData();
        void returnProfileWindow();
        void returnCategoriesWindow();
        void returnBookWindow();
        void returnFavoriteWindow();
        void returnMyBooksWindow();
        void findUser(QString name, QString password);
        void addUser(QString name, QString password, QString mail);
};

#endif // ADMIN_H
