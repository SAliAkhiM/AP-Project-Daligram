#include "usermsgthread.h"


//userMsgThread::userMsgThread()
//{

//}

void userMsgThread::usrMsgUpdate(QString token, MainWindow *m)
{

    file f;
    request r;
    while(1){

    vector<QString> curUserlist;
    curUserlist=f.readUserList();

    vector<messageClass> prevMsg;
    vector<messageClass> curMsg;

    QJsonObject json4;
qDebug()<<curUserlist[0];

    json4=r.getUserChats(token,curUserlist[0]);

    f.saveUserChats(json4);

//    for(int i=0;i<curUserlist.size();i++){


//       prevMsg=f.readUserMessages(token,curUserlist[i]);

//       json4=r.getUserChats(token,curUserlist[i]);

//       f.saveUserChats(json4);

//       curMsg=f.readUserMessages(token,curUserlist[i]);

//       if(prevMsg!=curMsg){

//       m->userMsgChange(curUserlist[i]);
//       }

//    }
    }
}
