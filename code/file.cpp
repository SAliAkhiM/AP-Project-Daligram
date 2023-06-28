#include "file.h"
#include"request.h"
#include<fstream>
#include <iostream>
#include<QDir>
#include<QString>


using namespace std;
file::file()
{
  int folderBuildCheck1=buildFolders("Users");
  int folderBuildCheck2=buildFolders("Groups");
  int folderBuildCheck3=buildFolders("Channels");

  if(folderBuildCheck1==0||folderBuildCheck2==0||folderBuildCheck3==0)
      throw "error building folders";

}

int file:: buildFolders(QString folderName){

    //QString folder_path = "path/to/folder";

  QString folder_path =  QDir::currentPath()+"/"+folderName;

        QDir dir(folder_path);
        if (!dir.exists()) {
            if (dir.mkpath(".")) {
                qDebug() << "Folder created:" << folder_path;
            } else {
                qWarning() << "Error creating folder:" << folder_path;
                return 0;
            }
        }
        return 1;

}

int file::getNum(QString message,QString type){
    QString number;

    if (type.compare("user")==0){
        for(int i=20;message[i]!='-';i++){
            number.append(message[i]);
        }

    }
    else if(type.compare("channel")==0||type.compare("group")==0){
        for(int i=12;message[i]!='-';i++){
            number.append(message[i]);
        }
    }
    else if(type.compare("chatlist")==0){
        for(int i=11;message[i]!='-';i++){
            number.append(message[i]);
        }
    }
return number.toInt();
}

void file:: saveGroupList(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Groups/GroupList.txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int groupNum=f.getNum(jsonobj.value("message").toString(),"group");


    if(file1.is_open()){
    for(int i=0;i<groupNum;i++){
        file1<<((((jsonobj.value("block "+QString::number(i))).toObject()).value("group_name")).toString()).toStdString()<<"\n";
    }

    file1.close();
}
    else
        throw "failed to open the file";




}

void file:: saveChannelList(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Channels/ChannelList.txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int channelNum=f.getNum(jsonobj.value("message").toString(),"channel");


    if(file1.is_open()){
    for(int i=0;i<channelNum;i++){
        file1<<((((jsonobj.value("block "+QString::number(i))).toObject()).value("channel_name")).toString()).toStdString()<<"\n";
    }

    file1.close();
}
    else
        throw "failed to open the file";


}

void file:: saveUserList(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Users/UserList.txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int userNum=f.getNum(jsonobj.value("message").toString(),"user");


    if(file1.is_open()){
    for(int i=0;i<userNum;i++){
        file1<<((((jsonobj.value("block "+QString::number(i))).toObject()).value("src")).toString()).toStdString()<<"\n";
    }

    file1.close();
}
    else
        throw "failed to open the file";

}

void file::saveUserChats(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Users/"+(((jsonobj.value("block 0").toObject()).value("dst")).toString())+".txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int chatNum=f.getNum(jsonobj.value("message").toString(),"chatlist");

  QJsonObject jsonobj1;

    if(file1.is_open()){
    for(int i=0;i<chatNum;i++){
        jsonobj1 = jsonobj.value("block "+QString::number(i)).toObject();
        file1<<jsonobj1.value("body").toString().toStdString()<<" "<<jsonobj1.value("src").toString().toStdString()<<" "<<jsonobj1.value("dst").toString().toStdString()<<" "<<jsonobj1.value("date").toString().toStdString()<<"\n";
    }

    file1.close();
}
    else
        throw "failed to open the file";

}

void file::saveGroupChats(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Groups/"+(((jsonobj.value("block 0").toObject()).value("dst")).toString())+".txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int chatNum=f.getNum(jsonobj.value("message").toString(),"chatlist");

  QJsonObject jsonobj1;

    if(file1.is_open()){
    for(int i=0;i<chatNum;i++){
        jsonobj1 = jsonobj.value("block "+QString::number(i)).toObject();
        file1<<jsonobj1.value("body").toString().toStdString()<<" "<<jsonobj1.value("src").toString().toStdString()<<" "<<jsonobj1.value("dst").toString().toStdString()<<" "<<jsonobj1.value("date").toString().toStdString()<<"\n";
    }

    file1.close();
}
    else
        throw "failed to open the file";

}

void file::saveChannelChats(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Channels/"+(((jsonobj.value("block 0").toObject()).value("dst")).toString())+".txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int chatNum=f.getNum(jsonobj.value("message").toString(),"chatlist");

  QJsonObject jsonobj1;

    if(file1.is_open()){
    for(int i=0;i<chatNum;i++){
        jsonobj1 = jsonobj.value("block "+QString::number(i)).toObject();
        file1<<jsonobj1.value("body").toString().toStdString()<<" "<<jsonobj1.value("src").toString().toStdString()<<" "<<jsonobj1.value("dst").toString().toStdString()<<" "<<jsonobj1.value("date").toString().toStdString()<<"\n";
    }

    file1.close();
}
    else
        throw "failed to open the file";

}
