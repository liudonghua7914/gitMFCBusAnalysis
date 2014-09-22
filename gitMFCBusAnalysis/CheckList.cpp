// CheckList.cpp : 实现文件
//

#include "stdafx.h"
#include "gitMFCBusAnalysis.h"
#include "CheckList.h"
#include "afxdialogex.h"


// CCheckList 对话框

IMPLEMENT_DYNAMIC(CCheckList, CDialogEx)

CCheckList::CCheckList(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCheckList::IDD, pParent)
{

}

CCheckList::~CCheckList()
{

}

void CCheckList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	UINT i = 0;
/*
*
*/

	for (i = IDC_CHECK1;i <= IDC_CHECK100;i++)
	{
		GetDlgItem(i)->ShowWindow(FALSE);
	}

	for (i = IDC_CHECK1;i < IDC_CHECK1 + m_ListLen;i++)
	{
		GetDlgItem(i)->ShowWindow(TRUE);

		WCHAR *pwDebug = NULL;
		int copyLen = 0;
		struct  CAN_MSG *pt;
		pt = m_ListArray[i - IDC_CHECK1];

		copyLen = MultiByteToWideChar(CP_ACP,0,(char *)pt->idName,-1,NULL,0);
		pwDebug = new WCHAR[copyLen + 1];
		pwDebug[copyLen] = '\0';
		MultiByteToWideChar(CP_ACP,0,(char *)pt->idName,-1,pwDebug,copyLen);
		SetDlgItemText(i,pwDebug);
	}

/*
*	
*/
	DWORD dwThreadID;
	m_bKillThread = FALSE;
	m_handleThread = CreateThread((LPSECURITY_ATTRIBUTES)NULL,
		0,
		(LPTHREAD_START_ROUTINE)ThreadProc,
		this,
		0,
		&dwThreadID
		);
	m_handleEvent = CreateEvent(NULL,FALSE,TRUE,FALSE);

	DDX_Control(pDX, IDC_CHECK102, m_checklistall);
	DDX_Control(pDX, IDC_CHECK103, m_checklistdisall);
}


BEGIN_MESSAGE_MAP(CCheckList, CDialogEx)
	
	ON_BN_CLICKED(IDC_CHECK102, &CCheckList::OnBnClickedCheckSelectAll)
	ON_BN_CLICKED(IDC_CHECK103, &CCheckList::OnBnClickedCheckDisAll)
END_MESSAGE_MAP()

#define IDC_CHECKBOX    (0x11) // 控件的ID号
// CCheckList 消息处理程序


void CCheckList::SetCanIDCheck(UINT index,BOOL bCheck)
{
	struct  CAN_MSG *pt;
	if (m_CheckListHead)
	{
		pt = m_CheckListHead;
		while (pt)
		{
			if (index == pt->index)
			{
				pt->bShow = bCheck;
			}
			pt = pt->next;
		}
	}
}

void CCheckList::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码	
	CButton* pBtn;
	BOOL bCheck = FALSE;
	pBtn = (CButton*) GetDlgItem(IDC_CHECK1);
	if (pBtn->GetCheck())
	{
		bCheck = TRUE;
	}
	SetCanIDCheck(0,bCheck);
}


void CCheckList::OnBnClickedCheckSelectAll()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i = 0;
	CButton* pBtn;
	m_checklistdisall.SetCheck(0);
	for (i = IDC_CHECK1;i < m_checkListMax;i++)
	{
		pBtn = (CButton*) GetDlgItem(i);
		pBtn->SetCheck(1);
	}
}


void CCheckList::OnBnClickedCheckDisAll()
{
	// TODO: 在此添加控件通知处理程序代码	
	UINT i = 0;
	CButton* pBtn;
	m_checklistall.SetCheck(0);
	for (i = IDC_CHECK1;i < m_checkListMax;i++)
	{
		pBtn = (CButton*) GetDlgItem(i);
		pBtn->SetCheck(0);
	}
}

DWORD WINAPI CCheckList::ThreadProc(LPCVOID pContext)
{
	CCheckList *pUpdateCheck = (CCheckList *)pContext;
	UINT i = 0;
	CButton* pBtn;
	while (!pUpdateCheck->m_bKillThread)
	{
		WaitForSingleObject(pUpdateCheck->m_handleEvent,500);
		for (i = IDC_CHECK1;i < IDC_CHECK1 + pUpdateCheck->m_ListLen;i++)
		{
			pBtn = (CButton*)(pUpdateCheck->GetDlgItem(i));
			if (pUpdateCheck->m_checkBuf[i - IDC_CHECK1] != pBtn->GetCheck())
			{
				pUpdateCheck->m_checkBuf[i - IDC_CHECK1] = pBtn->GetCheck();
				if (pUpdateCheck->m_checkBuf[i - IDC_CHECK1])
				{
				}
			}
		}
	}
	return TRUE;
}
