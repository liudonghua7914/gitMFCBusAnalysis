// CheckList.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "gitMFCBusAnalysis.h"
#include "CheckList.h"
#include "afxdialogex.h"


// CCheckList �Ի���

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


// CCheckList ��Ϣ�������
