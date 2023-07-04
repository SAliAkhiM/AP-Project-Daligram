#include "mainwindow.h"
#include"signup.h"
#include"listupdatethread.h"
#include"usermsgthread.h"
#include <QApplication>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include<QString>
#include"groupmsgthread.h"
#include"channelmsgthread.h"

//MainWindow* wi=new MainWindow;
//static MainWindow wi;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    file f;
    request r;
    user user1=f.readProfile();



    signUp *su=new signUp();


    if(user1.getIsLogin()==0){
        f.deleteFolders();
        su->show();
    }



     else{
    MainWindow* w=new MainWindow;
    w->show();


        listUpdateThread* lu=new listUpdateThread(user1.getToken(),w);
        userMsgThread* um=new userMsgThread(user1.getToken(),w);
        groupMsgThread* gm=new groupMsgThread(user1.getToken(),w);
        channelMsgThread* cm=new channelMsgThread(user1.getToken(),w);

        lu->start();
        um->start();}
        //gm->start();
        //cm->start();






    return a.exec();
}

