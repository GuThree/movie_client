#ifndef FFMPEG_H
#define FFMPEG_H
/*
    ffmpeg 接口类
*/
#include <QObject>
#include <QMutex>

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavfilter/avfilter.h>
#include <libswscale/swscale.h>
#include <libavutil/frame.h>
#include <libswresample/swresample.h>
}

class ffmpeg :public QObject
{
    Q_OBJECT
public:
    ffmpeg();
    ~ffmpeg();
    bool initFFmpeg(QString url); //初始化ffmpeg

    AVPacket getPacket(); //读帧，获取一帧
    bool decode(const AVPacket *pkt);     //解码(音频和视频都可以)

    int getPCM(char* out);//后去pcm数据
    void getRBG();//解码后去视频帧数据

    void deleteFFmpeg();//析构  FFmpeg
signals:
    void GetImage(const QImage &image);

private:
    void initBase();   //初始化FFmpeg基础部分
    bool initAudio();  //初始化音频的相关
    bool initVideo();  //初始化视频相关

public:
    int m_videoStreamIndex = -1;
    int m_audioStreamIndex = -1;

private:
    AVFormatContext *m_avFormatContext = nullptr;       //流媒体的上下文

    AVCodecContext *m_videoCodecContext = nullptr;      //视频编解码的上下文
    AVCodecContext *m_audioCodecContext = nullptr;      //音频编解码的上下文

    AVFrame *m_yuvFrame = nullptr;            //解码后的视频帧数据
    AVFrame *m_pcmFrame = nullptr;            //解码后的音频数据

    SwrContext *m_audioSwrContext = nullptr;  //音频重采样上下文
    SwsContext *m_videoSwsContext = nullptr;  //处理像素问题,格式转换 yuv->rbg

    AVPicture  pAVPicture;//转换后的rgb数据

    AVPacket m_packet;  //每一帧数据 原始数据

    int m_sampleRate = 48000;//样本率
    int m_sampleSize = 16;//样本大小
    int m_channel = 2;///通道数

    QMutex m_mutex;

};
#endif // FFMPEG_H
