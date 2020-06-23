
// 0420_2(4).h: 0420_2(4) 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMy042024App:
// 有关此类的实现，请参阅 0420_2(4).cpp
//

class CMy042024App : public CWinApp
{
public:
	CMy042024App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy042024App theApp;
