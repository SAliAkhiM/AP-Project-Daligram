#include "user.h"

user::user()
{

}

void user::setUserName(QString username)
{
    this->username= username;
}

void user::setPassword(QString password)
{
    this->password= password;
}
void user::setToken(QString token)
{
    this->token= token;
}
void user::setIsLogin(int isLogin)
{
    this->isLogin= isLogin;
}
QString user::getUserName ()
{
    return username;
}

QString user::getPassword ()
{
    return password;
}
QString user::getToken ()
{
    return token;
}
int user::getIsLogin(){
    return isLogin;
}

user::~user()
{
}
