#include "request.h"
#include"file.h"
#include"user.h"
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


 QJsonObject request::logOutRequest(QString username,QString password){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/logout?username="+username+"&password="+password));

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


 QJsonObject request:: joinGroup(QString token,QString groupname){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/joingroup?token="+token+"&group_name="+groupname));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }





 }

 QJsonObject request::joinChannel(QString token,QString channelname){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/joinchannel?token="+token+"&channel_name="+channelname));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }



 }

 QJsonObject request::getGroupListRequest(QString token){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/getgrouplist?token="+token));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }



 }

 QJsonObject request::getChannelListRequest(QString token){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/getchannellist?token="+token));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }



 }

 QJsonObject request::getUserListRequest(QString token){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/getuserlist?token="+token));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }



 }

 QJsonObject request::sendMessage(QString token,QString dst,QString body,QString sendTo){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;

     // :|
     //if(sendTo.compare("user")==0)
     //request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/sendmessageuser?token="+token+"&dst="+dst+"&body="+body));
     //else if(sendTo.compare("group")==0)
     //request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/sendmessagegroup?token="+token+"&dst="+dst+"&body="+body));
     //else if(sendTo.compare("channel")==0)
     //request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/sendmessagechannel?token="+token+"&dst="+dst+"&body="+body));

     // Easy bro! :
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/sendmessage"+sendTo+"?token="+token+"&dst="+dst+"&body="+body));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }


 }

 QJsonObject request::getUserChats(QString token,QString dst){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/getuserchats?token="+token+"&dst="+dst));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }
 }

// QJsonObject request::getUserChats(QString token,QString dst,QString date){

 //}


 QJsonObject request::getGroupChats(QString token,QString dst){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/getgroupchats?token="+token+"&dst="+dst));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }
 }

 // QJsonObject request::getGroupChats(QString token,QString dst,QString date){

  //}


 QJsonObject request::getChannelChats(QString token,QString dst){

     QNetworkAccessManager* manager=new QNetworkAccessManager();
     QNetworkRequest request;
     request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/getchannelchats?token="+token+"&dst="+dst));

     QNetworkReply * reply=manager->get(request);


     while(!reply->isFinished()){
         QCoreApplication::processEvents();
     }


     if(reply->error()==QNetworkReply::NoError){

         QByteArray data=reply->readAll();
         QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

         QJsonObject jsonobj=jsonDoc.object();

         return jsonobj ;



     }
 }

 void request::prepare(QString token){

     file f;
     request r;
     user user1=f.readProfile();
    // UserIsLogin=user1.getIsLogin();userToken=user1.getToken();userUserName=user1.getUserName();userPassword=user1.getPassword();

     r.joinChannel(token,"aaddgfdsfrhfgyukghjhdrt");
     r.joinGroup(token,"dfhdfghfgjgh");
     r.sendMessage(token ,"hafez","hello","user");




     QJsonObject jo=r.getUserListRequest(token);
     QJsonObject jo1=r.getGroupListRequest(token);
     QJsonObject jo2=r.getChannelListRequest(token);
     f.saveUserList(jo);
     f.saveGroupList(jo1);
     f.saveChannelList(jo2);

 }

 int request:: isOnline(){

    request r;
    QJsonObject obj;
    QString code="default value";
    obj=r.sendMessage("baf6605150b1d3b2aa4ab17bc49d9a51" ,"hafez","hello","user");

    code=obj.value("code").toString();

    if(QString::compare(code,"200")==0||QString::compare(code,"404")==0||QString::compare(code,"204")==0||QString::compare(code,"401")==0){
        return 1;
    }
    else{
        return 0;
    }

 }
