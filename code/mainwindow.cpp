 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include"thread1.h"
#include"listupdatethread.h"
#include"usermsgthread.h"
#include<QTimer>
//#include"file.h"
//#include"message.h"
//#include"request.h"
//#include<QMessageBox>

QListWidgetItem *item;
QListWidgetItem *item1;
QListWidgetItem *item2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ui->setupUi(this);

    file f;
    request r;
    user user1=f.readProfile();
    UserIsLogin=user1.getIsLogin();userToken=user1.getToken();userUserName=user1.getUserName();userPassword=user1.getPassword();

   // f.saveGroupList(r.getGroupListRequest(getUserToken()));
   // f.saveGroupChats(r.getGroupChats(getUserToken(),"hhh"));

   r.joinGroup(userToken,"default");
   r.joinChannel(userToken,"default1");
   r.sendMessage(userToken,"hafez","default","user");

    QJsonObject jo=r.getUserListRequest(userToken);
    QJsonObject jo1=r.getGroupListRequest(userToken);
    QJsonObject jo2=r.getChannelListRequest(userToken);
    f.saveUserList(jo);
    f.saveGroupList(jo1);
    f.saveChannelList(jo2);

    startGroupList();
    startChannelList();
    startUserList();

    qDebug()<<userToken<<"::::::::";


    connect(ui->usersList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
    emit(item);

    connect(ui->GroupList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
    emit(item1);


    connect(ui->ChannelList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
    emit(item2);




    ui->nameFrame->setStyleSheet("background-color: red;");
}
void MainWindow::setUserToken(QString t){
    userToken=t;
}
void MainWindow::setUserUserName(QString u){
    userUserName=u;
}
void MainWindow::setUserPassword(QString p){
    userPassword=p;
}
void MainWindow::setUserIsLogin(int i){
    UserIsLogin=i;
}
void MainWindow::setCurDst(QString c){
    curdst=c;
}
void MainWindow::setDstType(QString d){
    dstType=d;
}
QString MainWindow::getUserToken(){
    return userToken;
}
QString MainWindow::getUserUserName(){
    return userUserName;
}
QString MainWindow::getUserPassword(){
    return userPassword;
}
QString MainWindow::getCurDst(){
    return curdst;
}
QString MainWindow::getDstType(){
    return dstType;
}

int  MainWindow::getUserIsLogin(){
    return UserIsLogin;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startUserList(){

    ui->usersList->clear();

    file f;

    vector<QString> userlist=f.readUserList();

//   QListWidgetItem *item;


std::reverse(userlist.begin(),userlist.end());


    for(int i=0;i<userlist.size();i++){
         if(QString::compare(userlist[i],"hafez")!=0){
      //  qDebug()<<userlist[i]<<" ";
      item = new QListWidgetItem();
      item->setText(userlist[i]);
      item->setSizeHint(QSize(1,50));
      //item->setIcon(QIcon(":/new/prefix1/hide.png"));
      //item->setToolTip("Item tooltip");
      //item->setWhatsThis("Item what's this");
      ui->usersList->addItem(item);
         }
    }

//  connect(ui->usersList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
//  emit(item);

}



void MainWindow::startGroupList(){
ui->GroupList->clear();
    file f;

    vector<QString> GroupList=f.readGroupList();



std::reverse(GroupList.begin(),GroupList.end());


//if(GroupList.size()!=0){
    for(int i=0;i<GroupList.size();i++){
        if(QString::compare(GroupList[i],"default")!=0){
      item = new QListWidgetItem();
      item->setText(GroupList[i]);
      item->setSizeHint(QSize(1,50));
      //item->setIcon(QIcon(":/new/prefix1/hide.png"));
      //item->setToolTip("Item tooltip");
      //item->setWhatsThis("Item what's this");
      ui->GroupList->addItem(item);
        }
    }
//}
//else{
//    qDebug()<<"no group";
//}

//  connect(ui->GroupList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
//  emit(item);

}
void MainWindow::startChannelList(){
ui->ChannelList->clear();
    file f;

    vector<QString> ChannelList=f.readChannelList();

    QListWidgetItem *item;



    std::reverse(ChannelList.begin(),ChannelList.end());

    for(int i=0;i<ChannelList.size();i++){
         if(QString::compare(ChannelList[i],"default1")!=0){
      item = new QListWidgetItem();
      item->setText(ChannelList[i]);
      item->setSizeHint(QSize(1,50));
      //item->setIcon(QIcon(":/new/prefix1/hide.png"));
      //item->setToolTip("Item tooltip");
      //item->setWhatsThis("Item what's this");
      ui->ChannelList->addItem(item);
         }
    }

//  connect(ui->ChannelList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
//  emit(item);

}


void MainWindow::onItemClicked(QListWidgetItem* item){
   request r;
   file f1;


   ui->messageTextEdit->hide();

    ui->nameLabel->setText(item->text());

    ui->messageList->clear();

    file f;
    vector<messageClass> messages;


    if(ui->tabWidget->currentIndex()==0){
        ui->messageTextEdit->show();
        ui->sendButton1->show();

        messages=f.readUserMessages(userToken,item->text());
        setDstType("user");
    }
    else if(ui->tabWidget->currentIndex()==1){
        ui->messageTextEdit->show();
        ui->sendButton1->show();

        messages=f.readGroupMessages(userToken,item->text());
        setDstType("group");
    }
    else if(ui->tabWidget->currentIndex()==2){

        ui->messageTextEdit->hide();
        ui->sendButton1->hide();

        messages=f.readChannelMessages(userToken,item->text());
        setDstType("channel");
    }




    QListWidgetItem *messageItem;


   for(int i=0;i<messages.size();i++){
     messageItem = new QListWidgetItem();
     messageItem->setText("*"+messages[i].getSrc()+"*\n"+messages[i].getBody());
     messageItem->setSizeHint(QSize());
     //item->setIcon(QIcon(":/new/prefix1/hide.png"));
     messageItem->setToolTip(messages[i].getDate());
     //item->setWhatsThis("Item what's this");
     ui->messageList->addItem(messageItem);
   }

  setCurDst(item->text());


  //qDebug()<<getDstType();

}

void MainWindow::on_sendButton1_clicked()
{
   file f;
   request req;
   req.sendMessage(getUserToken(),getCurDst(),ui->messageTextEdit->toPlainText(),getDstType());
   ui->messageTextEdit->clear();

   QJsonObject qobj1;

   ofstream file1;
   vector<QString> vec;
   QString path;

   if(QString::compare(getDstType(),"user")==0){
       vec=f.readUserList();

       path=QDir::currentPath()+"/Users/UserList.txt";

     //  qobj1=req.getUserChats(getUserToken(),getCurDst());
//       f.saveUserChats(qobj1);

   }
   else if(QString::compare(getDstType(),"group")==0){
       vec=f.readGroupList();

       path=QDir::currentPath()+"/Groups/GroupList.txt";

    //   qobj1=req.getGroupChats(getUserToken(),getCurDst());
    //   f.saveGroupChats(qobj1);
   }
   else if(QString::compare(getDstType(),"channel")==0){
       vec=f.readChannelList();
       path=QDir::currentPath()+"/Channels/ChannelList.txt";

     //  qobj1=req.getChannelChats(getUserToken(),getCurDst());
     //  f.saveChannelChats(qobj1);
   }

   auto iter = std::find(vec.begin(), vec.end(), getCurDst());
       if (iter != vec.begin()) {
           std::iter_swap(iter, vec.begin());
       }

   file1.open(path.toStdString());

   for(int i=0;i<vec.size();i++){
       file1<<vec[i].toStdString()<<"\n";
   }

  file1.close();

  if(QString::compare(getDstType(),"user")==0){startUserList();}
  else if(QString::compare(getDstType(),"group")==0){startGroupList();}
  else if(QString::compare(getDstType(),"group")==0){startChannelList();}


}




void MainWindow::Slot(QString s){
    qDebug()<<"fffffffffffffffff";
    ui->usersList->clear();
}



void MainWindow::listChange2(){

     startUserList();

}

void MainWindow::userMsgChange(QString user){

    qDebug()<<"message changed";
    vector<QString> vec;
    file f;

    vec=f.readUserList();
    qDebug()<<"reading userlist to change order";

    auto iter = std::find(vec.begin(), vec.end(), user);
        if (iter != vec.begin()) {
            std::iter_swap(iter, vec.begin());
        }


    ofstream file1;
    QString path=QDir::currentPath()+"/Users/UserList.txt";
    file1.open(path.toStdString());

    for(int i=0;i<vec.size();i++){
        file1<<vec[i].toStdString()<<"\n";
    }

    qDebug()<<"writing new userlist on file";

   file1.close();

   startUserList();

}

void MainWindow::groupMsgChange(QString group){

    qDebug()<<"message changed";
    vector<QString> vec;
    file f;

    vec=f.readGroupList();

    auto iter = std::find(vec.begin(), vec.end(), group);
        if (iter != vec.begin()) {
            std::iter_swap(iter, vec.begin());
        }
    qDebug()<<vec[0];

    ofstream file1;
    QString path=QDir::currentPath()+"/Groups/GroupList.txt";
    file1.open(path.toStdString());

    for(int i=0;i<vec.size();i++){
        file1<<vec[i].toStdString()<<"\n";
    }

   file1.close();

   startGroupList();

}

void MainWindow::channelMsgChange(QString channel)
{
    qDebug()<<"message changed";
    vector<QString> vec;
    file f;

    vec=f.readChannelList();

    auto iter = std::find(vec.begin(), vec.end(), channel);
        if (iter != vec.begin()) {
            std::iter_swap(iter, vec.begin());
        }
    qDebug()<<vec[0];

    ofstream file1;
    QString path=QDir::currentPath()+"/Channels/ChannelList.txt";
    file1.open(path.toStdString());

    for(int i=0;i<vec.size();i++){
        file1<<vec[i].toStdString()<<"\n";
    }

   file1.close();

   startChannelList();
}






void MainWindow::userMsgChangeSlot(QString user){

    qDebug()<<"message changed";

    QListWidgetItem* item ;
   for(int i=0;i<ui->usersList->count();i++){
       item= ui->usersList->item(i);
       if(item->text()==user){
           delete item;
           ui->usersList->addItem(item);
           break;
       }
   }
}



void MainWindow::groupMsgChangeSlot(QString)
{

}



void MainWindow::channelMsgChangeSlot(QString user)
{



}




void MainWindow::on_pushButton_clicked()
{
    thread1 t;
    t.ListOperation("d69f3713c9f0c11b812db3bfe57fcd29",this);
    qDebug()<<"finished";
}






void MainWindow::on_pushButton_2_clicked()
{
    request r;
    file f;
    QJsonObject obj;
    user user1=f.readProfile();
    obj=r.logOutRequest(user1.getUserName(),user1.getPassword());

    ofstream file1;
    QString path=QDir::currentPath()+"/Profile/profile.txt";
    file1.open(path.toStdString());

    file1<<"0";




    QString message=obj.value("message").toString();
    QString code=obj.value("code").toString();
    QMessageBox::information(this,code,message);


}


void MainWindow::on_UsersSearch_2_clicked()
{
    newUserChats *nuc=new newUserChats;
    nuc->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    CreateJoinGroups *cjg=new CreateJoinGroups;
    cjg->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    CreateJoinChannels *cjc=new CreateJoinChannels;
    cjc->show();
}

