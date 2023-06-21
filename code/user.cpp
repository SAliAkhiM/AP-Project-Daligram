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

QString user::getUserName ()
{
    return username;
}

QString user::getPassword ()
{
    return password;
}

user::~user()
{
}
