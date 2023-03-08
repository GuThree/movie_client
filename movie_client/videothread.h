#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QThread>
#include "ffmpeg.h"

class VideoThread : public QThread
{
    Q_OBJECT
public:
    VideoThread();

    void stopThread();
    void startThread();

    void init(QString url);

private:
    void run() override;

signals:
    void emitImage(const QImage&);

private:
    bool m_isRun = false;

public:
    ffmpeg *m_ffmpeg = nullptr;
};
#endif // VIDEOTHREAD_H
