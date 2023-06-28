#include "signup.h"
#include "ui_signup.h"
#include"request.h"
#include"login1.h"

#include <QLineEdit>
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


void signUp::on_checkBox_toggled(bool checked)
{
    if (checked) ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
       else ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

