
// 0420_2(2).h : 0420_2(2) Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0420_22App:
// �йش����ʵ�֣������ 0420_2(2).cpp
//

class CMy0420_22App : public CWinAppEx
{
public:
	CMy0420_22App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0420_22App theApp;
