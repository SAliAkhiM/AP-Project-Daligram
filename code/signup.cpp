#include "signup.h"
#include "ui_signup.h"


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

/////////////////////////////////////////////////////////////////////////////////////////////////////

   user user1=f.readProfile();


   MainWindow* w=new MainWindow;
   this->hide();
   w->show();


       listUpdateThread* lu=new listUpdateThread(user1.getToken(),w);
       userMsgThread* um=new userMsgThread(user1.getToken(),w);
//       groupMsgThread* gm=new groupMsgThread(user1.getToken(),w);
//       channelMsgThread* cm=new channelMsgThread(user1.getToken(),w);

       lu->start();
       um->start();

////////////////////////////////////////////////////////////////////////////////////////////////

    }


void signUp::on_pushButton_3_clicked()
{
    login1 *l=new login1;
    l->show();

}





void signUp::on_checkBox_toggled(bool checked)
{
    if (checked)   ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    else ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

