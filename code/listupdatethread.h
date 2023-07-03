#ifndef LISTUPDATETHREAD_H
#define LISTUPDATETHREAD_H
#include"mainwindow.h"
#include <QThread>

class listUpdateThread:public QThread
{
public:
    //listUpdateThread(QObject *parent = nullptr) : QThread(parent){};

    listUpdateThread(QString token,MainWindow* m) : token1(token),m1(m){};
    void ListOperation(QString token,MainWindow* m);


    void run() override {
            ListOperation(token1, m1);
        }

private:
    QString token1;MainWindow* m1;
};

#endif // LISTUPDATETHREAD_H
