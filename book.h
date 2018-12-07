#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;



class book
{
private:
    string title;
    string author;
    string editorial;
    string year;
    string type;
public:
    book();

    string getTitle() const;
    string getAuthor() const;
    string getEditorial() const;
    string getYear() const;
    string getType() const;

    void setTitle(const string &value);
    void setAuthor(const string &value);
    void setEditorial(const string &value);
    void setYear(const string &value);
    void setType(const string &value);
};

#endif // BOOK_H
