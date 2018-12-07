#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "book.h"
#include "node.h"
#include <vector>
#include <QHash>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(user &u,vector <book> bookscopy,QHash<QString, QHash<QString, int> > &g,QWidget *parent = nullptr);
    ~MainWindow();
    void gardaUsuario();
    void createRecomendations();
    void showRecomendations();
    bool validEdge(QString origen);
    struct sortVector
    {
            bool operator()( const node& left, const node& right ) const {
                return left.getWeight() > right.getWeight();
            }

    };

signals:
    void showCategories();
    void showProfile();
    void showFavorites();
    void showMyBooks();

private slots:

    void on_categoriesPB_clicked();

    void on_profilePB_clicked();

    void on_favoritesPB_clicked();

    void on_myBooksPB_clicked();

private:
    Ui::MainWindow *ui;
    user usr;
    node myNode;
    QString nombreViejo;
    vector <book> bc;
    vector <node> myRecommendatios;
    QHash<QString, QHash<QString, int> > myGraph;
};

#endif // MAINWINDOW_H
