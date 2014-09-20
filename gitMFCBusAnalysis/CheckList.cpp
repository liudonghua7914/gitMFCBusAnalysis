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
	//CheckListInit();
	UINT i = 0;
	for (i = IDC_CHECK2;i < IDC_CHECK102;i++)
	{
		GetDlgItem(i)->ShowWindow(FALSE);
	}

	for (i = IDC_CHECK2;i < m_checkListMax;i++)
	{
		GetDlgItem(i)->ShowWindow(TRUE);
	}
	DDX_Control(pDX, IDC_CHECK102, m_checklistall);
	DDX_Control(pDX, IDC_CHECK103, m_checklistdisall);
}


BEGIN_MESSAGE_MAP(CCheckList, CDialogEx)
	
	ON_BN_CLICKED(IDC_CHECK102, &CCheckList::OnBnClickedCheckSelectAll)
	ON_BN_CLICKED(IDC_CHECK103, &CCheckList::OnBnClickedCheckDisAll)
END_MESSAGE_MAP()

#define IDC_CHECKBOX    (0x11) // 控件的ID号
// CCheckList 消息处理程序



void CCheckList::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
}



void CCheckList::CheckListInit(void)
{
	UINT i = 0;
	
}


void CCheckList::OnBnClickedCheckSelectAll()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i = 0;
	CButton* pBtn;
	m_checklistdisall.SetCheck(0);
	for (i = IDC_CHECK2;i < m_checkListMax;i++)
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
	for (i = IDC_CHECK2;i < m_checkListMax;i++)
	{
		pBtn = (CButton*) GetDlgItem(i);
		pBtn->SetCheck(0);
	}
}
