#ifndef USER_H
#define USER_H
#include <string>
#include <QString>
#include <vector>

using namespace std;


class user
{

private:
    string nickName;
    string mail;
    string password;
    vector <QString> myBooks;
    vector <QString> favorites;

public:
    user();

    string getNickName() const;
    void setNickName(const string &value);

    string getMail() const;
    void setMail(const string &value);

    string getPassword() const;
    void setPassword(const string &value);

    vector <QString> getMyBook() const;
    void setMyBook(const QString &value);

    vector <QString> getMyFavorite() const;
    void setMyFavorite(const QString &value);

    void clearArray();
};

#endif // USER_H
