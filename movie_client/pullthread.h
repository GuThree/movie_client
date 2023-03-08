#ifndef PULLTHREAD_H
#define PULLTHREAD_H

#include <QThread>

class Room;
#include "room.h"

class PullThread : public QThread
{
public:
    PullThread(Room *r);
    void run();

private:
    Room * roomWidget;
};

#endif // PULLTHREAD_H
