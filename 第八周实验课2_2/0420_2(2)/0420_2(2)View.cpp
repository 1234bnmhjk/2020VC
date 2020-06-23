
// 0420_2(2)View.cpp : CMy0420_22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DRAWELLISPE, &CMy0420_22View::OnDrawellispe)
END_MESSAGE_MAP()

// CMy0420_22View ����/����

CMy0420_22View::CMy0420_22View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy0420_22View::~CMy0420_22View()
{
}

BOOL CMy0420_22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0420_22View ����

void CMy0420_22View::OnDraw(CDC* /*pDC*/)
{
	CMy0420_22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy0420_22View ��ӡ

BOOL CMy0420_22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0420_22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0420_22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy0420_22View ���

#ifdef _DEBUG
void CMy0420_22View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0420_22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0420_22Doc* CMy0420_22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0420_22Doc)));
	return (CMy0420_22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0420_22View ��Ϣ�������


void CMy0420_22View::OnDrawellispe()
{
	// TODO:  �ڴ���������������
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
