// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "0420_2(2).h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlg::IDD, pParent)
	, number1(0)
	, number2(0)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, number1);
	DDX_Text(pDX, IDC_EDIT2, number2);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg 消息处理程序
