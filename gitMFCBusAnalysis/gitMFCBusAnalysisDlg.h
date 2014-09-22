
// gitMFCBusAnalysisDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include "CheckList.h"



// CgitMFCBusAnalysisDlg 对话框
class CgitMFCBusAnalysisDlg : public CDialogEx
{
// 构造
public:
	CgitMFCBusAnalysisDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GITMFCBUSANALYSIS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_CanIdList;
	CListBox m_CanDataList;
	afx_msg void OnBnClickedButtonCheckList();

private:
	CCheckList m_CheckListDlg;
	BYTE m_Select;
	CButton m_Classified;
	CString m_cFilePatchName;
	UINT32 m_OpenFileLength;
	char *m_pOpenFileBuf;
	struct  CAN_MSG *m_pMsgHead;
	struct  CAN_MSG *m_pMsgNew;
	struct  CAN_MSG *m_pMsgCur;
	UINT m_CanIDIndexMax;

	struct  CAN_MSG *m_pCanList[100];
public:
	afx_msg void OnBnClickedRadioCheckClassfied();
	afx_msg void OnBnClickedRadioFilter();
	afx_msg void OnBnClickedButtonOpenFile();
	afx_msg void OnFileBuf(char *p,UINT len);
	afx_msg void checkIDName(char *p,UINT len);
	afx_msg void showList(void);
	afx_msg void OnLbnSelchangeListCanIdChange();
};
