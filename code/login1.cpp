#include "login1.h"
#include "ui_login1.h"
#include <QJsonObject>
#include"request.h"

login1::login1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login1)
{
    ui->setupUi(this);
}

login1::~login1()
{
    delete ui;
}

void login1::on_logIn_pushButton_clicked()
{


    QString username1=ui->username_login->text();
    QString password1=ui->password_login->text();

    request req;


    QJsonObject qobj=req.logInRequest(username1,password1);

    QString message=qobj.value("message").toString();
    QString code=qobj.value("code").toString();
    QString token=qobj.value("token").toString();


  //  QString message=req.logInRequest(username1,password1).value("message").toString();
   // QString code=req.logInRequest(username1,password1).value("code").toString();
   // QString token=req.logInRequest(username1,password1).value("token").toString();



    qDebug()<<message<<"***"<<code<<"***"<<token<<"\n";
}


void login1::on_checkBox_toggled(bool checked){

        if (checked) ui->password_login->setEchoMode(QLineEdit::Normal);
        else ui->password_login->setEchoMode(QLineEdit::Password);
}

