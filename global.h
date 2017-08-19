#ifndef global_h_thhyl_headerguard_SHENMADE_ZUI_TAOYAN_LE
#define global_h_thhyl_headerguard_SHENMADE_ZUI_TAOYAN_LE

LPCTSTR const g_title = _T("������ӳ¼");

extern LPCTSTR g_exefullpath;

inline LONG PointToLogical(int lPoint, CDC* dc)
{
	return -MulDiv(lPoint, dc->GetDeviceCaps(LOGPIXELSY), 72);
}
inline LONG PointToLogical(int lPoint, HDC hdc)
{
	return -MulDiv(lPoint, ::GetDeviceCaps(hdc, LOGPIXELSY), 72);
}
inline int LogicalToPoint(LONG lfHeight, HDC hdc)
{
	return MulDiv(-lfHeight, 72, ::GetDeviceCaps(hdc, LOGPIXELSY));
}
inline bool IsKeyDown(int vKey)
{
	return (GetAsyncKeyState(vKey) & 0x8000) ? true : false;
}

void LoadEditCtrlFont(CEdit*);
void SaveEditCtrlFont(CEdit* pEdit, LOGFONT* pLogFont);

//������֮��Ҫִ��UpdateData(FALSE);
void ComboSel2Edit(CComboBox& cb, UINT& uEdit);

void Edit2ComboSel(UINT uEdit, CComboBox& cb);
void ComboAddString(CComboBox& cb, UINT CodePage);

//����ֵ��ָ��̬�ڴ��LPCTSTR������ free() �� delete!
LPCTSTR GetErrorMessage(UINT ErrorCode);

// ��� RPY �ļ���С
BOOL CheckRPYFileSize(HANDLE hFile, HWND hwnd);



BOOL DumpBinData(const BYTE* pData, DWORD nSize, LPCTSTR szFilename);

// ��ȡ UTF-16LE with BOM �����ļ���ָ����
BOOL ReadUnicodeFileLine(LPCTSTR filename, int linenum, CString &outStrLine);
LPWSTR ReadLineW(LPWSTR s, int linenum);

CString LoadNotRpyString();

// lEnable = 1:on, 0:off, -1:toggle
// return GetLastError()
LONG EnableMaximize(HWND hwnd, LONG lEnable);


// ��������� SetControlFontSize() �� dwFlags ����
#define SCFS_INCREMENTAL			(0x01)  // �� n ����һ���������������С = ԭ�����С + n
#define SCFS_KEEPOLDHFONT			(0x02)  // ��Ҫ DeleteObject() ԭ���� HFONT
// ��� pOutLogFont ��Ϊ NULL�������µ� LOGFONT
BOOL SetControlFontSize(HWND hwnd, int n, LOGFONT* pOutLogFont, DWORD dwFlags=0);
BOOL SetControlFontSize(CWnd* pWnd, int n, LOGFONT* pOutLogFont, DWORD dwFlags=0);

DWORD simple_random();

#endif // global_h_thhyl_headerguard_SHENMADE_ZUI_TAOYAN_LE
