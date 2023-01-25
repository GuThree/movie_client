#ifndef INVITE_H
#define INVITE_H

#include <QWidget>
#include <QTcpSocket>
#include <QCheckBox>
#include <QListWidgetItem>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class Invite;
}

class Invite : public QWidget
{
    Q_OBJECT

public:
    explicit Invite(QTcpSocket *s, QString r, QString u, QString n, QHash<QString, QString> f, QWidget *parent = nullptr);
    ~Invite();

private slots:
    void on_inviteButton_clicked();

private:
    Ui::Invite *ui;
    QTcpSocket *socket;
    QString username;
    QString nickname;
    QString roomid;
    QHash<QString, QString> friendlist;
    QHash<int, QString> idlist;
};

#endif // INVITE_H
