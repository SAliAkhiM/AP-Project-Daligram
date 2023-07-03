#include "usermsgthread.h"


//userMsgThread::userMsgThread()
//{

//}

void userMsgThread::usrMsgUpdate(QString token, MainWindow *m)
{

//    file f;
//    request r;



    while(1){
    file f;
    request r;

    vector<QString> curUserlist;
    curUserlist=f.readUserList();


    qDebug()<<curUserlist[0]<<"iiiiiiiiiiiiiiiiiiiii";

    qDebug()<<curUserlist.size()<<"iiiiiiiiiiiiiiiiiii";

//    vector<messageClass> prevMsg;
//    vector<messageClass> curMsg;

    QJsonObject json4;



    for(int i=0;i<curUserlist.size();i++){


        //vector<messageClass> prevMsg;
//        vector<messageClass> curMsg;
//        qDebug()<<token;
//       prevMsg=f.readUserMessages(token,curUserlist[i]);
//         qDebug()<<"reading prev u";


       json4=r.getUserChats(token,curUserlist[i]);
         qDebug()<<"server delay";

       f.saveUserChats(json4);
         qDebug()<<"saving msgs";

//       curMsg=f.readUserMessages(token,curUserlist[i]);

//       qDebug()<<"reading cur umsg";

//       if(prevMsg!=curMsg){

//       m->userMsgChange(curUserlist[i]);
//       }



    }

    }


}
