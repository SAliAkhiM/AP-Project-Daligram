#include "signup.h"
#include "ui_signup.h"
#include"request.h"
#include"file.h"
#include"login1.h"
#include"message.h"

#include <QLineEdit>
#include <QPushButton>
#include<fstream>
#include<QDir>
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


    request r;
    file f;


    QString message=r.signUpRequest(username1,password1,firstname,lastname).value("message").toString();
    QString code=r.signUpRequest(username1,password1,firstname,lastname).value("code").toString();


   QMessageBox::information(this,code,message);

   request req;


   QJsonObject qobj=req.logInRequest(username1,password1);

   QString message2=qobj.value("message").toString();
   QString code2=qobj.value("code").toString();
   QString token=qobj.value("token").toString();


   f.saveProfile1(username1,password1,token);


    }


void signUp::on_pushButton_3_clicked()
{
    login1 *l=new login1;
    l->show();

}


void signUp::on_pushButton_4_clicked()
{
   // request r;


    file f;
    request r;
    vector<messageClass> v;

//    r.sendMessage("d69f3713c9f0c11b812db3bfe57fcd29","star","salam","user");
//    r.sendMessage("d69f3713c9f0c11b812db3bfe57fcd29","star","test2","user");
//    r.sendMessage("d69f3713c9f0c11b812db3bfe57fcd29","star","test3","user");
//    r.sendMessage("d69f3713c9f0c11b812db3bfe57fcd29","star","test4","user");
//    r.sendMessage("d69f3713c9f0c11b812db3bfe57fcd29","star","bye","user");



    QJsonObject qobj=r.getUserListRequest("d69f3713c9f0c11b812db3bfe57fcd29");
    QJsonObject qobj1=r.getUserChats("d69f3713c9f0c11b812db3bfe57fcd29","kkk");

   f.saveUserList(qobj);
   f.saveUserChats(qobj1);

    //f.saveUserList(r.getUserListRequest("033d53cbd1e4ab7e6654d684f6eeab6a"));


   // f.saveUserChats(r.getUserChats("033d53cbd1e4ab7e6654d684f6eeab6a","hafez"));



//    r.sendMessageUser("4c442565bbdddcb1786f61b0fb909194","hafez","hello mr.hafez","user");
//    f.saveUserChats(r.getUserListRequest("4c442565bbdddcb1786f61b0fb909194"));
//    v=f.readMessages("hafez");

//    f.saveGroupList(r.getGroupListRequest("4c442565bbdddcb1786f61b0fb909194"));
//    f.saveUserChats(r.getUserChats("4c442565bbdddcb1786f61b0fb909194","hafez"));
//     f.saveUserChats(r.getUserChats("4c442565bbdddcb1786f61b0fb909194","molana"));
//      f.saveUserChats(r.getUserChats("4c442565bbdddcb1786f61b0fb909194","bahar"));


}




void signUp::on_checkBox_toggled(bool checked)
{
    if (checked)   ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    else ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

