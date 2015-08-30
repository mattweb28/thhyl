// DlgComment.cpp : implementation file
//

#include "stdafx.h"
#include "cfgfile.h"
#include "thhyl.h"
#include "global.h"
#include "DlgComment.h"
#include "cpconv.h"

#include "thuserblock.h"
#include "CommonDlgWZ.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgComment dialog


CDlgComment::CDlgComment(CWnd* pParent /*=NULL*/)
	: CDlgBaseWZ(CDlgComment::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgComment)
	m_CommentCodeEdit = cfg.CommentCodeForEdit;
	//}}AFX_DATA_INIT

	m_pCommentData=NULL;
	m_pRpyData = NULL;
	m_dwRpySize = 0;
}


void CDlgComment::DoDataExchange(CDataExchange* pDX)
{
	CDlgBaseWZ::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgComment)
	DDX_Control(pDX, IDC_COMMENTCODE, m_CommentCode);
	DDX_Control(pDX, IDC_COMMENTEDIT, m_CommentEdit);
	DDX_Text(pDX, IDC_COMMENTCODEEDIT, m_CommentCodeEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgComment, CDlgBaseWZ)
	//{{AFX_MSG_MAP(CDlgComment)
	ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_COMMENTCODE, OnSelchangeCommentcode)
	ON_BN_CLICKED(IDC_SAVEAS, OnSaveas)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgComment message handlers

BOOL CDlgComment::OnInitDialog() 
{
	CDlgBaseWZ::OnInitDialog();
	
	// TODO: Add extra initialization here

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon( AfxGetApp()->LoadIcon(IDR_MAINFRAME), TRUE);		// Set big icon
	SetIcon( AfxGetApp()->LoadIcon(IDR_MAINFRAME), FALSE);		// Set small icon

	m_tooltip.AddTool( GetDlgItem(IDOK), _T("����ע��д�ص�ԭ¼���ļ��У�����������������ʾ��¼����Ϣ") );
	m_tooltip.AddTool( GetDlgItem(IDCANCEL), _T("�������ģ��رձ�����") );
	m_tooltip.AddTool( GetDlgItem(IDC_SAVEAS), _T("������ע�ͺ��¼�����Ϊһ�����ļ�") );

	ComboAddString(m_CommentCode, m_CommentCodeEdit);

	LoadEditCtrlFont(&m_CommentEdit);
	m_CommentEdit.SetWindowText((LPCTSTR)(*m_pCommentData));

	m_CommentEdit.SetSel(0, -1, TRUE);
	m_CommentEdit.SetFocus();

	m_dlgopt = DLGWZ_OPT_ENABLEMAXIMIZE;
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgComment::OnSize(UINT nType, int cx, int cy) 
{
	CDlgBaseWZ::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here

	if(IsWindow(m_CommentEdit.GetSafeHwnd())) {
		m_CommentEdit.MoveWindow(10, 100, cx-20, cy-110);
	}
}

void CDlgComment::OnSelchangeCommentcode() 
{
	// TODO: Add your control notification handler code here
	ComboSel2Edit(m_CommentCode, m_CommentCodeEdit);
	UpdateData(FALSE);
}

BOOL CDlgComment::UpdateCommentToFile(
		LPCSTR pComment,       // ָ��ע���ı���ָ��(ANSI)
		size_t dwCommentSize,  // ע���ı���С
		LPCTSTR newfilename    // Ҫ����ע�͵� RPY �ļ���
)
{
	// Ϊ��ע��׼�� user block ����
	RPYUserBlock ubComment((const BYTE*)pComment, dwCommentSize, ubid_comment);
	
	// �� user block ���󱣴浽 user block manager ��
	RPYUserBlockMgr ubm(m_pRpyData, m_dwRpySize);
	const int nCommentID = ubm.getCommentIndex();
	if (nCommentID >= 0) {
		ubm.remove(nCommentID); // remove original comment
	}
	if (!ubm.append(&ubComment)) {
		MessageBox(
			_T("�޷�������ע�͡�\r\n\r\n�����²�Ӧ�÷�����Ҳ���Ǹ� BUG����\r\n�������Ļ����뽫�� rpy �ļ��ύ�����ߡ�m(_ _)m"),
			g_title, MB_ICONSTOP);
		return FALSE;
	}
	
	// ���浽�µ� buffer ��
	size_t newrpysize = 0;
	BYTE* pNewRpyData = ubm.saveToRPY(m_pRpyData, m_dwRpySize, &newrpysize);
	BOOL ret = FALSE;

	// Write to new file
	CFile cfFile;
	if (!cfFile.Open(newfilename, CFile::modeCreate | CFile::modeWrite |
		CFile::shareExclusive | CFile::typeBinary))
	{
		MessageBox(CString(_T("���ļ�ʧ�ܣ�\n\n")) + newfilename, g_title, MB_ICONSTOP);		
		// 1.70 ������ֱ�� return �ˣ�������ڴ�й¶����
	}
	else {
		cfFile.Write(pNewRpyData, newrpysize);
		cfFile.Close();
		ret = TRUE;
	}

	free(pNewRpyData);
	return ret;
}

BOOL CDlgComment::WriteComment(LPCTSTR infile, LPCTSTR outfile)
{
	BOOL result = FALSE;
	ASSERT(m_pRpyData != NULL && m_dwRpySize != 0);

	// ��ȡ�ı����ڵ�ע������
	CString strComment;
	m_CommentEdit.GetWindowText(strComment);

	// ��ע���ı�ת�� ANSI
	BOOL bUsedDefaultChar;
	size_t lenCommentA;
	LPSTR lpszCommentA = Unicode2Ansi(strComment, m_CommentCodeEdit, &lenCommentA, &bUsedDefaultChar);
	if (lpszCommentA != NULL) { // ת����ANSI�ɹ�
		int retmb = IDYES;
		if (bUsedDefaultChar) { // ������ַ��޷�ת��
			retmb = MessageBox(_T("�����ַ��޷�ת����\r\n������Ǳ������ò�������ġ�\r\n\r\n�Ƿ���Ҫ��������ע�⣺�޷�ת�����ַ�����ʧ����"), g_title, MB_YESNO | MB_ICONEXCLAMATION);
		}
		if (retmb == IDYES) {
			// һ���׵���д�뵽���ļ���
			if ( UpdateCommentToFile(lpszCommentA, lenCommentA, outfile) )
				result = TRUE;
		}

		delete []lpszCommentA;
	}
	else { // ת����ANSIʧ��
		LPCTSTR errmsg = ::GetErrorMessage(GetLastError());
		CString strerr((LPCTSTR)IDS_CONVTOANSIERROR);
		strerr += errmsg;
		
		MessageBox(strerr, g_title, MB_ICONSTOP);
	}
	
	return result;
}


void CDlgComment::OnOK() 
{
	// TODO: Add extra validation here
	
	if(!UpdateData(TRUE))
		return;

	if(!WriteComment(m_filename, m_filename))
		return;

	CDlgBaseWZ::OnOK();
}

void CDlgComment::OnSaveas()
{
	// TODO: Add your control notification handler code here
	if (!UpdateData(TRUE))
		return;

	CString filter((LPCTSTR)IDS_DLGFILTER), newfilename;

	CFileDialogWZ dlg(FALSE, _T("rpy"), m_filename, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, this);
	if (dlg.DoModal() == IDOK) {
		newfilename = dlg.GetPathName();
		WriteComment(m_filename, newfilename);
	}
}
