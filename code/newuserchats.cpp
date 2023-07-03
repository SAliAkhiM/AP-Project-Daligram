#include "newuserchats.h"
#include "ui_newuserchats.h"

newUserChats::newUserChats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUserChats)
{
    ui->setupUi(this);
}

newUserChats::~newUserChats()
{
    delete ui;
}

void newUserChats::on_pushButton_clicked()
{
    file f , f2;
    user user1=f.readProfile();

    QString userToken;
    QString userUserName;
    QString userPassword;
    userToken=user1.getToken();
    userUserName=user1.getUserName();
    userPassword=user1.getPassword();

    QString newUserName=ui->lineEdit->text();
    QString body=ui->textEdit->toPlainText();

    request req;
    QJsonObject qobj=req.sendMessage(userToken,newUserName,body,"user");

    QString message=qobj.value("message").toString();
    QString code=qobj.value("code").toString();
    QString token=qobj.value("token").toString();

    QJsonObject qobj2=req.getUserListRequest(userToken);
    f2.saveGroupList(qobj2);

    QMessageBox::information(this,code,message);
}

