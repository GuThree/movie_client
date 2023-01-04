#ifndef ROOM_H
#define ROOM_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QList>
#include <QCloseEvent>

class Chatlist;
struct RoomWidgetInfo;
#include "chatlist.h"

namespace Ui {
class Room;
}

class Room : public QWidget
{
    Q_OBJECT

public:
    explicit Room(QTcpSocket *s, QString r, QString u, Chatlist *c, QList<RoomWidgetInfo> *l, QWidget *parent = nullptr);
    ~Room();
    void closeEvent(QCloseEvent *);

private slots:
    void show_room_member(QJsonObject);
    void show_room_text(QJsonObject);
    void on_sendButton_clicked();

    void on_leaveButton_clicked();

private:
    Ui::Room *ui;
    QTcpSocket *socket;
    QString userName;
    QString roomid;
    Chatlist *mainWidget;
    QList<RoomWidgetInfo> *roomWidgetList;
};

#endif // ROOM_H
