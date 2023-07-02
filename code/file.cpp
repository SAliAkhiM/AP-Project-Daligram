#include "file.h"
#include"request.h"
#include"message.h"
#include<fstream>
#include <iostream>
#include<QDir>
#include<QString>
#include"user.h"


using namespace std;
file::file()
{
  int folderBuildCheck1=buildFolders("Users");
  int folderBuildCheck2=buildFolders("Groups");
  int folderBuildCheck3=buildFolders("Channels");
  int folderBuildCheck4=buildFolders("Profile");

  //if(folderBuildCheck1==0||folderBuildCheck2==0||folderBuildCheck3==0)
     // throw "error building folders";

}

int file:: buildFolders(QString folderName){


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
    else if(type.compare("chatlist")==0||type.compare("message")==0){
        for(int i=11;message[i]!='-';i++){
            number.append(message[i]);
        }

    }

return number.toInt();
}

void file::saveProfile1(QString username,QString password,QString token){

    file f;
    ofstream file1;
    QString path=QDir::currentPath()+"/Profile/profile.txt";
    file1.open(path.toStdString());

    std::string usernameStr= username.toStdString();std::string passwordStr= password.toStdString();std::string tokenStr=token.toStdString();

    file1<<"1"<<"\n"<<usernameStr<<"\n"<<passwordStr<<"\n"<<tokenStr;



}

user file::readProfile(){

    user u;

    QString path=QDir::currentPath()+"/Profile/profile.txt";

    std::string userName;
    std::string password;
    std::string token;


    QString userName1;
    QString password1;
    QString token1;
    int isLogin;


    std::ifstream file;
    file.open(path.toStdString());

    file>>isLogin>>userName>>password>>token;
    userName1=QString::fromStdString(userName);password1=QString::fromStdString(password);token1=QString::fromStdString(token);


    u.setIsLogin(isLogin);u.setUserName(userName1);u.setPassword(password1);u.setToken(token1);

    return u;

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
   // else
     //   throw "failed to open the file";




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
 //   else
        //throw "failed to open the file";


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
  //  else
    //    throw "failed to open the file";

}

void file::saveUserChats(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Users/"+(((jsonobj.value("block 0").toObject()).value("dst")).toString())+".txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int chatNum=f.getNum(jsonobj.value("message").toString(),"chatlist");

    file1<<chatNum<<"\n";

  QJsonObject jsonobj1;

    if(file1.is_open()){
    for(int i=0;i<chatNum;i++){
        jsonobj1 = jsonobj.value("block "+QString::number(i)).toObject();
        file1<<jsonobj1.value("body").toString().toStdString()<<"\n^&*7I4%$u8Ag6()#3@!\n"<<jsonobj1.value("src").toString().toStdString()<<"\n"<<jsonobj1.value("dst").toString().toStdString()<<"\n"<<jsonobj1.value("date").toString().toStdString()<<"\n";
    }

    file1.close();
}
   // else
   //     throw "failed to open the file";

}

void file::saveGroupChats(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Groups/"+(((jsonobj.value("block 0").toObject()).value("dst")).toString())+".txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int chatNum=f.getNum(jsonobj.value("message").toString(),"chatlist");
    file1<<chatNum<<"\n";

  QJsonObject jsonobj1;

    if(file1.is_open()){
    for(int i=0;i<chatNum;i++){
        jsonobj1 = jsonobj.value("block "+QString::number(i)).toObject();
        file1<<jsonobj1.value("body").toString().toStdString()<<"\n^&*7I4%$u8Ag6()#3@!\n"<<jsonobj1.value("src").toString().toStdString()<<"\n"<<jsonobj1.value("dst").toString().toStdString()<<"\n"<<jsonobj1.value("date").toString().toStdString()<<"\n";
    }

    file1.close();
}
   // else
     //   throw "failed to open the file";

}

void file::saveChannelChats(QJsonObject jsonobj){

    std::ofstream file1;
    QString path=QDir::currentPath()+"/Channels/"+(((jsonobj.value("block 0").toObject()).value("dst")).toString())+".txt";

    file1.open(path.toStdString());

    request req;
    file f;
    int chatNum=f.getNum(jsonobj.value("message").toString(),"chatlist");
    file1<<chatNum<<"\n";

  QJsonObject jsonobj1;

    if(file1.is_open()){
    for(int i=0;i<chatNum;i++){
        jsonobj1 = jsonobj.value("block "+QString::number(i)).toObject();
        file1<<jsonobj1.value("body").toString().toStdString()<<"\n^&*7I4%$u8Ag6()#3@!\n"<<jsonobj1.value("src").toString().toStdString()<<"\n"<<jsonobj1.value("dst").toString().toStdString()<<"\n"<<jsonobj1.value("date").toString().toStdString()<<"\n";
    }

    file1.close();
}
  //  else
    //    throw "failed to open the file";

}

vector<QString> file::readUserList(){

    vector<QString> userlist;
    std::string user;
    QString user1;

    std::ifstream file1;
    QString path=QDir::currentPath()+"/Users/UserList.txt";
    file1.open(path.toStdString());


    if(file1.is_open()){


        file1>>user;
        user1=QString::fromStdString(user);
    while(!file1.eof()){
        userlist.push_back(user1);
        file1>>user;
        user1=QString::fromStdString(user);
    }

    file1.close();
    return userlist;
}
//    else
//        throw "failed to open the file";
}

vector<QString> file::readGroupList(){

    vector<QString> grouplist;
    std::string user;
    QString user1;

    std::ifstream file1;
    QString path=QDir::currentPath()+"/Groups/GroupList.txt";
    file1.open(path.toStdString());


    if(file1.is_open()){


        file1>>user;
        user1=QString::fromStdString(user);
    while(!file1.eof()){
        grouplist.push_back(user1);
        file1>>user;
        user1=QString::fromStdString(user);
    }

    file1.close();
    return grouplist;
}
 //   else
  //      throw "failed to open the file";
}

vector<QString> file::readChannelList(){

    vector<QString> channellist;
    std::string user;
    QString user1;

    std::ifstream file1;
    QString path=QDir::currentPath()+"/Channels/ChannelList.txt";
    file1.open(path.toStdString());


    if(file1.is_open()){


        file1>>user;
        user1=QString::fromStdString(user);
    while(!file1.eof()){
        channellist.push_back(user1);
        file1>>user;
        user1=QString::fromStdString(user);
    }

    file1.close();
    return channellist;
}
//    else
 //       throw "failed to open the file";
}

vector<messageClass> file::readUserMessages(QString token,QString dst2){

    messageClass msg;

    vector<messageClass> messages;
    std::string sep="^&*7I4%$u8Ag6()#3@!";
    std::string body;
    std::string bodyTmp;
    std::string src;
    std::string dst;
    std::string date;
    std::string time;
    QString body1;
    QString bodyTmp1;
    QString src1;
    QString dst1;
    QString date1;
    QString time1;


    file f;
    request req;
    QJsonObject jsonobj=req.getUserChats(token,dst2);///////////////////////getChannelList




    std::ifstream file1;
    QString path=QDir::currentPath()+"/Users/"+dst2+".txt";////////////////////Channels+dst2
    file1.open(path.toStdString());

    int chatNum;
    file1>>chatNum;

    if(file1.is_open()){
   // while(!file1.eof()){

        qDebug()<<chatNum<<"++++++++++++";
        for(int i=0;i<chatNum;i++){

         body1.clear();

        std::getline(file1,bodyTmp);
        bodyTmp1=QString::fromStdString(bodyTmp);
        while(QString::compare(bodyTmp1,"^&*7I4%$u8Ag6()#3@!")!=0){
              body1.append(bodyTmp1+"\n");
            std::getline(file1,bodyTmp);
            bodyTmp1=QString::fromStdString(bodyTmp);

        }

       std::getline(file1,src);std::getline(file1,dst);std::getline(file1,date);
       src1=QString::fromStdString(src);dst1=QString::fromStdString(dst);date1=QString::fromStdString(date);
       msg.setBody(body1);msg.setSrc(src1);msg.setDst(dst1);msg.setDate(date1);msg.setTime("00");

       messages.push_back(msg);

}

    file1.close();
    return messages;
    }

    else{
        throw "failed to open the file";
}

}

vector<messageClass> file::readChannelMessages(QString token,QString dst2){

    messageClass msg;

    vector<messageClass> messages;
    std::string sep="^&*7I4%$u8Ag6()#3@!";
    std::string body;
    std::string bodyTmp;
    std::string src;
    std::string dst;
    std::string date;
    std::string time;
    QString body1;
    QString bodyTmp1;
    QString src1;
    QString dst1;
    QString date1;
    QString time1;


    file f;
    request req;
    QJsonObject jsonobj=req.getChannelChats(token,dst2);



    std::ifstream file1;
    QString path=QDir::currentPath()+"/Channels/"+dst2+".txt";
    file1.open(path.toStdString());

    int chatNum;
    file1>>chatNum;


    if(file1.is_open()){
   // while(!file1.eof()){

        for(int i=0;i<chatNum;i++){

         body1.clear();

        std::getline(file1,bodyTmp);
        bodyTmp1=QString::fromStdString(bodyTmp);
        while(QString::compare(bodyTmp1,"^&*7I4%$u8Ag6()#3@!")!=0){
              body1.append(bodyTmp1+"\n");
            std::getline(file1,bodyTmp);
            bodyTmp1=QString::fromStdString(bodyTmp);

        }

       std::getline(file1,src);std::getline(file1,dst);std::getline(file1,date);
       src1=QString::fromStdString(src);dst1=QString::fromStdString(dst);date1=QString::fromStdString(date);
       msg.setBody(body1);msg.setSrc(src1);msg.setDst(dst1);msg.setDate(date1);msg.setTime("00");

       messages.push_back(msg);

}

    file1.close();
    return messages;
    }

    else{
        throw "failed to open the file";
}

}

vector<messageClass> file::readGroupMessages(QString token,QString dst2){

    messageClass msg;

    vector<messageClass> messages;
    std::string sep="^&*7I4%$u8Ag6()#3@!";
    std::string body;
    std::string bodyTmp;
    std::string src;
    std::string dst;
    std::string date;
    std::string time;
    QString body1;
    QString bodyTmp1;
    QString src1;
    QString dst1;
    QString date1;
    QString time1;


    file f;
    request req;
    QJsonObject jsonobj=req.getGroupChats(token,dst2);




    std::ifstream file1;
    QString path=QDir::currentPath()+"/Groups/"+dst2+".txt";
    file1.open(path.toStdString());

    int chatNum;
    file1>>chatNum;

    if(file1.is_open()){
   // while(!file1.eof()){

        for(int i=0;i<chatNum;i++){

         body1.clear();

        std::getline(file1,bodyTmp);
        bodyTmp1=QString::fromStdString(bodyTmp);
        while(QString::compare(bodyTmp1,"^&*7I4%$u8Ag6()#3@!")!=0){
              body1.append(bodyTmp1+"\n");
            std::getline(file1,bodyTmp);
            bodyTmp1=QString::fromStdString(bodyTmp);

        }

       std::getline(file1,src);std::getline(file1,dst);std::getline(file1,date);
       src1=QString::fromStdString(src);dst1=QString::fromStdString(dst);date1=QString::fromStdString(date);
       msg.setBody(body1);msg.setSrc(src1);msg.setDst(dst1);msg.setDate(date1);msg.setTime("00");

       messages.push_back(msg);

}

    file1.close();
    return messages;
    }

    else{
        throw "failed to open the file";
}

}

