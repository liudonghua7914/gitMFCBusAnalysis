#pragma once


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
};
