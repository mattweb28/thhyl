#ifndef __COMMONDLGWZ_H__55CFEA95_
#     define __COMMONDLGWZ_H__55CFEA95_

// written by wz520. need MFC
//
// ������һЩ MFC �����Ի�������ࡣ���ڽ�� MFC �����Ի����� WIN7 ���޷���ʾ�� WIN7 STYLE ������

class CFileDialogWZ : public CFileDialog
{
public:
	CFileDialogWZ(BOOL bOpenFileDialog,
		LPCTSTR lpszDefExt = NULL, LPCTSTR lpszFileName = NULL, DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL, CWnd* pParentWnd = NULL );

	int DoModal();
};

class CFontDialogWZ : public CFontDialog
{
public:
	CFontDialogWZ(LPLOGFONT lplfInitial = NULL, DWORD dwFlags = CF_EFFECTS | CF_SCREENFONTS, CDC* pdcPrinter = NULL, CWnd* pParentWnd = NULL );
	
	int DoModal();
};


#endif /* __COMMONDLGWZ_H__55CFEA95_ */
