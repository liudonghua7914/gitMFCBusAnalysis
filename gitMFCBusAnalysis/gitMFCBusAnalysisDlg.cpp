
// gitMFCBusAnalysisDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "gitMFCBusAnalysis.h"
#include "gitMFCBusAnalysisDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgitMFCBusAnalysisDlg 对话框




CgitMFCBusAnalysisDlg::CgitMFCBusAnalysisDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CgitMFCBusAnalysisDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgitMFCBusAnalysisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_CanIdList);
	DDX_Control(pDX, IDC_LIST1, m_CanDataList);
	DDX_Control(pDX, IDC_RADIO1, m_Classified);
}

BEGIN_MESSAGE_MAP(CgitMFCBusAnalysisDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CgitMFCBusAnalysisDlg::OnBnClickedButtonCheckList)
	ON_BN_CLICKED(IDC_RADIO1, &CgitMFCBusAnalysisDlg::OnBnClickedRadioCheckClassfied)
	ON_BN_CLICKED(IDC_RADIO2, &CgitMFCBusAnalysisDlg::OnBnClickedRadioFilter)
	ON_BN_CLICKED(IDC_BUTTON1, &CgitMFCBusAnalysisDlg::OnBnClickedButtonOpenFile)
	ON_LBN_SELCHANGE(IDC_LIST2, &CgitMFCBusAnalysisDlg::OnLbnSelchangeListCanIdChange)
END_MESSAGE_MAP()


// CgitMFCBusAnalysisDlg 消息处理程序

BOOL CgitMFCBusAnalysisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_Classified.SetCheck(TRUE);
	m_Select = 0x01;
	m_pMsgHead = NULL;
	m_pOpenFileBuf = NULL;
	m_CanIDIndexMax = 0;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CgitMFCBusAnalysisDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CgitMFCBusAnalysisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CgitMFCBusAnalysisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CgitMFCBusAnalysisDlg::OnBnClickedButtonCheckList()
{
	// TODO: 在此添加控件通知处理程序代码
	m_CheckListDlg.DoModal();
}


void CgitMFCBusAnalysisDlg::OnBnClickedRadioCheckClassfied()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Select = 0x01;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_LIST2)->EnableWindow(TRUE);
}


void CgitMFCBusAnalysisDlg::OnBnClickedRadioFilter()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Select = 0x02;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_LIST2)->EnableWindow(FALSE);
	
}


void CgitMFCBusAnalysisDlg::OnBnClickedButtonOpenFile()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL bOpen = FALSE;
	CFileDialog UpdateFileDlg(TRUE);
	UpdateFileDlg.m_ofn.lpstrFilter = __T("All File (*.*)\0*.*\0*.bin\0*.bin\0Text(*.txt)\0*.txt\0\0");
	m_CanIdList.ResetContent();
	if (IDOK  == UpdateFileDlg.DoModal())
	{
		m_cFilePatchName = UpdateFileDlg.GetPathName();
		m_CanIDIndexMax = 0;

		if (m_pMsgHead)
		{
			free(m_pMsgHead);
		}

		m_pMsgHead = NULL; 
		m_pMsgNew = NULL;
		m_pMsgNew = NULL;
	
		CFile OpenFile(m_cFilePatchName,CFile::modeRead);
		m_OpenFileLength = OpenFile.GetLength();
		if(m_OpenFileLength)
		{
			//if (NULL == m_pOpenFileBuf)
			{
				m_pOpenFileBuf = new char[m_OpenFileLength + 1];
				m_pOpenFileBuf[m_OpenFileLength] = '\0';
				OpenFile.Read(m_pOpenFileBuf,m_OpenFileLength);
				//关闭文件
				OpenFile.Close();
				bOpen = TRUE;
			}

			if(bOpen)
			{
				OnFileBuf(m_pOpenFileBuf,m_OpenFileLength +1);		
			}

		}
		else
		{
			MessageBox(__T("OpenFile Fail"));
		}
	}
}

void CgitMFCBusAnalysisDlg::checkIDName(char *p,UINT len)
{
	struct  CAN_MSG *pt;
	UINT i;
	UINT cnt = 0;
	char idname[10];
	BYTE idnamecnt = 0;
	BOOL bTre = FALSE;
	memset(idname,'\0',10);
	for(i = 0;i < len;i++)
	{
		if ((('0' <= p[i]) &&('9' >= p[i])) ||(('a' <= p[i]) &&('z' >= p[i])) || (('A' <= p[i]) &&('Z' >= p[i])))
		{
			idname[idnamecnt] =  p[i];
			idnamecnt = (idnamecnt + 1) % 10;
		}
		else
		{
			if (8 <= idnamecnt)
			{
				i = len;
				break;
			}
			idnamecnt = 0;
		}
	}

	m_pMsgNew = new (struct CAN_MSG);
	if(m_pMsgNew)
	{
		m_pMsgNew->bShow = TRUE;
		memset(m_pMsgNew->fullMsg,'\0',128);
		memset(m_pMsgNew->idName,'\0',10);
		memcpy(m_pMsgNew->idName,idname,idnamecnt);	
		memcpy(m_pMsgNew->fullMsg,p,len);
		m_pMsgNew->next = NULL;
	}

	if (NULL == m_pMsgHead)
	{
		m_pMsgNew->index = 0;
		m_pMsgHead = m_pMsgNew;
		m_pMsgCur = m_pMsgNew;
		m_pCanList[0] = m_pMsgHead;
	}
	else
	{
		pt = m_pMsgHead;
		while(pt)
		{
			if(!memcmp(pt->idName,m_pMsgNew->idName,strlen(m_pMsgNew->idName)))
			{			
				m_pMsgNew->index = pt->index;
				bTre = TRUE;
				break;
			}
			pt = pt->next;
		}

		if (!bTre)
		{
			m_CanIDIndexMax = m_CanIDIndexMax + 1;
			m_pCanList[m_CanIDIndexMax] = m_pMsgNew;
			m_pMsgNew->index = m_CanIDIndexMax;
		}

		m_pMsgCur->next = m_pMsgNew;
		m_pMsgCur = m_pMsgNew;
	}
}

void CgitMFCBusAnalysisDlg::OnFileBuf(char *p,UINT len)
{
	UINT i = 0;
	
	BOOL bNewLine = FALSE;
	char idname[10];
	char idmsg[128];
	BYTE idnamecnt = 0;
	BYTE idmsgcnt = 0;
	BOOL bID = FALSE;
	memset(idmsg,'\0',128);
	for (i = 0;i < len;i++)
	{
		if(('\r' == p[i]) || ('\n' == p[i]) || ('\0' == p[i]))
		{
			bNewLine = TRUE;
			if (idmsgcnt)
			{	
				checkIDName(idmsg,idmsgcnt);
				idmsgcnt = 0;
				memset(idmsg,'\0',128);
			}
		}
		else
		{
			idmsg[idmsgcnt] = p[i];
			idmsgcnt = (idmsgcnt + 1) % 128;
		}
	}
	showList();
	m_CanIdList.SetCurSel(0);
	m_CheckListDlg.m_checkListMax = m_CanIDIndexMax + 1 + IDC_CHECK1;
	m_CheckListDlg.m_CheckListHead = m_pMsgHead;
	m_CheckListDlg.m_ListArray = m_pCanList;
	m_CheckListDlg.m_ListLen = m_CanIDIndexMax + 1;
	GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
}


void CgitMFCBusAnalysisDlg::showList(void)
{
	WCHAR *pwDebug = NULL;
	int copyLen = 0;
	UINT i = 0;
	struct  CAN_MSG *pt;
	pt = m_pMsgHead;
	for (i = 0;i < m_CanIDIndexMax + 1;i++)
	{
		copyLen = MultiByteToWideChar(CP_ACP,0,(char *)m_pCanList[i]->idName,-1,NULL,0);
		pwDebug = new WCHAR[copyLen + 1];
		pwDebug[copyLen] = '\0';
		MultiByteToWideChar(CP_ACP,0,(char *)m_pCanList[i]->idName,-1,pwDebug,copyLen);
		m_CanIdList.AddString(pwDebug);
	}

	while(pt)
	{
		if(0 == pt->index)
		{
			copyLen = MultiByteToWideChar(CP_ACP,0,(char *)pt->fullMsg,-1,NULL,0);
			pwDebug = new WCHAR[copyLen + 1];
			pwDebug[copyLen] = '\0';
			MultiByteToWideChar(CP_ACP,0,(char *)pt->fullMsg,-1,pwDebug,copyLen);
			m_CanDataList.AddString(pwDebug);
		}		
		pt = pt->next;
	}
	
}

void CgitMFCBusAnalysisDlg::OnLbnSelchangeListCanIdChange()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = 0;
	WCHAR *pwDebug = NULL;
	int copyLen = 0;
	struct  CAN_MSG *pt;
	struct  CAN_MSG *qt;
	index = m_CanIdList.GetCurSel();
	pt = m_pMsgHead;
	m_CanDataList.ResetContent();
	
	pt = m_pMsgHead;
	qt = m_pCanList[index];
#if 1
	while(pt)
	{
		if(qt->index == pt->index)
		{
			copyLen = MultiByteToWideChar(CP_ACP,0,(char *)pt->fullMsg,-1,NULL,0);
			pwDebug = new WCHAR[copyLen + 1];
			pwDebug[copyLen] = '\0';
			MultiByteToWideChar(CP_ACP,0,(char *)pt->fullMsg,-1,pwDebug,copyLen);
			m_CanDataList.AddString(pwDebug);
		}		
		pt = pt->next;
	}
#endif
}
