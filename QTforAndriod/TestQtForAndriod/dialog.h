#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(int iWidth,int iHeight,QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int width;
    int height;

public:
    QCheckBox   *chkBoxUnder;
    QCheckBox   *chkBoxItalic;
    QCheckBox   *chkBoxBold;
    QRadioButton    *rBtnBlack;
    QRadioButton    *rBtnRed;
    QRadioButton    *rBtnBlue;
    QPlainTextEdit  *txtEdit;
    QPushButton     *btnOK;
    QPushButton     *btnCancel;
    QPushButton     *btnClose;
    QPushButton     *btnTest;
    QPushButton     *btnTest2;
    void    iniUI();//UI 创建与初始化
    void    iniSignalSlots();//初始化信号与槽的链接
private slots:
    void on_chkBoxUnder(bool checked); //Underline 的clicked(bool)信号的槽函数
    void on_chkBoxItalic(bool checked);//Italic 的clicked(bool)信号的槽函数
    void on_chkBoxBold(bool checked); //Bold 的clicked(bool)信号的槽函数
    void setTextFontColor(); //设置字体颜色
    void on_btnTest();
    void on_btnTest2();
 public:
    Ui::Dialog* GetUI();
};
#endif // DIALOG_H
