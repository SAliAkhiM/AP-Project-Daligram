#include "signup.h"
#include "ui_signup.h"

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

signUp::signUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signUp)
{
    ui->setupUi(this);
}

signUp::~signUp()
{
    delete ui;
}

void signUp::on_pushButton_clicked()
{
    QString username1=ui->lineEdit_1->text();
    QString password1=ui->lineEdit_2->text();
    QString firstname=ui->lineEdit_fname->text();
    QString lastname=ui->lineEdit_lname->text();

    QNetworkAccessManager* manager=new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl("http://api.barafardayebehtar.ml:8080/signup?username="+username1+"&password="+password1+"&firstname="+firstname+"&lastname="+lastname));

    QNetworkReply * reply=manager->get(request);


    while(!reply->isFinished()){
        QCoreApplication::processEvents();
    }


    if(reply->error()==QNetworkReply::NoError){

        QByteArray data=reply->readAll();
        QJsonDocument jsonDoc=QJsonDocument::fromJson(data);

        QJsonObject jsonobj=jsonDoc.object();
        QString f=jsonobj.value("message").toString();

        qDebug()<<f;
        QMessageBox::information(this,"success",f);



    }
}
