#ifndef FILE_H
#define FILE_H
#include <QJsonObject>
#include<vector>
#include"qstring.h"
#include"message.h"
using namespace std;

class file
{
public:
    file();
 int getNum(QString  message ,QString type);
 void saveGroupList(QJsonObject jsonobj);
 void saveChannelList(QJsonObject jsonobj);
 void saveUserList(QJsonObject jsonobj);
 int  buildFolders(QString folderName);
 void saveUserChats(QJsonObject jsonobj);
 void saveGroupChats(QJsonObject jsonobj);
 void saveChannelChats(QJsonObject jsonobj);
 vector<QString> readUserList();
 vector<QString> readGroupList();
 vector<QString> readChannelList();
 vector<messageClass> readMessages(QString dst2);


};

#endif // FILE_H
