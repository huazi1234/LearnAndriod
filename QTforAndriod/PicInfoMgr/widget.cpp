#include "widget.h"
#include <QMessageBox>
#include <QDir>
#include<QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    CreateView();
    InitSlot();

    InitData();
    //InitList();
    ShowDataToList();
    qDebug("debug start");
}

Widget::~Widget()
{

}
void Widget::InitGrid()
{
    //添加QTableView代码
    tableView = new QTableView;
    standItemModel = new QStandardItemModel();
    //添加表头
    standItemModel->setColumnCount(3);
    standItemModel->setHeaderData(0,Qt::Horizontal,/*QString::fromUtf8*/("序号"));   //设置表头内容
    standItemModel->setHeaderData(1,Qt::Horizontal,/*QString::fromUtf8*/("名称"));
    standItemModel->setHeaderData(2,Qt::Horizontal,/*QString::fromUtf8*/("地址"));
    //向表格添加100行内容
//    for(int i=0;i<100;i++)
//    {
//        QStandardItem *standItem1 = new QStandardItem(QString::fromUtf8("%1").arg(i+1));
//        QStandardItem *standItem2 = new QStandardItem(QString::fromUtf8("di%1hang").arg(i+1));
//        QStandardItem *standItem3 = new QStandardItem(QString::fromUtf8("xx"));

//        standItemModel->setItem(i,0,standItem1);                                //表格第i行，第0列添加一项内容
//        standItemModel->item(i,0)->setForeground(QBrush(QColor(255,0,0)));      //设置字符颜色
//        standItemModel->item(i,0)->setTextAlignment(Qt::AlignCenter);           //设置表格内容居中
//        standItemModel->setItem(i,1,standItem2);                                //表格第i行，第1列添加一项内容
//        standItemModel->setItem(i,2,standItem3);
//    }
    tableView->setModel(standItemModel);    //挂载表格模型
    //设置表格属性
    tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);        //表头信息显示居中
    tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);  //设定表头列宽不可变
    tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
    tableView->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);//设定第2列表头弹性拉伸
    tableView->setColumnWidth(0,100);       //设定表格第0列宽度
    tableView->setColumnWidth(1,200);
    tableView->setColumnWidth(2,200);
    tableView->verticalHeader()->hide();    //隐藏默认显示的行头
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选中时整行选中
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);  //设置表格属性只读，不能编辑
//    tableView->setContextMenuPolicy(Qt::CustomContextMenu);         //需要在表格使用右键菜单，需要启动该属性
//    tableView->sortByColumn(0,Qt::AscendingOrder);                 //表格第0列，按降序排列
//    standItemModel->removeRows(0,10);
}
void Widget::CreateView()
{

    InitGrid();
    mainLayout = new QVBoxLayout;       //垂直布局
    mainLayout->setSpacing(10);         //设置控件间距
    mainLayout->setMargin(10);          //设置边缘间距
    AddBtn = new QPushButton("add");
    DelBtn = new QPushButton("delete");
    SaveBtn = new QPushButton("Save");
    ModifyBtn = new QPushButton("Modify");

    labelName = new QLabel("Name");
    labelAddress = new QLabel("Address");

    editName = new QLineEdit("Test");
    editAddress = new QLineEdit("Test2");

    //删除从第0行开始的连续10行
    QHBoxLayout* HLayout1 = new QHBoxLayout;
    HLayout1->addWidget(labelName);
    HLayout1->addWidget(editName);

    QHBoxLayout* HLayout2 = new QHBoxLayout;
    HLayout2->addWidget(labelAddress);
    HLayout2->addWidget(editAddress);

    QHBoxLayout* HLayout3 = new QHBoxLayout;
    HLayout3->addWidget(AddBtn);
    HLayout3->addWidget(DelBtn);
    HLayout3->addWidget(SaveBtn);
    HLayout3->addWidget(ModifyBtn);

    mainLayout->addLayout(HLayout1);
    mainLayout->addLayout(HLayout2);
    mainLayout->addLayout(HLayout3);




    mainLayout->addWidget(tableView);    //添加控件
    this->setLayout(mainLayout);        //显示垂直布局

    //addData(QString("Lucy" ),QString("BJ"));
}

void Widget::InitData()
{
    //加载数据到结构中
    //创建配置文件
    QString path;
    QDir dir;
    path=dir.currentPath();
    m_setting =new QSettings(path+"/test.ini", QSettings::IniFormat);
    //参数1，代表新建ini文件的位置的绝对路径；  参数2，将设置存储在ini文件中
    //MessageBox(m_setting->fileName());
    m_setting->beginGroup("ItemNum");
    int num = m_setting->value("num").toInt();
    //MessageBox(QString("num:%02").arg(num));
    m_setting->endGroup();
    m_arrItems.clear();
    for(int i= 0;i < num;i++)
    {
        m_setting->beginGroup(QString("Item%02").arg(i));
        QString strName = m_setting->value("name").toString();
        QString strAddress = m_setting->value("address").toString();
        m_setting->endGroup();

        ST_ITEMDATA st;
        st.strName = strName;
        st.strAddress = strAddress;
        m_arrItems.append(st);
        //addData(&st);
    }
    ShowDataToList();

}
void Widget::SaveData()
{
    int num = m_arrItems.count();
    m_setting->beginGroup("ItemNum");
    m_setting->setValue("num",num);
    m_setting->endGroup();
    for(int i=0;i<num;i++)
    {
        m_setting->beginGroup(QString("Item%02").arg(i));
        m_setting->setValue("name",m_arrItems.at(i).strName);
        m_setting->setValue("address",m_arrItems.at(i).strAddress);
        m_setting->endGroup();
    }
}
void Widget::InitSlot()
{
    connect(AddBtn,SIGNAL(clicked()),this,SLOT(OnBtnClick_Add()));
    connect(DelBtn,SIGNAL(clicked()),this,SLOT(OnBtnClick_Del()));
    connect(SaveBtn,SIGNAL(clicked()),this,SLOT(OnBtnClick_Save()));
    connect(ModifyBtn,SIGNAL(clicked()),this,SLOT(OnBtnClick_Modify()));
    connect(tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));

}

void Widget::onTableClicked(const QModelIndex &index)
{
    ST_ITEMDATA st;
    GetSelRowData(&st);

    editName->setText(st.strName);
    editAddress->setText(st.strAddress);

}
int Widget::GetSelRowIndex()
{
//   QModelIndexList list = tableView->selectedIndexes();
//   if (list.count() <= 0) return;

   QModelIndex index = tableView->selectionModel()->currentIndex();
   int iSel = index.row();
   return iSel;

}
void Widget::OnBtnClick_Modify()
{
    ST_ITEMDATA st;
    GetData(&st);
    int iSel = GetSelRowIndex();
    ModifyData(&st,iSel);
    tableView->selectRow(iSel);
}
void Widget::OnBtnClick_Save()
{
    SaveData();
}
void Widget::OnBtnClick_Del()
{
    int iSel = GetSelRowIndex();
    DelData(iSel);
    int nCnt = standItemModel->rowCount();
    if(iSel >= nCnt)
    {
        if(nCnt >= 1)
        {
            tableView->selectRow(nCnt-1);
        }
    }
    else
    {
        tableView->selectRow(iSel);
    }

}
void Widget::OnBtnClick_Add()
{
    ST_ITEMDATA st;
    GetData(&st);
    addData(&st);
    ShowDataToList();
}
void Widget::ModifyData(PST_ITEMDATA pst,int iSel)
{
    if(IsIndexValid(iSel))
    {
        m_arrItems.remove(iSel);
        m_arrItems.insert(iSel,*pst);
        ShowDataToList();
    }
    else
    {
        MessageBox("You haven't select any Row");
    }
}
void Widget::GetData(PST_ITEMDATA pst)
{
    pst->strName = editName->text();
    pst->strAddress = editAddress->text();

}
void Widget::DelData(int nIndex)
{
    //standItemModel->removeRow(nIndex);
    if(IsIndexValid(nIndex))
    {
        m_arrItems.removeAt(nIndex);
        ShowDataToList();
    }
    else
    {
        MessageBox("You haven't select any Row");
    }
}
void Widget::addDataToList(PST_ITEMDATA pst)
{
    int n = standItemModel->rowCount();
    QStandardItem *standItem1 = new QStandardItem(QString::fromUtf8("%1").arg(n));
    QStandardItem *standItem2 = new QStandardItem(pst->strName);
    QStandardItem *standItem3 = new QStandardItem(pst->strAddress);

    standItemModel->setItem(n,0,standItem1);                                //表格第i行，第0列添加一项内容
    standItemModel->item(n,0)->setForeground(QBrush(QColor(255,0,0)));      //设置字符颜色
    standItemModel->item(n,0)->setTextAlignment(Qt::AlignCenter);           //设置表格内容居中
    standItemModel->setItem(n,1,standItem2);                                //表格第i行，第1列添加一项内容
    standItemModel->setItem(n,2,standItem3);
}
void Widget::addData(PST_ITEMDATA pst)
{
    //addDataToList(pst);
    m_arrItems.append(*pst);
}
void Widget::GetSelRowData(PST_ITEMDATA pst)
{
    int row= tableView->currentIndex().row();
    QAbstractItemModel *model = tableView->model();
    int columnCount = model->columnCount();
    for(int i =0;i<columnCount;i++)
    {
        QModelIndex index = model->index(row,i);//选中行第一列的内容
        QVariant data = model->data(index);
        if(index.isValid())
        {
            QString cellText = index.data().toString();
            //MessageBox(cellText);
            if(i == 1)
            {
                pst->strName = cellText;
            }
            else if(i ==2)
            {
               pst->strAddress = cellText;
            }
        }
    }
}
void Widget::MessageBox(QString str)
{
    QString dlgTitle="收到数据";
    QString strInfo=str;
    QMessageBox::information(this, dlgTitle, strInfo,
                              QMessageBox::Ok,QMessageBox::NoButton);
}

void Widget::ShowDataToList()
{
    //standItemModel->clear();
    DelAllRows();
    int num = m_arrItems.count();
    for(int i =0;i<num;i++)
    {
        ST_ITEMDATA st = m_arrItems.at(i);
        addDataToList(&st);
    }
}
bool Widget::IsIndexValid(int nIndex)
{
    int nCnt = m_arrItems.count();
    if(nIndex >= nCnt ||nIndex < 0 )
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Widget::DelAllRows()
{
//    int n = standItemModel->rowCount();
//    for(int i = 0;i < n;i++)
//    {
//       standItemModel->removeRow(0);
//    }

    standItemModel->removeRows(0,standItemModel->rowCount());
}


