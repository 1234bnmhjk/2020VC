
// 0420_2(3)View.cpp : CMy0420_23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0420_2(3).h"
#endif

#include "0420_2(3)Doc.h"
#include "0420_2(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0420_23View

IMPLEMENT_DYNCREATE(CMy0420_23View, CView)

BEGIN_MESSAGE_MAP(CMy0420_23View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0420_23View ����/����

CMy0420_23View::CMy0420_23View()
{
	// TODO:  �ڴ˴���ӹ������
	rect.left = 100;
	rect.top = 100;
	rect.right = 500;
	rect.bottom = 300;

	set = false;
}

CMy0420_23View::~CMy0420_23View()
{
}

BOOL CMy0420_23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0420_23View ����

void CMy0420_23View::OnDraw(CDC* pDC)
{
	CMy0420_23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CPen pen;
	if (set){
		pen.CreatePen(PS_DASH,1,RGB(255, 0, 0));
	}
	else {
		pen.CreatePen(PS_NULL, 1, RGB(255, 0, 0));
	}
	
	CPen* oldpen = pDC->SelectObject(&pen);
	pDC->Rectangle(rect);
	pen.DeleteObject();

	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	oldpen = pDC->SelectObject(&pen);
	pDC->Ellipse(rect);

}


// CMy0420_23View ��ӡ

BOOL CMy0420_23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0420_23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0420_23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy0420_23View ���

#ifdef _DEBUG
void CMy0420_23View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0420_23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0420_23Doc* CMy0420_23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0420_23Doc)));
	return (CMy0420_23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0420_23View ��Ϣ�������


void CMy0420_23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	float a = pow((rect.left - rect.right) / 2, 2);
	float b = pow((rect.bottom - rect.top) / 2, 2);
	float c = (rect.left + rect.right) / 2;
	float d = (rect.bottom + rect.top) / 2;
	if ((pow(point.x - c,2) / a + pow(point.y - d, 2) / b) <= 1){
		set = true;
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}
