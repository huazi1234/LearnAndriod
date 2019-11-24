
#include <QByteArray>
#include <iostream>
#include "UdpReceiver.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include "dialog.h"
//const quint16 PORT = 10333;

UdpReceiver::UdpReceiver(QWidget *Wnd,QSettings* Setting,QObject *p) :
    QObject(p),m_Setting(Setting)
{
    uSocket = new QUdpSocket;
    connect(uSocket, SIGNAL(readyRead()), this, SLOT(receive()));
    uint port =m_Setting->value("port").toUInt();
    m_Wnd = Wnd;
    bool ret = false;
    ret = uSocket->bind(QHostAddress::Any, (quint16)port);

     //ret = uSocket->bind(QHostAddress("192.168.8.109"), PORT);
    //uSocket->bind(PORT);
    if(ret)
    {
        ((Dialog*)m_Wnd)->txtEdit->setStyleSheet("background-color:red;");
        //((Dialog*)m_Wnd)->txtEdit->setPlainText(QVariant(ret).toString());

        quint16 localport = uSocket->localPort();
        QHostAddress ad =   uSocket->localAddress();
        QString strTmp = QVariant(localport).toString();
        strTmp+= tr("\n");
        strTmp+= ad.toString();
        ((Dialog*)m_Wnd)->txtEdit->setPlainText(strTmp);
    }
    else
    {
        ((Dialog*)m_Wnd)->txtEdit->setStyleSheet("background-color:green;");
        ((Dialog*)m_Wnd)->txtEdit->setPlainText(QVariant(ret).toString());
    }
    //uSocket->listen();


}

UdpReceiver::~UdpReceiver()
{
    delete uSocket;
}

void UdpReceiver::receive()
{

    QString dlgTitle="收到数据";
    QString strInfo="receive";
    QMessageBox::information(m_Wnd, dlgTitle, strInfo,
                              QMessageBox::Ok,QMessageBox::NoButton);


    QByteArray ba;
    while(uSocket->hasPendingDatagrams())
    {
        ba.resize(uSocket->pendingDatagramSize());
        uSocket->readDatagram(ba.data(), ba.size());
        //std::cout << ba.data() << std::endl;
        ((Dialog*)m_Wnd)->txtEdit->setStyleSheet("background-color:blue;");
        QByteArray msg = "Hello world!";
        uSocket->writeDatagram(msg, QHostAddress("192.168.8.108"), 2000);

        ((Dialog*)m_Wnd)->txtEdit->setPlainText(QVariant(ba).toString());

        QString dlgTitle="收到数据";
        QString strInfo="";
        strInfo = ba.data();
        QMessageBox::information(m_Wnd, dlgTitle, strInfo,
                                  QMessageBox::Ok,QMessageBox::NoButton);
    }
}


