#ifndef ROOM_H
#define ROOM_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QList>
#include <QCloseEvent>
#include <QHash>
#include <QFile>
#include <QCoreApplication>
#include "invite.h"
#include "pushthread.h"
#include "kick.h"
#include "videothread.h"

class Chatlist;
struct RoomWidgetInfo;
#include "chatlist.h"

class PullThread;
#include "pullthread.h"

namespace Ui {
class Room;
}

class Room : public QWidget
{
    Q_OBJECT

public:
    explicit Room(QTcpSocket *s, QString r, QString u, QString n, Chatlist *c, QHash<QString, QString> f,
                  QList<RoomWidgetInfo> *l, bool o = false, QWidget *parent = nullptr);
    ~Room();
    void reset_friends(QHash<QString, QString>);
    void closeEvent(QCloseEvent *);

private slots:
    void show_room_member(QJsonObject);
    void show_room_text(QJsonObject);
    void deal_with_memberid(QJsonObject);
    void on_sendButton_clicked();
    void on_leaveButton_clicked();
    void on_inviteButton_clicked();
    void on_videoButton_clicked();

    void on_kickButton_clicked();

private:
    Ui::Room *ui;
    bool is_owner;
    bool is_kickClicked;
    QTcpSocket *socket;
    QString userName;
    QString nickName;
    QString roomid;
    QHash<QString, QString> friendlist;
    Chatlist *mainWidget;
    QList<RoomWidgetInfo> *roomWidgetList;
    QStringList memberListId;
    QStringList memberListNick;

public:
    VideoThread* m_videoThread =  nullptr;
};

#endif // ROOM_H
