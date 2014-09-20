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
}


BEGIN_MESSAGE_MAP(CCheckList, CDialogEx)
END_MESSAGE_MAP()


// CCheckList 消息处理程序
