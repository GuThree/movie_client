#ifndef PRIVATECHAT_H
#define PRIVATECHAT_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QList>
#include <QFileDialog>
#include <QCoreApplication>
#include <QFile>
#include <QCloseEvent>

class Chatlist;
struct ChatWidgetInfo;
#include "chatlist.h"

namespace Ui {
class PrivateChat;
}

class PrivateChat : public QWidget
{
    Q_OBJECT

public:
    explicit PrivateChat(QTcpSocket *s, QString u, QString f, Chatlist *c, QList<ChatWidgetInfo> *l, QWidget *parent = nullptr);
    ~PrivateChat();
    void closeEvent(QCloseEvent *);

private slots:
    void on_sendButton_clicked();
    void show_text_slot(QJsonObject);

private:
    Ui::PrivateChat *ui;
    QTcpSocket *socket;
    QString userName;
    QString friendName;
    Chatlist *mainWidget;
    QList<ChatWidgetInfo> *chatWidgetList;
};

#endif // PRIVATECHAT_H