
// 0420_2(4)View.cpp: CMy042024View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0420_2(4).h"
#endif

#include "0420_2(4)Doc.h"
#include "0420_2(4)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy042024View

IMPLEMENT_DYNCREATE(CMy042024View, CView)

BEGIN_MESSAGE_MAP(CMy042024View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_ADDCOLOR, &CMy042024View::OnAddcolor)
END_MESSAGE_MAP()

// CMy042024View 构造/析构

CMy042024View::CMy042024View() noexcept
{
	// TODO: 在此处添加构造代码
	rect.left = 100;
	rect.top = 100;
	rect.right = 500;
	rect.bottom = 300;

	set = false;
	//CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	
}

CMy042024View::~CMy042024View()
{
}

BOOL CMy042024View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy042024View 绘图

void CMy042024View::OnDraw(CDC* pDC)
{
	CMy042024Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen pen;
	if (set) {
		pen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
	}
	else {
		pen.CreatePen(PS_NULL, 1, RGB(255, 0, 0));
	}

	CPen* oldpen = pDC->SelectObject(&pen);
	pDC->Rectangle(rect);
	pen.DeleteObject();

	if (!set) {
		pDC->SelectStockObject(NULL_BRUSH);
	}
	else{
		CBrush* oldbrush = pDC->SelectObject(&brush);
	}
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	oldpen = pDC->SelectObject(&pen);
	pDC->Ellipse(rect);
	
}


// CMy042024View 打印

BOOL CMy042024View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy042024View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy042024View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy042024View 诊断

#ifdef _DEBUG
void CMy042024View::AssertValid() const
{
	CView::AssertValid();
}

void CMy042024View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy042024Doc* CMy042024View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy042024Doc)));
	return (CMy042024Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy042024View 消息处理程序


void CMy042024View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	float a = pow((rect.left - rect.right) / 2, 2);
	float b = pow((rect.bottom - rect.top) / 2, 2);
	float c = (rect.left + rect.right) / 2;
	float d = (rect.bottom + rect.top) / 2;
	if ((pow(point.x - c, 2) / a + pow(point.y - d, 2) / b) <= 1) {
		set = true;
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy042024View::OnAddcolor()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = GetDC();

	MyDlg dlg;

	if (set) {
		if (dlg.DoModal() == IDOK) {
			UpdateData();
			brush.DeleteObject();
			brush.CreateSolidBrush(RGB(dlg.a, dlg.b, dlg.c));
		}
		
		Invalidate();
	}

}
