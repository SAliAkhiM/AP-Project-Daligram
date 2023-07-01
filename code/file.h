#ifndef FILE_H
#define FILE_H
#include <QJsonObject>
#include<vector>
#include"qstring.h"
#include"message.h"
#include"user.h"
using namespace std;

class file
{
public:
    file();
 int getNum(QString  message ,QString type);
 void saveProfile1(QString username,QString password,QString token);
 user readProfile();
 void saveGroupList(QJsonObject jsonobj);
 void saveChannelList(QJsonObject jsonobj);
 void saveUserList(QJsonObject jsonobj);
 int  buildFolders(QString folderName);
 void saveUserChats(QJsonObject jsonobj);
 void saveGroupChats(QJsonObject jsonobj);
 void saveChannelChats(QJsonObject jsonobj);
 void saveProfile();
 vector<QString> readUserList();
 vector<QString> readGroupList();
 vector<QString> readChannelList();
 vector<messageClass> readUserMessages(QString token,QString dst2);
 vector<messageClass> readChannelMessages(QString token,QString dst2);
 vector<messageClass> readGroupMessages(QString token,QString dst2);


};

#endif // FILE_H
