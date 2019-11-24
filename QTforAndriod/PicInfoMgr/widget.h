#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTreeView>
#include <QTableView>
#include <QHeaderView>  //tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
#include <QLineEdit>
#include <QLabel>
#include "Common.h"
#include <QSettings>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void CreateView();
    void InitSlot();
    void GetData(PST_ITEMDATA pst);
    void addData(PST_ITEMDATA pst);
    void InitGrid();
    void DelData(int nIndex);
    void ModifyData(PST_ITEMDATA pst,int iSel);

    int GetSelRowIndex();
    void GetSelRowData(PST_ITEMDATA pst);
    void MessageBox(QString str);
    void InitData();
    void SaveData();
    void ShowDataToList();
    void addDataToList(PST_ITEMDATA pst);
    bool IsIndexValid(int nIndex);
    void DelAllRows();
public slots:
    void OnBtnClick_Add();
    void OnBtnClick_Del();
    void OnBtnClick_Modify();
    void OnBtnClick_Save();
    void onTableClicked(const QModelIndex &index);
private:
    QPushButton *AddBtn;
    QPushButton *DelBtn;
    QPushButton *SaveBtn;
    QPushButton *ModifyBtn;
    QVBoxLayout *mainLayout;
    //    QTreeView *treeView;
    QStandardItemModel *standItemModel;
    QTableView *tableView;

    QLabel* labelName;
    QLabel* labelAddress;

    QLineEdit* editName;
    QLineEdit* editAddress;

    QString m_strName;
    QString m_strAdd;

    QVector<ST_ITEMDATA>  m_arrItems;
    QSettings* m_setting;
};
#endif // WIDGET_H
