#include "kick.h"
#include "ui_kick.h"

Kick::Kick(QTcpSocket *s, QString r, QStringList mid, QStringList mni, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Kick)
{
    ui->setupUi(this);
    socket = s;
    roomid = r;
    memberlistid = mid;
    memberlistnick = mni;
    int j = 0;
    for (int i = 1; i < memberlistnick.size(); i++, j++)
    {
        idlist[j] = memberlistid.at(i);
        QListWidgetItem *item = new QListWidgetItem(memberlistnick.at(i), ui->listWidget);
        ui->listWidget->addItem(item);
        item->setCheckState(Qt::Unchecked);
    }
}

Kick::~Kick()
{
    delete ui;
}

void Kick::on_kickButton_clicked()
{
    QString kickMembers;
    for (int i = 0; i < ui->listWidget->count(); ++i)
    {
        if (ui->listWidget->item(i)->checkState() == Qt::Checked)
        {
            kickMembers += idlist[i];
            kickMembers += "|";
        }
    }

    QJsonObject obj;
    obj.insert("cmd", "kick");
    obj.insert("roomid", roomid);
    obj.insert("to_mem", kickMembers);
    QByteArray ba = QJsonDocument(obj).toJson();
    socket->write(ba);
    this->close();
}
