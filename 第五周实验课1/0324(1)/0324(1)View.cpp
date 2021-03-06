﻿
// 0324(1)View.cpp: CMy03241View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0324(1).h"
#endif

#include "0324(1)Doc.h"
#include "0324(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03241View

IMPLEMENT_DYNCREATE(CMy03241View, CView)

BEGIN_MESSAGE_MAP(CMy03241View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowName, &CMy03241View::OnShowname)
END_MESSAGE_MAP()

// CMy03241View 构造/析构

CMy03241View::CMy03241View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03241View::~CMy03241View()
{
}

BOOL CMy03241View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03241View 绘图

void CMy03241View::OnDraw(CDC* /*pDC*/)
{
	CMy03241Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03241View 打印

BOOL CMy03241View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03241View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03241View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03241View 诊断

#ifdef _DEBUG
void CMy03241View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03241View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03241Doc* CMy03241View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03241Doc)));
	return (CMy03241Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03241View 消息处理程序


void CMy03241View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString name;
	name.Format(_T("郭韵萧"));

	CClientDC dc(this);
	dc.TextOutW(10, 10, name);
}
