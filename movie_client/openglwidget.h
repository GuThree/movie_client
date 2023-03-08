#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>

class OpenglWidget :public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenglWidget(QWidget *parent = nullptr);
    ~OpenglWidget();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void showImage(const QImage& image);

private:
    QImage m_image;
};

#endif // OPENGLWIDGET_H
