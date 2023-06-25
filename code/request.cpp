#include "request.h"

request::request()
{

}
 QJsonObject request::signUpRequest(QString username,QString password,QString firstname,QString lastname){


    QNetworkAccessManager* manager=new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/signup?username="+username+"&password="+password+"&firstname="+firstname+"&lastname="+lastname));

    QNetworkReply * reply=manager->get(request);


    while(!reply->isFinished()){
        QCoreApplication::processEvents();
    }


    if(reply->error()==QNetworkReply::NoError){

        QByteArray data=reply->readAll();
        QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

        QJsonObject jsonobj=jsonDoc.object();
        //QString f=jsonobj.value("message").toString();

        return jsonobj ;
       // return f ;


    }



}


 QJsonObject request::logInRequest(QString username,QString password){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/login?username="+username+"&password="+password));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();
         //QString f=jsonobj.value("message").toString();

         return jsonobj ;
        // return f ;


     }



 }



