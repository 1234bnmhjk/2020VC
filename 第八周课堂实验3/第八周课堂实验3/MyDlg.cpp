// MyDlg.cpp: 实现文件
//

#include "pch.h"
#include "第八周课堂实验3.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	
	CListBox *list = (CListBox*)GetDlgItem(IDC_LIST1);
	list->AddString(fileName);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
