#pragma once


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
};
