
// 0420_2(3)View.h : CMy0420_23View ��Ľӿ�
//

#pragma once


class CMy0420_23View : public CView
{
protected: // �������л�����
	CMy0420_23View();
	DECLARE_DYNCREATE(CMy0420_23View)

// ����
public:
	CMy0420_23Doc* GetDocument() const;

// ����
public:
	CRect rect;
	int number;
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy0420_23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0420_2(3)View.cpp �еĵ��԰汾
inline CMy0420_23Doc* CMy0420_23View::GetDocument() const
   { return reinterpret_cast<CMy0420_23Doc*>(m_pDocument); }
#endif

