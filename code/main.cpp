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

//MainWindow* wi=new MainWindow;
//static MainWindow wi;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();


    MainWindow* w=new MainWindow;
    w->show();


    file f;
    request r;
    user user1=f.readProfile();

    listUpdateThread* lu=new listUpdateThread(user1.getToken(),w);
    userMsgThread* um=new userMsgThread(user1.getToken(),w);

    lu->start();
    um->start();



   // lu->wait();
   // um->wait();




    signUp *su=new signUp();
    su->show();


    return a.exec();
}
