#include "room.h"
#include "ui_room.h"

Room::Room(QTcpSocket *s, QString r, QString u, QString n, Chatlist *c, QHash<QString, QString> f,
           QList<RoomWidgetInfo> *l, bool o, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Room)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/pic/icon.png"));
    is_owner = o;
    socket = s;
    roomid = r;
    userName = u;
    nickName = n;
    friendlist = f;
    mainWidget = c;
    roomWidgetList = l;
    is_kickClicked = false;

    if(!is_owner)
    {
        ui->kickButton->hide();
        ui->videoButton->hide();
    }

    QJsonObject obj;
    obj.insert("cmd", "get_room_member");
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    connect(mainWidget, &Chatlist::signal_to_sub_widget_member, this, &Room::show_room_member);
    connect(mainWidget, &Chatlist::signal_to_sub_widget_member_id, this, &Room::deal_with_memberid);
    connect(mainWidget, &Chatlist::signal_to_sub_widget_room, this, &Room::show_room_text);

    if(nullptr == m_videoThread)
    {
        m_videoThread = new VideoThread;
        connect(m_videoThread, SIGNAL(emitImage(const QImage&)), ui->openglWidget, SLOT(showImage(const QImage&)));
    }

    PullThread *pullthread = new PullThread(this, roomid);
    pullthread->start();
}

Room::~Room()
{
    delete ui;
}

// 发送群聊消息
void Room::on_sendButton_clicked()
{
    QString text = ui->lineEdit->text();
    if (text == "")
        return;

    QJsonObject obj;
    obj.insert("cmd", "room_chat");
    obj.insert("username", userName);
    obj.insert("nickname", nickName);
    obj.insert("roomid", roomid);
    obj.insert("text", text);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    ui->lineEdit->clear();
    ui->textBrowser->append(nickName+":"+text);
    ui->textBrowser->append("\n");
}

// 展示房间成员
void Room::show_room_member(QJsonObject obj)
{
    if (obj.value("cmd").toString() == "get_room_member_reply")
    {
        if (obj.value("roomid").toString() == roomid)
        {
            ui->listWidget->clear();
            memberListNick = obj.value("member").toString().split("|");
            for (int i = 0; i < memberListNick.size(); i++)
            {
                ui->listWidget->addItem(memberListNick.at(i));
            }
        }
    }

    QJsonObject obj1;
    obj1.insert("cmd", "get_room_member_id");
    obj1.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj1).toJson();
    socket->write(ba);
}

// 显示房间成员发送的消息
void Room::show_room_text(QJsonObject obj)
{
    if (obj.value("cmd").toString() == "room_chat")
    {
        if (obj.value("roomid").toString() == roomid)
        {
            if (this->isMinimized())
            {
                this->showNormal();
            }
            this->activateWindow();
            ui->textBrowser->append(obj.value("nickname").toString()+":"+obj.value("text").toString());
            ui->textBrowser->append("\n");
        }
    }
}

// 服务器给成员ID时进行处理
void Room::deal_with_memberid(QJsonObject obj)
{
    if (obj.value("cmd").toString() == "get_room_member_id_reply")
    {
        if (obj.value("roomid").toString() == roomid)
        {
            memberListId = obj.value("memberid").toString().split("|");
        }
    }

    if (is_kickClicked)
    {
        Kick *kick = new Kick(socket, roomid, memberListId, memberListNick);
        kick->setWindowTitle("踢出成员");
        kick->show();

        is_kickClicked = false;
    }
}

// 点击退出房间
void Room::on_leaveButton_clicked()
{
    QJsonObject obj;
    obj.insert("cmd", "leave_room");
    obj.insert("username", userName);
    obj.insert("nickname", nickName);
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    this->close();
}

// 点击邀请好友
void Room::on_inviteButton_clicked()
{
    Invite *invite = new Invite(socket, roomid, userName, nickName, friendlist);
    invite->setWindowTitle("邀请好友");
    invite->show();
}

// 重置好友列表
void Room::reset_friends(QHash<QString, QString> f)
{
    friendlist = f;
}

// 关闭对话框
void Room::closeEvent(QCloseEvent * event)
{
    if(m_videoThread->isRunning())
    {
        m_videoThread->stopThread();
    }
    m_videoThread->m_ffmpeg->deleteFFmpeg();

    QJsonObject obj;
    obj.insert("cmd", "leave_room");
    obj.insert("username", userName);
    obj.insert("nickname", nickName);
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    for (int i = 0; i < roomWidgetList->size(); i++)
    {
        if (roomWidgetList->at(i).name == roomid)
        {
            roomWidgetList->removeAt(i);
            break;
        }
    }
    event->accept();
}

// 选择视频按钮被点击
void Room::on_videoButton_clicked()
{
    QString name = QFileDialog::getOpenFileName(this, "选择视频", "C:", tr("MP4(*mp4)"));
    PushThread *pushthread = new PushThread(name, "rtmp://192.168.211.153/live/livestream/"+roomid);
    pushthread->start();
}

// 踢出成员按钮被点击
void Room::on_kickButton_clicked()
{
    QJsonObject obj;
    obj.insert("cmd", "get_room_member");
    obj.insert("roomid", roomid);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);

    is_kickClicked = true;
}
