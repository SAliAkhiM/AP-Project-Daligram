#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include"file.h"
//#include"message.h"
//#include"request.h"
//#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ui->setupUi(this);

    file f;
    user user1=f.readProfile();
    UserIsLogin=user1.getIsLogin();userToken=user1.getToken();userUserName=user1.getUserName();userPassword=user1.getPassword();
    startGroupList();
    startChannelList();
    startUserList();

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

    file f;

    vector<QString> userlist=f.readUserList();

    QListWidgetItem *item;



    for(int i=0;i<userlist.size();i++){
      item = new QListWidgetItem();
      item->setText(userlist[i]);
      item->setSizeHint(QSize(1,50));
      //item->setIcon(QIcon(":/new/prefix1/hide.png"));
      //item->setToolTip("Item tooltip");
      //item->setWhatsThis("Item what's this");
      ui->usersList->addItem(item);
    }

  connect(ui->usersList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
  emit(item);

}
void MainWindow::startGroupList(){

    file f;

    vector<QString> GroupList=f.readGroupList();

    QListWidgetItem *item;



    for(int i=0;i<GroupList.size();i++){
      item = new QListWidgetItem();
      item->setText(GroupList[i]);
      item->setSizeHint(QSize(1,50));
      //item->setIcon(QIcon(":/new/prefix1/hide.png"));
      //item->setToolTip("Item tooltip");
      //item->setWhatsThis("Item what's this");
      ui->GroupList->addItem(item);
    }

  connect(ui->GroupList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
  emit(item);

}
void MainWindow::startChannelList(){

    file f;

    vector<QString> ChannelList=f.readChannelList();

    QListWidgetItem *item;



    for(int i=0;i<ChannelList.size();i++){
      item = new QListWidgetItem();
      item->setText(ChannelList[i]);
      item->setSizeHint(QSize(1,50));
      //item->setIcon(QIcon(":/new/prefix1/hide.png"));
      //item->setToolTip("Item tooltip");
      //item->setWhatsThis("Item what's this");
      ui->ChannelList->addItem(item);
    }

  connect(ui->ChannelList,SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
  emit(item);

}


void MainWindow::onItemClicked(QListWidgetItem* item){
   request r;
   file f1;


    ui->nameLabel->setText(item->text());

    ui->messageList->clear();

    file f;
    vector<messageClass> messages;


    if(ui->tabWidget->currentIndex()==0){
        messages=f.readUserMessages(userToken,item->text());
        setDstType("user");
    }
    else if(ui->tabWidget->currentIndex()==1){
        messages=f.readGroupMessages(userToken,item->text());
        setDstType("group");
    }
    else if(ui->tabWidget->currentIndex()==2){
        messages=f.readChannelMessages(userToken,item->text());
        setDstType("channel");
    }




    QListWidgetItem *messageItem;


   for(int i=0;i<messages.size();i++){
     messageItem = new QListWidgetItem();
     messageItem->setText(messages[i].getBody());
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

    QJsonObject qobj1=req.getUserChats("d69f3713c9f0c11b812db3bfe57fcd29","star");
    f.saveUserChats(qobj1);

}


//void changeSlot(QString msg){
//    if(QString::compare(msg,"userListChanged")==0){
//      //  startUserList();
//    }
//}
