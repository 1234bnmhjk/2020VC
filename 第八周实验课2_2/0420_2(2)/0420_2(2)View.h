
// 0420_2(2)View.h : CMy0420_22View ��Ľӿ�
//

#pragma once


class CMy0420_22View : public CView
{
protected: // �������л�����
	CMy0420_22View();
	DECLARE_DYNCREATE(CMy0420_22View)

// ����
public:
	CMy0420_22Doc* GetDocument() const;

// ����
public:

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
	virtual ~CMy0420_22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawellispe();
};

#ifndef _DEBUG  // 0420_2(2)View.cpp �еĵ��԰汾
inline CMy0420_22Doc* CMy0420_22View::GetDocument() const
   { return reinterpret_cast<CMy0420_22Doc*>(m_pDocument); }
#endif

