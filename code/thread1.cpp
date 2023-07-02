#include "thread1.h"
#include "ui_thread1.h"
#include"mainwindow.h"
#include<message.h>
#include <QDialog>

thread1::thread1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thread1)
{
    ui->setupUi(this);
}

thread1::~thread1()
{
    delete ui;
}



void thread1::ListOperation(QString token)
{
    file f;
    request r;

    vector<QString> prevUserlist;
    vector<QString> prevGrouplist;
    vector<QString> prevChannellist;

    vector<QString> curUserlist;
    vector<QString> curGrouplist;
    vector<QString> curChannellist;
    //******************************************************
    prevUserlist=f.readUserList();
    prevGrouplist=f.readGroupList();
    prevChannellist=f.readChannelList();


    QJsonObject json1=r.getUserListRequest(token);
    QJsonObject json2=r.getGroupListRequest(token);
    QJsonObject json3=r.getChannelListRequest(token);


    f.saveUserList(json1);
    f.saveGroupList(json2);
    f.saveChannelList(json3);

    curUserlist=f.readUserList();
    curGrouplist=f.readGroupList();
    curChannellist=f.readChannelList();


    MainWindow* m=new MainWindow;

    if(prevUserlist!=curUserlist||prevGrouplist!=curGrouplist){
         QObject::connect(this,SIGNAL(changeSignal(QString)),m,SLOT(changeSlot(QString)));

     emit("ListChanged");
    }

    //******************************************************************************************************

    vector<messageClass> prevMsg;
    vector<messageClass> curMsg;

    QJsonObject json4;

    for(int i=0;i<curUserlist.size();i++){


       prevMsg=f.readUserMessages(token,curUserlist[i]);

       json4=r.getUserChats(token,curUserlist[i]);

       f.saveUserChats(json4);

       curMsg=f.readUserMessages(token,curUserlist[i]);

       if(prevMsg!=curMsg){
            QObject::connect(this,SIGNAL(changeSignal(QString)),m,SLOT(userMsgChangeSlot(QString)));

        emit(curUserlist[i]);
       }

    }

    for(int i=0;i<curGrouplist.size();i++){


       prevMsg=f.readGroupMessages(token,curGrouplist[i]);

       json4=r.getGroupChats(token,curGrouplist[i]);

       f.saveGroupChats(json4);

       curMsg=f.readGroupMessages(token,curGrouplist[i]);

       if(prevMsg!=curMsg){
        QObject::connect(this,SIGNAL(changeSignal(QString)),m,SLOT(groupMsgChangeSlot(QString)));

        emit(curGrouplist[i]);
       }

    }

    for(int i=0;i<curChannellist.size();i++){


       prevMsg=f.readChannelMessages(token,curChannellist[i]);

       json4=r.getChannelChats(token,curChannellist[i]);

       f.saveChannelChats(json4);

       curMsg=f.readChannelMessages(token,curChannellist[i]);

       if(prevMsg!=curMsg){
        QObject::connect(this,SIGNAL(changeSignal(QString)),m,SLOT(channelMsgChangeSlot(QString)));

        emit(curChannellist[i]);
       }

    }



}
