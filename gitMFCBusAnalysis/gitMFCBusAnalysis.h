
// gitMFCBusAnalysis.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CgitMFCBusAnalysisApp:
// �йش����ʵ�֣������ gitMFCBusAnalysis.cpp
//

class CgitMFCBusAnalysisApp : public CWinApp
{
public:
	CgitMFCBusAnalysisApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CgitMFCBusAnalysisApp theApp;