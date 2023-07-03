#include "createjoingroups.h"
#include "ui_createjoingroups.h"


CreateJoinGroups::CreateJoinGroups(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateJoinGroups)
{
    ui->setupUi(this);
}

CreateJoinGroups::~CreateJoinGroups()
{
    delete ui;
}

void CreateJoinGroups::on_pushButton_2_clicked()
{
    file f , f2;
    user user1=f.readProfile();

    QString userToken;
    QString userUserName;
    QString userPassword;
    userToken=user1.getToken();
    userUserName=user1.getUserName();
    userPassword=user1.getPassword();

    QString groupName=ui->lineEdit->text();
    QString groupTitle=ui->lineEdit_2->text();

    request req;
    QJsonObject qobj=req.createGroupRequest(groupName,groupTitle ,userToken );

    QString message=qobj.value("message").toString();
    QString code=qobj.value("code").toString();
    QString token=qobj.value("token").toString();

    QJsonObject qobj2=req.getGroupListRequest(userToken);
    f2.saveGroupList(qobj2);

    QMessageBox::information(this,code,message);

}


void CreateJoinGroups::on_pushButton_clicked()
{
    file f , f2;
    user user1=f.readProfile();

    QString userToken;
    QString userUserName;
    QString userPassword;
    userToken=user1.getToken();
    userUserName=user1.getUserName();
    userPassword=user1.getPassword();

    QString groupName=ui->lineEdit->text();
    QString groupTitle=ui->lineEdit_2->text();

    request req;
    QJsonObject qobj=req.joinGroup(userToken,groupName);

    QString message=qobj.value("message").toString();
    QString code=qobj.value("code").toString();
    QString token=qobj.value("token").toString();

    QJsonObject qobj2=req.getGroupListRequest(userToken);
    f2.saveGroupList(qobj2);

    QMessageBox::information(this,code,message);

}

