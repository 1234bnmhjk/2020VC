
// 0420_2(1)View.h : CMy0420_21View ��Ľӿ�
//

#pragma once


class CMy0420_21View : public CView
{
protected: // �������л�����
	CMy0420_21View();
	DECLARE_DYNCREATE(CMy0420_21View)

// ����
public:
	CMy0420_21Doc* GetDocument() const;

// ����
public:
	bool set;
	CPoint startPoint, endPoint;
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
	virtual ~CMy0420_21View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0420_2(1)View.cpp �еĵ��԰汾
inline CMy0420_21Doc* CMy0420_21View::GetDocument() const
   { return reinterpret_cast<CMy0420_21Doc*>(m_pDocument); }
#endif

