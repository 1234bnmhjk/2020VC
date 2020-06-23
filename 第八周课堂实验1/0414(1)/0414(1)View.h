
// 0414(1)View.h: CMy04141View 类的接口
//

#pragma once


class CMy04141View : public CView
{
protected: // 仅从序列化创建
	CMy04141View() noexcept;
	DECLARE_DYNCREATE(CMy04141View)

// 特性
public:
	CMy04141Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CMy04141View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0414(1)View.cpp 中的调试版本
inline CMy04141Doc* CMy04141View::GetDocument() const
   { return reinterpret_cast<CMy04141Doc*>(m_pDocument); }
#endif

