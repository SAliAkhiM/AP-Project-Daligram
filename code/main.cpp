#include "mainwindow.h"
#include"signup.h"
#include"listupdatethread.h"
#include"usermsgthread.h"
#include"groupmsgthread.h"
#include"channelmsgthread.h"
#include <QApplication>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

//MainWindow* wi=new MainWindow;
//static MainWindow wi;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    file f;
    request r;
    user user1=f.readProfile();
    qDebug()<<user1.getToken();

    signUp *su=new signUp;
    MainWindow* w=new MainWindow;


w->show();/////////////////////////////////////////////////////////////
su->show();


        listUpdateThread* lu=new listUpdateThread(user1.getToken(),w);
        userMsgThread* um=new userMsgThread(user1.getToken(),w);
        groupMsgThread* gm=new groupMsgThread(user1.getToken(),w);
        channelMsgThread* cm=new channelMsgThread(user1.getToken(),w);


        qDebug()<<user1.getToken();


        lu->start();
        um->start();
        gm->start();
        cm->start();








    return a.exec();
}

