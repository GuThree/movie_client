#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QAudioOutput>
#include <QMutex>


class AudioPlayer
{
public:
    static AudioPlayer *Get();//单例模式
    static AudioPlayer *s_audioPlayer;
    ~AudioPlayer();

    bool Start();                              //开始
    void Play(bool isplay);                    //是否播放
    bool Write(const char *data,int datasize); //将音频写入
    void Stop();                               //停止
    int GetFree();                             //获取剩余空间

private:
    AudioPlayer();

public:
    int m_sampleRate = 48000;//样本率
    int m_sampleSize = 16;//样本大小
    int m_channel = 2;///通道数

private:
    QAudioOutput *m_output = nullptr;
    QIODevice *m_deviceIo = nullptr;
    QMutex m_mutex;
};


#endif // AUDIOPLAYER_H
