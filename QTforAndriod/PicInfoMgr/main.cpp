#include "widget.h"

#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(960,640);
    //w.setWindowTitle(QString::fromUtf8("图片信息设置"));

    //QTextCodec *codec = QTextCodec::codecForName("UTF8");
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    w.setWindowTitle(/*codec->toUnicode*/("图片信息设置"));
    w.show();
    return a.exec();
}
