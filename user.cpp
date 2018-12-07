#include "user.h"

string user::getNickName() const
{
    return nickName;
}

void user::setNickName(const string &value)
{
    nickName = value;
}

string user::getMail() const
{
    return mail;
}

void user::setMail(const string &value)
{
    mail = value;
}

string user::getPassword() const
{
    return password;
}

void user::setPassword(const string &value)
{
    password = value;
}

vector<QString> user::getMyBook() const
{
    return myBooks;
}

void user::setMyBook(const QString &value)
{
    myBooks.push_back(value);
}

vector<QString> user::getMyFavorite() const
{
    return favorites;
}

void user::setMyFavorite(const QString &value)
{
    favorites.push_back(value);

}

void user::clearArray()
{
    myBooks.clear();
    favorites.clear();
}



user::user()
{

}
