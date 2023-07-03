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



void thread1::ListOperation(QString token,MainWindow* m)
{


    file f;
    request r;

//    vector<QString> prevUserlist;
//    vector<QString> prevGrouplist;
//    vector<QString> prevChannellist;

    vector<QString> curUserlist;
//    vector<QString> curGrouplist;
//    vector<QString> curChannellist;
//    //******************************************************
//    prevUserlist=f.readUserList();
//    prevGrouplist=f.readGroupList();
//    prevChannellist=f.readChannelList();


//    QJsonObject json1=r.getUserListRequest(token);
//    QJsonObject json2=r.getGroupListRequest(token);
//    QJsonObject json3=r.getChannelListRequest(token);


//    f.saveUserList(json1);
//    f.saveGroupList(json2);
//    f.saveChannelList(json3);

    curUserlist=f.readUserList();
//    curGrouplist=f.readGroupList();
//    curChannellist=f.readChannelList();


//    if(prevUserlist!=curUserlist||prevGrouplist!=curGrouplist||prevChannellist!=curChannellist){
//        qDebug()<<"list changed llllll";

//    //  connect(this,SIGNAL(listChangeSignal(QString)),m,SLOT(Slot(QString)));
//        //emit("ListChanged");

//      m->listChange2();


//    }

    //******************************************************************************************************








}

void thread1::usrMsgUpdate(QString token,MainWindow* m){

    file f;
    request r;

    vector<QString> curUserlist;
    curUserlist=f.readUserList();

    vector<messageClass> prevMsg;
    vector<messageClass> curMsg;

    QJsonObject json4;

    for(int i=0;i<curUserlist.size();i++){


       prevMsg=f.readUserMessages(token,curUserlist[i]);

       json4=r.getUserChats(token,curUserlist[i]);

       f.saveUserChats(json4);

       curMsg=f.readUserMessages(token,curUserlist[i]);

       if(prevMsg!=curMsg){

       m->userMsgChange(curUserlist[i]);
       }

    }

}

void thread1::groupMsgUpdate(QString token,MainWindow* m){

    file f;
    request r;

    vector<QString> curGrouplist;
    curGrouplist=f.readGroupList();

    vector<messageClass> prevMsg;
    vector<messageClass> curMsg;

    QJsonObject json4;

        for(int i=0;i<curGrouplist.size();i++){


           prevMsg=f.readGroupMessages(token,curGrouplist[i]);

           json4=r.getGroupChats(token,curGrouplist[i]);

           f.saveGroupChats(json4);

           curMsg=f.readGroupMessages(token,curGrouplist[i]);

           if(prevMsg!=curMsg){
            m->groupMsgChange(curGrouplist[i]);
           }

        }
}

void thread1::channelMsgUpdate(QString token, MainWindow *m)
{

    file f;
    request r;

    vector<QString> curChannellist;
    curChannellist=f.readChannelList();

    vector<messageClass> prevMsg;
    vector<messageClass> curMsg;

    QJsonObject json4;



        for(int i=0;i<curChannellist.size();i++){


           prevMsg=f.readChannelMessages(token,curChannellist[i]);

           json4=r.getChannelChats(token,curChannellist[i]);

           f.saveChannelChats(json4);

           curMsg=f.readChannelMessages(token,curChannellist[i]);

           if(prevMsg!=curMsg){
            m->channelMsgChange(curChannellist[i]);
           }

        }
}


