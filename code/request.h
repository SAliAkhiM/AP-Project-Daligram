#ifndef REQUEST_H
#define REQUEST_H
#include<QMessageBox>
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
class request
{
public:
    request();
     QJsonObject signUpRequest(QString username,QString password,QString firstname,QString lastname);
     QJsonObject logInRequest(QString username,QString password);
     QJsonObject createGroupRequest(QString groupName ,QString groupTitle ,QString token);
     QJsonObject createChannelRequest(QString channelName ,QString channelTitle ,QString token);
     QJsonObject joinGroup(QString token,QString groupname);
     QJsonObject joinChannel(QString token,QString channelname);
     QJsonObject getGroupListRequest(QString token);
     QJsonObject getChannelListRequest(QString token);
     QJsonObject getUserListRequest(QString token);
     QJsonObject sendMessageUser(QString token,QString dst,QString body,QString sendTo);
     QJsonObject getUserChats(QString token,QString dst);
     //QJsonObject getUserChats(QString token,QString dst,QString date);
     QJsonObject getGroupChats(QString token,QString dst);
     //QJsonObject getGroupChats(QString token,QString dst,QString date);
     QJsonObject getChannelChats(QString token,QString dst);
     //QJsonObject getChannelChats(QString token,QString dst,QString date);


    // QJsonObject logInRequest(QString username,QString password);







};

#endif // REQUEST_H
