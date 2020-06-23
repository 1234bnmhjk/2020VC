
// 0420_2(1)View.cpp : CMy0420_21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy0420_21View ����/����

CMy0420_21View::CMy0420_21View()
{
	// TODO:  �ڴ˴���ӹ������
	set = false;
	
}

CMy0420_21View::~CMy0420_21View()
{
}

BOOL CMy0420_21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0420_21View ����

void CMy0420_21View::OnDraw(CDC* /*pDC*/)
{
	CMy0420_21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0420_21View ��ӡ

BOOL CMy0420_21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0420_21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0420_21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy0420_21View ���

#ifdef _DEBUG
void CMy0420_21View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0420_21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0420_21Doc* CMy0420_21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0420_21Doc)));
	return (CMy0420_21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0420_21View ��Ϣ�������


void CMy0420_21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	startPoint = point;
	endPoint = point;
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0420_21View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMy0420_21View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
