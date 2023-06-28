#include "signup.h"
#include "ui_signup.h"
#include"request.h"
#include"file.h"
#include"login1.h"

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



    QString message=r.signUpRequest(username1,password1,firstname,lastname).value("message").toString();
    QString code=r.signUpRequest(username1,password1,firstname,lastname).value("code").toString();


   QMessageBox::information(this,code,message);



       // qDebug()<<message1;
       // QMessageBox::information(this,"success",f);



    }


void signUp::on_pushButton_3_clicked()
{
    login1 *l=new login1;
    l->show();

}


void signUp::on_pushButton_4_clicked()
{
    request r;


    file f;
   // f.saveGroupList(r.getGroupListRequest("705e436fad02cd677ce0e21d59319533"));
   // f.saveChannelList(r.getChannelListRequest("705e436fad02cd677ce0e21d59319533"));
   // f.saveUserList(r.getUserListRequest("705e436fad02cd677ce0e21d59319533"));

    f.saveChannelChats(r.getChannelChats("705e436fad02cd677ce0e21d59319533","lab"));


    //r.sendMessageUser("705e436fad02cd677ce0e21d59319533","lab","hello?","channel");
   // _sleep(3000);
   // r.sendMessageUser("705e436fad02cd677ce0e21d59319533","lab","how?","channel");
   // _sleep(3000);
   // r.sendMessageUser("705e436fad02cd677ce0e21d59319533","lab","are?","channel");
   // _sleep(3000);
   // r.sendMessageUser("705e436fad02cd677ce0e21d59319533","lab","you?","channel");

   // std::ofstream file1;

   // file1.open("D:/file practice/GroupList.txt");


    //int groupNum=f.getNum(r.getGroupListRequest("705e436fad02cd677ce0e21d59319533").value("message").toString(),"group");


  //  QString groupNum=r.getGroupListRequest("705e436fad02cd677ce0e21d59319533").value("message").toString();

    //qDebug()<<message1;


}

