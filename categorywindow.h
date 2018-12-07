#ifndef CATEGORYWINDOW_H
#define CATEGORYWINDOW_H

#include <QDialog>
#include "categorytemplate.h"
#include "book.h"

namespace Ui {
class categoryWindow;
}

class categoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit categoryWindow(QWidget *parent = nullptr);
    ~categoryWindow();

signals:
    void showBooks();
    void returnCategories();

private slots:
    void on_pushButton_clicked();

    void on_backPB_clicked();

    void on_antologiaPB_clicked();

    void on_biografiaPB_clicked();

    void on_dramaPB_clicked();

    void on_expositivoPB_clicked();

    void on_epistolarPB_clicked();

    void on_narrativaPB_clicked();

    void on_obraGraficaPB_clicked();

    void on_poesiaPB_clicked();

    void on_referenciaPB_clicked();

    void on_clasicoPB_clicked();

private:
    Ui::categoryWindow *ui;
    categorytemplate* catTemplate;
};

#endif // CATEGORYWINDOW_H
