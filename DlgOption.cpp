// DlgOption.cpp : implementation file
//

#include "stdafx.h"
#include "cfgfile.h"
#include "thhyl.h"
#include "DlgOption.h"
#include "global.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOption dialog

CDlgOption::CDlgOption(CWnd* pParent /*=NULL*/)
	: CDlgBaseWZ(CDlgOption::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgOption)
	m_CommentCodeEdit = cfg.CommentCode;
	m_InfoCodeEdit    = cfg.InfoCode;
	m_chkDblClk       = HasConfigOption(CFG_DBLCLK);
	m_chkMBtn         = HasConfigOption(CFG_MBTN);
	m_chkConfirm      = HasConfigOption(CFG_CONFIRM);
	m_chkPlayTime     = HasConfigOption(CFG_SHOWPLAYTIME);
	m_chkSlowRate     = HasConfigOption(CFG_SHOWSLOWRATE);
	m_chk9            = HasConfigOption(CFG_9);
	m_chkCopyOpenDest = HasConfigOption(CFG_COPYOPENDEST);
	m_chkAnyDrag      = HasConfigOption(CFG_ANYDRAG);
	m_chkAutoExit     = HasConfigOption(CFG_AUTOEXIT);
	m_chkNoBTooltip   = HasConfigOption(CFG_NOBALLOONTOOLTIP);
	//}}AFX_DATA_INIT
}


void CDlgOption::DoDataExchange(CDataExchange* pDX)
{
	CDlgBaseWZ::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOption)
	DDX_Control(pDX, IDC_INFOCODE, m_InfoCode);
	DDX_Control(pDX, IDC_COMMENTCODE, m_CommentCode);
	DDX_Text(pDX, IDC_COMMENTCODEEDIT, m_CommentCodeEdit);
	DDX_Text(pDX, IDC_INFOCODEEDIT, m_InfoCodeEdit);
	DDX_Check(pDX, IDC_CHK_DBLCLK, m_chkDblClk);
	DDX_Check(pDX, IDC_CHK_MBTN, m_chkMBtn);
	DDX_Check(pDX, IDC_CHK_CONFIRM, m_chkConfirm);
	DDX_Check(pDX, IDC_CHK_PLAYTIME, m_chkPlayTime);
	DDX_Check(pDX, IDC_CHK_SLOWRATE, m_chkSlowRate);
	DDX_Check(pDX, IDC_CHK_9, m_chk9);
	DDX_Check(pDX, IDC_CHK_COPYOPENDEST, m_chkCopyOpenDest);
	DDX_Check(pDX, IDC_CHK_ANYDRAG, m_chkAnyDrag);
	DDX_Check(pDX, IDC_CHK_AUTOEXIT, m_chkAutoExit);
	DDX_Check(pDX, IDC_CHK_NOBTOOLTIP, m_chkNoBTooltip);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOption, CDlgBaseWZ)
	//{{AFX_MSG_MAP(CDlgOption)
	ON_CBN_SELCHANGE(IDC_COMMENTCODE, OnSelchangeCommentcode)
	ON_CBN_SELCHANGE(IDC_INFOCODE, OnSelchangeInfocode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOption message handlers

BOOL CDlgOption::OnInitDialog() 
{
	CDlgBaseWZ::OnInitDialog();
	
	// TODO: Add extra initialization here
	ComboAddString(m_CommentCode, m_CommentCodeEdit);
	ComboAddString(m_InfoCode, m_InfoCodeEdit);

	CEdit* pInfoCodeEdit=(CEdit*)GetDlgItem(IDC_INFOCODEEDIT);
	pInfoCodeEdit->SetSel(0, -1, TRUE);
	pInfoCodeEdit->SetFocus();

	// ���� tooltip
	m_tooltip.AddTool( GetDlgItem(IDC_CHK_PLAYTIME), _T("��ʾ��Ϸʱ�䣨��ʽ��֡(��:��.����)��") );
	m_tooltip.AddTool( GetDlgItem(IDC_CHK_SLOWRATE), _T("��ʾʹ��FPS���ݼ���ó��ĵ�֡�ʣ�ʹ�ô������ʾ��ӳڣ�Ĵ��µ�֡�ʣ�") );
	m_tooltip.AddTool( GetDlgItem(IDC_CHK_DBLCLK), _T("������ѡ��˫���� ���/��ԭ ����") );
	m_tooltip.AddTool( GetDlgItem(IDC_CHK_9), _T("����ӳڣ������Ϣ�еġ�Cirno���ĳɡ��ᡱ") );
	m_tooltip.AddTool( GetDlgItem(IDC_CHK_COPYOPENDEST), _T("ʹ�ò˵��еġ����Ƶ�...�����ܸ����ļ��ɹ����Զ���Ŀ���ļ�") );
	m_tooltip.AddTool( GetDlgItem(IDC_CHK_ANYDRAG), _T("���ָ��λ�ڴ��ڵ�����λ�ö����϶�����") );
	m_tooltip.AddTool( GetDlgItem(IDC_CHK_AUTOEXIT), _T("ʹ�á�ɾ��������ɾ���ļ��ɹ����򵱼�⵽�򿪵�¼���ļ����ٴ���ʱ�Զ��˳�����") );
	m_tooltip.AddTool( GetDlgItem(IDC_CHK_NOBTOOLTIP), _T("����ѡ����ʹ����ͨ���Ĺ�����ʾ����ֻ���´�����Ч��") );
	m_tooltip.Activate(TRUE);
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgOption::OnSelchangeCommentcode() 
{
	// TODO: Add your control notification handler code here
	ComboSel2Edit(m_CommentCode, m_CommentCodeEdit);
	UpdateData(FALSE);
}

void CDlgOption::OnSelchangeInfocode() 
{
	// TODO: Add your control notification handler code here
	ComboSel2Edit(m_InfoCode, m_InfoCodeEdit);
	UpdateData(FALSE);
}

void CDlgOption::OnOK() 
{
	// TODO: Add extra validation here

	if(!UpdateData(TRUE))
		return;

	cfg.CommentCode = m_CommentCodeEdit;
	cfg.InfoCode    = m_InfoCodeEdit;
	cfg.set(CFG_DBLCLK, m_chkDblClk);
	cfg.set(CFG_MBTN, m_chkMBtn);
	cfg.set(CFG_CONFIRM, m_chkConfirm);
	cfg.set(CFG_SHOWPLAYTIME, m_chkPlayTime);
	cfg.set(CFG_SHOWSLOWRATE, m_chkSlowRate);
	cfg.set(CFG_9, m_chk9);
	cfg.set(CFG_COPYOPENDEST, m_chkCopyOpenDest);
	cfg.set(CFG_ANYDRAG, m_chkAnyDrag);
	cfg.set(CFG_AUTOEXIT, m_chkAutoExit);
	cfg.set(CFG_NOBALLOONTOOLTIP, m_chkNoBTooltip);
	
	CDlgBaseWZ::OnOK();
}


