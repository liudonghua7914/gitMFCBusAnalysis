
// gitMFCBusAnalysisDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#include "CheckList.h"



// CgitMFCBusAnalysisDlg �Ի���
class CgitMFCBusAnalysisDlg : public CDialogEx
{
// ����
public:
	CgitMFCBusAnalysisDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GITMFCBUSANALYSIS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
