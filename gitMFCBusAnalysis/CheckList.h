#pragma once
#include "afxwin.h"


// CCheckList �Ի���

class CCheckList : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckList)

public:
	CCheckList(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCheckList();

// �Ի�������
	enum { IDD = IDD_CHECKLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()



public:
	UINT m_checkListMax;

public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheckSelectAll();
	afx_msg void CheckListInit(void);
	CButton m_checklistall;
	CButton m_checklistdisall;
	afx_msg void OnBnClickedCheckDisAll();
};
