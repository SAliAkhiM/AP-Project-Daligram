#ifndef GROUPMSGTHREAD_H
#define GROUPMSGTHREAD_H
#include"mainwindow.h"
#include <QThread>

class groupMsgThread : public QThread
{
public:

    groupMsgThread(QString token,MainWindow* m) : token1(token),m1(m){};
     void groupMsgUpdate(QString token,MainWindow* m);


    void run() override {
            groupMsgUpdate(token1, m1);
        }

private:
    QString token1;MainWindow* m1;
};

#endif // GROUPMSGTHREAD_H

