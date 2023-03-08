#include "ffmpeg.h"
#include <QDebug>
#include <QImage>
#include "audioplayer.h"

ffmpeg::ffmpeg()
{

}

ffmpeg::~ffmpeg()
{
    avformat_free_context(m_avFormatContext);
}

void ffmpeg::initBase()
{
    avcodec_register_all();//注册所有解码器
    av_register_all();//注册所有格式
    avformat_network_init();//初始化网络流格式,使用RTSP网络流时必须先执行

    if(nullptr == m_avFormatContext)
        m_avFormatContext = avformat_alloc_context();

    m_yuvFrame = av_frame_alloc();
    m_pcmFrame = av_frame_alloc();
}

bool ffmpeg::initFFmpeg(QString url)
{
    deleteFFmpeg();

    if(nullptr == m_avFormatContext)
        initBase();

    //打开视频流
    int result=avformat_open_input(&m_avFormatContext, url.toStdString().c_str(),nullptr,nullptr);
    if (result<0)
    {
        qDebug()<<"avformat_open_input error ---"<<result;
        return false;
    }
    //获取视频流信息
    result=avformat_find_stream_info(m_avFormatContext,nullptr);
    if (result<0)
    {
        qDebug()<<"avformat_find_stream_info error ---"<<result;
        return false;
    }



    if(!initAudio())
    {
        qDebug()<<"init audio error";
        return false;
    }

    if(!initVideo())
    {
        qDebug()<<"init Video error";
        return false;
    }

    return true;
}

bool ffmpeg::initAudio()
{
    //获取音频流索引
    for (uint i = 0; i < m_avFormatContext->nb_streams; i++)
    {
        if (AVMEDIA_TYPE_AUDIO == m_avFormatContext->streams[i]->codec->codec_type)
        {
            m_audioCodecContext = m_avFormatContext->streams[i]->codec;
            m_audioStreamIndex = i;
            break;
        }
    }

    if (-1 == m_audioStreamIndex)
    {
        qDebug()<<"audioStreamIndex init error -----";
        return false;
    }

    if(nullptr == m_audioCodecContext)
    {
        qDebug()<<"m_audioCidecContext error---";
        return false;
    }

    //初始化一个视音频编解码器的AVCodecContext
    AVCodec *codec = avcodec_find_decoder(m_audioCodecContext->codec_id);//查找解码器
    if (avcodec_open2(m_audioCodecContext, codec, nullptr) < 0)
    {
        qDebug()<<"avcodec_open2 error---";
        return false;
    }

    m_sampleRate = m_audioCodecContext->sample_rate;//样本率
    m_channel = m_audioCodecContext->channels;//通道数
    switch (m_audioCodecContext->sample_fmt)//样本大小
    {
    case AV_SAMPLE_FMT_S16:
        this->m_sampleSize = 16;
        break;
    case  AV_SAMPLE_FMT_S32:
        this->m_sampleSize = 32;
    default:
        break;
    }

    //初始化音频的设备
    AudioPlayer::Get()->m_sampleRate = m_sampleRate;
    AudioPlayer::Get()->m_channel = m_channel;
    AudioPlayer::Get()->m_sampleSize = m_sampleSize;
    AudioPlayer::Get()->Start();

    if (nullptr == m_audioSwrContext)
    {
        m_audioSwrContext = swr_alloc();//初始化
        swr_alloc_set_opts(m_audioSwrContext,m_audioCodecContext->channel_layout,
                           AV_SAMPLE_FMT_S16,
                           m_audioCodecContext->sample_rate,
                           m_audioCodecContext->channels,
                           m_audioCodecContext->sample_fmt,
                           m_audioCodecContext->sample_rate,
                           0,0
                           );
        swr_init(m_audioSwrContext);
    }

    return true;
}

bool ffmpeg::initVideo()
{
    //获取视频流索引
    for (uint i = 0; i < m_avFormatContext->nb_streams; i++)
    {
        if (AVMEDIA_TYPE_VIDEO == m_avFormatContext->streams[i]->codec->codec_type)
        {
            m_videoStreamIndex = i;
            m_videoCodecContext = m_avFormatContext->streams[i]->codec;
            break;
        }
    }

    if(-1 == m_videoStreamIndex)
    {
        qDebug()<<"videoStreamIndex init error---";
        return false;
    }
    if (m_videoCodecContext == nullptr)
    {
        qDebug()<<"videoCodecContext init error---";
        return false;
    }

    //获取视频流解码器
    AVCodec *pAVCodec = avcodec_find_decoder(m_videoCodecContext->codec_id);
    //打开对应解码器
    int result=avcodec_open2(m_videoCodecContext,pAVCodec,nullptr);
    if (result<0)
    {
        qDebug()<<"avcodec_open2 video open error";
        return false;
    }

    m_videoSwsContext = sws_getContext(m_videoCodecContext->width,m_videoCodecContext->height,
                                       m_videoCodecContext->pix_fmt,
                                       m_videoCodecContext->width,m_videoCodecContext->height,
                                       AV_PIX_FMT_BGRA,SWS_BICUBIC,0,0,0);

    avpicture_alloc(&pAVPicture,AV_PIX_FMT_BGRA,m_videoCodecContext->width,m_videoCodecContext->height);


    return true;
}

AVPacket ffmpeg::getPacket()
{
    AVPacket pkt;
    memset(&pkt, 0, sizeof(AVPacket));

    if (!m_avFormatContext)
    {
        return pkt;
    }
    int err = av_read_frame(m_avFormatContext, &pkt);//读取视频帧
    if (err != 0)//读取失败
    {
        char errorbuff[1024];//错误信息
        av_strerror(err, errorbuff, sizeof(errorbuff));
    }
    return pkt;
}

bool ffmpeg::decode(const AVPacket *pkt)
{
    m_mutex.lock();
    if (!m_avFormatContext)
    {
        m_mutex.unlock();
        return false;
    }

    AVFrame *frame;
    if (pkt->stream_index == m_audioStreamIndex)
    {
        frame = m_pcmFrame;//此时frame是解码后的音频流
    }
    else
    {
        frame = m_yuvFrame;
    }
    int re = avcodec_send_packet(m_avFormatContext->streams[pkt->stream_index]->codec, pkt);//发送之前读取的pkt
    if (re != 0)
    {
        m_mutex.unlock();
        qDebug()<<"avcodec_send_packet error---"<<re;
        return NULL;
    }
    re = avcodec_receive_frame(m_avFormatContext->streams[pkt->stream_index]->codec, frame);//解码pkt后存入yuv中
    if (re != 0)
    {
        m_mutex.unlock();
        qDebug()<<"avcodec_receive_frame error---"<<re;
        return NULL;
    }
    m_mutex.unlock();
    return true;
}

int ffmpeg::getPCM(char *out)
{
    m_mutex.lock();
    uint8_t  *data[1];
    data[0] = (uint8_t *)out;
    int len = swr_convert(m_audioSwrContext, data, 10000,
                          (const uint8_t **)m_pcmFrame->data,
                          m_pcmFrame->nb_samples
                          );
    if (len <= 0)
    {
        m_mutex.unlock();
        return 0;
    }
    int outsize = av_samples_get_buffer_size(nullptr, m_audioCodecContext->channels,
                                             m_pcmFrame->nb_samples,
                                             AV_SAMPLE_FMT_S16,
                                             0);
    m_mutex.unlock();
    return outsize;
}

void ffmpeg::getRBG()
{
    m_mutex.lock();
    int result = sws_scale(m_videoSwsContext,m_yuvFrame->data,m_yuvFrame->linesize,
                           0,m_videoCodecContext->height,pAVPicture.data,pAVPicture.linesize);

    if (result<0)
    {
        m_mutex.unlock();
        return;
    }

    //发送获取一帧图像信号
    QImage image(pAVPicture.data[0],m_videoCodecContext->width,m_videoCodecContext->height,QImage::Format_ARGB32);
    emit GetImage(image);

    m_mutex.unlock();
}

void ffmpeg::deleteFFmpeg()
{
    m_mutex.lock();

    avformat_close_input(&m_avFormatContext);
    av_free(m_yuvFrame);
    av_free(m_pcmFrame);

    if (m_videoSwsContext)
    {
        sws_freeContext(m_videoSwsContext);
        m_videoSwsContext = nullptr;
    }
    if (m_audioSwrContext)
    {
        swr_free(&m_audioSwrContext);
    }

    m_mutex.unlock();
}
