#include"mainwindow.h"
#include "login1.h"
#include "ui_login1.h"
#include <QJsonObject>
#include"file.h"
#include"request.h"
#include"user.h"
#include"groupmsgthread.h"
#include"channelmsgthread.h"
#include"listupdatethread.h"
#include"usermsgthread.h"


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
    file f;
    request r;

    QString username1=ui->username_login->text();
    QString password1=ui->password_login->text();

    request req;

    QJsonObject qobj=req.logInRequest(username1,password1);

    QString message=qobj.value("message").toString();
    QString code=qobj.value("code").toString();
    QString token=qobj.value("token").toString();

    f.saveProfile1(username1,password1,token);
    qDebug()<<token;

///////////////////////////////////////////////////////////////
    user user1=f.readProfile();

     r.prepare(user1.getToken());
    MainWindow* w=new MainWindow;
    this->hide();
    w->show();


        listUpdateThread* lu=new listUpdateThread(user1.getToken(),w);
        userMsgThread* um=new userMsgThread(user1.getToken(),w);
        groupMsgThread* gm=new groupMsgThread(user1.getToken(),w);
        channelMsgThread* cm=new channelMsgThread(user1.getToken(),w);

        lu->start();
        um->start();
        gm->start();
        cm->start();
/////////////////////////////////////////////////////////////////

}


void login1::on_checkBox_toggled(bool checked){

        if (checked) ui->password_login->setEchoMode(QLineEdit::Normal);
        else ui->password_login->setEchoMode(QLineEdit::Password);
}

