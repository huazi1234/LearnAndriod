#include "dialog.h"
#include "ui_dialog.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDir>
#include <QSettings>
#include "UdpReceiver.h"
Dialog::Dialog(int iWidth,int iHeight,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    width = iWidth;
    height = iHeight-50;
    //ui->setupUi(this);
    this->setFixedSize(width,height);
    iniUI(); //界面创建与布局
    iniSignalSlots(); //信号与槽的关联
    setWindowTitle("Form created mannually");

    ui->setupUi(this);

    QString path;
    QDir dir;
    path=dir.currentPath();
    QString dlgTitle="information消息框11";
    QString strInfo=path;
   QMessageBox::information(this, dlgTitle, strInfo,
                              QMessageBox::Ok,QMessageBox::NoButton);

   //创建配置文件

   QSettings iniFile(path+"/test.ini", QSettings::IniFormat);
   //参数1，代表新建ini文件的位置的绝对路径；  参数2，将设置存储在ini文件中
   iniFile.setValue("port",10000);



    UdpReceiver ur(this,&iniFile);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::iniUI()
{
    //创建 Underline, Italic, Bold 3 个CheckBox，并水平布局
    chkBoxUnder=new QCheckBox(tr("Underline"));
    chkBoxItalic=new QCheckBox(tr("Italic"));
    chkBoxBold=new QCheckBox(tr("Bold"));
    QHBoxLayout *HLay1=new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);
    //创建 Black, Red, Blue 3 个RadioButton，并水平布局
    rBtnBlack=new QRadioButton(tr("Black"));
    rBtnBlack->setChecked(true);
    rBtnRed=new QRadioButton(tr("Red"));
    rBtnBlue=new QRadioButton(tr("Blue"));
    QHBoxLayout *HLay2=new QHBoxLayout;
    HLay2->addWidget(rBtnBlack);
    HLay2->addWidget(rBtnRed);
    HLay2->addWidget(rBtnBlue);
    //创建确定, 取消, 退出3 个 PushButton, 并水平布局
    btnOK=new QPushButton(tr("确定"));
    btnCancel=new QPushButton(tr("取消"));
    btnClose=new QPushButton(tr("退出"));
    QHBoxLayout *HLay3=new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);
    //创建文本框,并设置初始字体
    txtEdit=new QPlainTextEdit;
    txtEdit->setPlainText("Hello world\n\nIt is my demo");
    QFont font=txtEdit->font(); //获取字体
    font.setPointSize(20);//修改字体大小
    txtEdit->setFont(font);//设置字体


    QHBoxLayout *HLay4=new QHBoxLayout;
    HLay4->addStretch();
    btnTest=new QPushButton(tr("测试"));
    HLay4->addWidget(btnTest);

    QHBoxLayout *HLay5=new QHBoxLayout;
    HLay5->addStretch();
    btnTest2=new QPushButton(tr("测试2"));
    HLay5->addWidget(btnTest2);

    //创建垂直布局，并设置为主布局
    QVBoxLayout *VLay=new QVBoxLayout;
    VLay->addLayout(HLay1); //添加字体类型组
    VLay->addLayout(HLay2);//添加字体颜色组
    VLay->addWidget(txtEdit);//添加PlainTextEdit
    VLay->addLayout(HLay3);//添加按键组

    VLay->addLayout(HLay4);//添加按键组
    VLay->addLayout(HLay5);//添加按键组
    setLayout(VLay); //设置为窗体的主布局
}

void Dialog::iniSignalSlots()
{
    //三个颜色 QRadioButton 的clicked()信号与setTextFontColor()槽函数关联
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    //三个字体设置的 QCheckBox 的clicked(bool)信号与相应的槽函数关联
    connect(chkBoxUnder,SIGNAL(clicked(bool)),
    this,SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),
    this,SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)),
    this,SLOT(on_chkBoxBold(bool)));
    //三个按钮的信号与窗体的槽函数关联
    connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnTest,SIGNAL(clicked()),this,SLOT(on_btnTest()));
    connect(btnTest2,SIGNAL(clicked()),this,SLOT(on_btnTest2()));
}

void Dialog::on_chkBoxUnder(bool checked)
{
    QFont font=txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::on_chkBoxItalic(bool checked)
{
    QFont font=txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::on_chkBoxBold(bool checked)
{
    QFont font=txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}
Ui::Dialog* Dialog::GetUI()
{
    return ui;
}
void Dialog::setTextFontColor()
{
    txtEdit->setStyleSheet("background-color:lightYellow;");
    //文字的颜色设置：
    QPalette p = txtEdit->palette();
    if (rBtnBlack->isChecked())
    {
        p.setColor(QPalette::Text, Qt::black);
    }
    else if (rBtnRed->isChecked())
    {
        p.setColor(QPalette::Text, Qt::red);
    }
    else if (rBtnBlue->isChecked())
    {
        p.setColor(QPalette::Text, Qt::blue);
    }
    //p.setColor(QPalette::Inactive, QPalette::Base, Qt::red);
    txtEdit->setPalette(p);
}

void Dialog::on_btnTest()
{
    QString dlgTitle="information消息框";
    QString strInfo="文件已经打开，字体大小已设置";
   QMessageBox::information(this, dlgTitle, strInfo,
                              QMessageBox::Ok,QMessageBox::NoButton);
}

void Dialog::on_btnTest2()
{
    txtEdit->setStyleSheet("background-color:red;");

    QUdpSocket qus;
   //  qus.bind(QHostAddress("127.0.0.1"), PORT+1);
       QByteArray msg = "Hello world!";
       //std::cout << "--- Sender ---" << std::endl;
       for(int i=0; i<100; ++i)
           qus.writeDatagram(msg, QHostAddress("192.168.101.4"), 2000);

}

