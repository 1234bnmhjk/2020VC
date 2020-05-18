﻿
// 第一周课堂实验View.cpp: C第一周课堂实验View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第一周课堂实验.h"
#endif

#include "第一周课堂实验Doc.h"
#include "第一周课堂实验View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第一周课堂实验View

IMPLEMENT_DYNCREATE(C第一周课堂实验View, CView)

BEGIN_MESSAGE_MAP(C第一周课堂实验View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C第一周课堂实验View 构造/析构

C第一周课堂实验View::C第一周课堂实验View() noexcept
{
	// TODO: 在此处添加构造代码

}

C第一周课堂实验View::~C第一周课堂实验View()
{
}

BOOL C第一周课堂实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第一周课堂实验View 绘图

void C第一周课堂实验View::OnDraw(CDC* pDC)
{
	C第一周课堂实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CString str = _T("Hello World!");

	pDC->TextOutW(100, 100, str);
}


// C第一周课堂实验View 打印

BOOL C第一周课堂实验View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第一周课堂实验View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第一周课堂实验View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第一周课堂实验View 诊断

#ifdef _DEBUG
void C第一周课堂实验View::AssertValid() const
{
	CView::AssertValid();
}

void C第一周课堂实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第一周课堂实验Doc* C第一周课堂实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第一周课堂实验Doc)));
	return (C第一周课堂实验Doc*)m_pDocument;
}
#endif //_DEBUG


// C第一周课堂实验View 消息处理程序
