
// 0420_2(1)View.cpp : CMy0420_21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0420_2(1).h"
#endif

#include "0420_2(1)Doc.h"
#include "0420_2(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0420_21View

IMPLEMENT_DYNCREATE(CMy0420_21View, CView)

BEGIN_MESSAGE_MAP(CMy0420_21View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy0420_21View 构造/析构

CMy0420_21View::CMy0420_21View()
{
	// TODO:  在此处添加构造代码
	set = false;
	
}

CMy0420_21View::~CMy0420_21View()
{
}

BOOL CMy0420_21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0420_21View 绘制

void CMy0420_21View::OnDraw(CDC* /*pDC*/)
{
	CMy0420_21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy0420_21View 打印

BOOL CMy0420_21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0420_21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy0420_21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy0420_21View 诊断

#ifdef _DEBUG
void CMy0420_21View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0420_21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0420_21Doc* CMy0420_21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0420_21Doc)));
	return (CMy0420_21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0420_21View 消息处理程序


void CMy0420_21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	startPoint = point;
	endPoint = point;
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0420_21View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMy0420_21View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (set){
		CClientDC dc(this);
		int oldMode = dc.SetROP2(R2_NOTXORPEN);
		dc.Ellipse(&CRect(startPoint, endPoint));
		dc.Ellipse(&CRect(startPoint, point));
		endPoint = point;
		dc.SetROP2(oldMode);
	}
	CView::OnMouseMove(nFlags, point);
}
