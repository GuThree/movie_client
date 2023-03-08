#include "videothread.h"

#include <QDebug>
#include "audioplayer.h"
#include <QImage>

VideoThread::VideoThread()
{

}

void VideoThread::stopThread()
{
    m_isRun = false;
}

void VideoThread::startThread()
{
    m_isRun = true;
    start();
}

void VideoThread::init(QString url)
{
    if(nullptr == m_ffmpeg)
    {
        m_ffmpeg = new ffmpeg;
        connect(m_ffmpeg,SIGNAL(GetImage(const QImage&)),this,SIGNAL(emitImage(const QImage&)));
    }
    if(!(m_ffmpeg->initFFmpeg(url)))
    {
        qDebug()<<"initFFmpeg  error---";
        return;
    }
}

void VideoThread::run()
{
    char audioOut[10000] = {0};

    while(m_isRun)
    {
        int free = AudioPlayer::Get()->GetFree();
        if (free < 10000)
        {
            msleep(1);
            continue;
        }
        AVPacket pkt = m_ffmpeg->getPacket();
        if (pkt.size <= 0)
        {

            msleep(10);
            continue;
        }
        if (pkt.stream_index == m_ffmpeg->m_audioStreamIndex)
        {
            m_ffmpeg->decode(&pkt);//解码

            int len = m_ffmpeg->getPCM(audioOut);//获取一帧音频的pcm

            AudioPlayer::Get()->Write(audioOut, len);
        }
        else
        {
            if(m_ffmpeg->decode(&pkt))
            {
                m_ffmpeg->getRBG();
            }
        }

        av_packet_unref(&pkt);
    }
}
