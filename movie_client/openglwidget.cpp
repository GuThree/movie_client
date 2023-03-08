#include "openglwidget.h"

#include <QPainter>

OpenglWidget::OpenglWidget(QWidget *parent) :QOpenGLWidget(parent)
{

}

OpenglWidget::~OpenglWidget()
{
}

void OpenglWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    painter.begin(this);//清理屏幕
    painter.drawImage(QPoint(0, 0), m_image);//绘制FFMpeg解码后的视频
    painter.end();//
}

void OpenglWidget::showImage(const QImage &image)
{
    if(image.width() > image.height())
        m_image = image.scaledToWidth(width(),Qt::SmoothTransformation);
    else
        m_image = image.scaledToHeight(height(),Qt::SmoothTransformation);

    update();
}
