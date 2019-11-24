
#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include <QWidget>
#include <QSettings>
class UdpReceiver : public QObject
{
    Q_OBJECT

public:
    UdpReceiver(QWidget *Wnd,QSettings* Setting,QObject *p = nullptr);
    ~UdpReceiver();

public slots:
    void receive();

private:
    QUdpSocket *uSocket;
    QWidget* m_Wnd;
    QSettings* m_Setting;
};

#endif // UDPRECEIVER_H

