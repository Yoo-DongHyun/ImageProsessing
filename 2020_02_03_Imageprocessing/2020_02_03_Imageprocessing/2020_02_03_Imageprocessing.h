
// 2020_02_03_Imageprocessing.h : 2020_02_03_Imageprocessing ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy2020_02_03_ImageprocessingApp:
// �� Ŭ������ ������ ���ؼ��� 2020_02_03_Imageprocessing.cpp�� �����Ͻʽÿ�.
//

class CMy2020_02_03_ImageprocessingApp : public CWinAppEx
{
public:
	CMy2020_02_03_ImageprocessingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2020_02_03_ImageprocessingApp theApp;
