#pragma once
#include "afxwin.h"

struct  CAN_MSG
{
	BOOL bShow;
	UINT index;
	char idName[10];
	char fullMsg[128];
	struct  CAN_MSG *next;
};
// CCheckList 对话框

class CCheckList : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckList)

public:
	CCheckList(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckList();

// 对话框数据
	enum { IDD = IDD_CHECKLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()



public:
	UINT m_checkListMax;
	HANDLE m_handleThread;
	HANDLE m_handleEvent;
	BOOL m_bKillThread;
	int m_checkBuf[100];
	static DWORD WINAPI ThreadProc(LPCVOID pContext);

public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheckSelectAll();
	CButton m_checklistall;
	CButton m_checklistdisall;
	struct  CAN_MSG *m_CheckListHead;
	struct  CAN_MSG **m_ListArray;
	UINT m_ListLen;
	BOOL bStart;
	afx_msg void OnBnClickedCheckDisAll();
	afx_msg void SetCanIDCheck(UINT index,BOOL bCheck);
};
