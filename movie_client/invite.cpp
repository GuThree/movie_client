#include "invite.h"
#include "ui_invite.h"

Invite::Invite(QTcpSocket *s, QString r, QString u, QString n, QHash<QString, QString> f, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Invite)
{
    ui->setupUi(this);
    socket = s;
    username = u;
    nickname = n;
    roomid = r;
    friendlist = f;

    QHash<QString, QString>::const_iterator it = friendlist.constBegin();   
    int i = 0;
    while (it != friendlist.constEnd()) {
        idlist[i] = it.key();
        ++i;
        QListWidgetItem *item = new QListWidgetItem(it.value(), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setCheckState(Qt::Unchecked);
        ++it;
    }
}

// 邀请按钮被点击
void Invite::on_inviteButton_clicked()
{
    QString inviteFriends;
    for (int i = 0; i < ui->listWidget->count(); ++i)
    {
        if (ui->listWidget->item(i)->checkState() == Qt::Checked)
        {
            inviteFriends += idlist[i];
            inviteFriends += "|";
        }
    }

    QJsonObject obj;
    obj.insert("cmd", "invite");
    obj.insert("from_user", nickname);
    obj.insert("roomid", roomid);
    obj.insert("to_fri", inviteFriends);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
    this->close();
}

Invite::~Invite()
{
    delete ui;
}
