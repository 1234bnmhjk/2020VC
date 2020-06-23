
// 0414(1)View.cpp: CMy04141View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0414(1).h"
#endif

#include "0414(1)Doc.h"
#include "0414(1)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04141View

IMPLEMENT_DYNCREATE(CMy04141View, CView)

BEGIN_MESSAGE_MAP(CMy04141View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy04141View 构造/析构

CMy04141View::CMy04141View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy04141View::~CMy04141View()
{
}

BOOL CMy04141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04141View 绘图

void CMy04141View::OnDraw(CDC* /*pDC*/)
{
	CMy04141Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy04141View 打印

BOOL CMy04141View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy04141View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy04141View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy04141View 诊断

#ifdef _DEBUG
void CMy04141View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04141View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04141Doc* CMy04141View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04141Doc)));
	return (CMy04141Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04141View 消息处理程序


void CMy04141View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r == IDOK) {
		CString str = cfd.GetFileName();
		CString filename = str.Left(str.Find('.'));
		dc.TextOutW(200, 300, filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}
