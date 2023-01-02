#ifndef CREATEROOM_H
#define CREATEROOM_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class CreateRoom;
}

class CreateRoom : public QWidget
{
    Q_OBJECT

public:
    explicit CreateRoom(QTcpSocket *s, QString u, QWidget *parent = nullptr);
    ~CreateRoom();

private slots:
    void on_cancelButton_clicked();
    void on_createButton_clicked();

private:
    Ui::CreateRoom *ui;
    QString userName;
    QTcpSocket *socket;
};

#endif // CREATEROOM_H
