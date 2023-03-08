#ifndef PULLTHREAD_H
#define PULLTHREAD_H

#include <QThread>

class Room;
#include "room.h"

class PullThread : public QThread
{
public:
    PullThread(Room *r, QString id);
    void run();

private:
    QString roomid;
    Room * roomWidget;
};

#endif // PULLTHREAD_H
