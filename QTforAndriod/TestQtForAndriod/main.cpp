#include "dialog.h"

#include <QApplication>
#include <QScreen>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QScreen *iScreen = a.primaryScreen();
    QSize rScreenSize = iScreen->size();
    int iWidth,iHeight;
    iWidth = rScreenSize.width();
    iHeight = rScreenSize.height();
    Dialog w(iWidth,iHeight);
    w.show();
    return a.exec();
}
