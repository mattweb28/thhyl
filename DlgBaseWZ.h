#if !defined(AFX_DLGBASEWZ_H__86AEDC29_CC94_4FB9_98EB_5144FCD31136__INCLUDED_)
#define AFX_DLGBASEWZ_H__86AEDC29_CC94_4FB9_98EB_5144FCD31136__INCLUDED_

// ����������жԻ���Ļ���

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBaseWZ.h : header file
//

#ifndef TTS_USEVISUALSTYLE
# define TTS_USEVISUALSTYLE (0x100)
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBaseWZ dialog

class CDlgBaseWZ : public CDialog
{
// Construction
public:
	CDlgBaseWZ( UINT nIDTemplate, CWnd* pParent = NULL);   // standard constructor

	// s_dialogcount��صķ�����Ŀǰ��ʹ��
	//static int GetDialogCount() { return s_dialogcount; }
	//static void AddRefCount() { ++s_dialogcount; }
	//static void DecRefCount() { --s_dialogcount; }

// Dialog Data
	//{{AFX_DATA(CDlgBaseWZ)
	// enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBaseWZ)
	public:
	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBaseWZ)
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	CToolTipCtrl	m_tooltip;
	DWORD			m_dlgopt;
private:
	// ��Ŀǰ��ʹ�ã���ΪĿǰ�����������Ƿ�Enabled���ж��Ƿ���Ը��Ĵ򿪵��ļ����Ժ���ܻ��иı䡿
	// ��ֵ��ʾһ�����ü�����
	// ��� m_dlgopt û������ DLGWZ_OPT_NOCHANGECOUNT����ô��ʾ�öԻ�����õ�¼���ļ������ݡ��� InitDialog() �� DestroyWindow() �л�ֱ����� s_dialogcount ��ֵ��
	// Ŀǰ���ڿ����ļ��б�(CFileListWindow)�Ķ��������ü�������1ʱ����������ļ��б��и��Ĵ򿪵��ļ����Է�ֹ����Ұָ�롣
	// ����ĳЩ�����õ�¼���ļ����ݵĶԻ��򣬿����ڹ��캯����д�ϣ�m_dlgopt |= DLGWZ_OPT_NOCHANGECOUNT ��
	//static int s_dialogcount;  
};

#define DLGWZ_OPT_ENABLEMAXIMIZE		0x00000001  // ���� F11 ���
#define DLGWZ_OPT_ALWAYSANYDRAG			0x00000002  // `λ�ڷǱ�����Ҳ���϶�` ������Ч������ѡ���е����õ�Ӱ��
#define DLGWZ_OPT_NOCHANGECOUNT			0x00000004  // ��Ҫ���� s_dialogcount��Ŀǰ��ʹ�ã�

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBASEWZ_H__86AEDC29_CC94_4FB9_98EB_5144FCD31136__INCLUDED_)
