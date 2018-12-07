#ifndef SORTWINDOW_H
#define SORTWINDOW_H

#include <QDialog>
#include "book.h"
#include <string>

using namespace std;

namespace Ui {
class sortwindow;
}

class sortwindow : public QDialog
{
    Q_OBJECT

public:
    explicit sortwindow(vector<book> boo,QWidget *parent = nullptr);
    ~sortwindow();

    vector <book> returnSorted();

    struct sortedByTitle
    {
        bool operator()( const book& left, const book& right ) const {
            return left.getTitle() < right.getTitle();
        }
    };

    struct sortedByAuthor
    {
        bool operator()( const book& left, const book& right ) const {
            return left.getAuthor() < right.getAuthor();
        }
    };

    struct sortedByEditorial
    {
        bool operator()( const book& left, const book& right ) const {
            return left.getEditorial() < right.getEditorial();
        }
    };

    struct sortedByYear
    {
        bool operator()( const book& left, const book& right ) const {
            return left.getYear() < right.getYear();
        }
    };

    struct sortedByType
    {
        bool operator()( const book& left, const book& right ) const {
            return left.getType() < right.getType();
        }
    };
private slots:
    void on_pushButton_clicked();

private:
    Ui::sortwindow *ui;
    vector <book> libros;
};

#endif // SORTWINDOW_H
