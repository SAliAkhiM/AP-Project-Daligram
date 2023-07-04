#include "channelmsgthread.h"

//channelMsgThread::channelMsgThread()
//{

//}

void channelMsgThread::channelMsgUpdate(QString token, MainWindow *m)
{



    while(1){
    file f;
    request r;

    vector<QString> curChannellist;
    curChannellist=f.readChannelList();


    qDebug()<<curChannellist[0]<<"iiiiiiiiiiiiiiiiiiiii";

    qDebug()<<curChannellist.size()<<"iiiiiiiiiiiiiiiiiii";

//    vector<messageClass> prevMsg;
//    vector<messageClass> curMsg;

    QJsonObject json4;



    for(unsigned long long int i=0;i<curChannellist.size();i++){


        //vector<messageClass> prevMsg;
//        vector<messageClass> curMsg;
//        qDebug()<<token;
//       prevMsg=f.readChannelMessages(token,curChannellist[i]);
//         qDebug()<<"reading prev u";


       json4=r.getChannelChats(token,curChannellist[i]);
         qDebug()<<"server delay";

       f.saveChannelChats(json4);
         qDebug()<<"saving msgs";

//       curMsg=f.readChannelMessages(token,curChannellist[i]);

//       qDebug()<<"reading cur Channelmsg";

//       if(prevMsg!=curMsg){

 //     m->ChannelMsgChange(curChannellist[i]);
//       }



    }

    }


}
