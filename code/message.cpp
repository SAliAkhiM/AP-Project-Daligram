#include "message.h"

messageClass::messageClass()
{

}

void messageClass::setBody(QString body)
{
    this->body= body;
}

void messageClass::setSrc(QString src)
{
    this->src= src;
}
void messageClass::setDst(QString body)
{
    this->dst= dst;
}

void messageClass::setDate(QString date)
{
    this->date= date;
}

void messageClass::setTime(QString time)
{
    this->time=time;
}

QString messageClass::getBody ()
{
    return body;
}

QString messageClass::getSrc ()
{
    return src;
}
QString messageClass::getDst ()
{
    return dst;
}
QString messageClass::getDate ()
{
    return date;
}
QString messageClass::getTime ()
{
    return time;
}

messageClass::~messageClass()
{
}