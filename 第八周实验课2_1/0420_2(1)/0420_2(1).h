
// 0420_2(1).h : 0420_2(1) Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0420_21App:
// �йش����ʵ�֣������ 0420_2(1).cpp
//

class CMy0420_21App : public CWinAppEx
{
public:
	CMy0420_21App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0420_21App theApp;
