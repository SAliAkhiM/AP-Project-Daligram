#ifndef USERMSGTHREAD_H
#define USERMSGTHREAD_H
#include"mainwindow.h"
#include <QThread>

class userMsgThread:public QThread
{
public:

    userMsgThread(QString token,MainWindow* m) : token1(token),m1(m){};
     void usrMsgUpdate(QString token,MainWindow* m);


    void run() override {
            usrMsgUpdate(token1, m1);
        }

private:
    QString token1;MainWindow* m1;
};

#endif // USERMSGTHREAD_H
