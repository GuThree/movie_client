#ifndef ENTERROOM_H
#define ENTERROOM_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class EnterRoom;
}

class EnterRoom : public QWidget
{
    Q_OBJECT

public:
    explicit EnterRoom(QTcpSocket *s, QString u, QString n, QWidget *parent = nullptr);
    ~EnterRoom();

private slots:
    void on_enterButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::EnterRoom *ui;
    QTcpSocket *socket;
    QString userName;
    QString nickName;
};

#endif // ENTERROOM_H
