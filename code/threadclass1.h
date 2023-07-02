#ifndef THREADCLASS1_H
#define THREADCLASS1_H
#include<QString>
#include <QDialog>

class threadClass1
{
public:
    threadClass1();
    void operation(QString token);
signals:
    void changeSignal(QString);

};

#endif // THREADCLASS1_H
