#pragma once
#include "afxwin.h"


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

public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheckSelectAll();
	afx_msg void CheckListInit(void);
	CButton m_checklistall;
	CButton m_checklistdisall;
	afx_msg void OnBnClickedCheckDisAll();
};
