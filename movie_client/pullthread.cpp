#include "pullthread.h"
PullThread::PullThread(Room *r, QString id)
{
    roomWidget = r;
    roomid = id;
}

void PullThread::run()
{
    QString pullURL = "rtmp://192.168.211.153/live/livestream/" + roomid;
//    QString pullURL = "rtmp://192.168.211.153/live/livestream";

    if(roomWidget->m_videoThread->isRunning())
    {
        roomWidget->m_videoThread->stopThread();
    }

    roomWidget->m_videoThread->init(pullURL);
    roomWidget->m_videoThread->startThread();
}
