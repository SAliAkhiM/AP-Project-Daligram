#ifndef FILE_H
#define FILE_H
#include <QJsonObject>
#include"qstring.h"

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

};

#endif // FILE_H
