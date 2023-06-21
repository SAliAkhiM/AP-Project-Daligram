#ifndef USER_H
#define USER_H
#include<QString>

class user
{
    QString username;
    QString password;


public:
    user();

    void setUserName(QString username);
    void setPassword(QString Password);
    QString getUserName ();
    QString getPassword ();
    ~user();
};

#endif // USER_H
