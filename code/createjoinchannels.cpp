#include "createjoinchannels.h"
#include "ui_createjoinchannels.h"

CreateJoinChannels::CreateJoinChannels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateJoinChannels)
{
    ui->setupUi(this);
}

CreateJoinChannels::~CreateJoinChannels()
{
    delete ui;
}

void CreateJoinChannels::on_pushButton_clicked()
{

    file f , f2;
    user user1=f.readProfile();

    QString userToken;
    QString userUserName;
    QString userPassword;
    userToken=user1.getToken();
    userUserName=user1.getUserName();
    userPassword=user1.getPassword();

    QString channelName=ui->lineEdit->text();
    QString channelTitle=ui->lineEdit_2->text();

    request req;
    QJsonObject qobj=req.createChannelRequest(channelName,channelTitle ,userToken );

    QString message=qobj.value("message").toString();
    QString code=qobj.value("code").toString();
    QString token=qobj.value("token").toString();

    QJsonObject qobj2=req.getChannelListRequest(userToken);
    f2.saveChannelList(qobj2);

    QMessageBox::information(this,code,message);
}


void CreateJoinChannels::on_pushButton_2_clicked()
{
    file f , f2;
    user user1=f.readProfile();

    QString userToken;
    QString userUserName;
    QString userPassword;
    userToken=user1.getToken();
    userUserName=user1.getUserName();
    userPassword=user1.getPassword();

    QString channelName=ui->lineEdit->text();
    QString channelTitle=ui->lineEdit_2->text();

    request req;
    QJsonObject qobj=req.joinChannel(userToken,channelName);

    QString message=qobj.value("message").toString();
    QString code=qobj.value("code").toString();
    QString token=qobj.value("token").toString();

    QJsonObject qobj2=req.getChannelListRequest(userToken);
    f2.saveChannelList(qobj2);

    QMessageBox::information(this,code,message);
}

