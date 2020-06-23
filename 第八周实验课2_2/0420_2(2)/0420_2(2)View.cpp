
// 0420_2(2)View.cpp : CMy0420_22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0420_2(2).h"
#endif

#include "0420_2(2)Doc.h"
#include "0420_2(2)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0420_22View

IMPLEMENT_DYNCREATE(CMy0420_22View, CView)

BEGIN_MESSAGE_MAP(CMy0420_22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DRAWELLISPE, &CMy0420_22View::OnDrawellispe)
END_MESSAGE_MAP()

// CMy0420_22View 构造/析构

CMy0420_22View::CMy0420_22View()
{
	// TODO:  在此处添加构造代码

}

CMy0420_22View::~CMy0420_22View()
{
}

BOOL CMy0420_22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0420_22View 绘制

void CMy0420_22View::OnDraw(CDC* /*pDC*/)
{
	CMy0420_22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy0420_22View 打印

BOOL CMy0420_22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0420_22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy0420_22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy0420_22View 诊断

#ifdef _DEBUG
void CMy0420_22View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0420_22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0420_22Doc* CMy0420_22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0420_22Doc)));
	return (CMy0420_22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0420_22View 消息处理程序


void CMy0420_22View::OnDrawellispe()
{
	// TODO:  在此添加命令处理程序代码
	MyDlg dlg;
	
	if (dlg.DoModal() == IDOK){
		CClientDC dc(this);
		CRect rect;
		this->GetClientRect(&rect);
		CPoint point;
		point.x = (rect.right - rect.left) / 2;
		point.y = (rect.bottom - rect.top) / 2;

		int a, b;
		UpdateData(true);
		a = dlg.number1;
		b = dlg.number2;

		dc.Ellipse(point.x - dlg.number1, point.y - dlg.number2, point.x + dlg.number1, point.y + dlg.number2);
	}
}
