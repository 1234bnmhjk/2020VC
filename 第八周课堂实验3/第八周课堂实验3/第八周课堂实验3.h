
// 第八周课堂实验3.h: 第八周课堂实验3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// C第八周课堂实验3App:
// 有关此类的实现，请参阅 第八周课堂实验3.cpp
//

class C第八周课堂实验3App : public CWinApp
{
public:
	C第八周课堂实验3App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C第八周课堂实验3App theApp;
