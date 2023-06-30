#ifndef MESSAGE_H
#define MESSAGE_H
#include<QString>

class messageClass
{
    QString body;
    QString src;
    QString dst;
    QString date;
    QString time;

public:

    messageClass();

    void setBody(QString body);
    void setSrc(QString username);
    void setDst(QString username);
    void setDate(QString username);
    void setTime(QString username);

    QString getBody ();
    QString getSrc ();
    QString getDst ();
    QString getDate ();
    QString getTime ();

    ~messageClass();

};

#endif // MESSAGE_H



