
// 0420_2(1)View.h : CMy0420_21View 类的接口
//

#pragma once


class CMy0420_21View : public CView
{
protected: // 仅从序列化创建
	CMy0420_21View();
	DECLARE_DYNCREATE(CMy0420_21View)

// 特性
public:
	CMy0420_21Doc* GetDocument() const;

// 操作
public:
	bool set;
	CPoint startPoint, endPoint;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy0420_21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0420_2(1)View.cpp 中的调试版本
inline CMy0420_21Doc* CMy0420_21View::GetDocument() const
   { return reinterpret_cast<CMy0420_21Doc*>(m_pDocument); }
#endif

