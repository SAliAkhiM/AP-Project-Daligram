#ifndef USER_H
#define USER_H
#include<QString>

class user
{
    QString username;
    QString password;
    QString token;
    bool isLogin;


public:
    user();

    void setUserName(QString username);
    void setToken(QString Token);
    void setPassword(QString Password);
    void setIsLogin(int b);
    QString getUserName ();
    QString getPassword ();
    QString getToken ();
    int getIsLogin ();

    ~user();
};

#endif // USER_H
