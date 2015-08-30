#include "stdafx.h"
#include "CommonDlgWZ.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFileDialogWZ::CFileDialogWZ(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName, DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd)
		: CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
	// VC6 MFC �ĶԻ����� WIN7 ������ʹ�� WINXP �ĶԻ���
	// ȥ�� OFN_ENABLEHOOK ���ɽ����
	m_ofn.Flags &= ~OFN_ENABLEHOOK;
	// ���� MFC ʹ�õ����ϵ� struct, ʹ�� XP/WIN7 STYLE ��Ҫ���� lStructSize �������1����Ա����
	m_ofn.lStructSize = 88;
	*(DWORD*)(((BYTE*)&m_ofn)+84) = 0;
}

int CFileDialogWZ::DoModal()
{
	// ȥ����һЩ���ǵ� ASSERTION
	ASSERT_VALID(this);
	
	// zero out the file buffer for consistent parsing later
	ASSERT(AfxIsValidAddress(m_ofn.lpstrFile, m_ofn.nMaxFile));
	DWORD nOffset = lstrlen(m_ofn.lpstrFile)+1;
	ASSERT(nOffset <= m_ofn.nMaxFile);
	memset(m_ofn.lpstrFile+nOffset, 0, (m_ofn.nMaxFile-nOffset)*sizeof(TCHAR));
	
	// WINBUG: This is a special case for the file open/save dialog,
	//  which sometimes pumps while it is coming up but before it has
	//  disabled the main window.
	HWND hWndFocus     = ::GetFocus();
	BOOL bEnableParent = FALSE;
	m_ofn.hwndOwner    = PreModal();
	if (m_ofn.hwndOwner != NULL && ::IsWindowEnabled(m_ofn.hwndOwner)) {
		bEnableParent = TRUE;
		::EnableWindow(m_ofn.hwndOwner, FALSE);
	}
	
	_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
	ASSERT(pThreadState->m_pAlternateWndInit == NULL);
	
	if (m_ofn.Flags & OFN_EXPLORER)
		pThreadState->m_pAlternateWndInit = this;
	
	int nResult;
	nResult = m_bOpenFileDialog ? ::GetOpenFileName(&m_ofn) : ::GetSaveFileName(&m_ofn);
	
	pThreadState->m_pAlternateWndInit = NULL;
	
	// WINBUG: Second part of special case for file open/save dialog.
	if (bEnableParent)
		::EnableWindow(m_ofn.hwndOwner, TRUE);
	if (::IsWindow(hWndFocus))
		::SetFocus(hWndFocus);
	
	PostModal();
	return nResult ? nResult : IDCANCEL;

}


/////////////////////////////////////////


CFontDialogWZ::CFontDialogWZ(LPLOGFONT lplfInitial, DWORD dwFlags, CDC* pdcPrinter, CWnd* pParentWnd)
	: CFontDialog(lplfInitial, dwFlags, pdcPrinter, pParentWnd)
{
	// VC6 MFC �ĶԻ����� WIN7 ������ʹ�� WINXP �ĶԻ���
	// ȥ�� OFN_ENABLEHOOK ���ɽ����
	m_cf.Flags &= ~CF_ENABLEHOOK;
}

int CFontDialogWZ::DoModal()
{
	// ȥ����һЩ���� ASSERTION
	ASSERT_VALID(this);

	m_cf.hwndOwner = PreModal();
	int nResult = ::ChooseFont(&m_cf);
	PostModal();

	if (nResult == IDOK) {
		// copy logical font from user's initialization buffer (if needed)
		memcpy(&m_lf, m_cf.lpLogFont, sizeof(m_lf));
		return IDOK;
	}
	return nResult ? nResult : IDCANCEL;	
}
