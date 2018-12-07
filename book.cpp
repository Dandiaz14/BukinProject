#include "book.h"

book::book()
{

}

string book::getTitle() const
{
    return title;
}

string book::getAuthor() const
{
    return author;
}

string book::getEditorial() const
{
    return editorial;
}

string book::getYear() const
{
    return year;
}

string book::getType() const
{
    return type;
}

void book::setTitle(const string &value)
{
    title = value;
}

void book::setAuthor(const string &value)
{
   author = value;
}

void book::setEditorial(const string &value)
{
    editorial = value;
}

void book::setYear(const string &value)
{
    year = value;
}

void book::setType(const string &value)
{
    type = value;
}

