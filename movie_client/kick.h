#ifndef KICK_H
#define KICK_H

#include <QWidget>
#include <QTcpSocket>
#include <QCheckBox>
#include <QListWidgetItem>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class Kick;
}

class Kick : public QWidget
{
    Q_OBJECT

public:
    explicit Kick(QTcpSocket *s, QString r, QStringList mid, QStringList mni, QWidget *parent = nullptr);
    ~Kick();

private slots:
    void on_kickButton_clicked();

private:
    Ui::Kick *ui;
    QTcpSocket *socket;
    QString roomid;
    QStringList memberlistid;
    QStringList memberlistnick;
    QHash<int, QString> idlist;
};

#endif // KICK_H
