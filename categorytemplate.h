#ifndef CATEGORYTEMPLATE_H
#define CATEGORYTEMPLATE_H

#include <QDialog>
#include "book.h"
#include "string"
#include "bookwidget.h"

namespace Ui {
class categorytemplate;
}

class categorytemplate : public QDialog
{
    Q_OBJECT

public:
    explicit categorytemplate(string name, QWidget *parent = nullptr);
    ~categorytemplate();

private:
    Ui::categorytemplate *ui;
};

#endif // CATEGORYTEMPLATE_H
