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
    else{
    //throw
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

 QJsonObject request::createGroupRequest(QString groupName ,QString groupTitle ,QString token){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/creategroup?token="+ token +"&group_name="+groupName+"&group_title="+groupTitle));

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

 QJsonObject request::createChannelRequest(QString channelName ,QString channelTitle ,QString token){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/creategroup?token="+ token +"&group_name="+channelName+"&group_title="+channelTitle));

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


 QJsonObject request::joinGroupRequest(QString groupName ,QString token){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/joingroup?token="+ token +"&group_name="+groupName));

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


 QJsonObject request::joinChannelRequest(QString channelName ,QString token){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/joinchannel?token="+ token +"&channel_name="+channelName));

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



