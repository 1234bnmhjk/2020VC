
// 0414(2)View.cpp: CMy04142View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0414(2).h"
#endif

#include "0414(2)Doc.h"
#include "0414(2)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04142View

IMPLEMENT_DYNCREATE(CMy04142View, CView)

BEGIN_MESSAGE_MAP(CMy04142View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SHOWFILENAME, &CMy04142View::OnShowfilename)
END_MESSAGE_MAP()

// CMy04142View 构造/析构

CMy04142View::CMy04142View() noexcept
{
	// TODO: 在此处添加构造代码
	
}

CMy04142View::~CMy04142View()
{
}

BOOL CMy04142View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04142View 绘图

void CMy04142View::OnDraw(CDC* pDC)
{
	CMy04142Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(200, 300, filename);
}


// CMy04142View 打印

BOOL CMy04142View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy04142View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy04142View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy04142View 诊断

#ifdef _DEBUG
void CMy04142View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04142View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04142Doc* CMy04142View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04142Doc)));
	return (CMy04142Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04142View 消息处理程序


void CMy04142View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	
	if (r == IDOK) {
		CString str = cfd.GetFileName();
		filename = str.Left(str.Find('.'));
		Invalidate();
	}
	
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy04142View::OnShowfilename()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	dlg.SetString(filename);
	dlg.DoModal();
}
