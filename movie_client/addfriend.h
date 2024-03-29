#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class Addfriend;
}

class Addfriend : public QWidget
{
    Q_OBJECT

public:
    explicit Addfriend(QTcpSocket *s, QString u, QWidget *parent = nullptr);
    ~Addfriend();

private slots:
    void on_cancelButton_clicked();
    void on_addfriendButton_clicked();

private:
    Ui::Addfriend *ui;
    QTcpSocket *socket;
    QString userName;
};

#endif // ADDFRIEND_H
