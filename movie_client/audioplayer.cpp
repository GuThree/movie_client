#include "audioplayer.h"
#include <QAudioOutput>
#include <QMutex>

AudioPlayer* AudioPlayer::s_audioPlayer = nullptr;

AudioPlayer * AudioPlayer::Get()
{
    if(nullptr == s_audioPlayer)
    {
        s_audioPlayer = new AudioPlayer;
    }
    return s_audioPlayer;
}

AudioPlayer::AudioPlayer()
{
}

AudioPlayer::~AudioPlayer()
{

}

void AudioPlayer::Stop()
{
    m_mutex.lock();
    if (m_output)
    {
        m_output->stop();
        delete m_output;
        m_output = nullptr;
        m_deviceIo = nullptr;
    }
    m_mutex.unlock();
}

bool AudioPlayer::Start()
{
    Stop();
    m_mutex.lock();
    QAudioFormat fmt;
    fmt.setSampleRate(m_sampleRate);
    fmt.setSampleSize(m_sampleSize);
    fmt.setChannelCount(m_channel);
    fmt.setCodec("audio/pcm");
    fmt.setByteOrder(QAudioFormat::LittleEndian);
    fmt.setSampleType(QAudioFormat::UnSignedInt);
    m_output = new QAudioOutput(fmt);
    m_deviceIo = m_output->start();
    m_mutex.unlock();
    return true;
}

void AudioPlayer::Play(bool isplay)
{
    m_mutex.lock();
    if (!m_output)
    {
        m_mutex.unlock();
        return;
    }

    if (isplay)
    {
        m_output->resume();//恢复播放
    }
    else
    {
        m_output->suspend();//暂停播放
    }
    m_mutex.unlock();
}


int AudioPlayer::GetFree()
{
    m_mutex.lock();
    if (!m_output)
    {
        m_mutex.unlock();
        return 0;
    }
    int free = m_output->bytesFree();//剩余的空间

    m_mutex.unlock();

    return free;
}

bool AudioPlayer::Write(const char *data, int datasize)
{
    m_mutex.lock();
    if (m_deviceIo)
       m_deviceIo->write(data, datasize);//将获取的音频写入到缓冲区中
    m_mutex.unlock();
    return true;
}
