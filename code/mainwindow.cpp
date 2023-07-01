#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"file.h"
#include"message.h"
#include"request.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startUserList();
    ui->nameFrame->setStyleSheet("background-color: red;");
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



    messages=f.readMessages(item->text());


    QListWidgetItem *messageItem;


   for(int i=0;i<messages.size();i++){
     messageItem = new QListWidgetItem();
     messageItem->setText(messages[i].getBody());
     messageItem->setSizeHint(QSize(1,60));
     //item->setIcon(QIcon(":/new/prefix1/hide.png"));
     messageItem->setToolTip(messages[i].getDate());
     //item->setWhatsThis("Item what's this");
     ui->messageList->addItem(messageItem);
   }


}





void MainWindow::on_pushButton_3_clicked()
{

}


void MainWindow::on_pushButton_2_clicked()
{
 //   ui->listWidget->addItem("hello");

}

