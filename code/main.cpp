#include "mainwindow.h"
#include"signup.h"

#include <QApplication>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    signUp *su=new signUp();
    su->show();

    QNetworkAccessManager* manager=new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/signup?username=saraaaaaaaaaaaaaaa1&password=1234&firstname=sara&lastname=baradaran"));

    QNetworkReply* reply=manager->get(request);


    while(!reply->isFinished()){
        QCoreApplication::processEvents();
    }


    if(reply->error()==QNetworkReply::NoError){

        QByteArray data=reply->readAll();
        QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

        QJsonObject jsonobj=jsonDoc.object();
        QString f=jsonobj.value("message").toString();

        qDebug()<<f;



    }

    return a.exec();
}
