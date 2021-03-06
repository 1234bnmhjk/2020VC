
// 0420_2(2)View.h : CMy0420_22View 类的接口
//

#pragma once


class CMy0420_22View : public CView
{
protected: // 仅从序列化创建
	CMy0420_22View();
	DECLARE_DYNCREATE(CMy0420_22View)

// 特性
public:
	CMy0420_22Doc* GetDocument() const;

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
	virtual ~CMy0420_22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawellispe();
};

#ifndef _DEBUG  // 0420_2(2)View.cpp 中的调试版本
inline CMy0420_22Doc* CMy0420_22View::GetDocument() const
   { return reinterpret_cast<CMy0420_22Doc*>(m_pDocument); }
#endif

