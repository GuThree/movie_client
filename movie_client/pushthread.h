#ifndef PUSHTHREAD_H
#define PUSHTHREAD_H

#include <QThread>
#include <iostream>

class PushThread : public QThread
{
public:
    PushThread(QString f, QString url);
    void run();
private:
    QString fileName;
    QString url;
};

#endif // PUSHTHREAD_H
