
// 0420_2(4)View.h: CMy042024View 类的接口
//

#pragma once


class CMy042024View : public CView
{
protected: // 仅从序列化创建
	CMy042024View() noexcept;
	DECLARE_DYNCREATE(CMy042024View)

// 特性
public:
	CMy042024Doc* GetDocument() const;

// 操作
public:

	bool set;
	CRect rect;
	CBrush brush;

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
	virtual ~CMy042024View();
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
	afx_msg void OnAddcolor();
};

#ifndef _DEBUG  // 0420_2(4)View.cpp 中的调试版本
inline CMy042024Doc* CMy042024View::GetDocument() const
   { return reinterpret_cast<CMy042024Doc*>(m_pDocument); }
#endif

