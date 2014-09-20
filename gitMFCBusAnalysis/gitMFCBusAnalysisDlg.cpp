
// gitMFCBusAnalysisDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "gitMFCBusAnalysis.h"
#include "gitMFCBusAnalysisDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CgitMFCBusAnalysisDlg �Ի���




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
END_MESSAGE_MAP()


// CgitMFCBusAnalysisDlg ��Ϣ�������

BOOL CgitMFCBusAnalysisDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_Classified.SetCheck(TRUE);
	m_Select = 0x01;
	m_pMsgHead = NULL;
	m_pOpenFileBuf = NULL;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CgitMFCBusAnalysisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CgitMFCBusAnalysisDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CgitMFCBusAnalysisDlg::OnBnClickedButtonCheckList()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_CheckListDlg.DoModal();
}


void CgitMFCBusAnalysisDlg::OnBnClickedRadioCheckClassfied()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Select = 0x01;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
}


void CgitMFCBusAnalysisDlg::OnBnClickedRadioFilter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Select = 0x02;
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
}


void CgitMFCBusAnalysisDlg::OnBnClickedButtonOpenFile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL bOpen = FALSE;
	CFileDialog UpdateFileDlg(TRUE);
	UpdateFileDlg.m_ofn.lpstrFilter = __T("All File (*.*)\0*.*\0*.bin\0*.bin\0Text(*.txt)\0*.txt\0\0");

	if (IDOK  == UpdateFileDlg.DoModal())
	{
		m_cFilePatchName = UpdateFileDlg.GetPathName();

		CFile OpenFile(m_cFilePatchName,CFile::modeRead);
		m_OpenFileLength = OpenFile.GetLength();
		if(m_OpenFileLength)
		{
			if (NULL == m_pOpenFileBuf)
			{
				m_pOpenFileBuf = new char[m_OpenFileLength + 1];
				m_pOpenFileBuf[m_OpenFileLength] = '\0';
				OpenFile.Read(m_pOpenFileBuf,m_OpenFileLength);
				//�ر��ļ�
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
	}
	else
	{
		pt = m_pMsgHead;
		while(pt)
		{
			if(!memcmp(pt->idName,m_pMsgNew->idName,strlen(m_pMsgNew->idName)))
			{			
				break;
			}
			pt = pt->next;
			cnt++;
		}
		m_pMsgNew->index = cnt;
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
}


void CgitMFCBusAnalysisDlg::showList(void)
{
	struct  CAN_MSG *pt;
	WCHAR *pwDebug = NULL;
	int copyLen = 0;

	pt = m_pMsgHead;
	while(pt)
	{
		copyLen = MultiByteToWideChar(CP_ACP,0,(char *)pt->idName,-1,NULL,0);
		pwDebug = new WCHAR[copyLen + 1];
		pwDebug[copyLen] = '\0';
		MultiByteToWideChar(CP_ACP,0,(char *)pt->idName,-1,pwDebug,copyLen);
		m_CanIdList.AddString(pwDebug);
		pt = pt->next;
	}







	
	
	
}