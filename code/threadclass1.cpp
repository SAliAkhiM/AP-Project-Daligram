#include "threadclass1.h"
#include"mainwindow.h"

//#include"file.h"
//#include"request.h"
//#include<QString>

threadClass1::threadClass1()
{

}

void threadClass1::operation(QString token)
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


    MainWindow* mw=new MainWindow;

    if(prevUserlist!=curUserlist){

   // connect(this,SIGNAL(changeSignal(QString)),mw,SLOT(changeSlot(QString)));
     emit("userListChanged");

    }

}
