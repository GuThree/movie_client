#ifndef PUSHTHREAD_H
#define PUSHTHREAD_H

#include <QThread>

class PushThread : public QThread
{
public:
    PushThread(QString f);
    void run();
private:
    QString fileName;
};

#endif // PUSHTHREAD_H
