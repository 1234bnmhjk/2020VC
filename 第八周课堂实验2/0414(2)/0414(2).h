
// 0414(2).h: 0414(2) 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMy04142App:
// 有关此类的实现，请参阅 0414(2).cpp
//

class CMy04142App : public CWinApp
{
public:
	CMy04142App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy04142App theApp;
