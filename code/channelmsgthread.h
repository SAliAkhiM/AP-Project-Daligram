#ifndef CHANNELMSGTHREAD_H
#define CHANNELMSGTHREAD_H
#include"mainwindow.h"
#include <QThread>

class channelMsgThread : public QThread
{
public:

    channelMsgThread(QString token,MainWindow* m) : token1(token),m1(m){};
     void channelMsgUpdate(QString token,MainWindow* m);


    void run() override {
            channelMsgUpdate(token1, m1);
        }

private:
    QString token1;MainWindow* m1;
};

#endif // CHANNELMSGTHREAD_H

