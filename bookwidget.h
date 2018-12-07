#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class bookwidget;
}

class bookwidget : public QWidget
{
    Q_OBJECT

public:
    explicit bookwidget(QString title, QString author, QString editorial, QString year, QString type,QWidget *parent = nullptr);
    ~bookwidget();

private:
    Ui::bookwidget *ui;
};

#endif // BOOKWIDGET_H
