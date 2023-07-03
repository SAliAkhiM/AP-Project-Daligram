#include "listupdatethread.h"

//listUpdateThread::listUpdateThread()
//{

//}

void listUpdateThread::ListOperation(QString token, MainWindow *m)
{
    while(1){
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


    if(prevUserlist!=curUserlist||prevGrouplist!=curGrouplist||prevChannellist!=curChannellist){

      m->startChannelList();
      m->startGroupList();
      m->startUserList();

    }
    }

}