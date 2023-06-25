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
     QJsonObject createChannelRequest(QString ChannelName ,QString ChannelTitle ,QString token);
    // QJsonObject logInRequest(QString username,QString password);







};

#endif // REQUEST_H
