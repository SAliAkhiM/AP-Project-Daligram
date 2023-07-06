#include "groupmsgthread.h"

//groupMsgThread::groupMsgThread()
//{

//}

void groupMsgThread::groupMsgUpdate(QString token, MainWindow *m)
{

//    file f;
//    request r;

    file f;
    request r;

    while(1){


    vector<QString> curGrouplist;
    curGrouplist=f.readGroupList();



//    vector<messageClass> prevMsg;
//    vector<messageClass> curMsg;

    QJsonObject json4;



    for(unsigned long long int i=0;i<curGrouplist.size();i++){


        //vector<messageClass> prevMsg;
//        vector<messageClass> curMsg;
//        qDebug()<<token;
//       prevMsg=f.readGroupMessages(token,curGrouplist[i]);
//         qDebug()<<"reading prev u";


       json4=r.getGroupChats(token,curGrouplist[i]);
         qDebug()<<"server delay";

       f.saveGroupChats(json4);
         qDebug()<<"saving "+curGrouplist[i]+"group msgs";

//       curMsg=f.readGroupMessages(token,curUserlist[i]);

//       qDebug()<<"reading cur Groupmsg";

//       if(prevMsg!=curMsg){

 //     m->groupMsgChange(curGrouplist[i]);
//       }



    }

    }


}
