#ifndef REGISTRY_H_THHYL_
#define REGISTRY_H_THHYL_

LONG WriteKey(const void* lpInData,
			  HKEY hKey,
			  LPCTSTR lpSubKey,
			  LPCTSTR lpValue,
			  DWORD dwType=REG_SZ,
			  DWORD cbData=0);

LONG ReadKey(HKEY hKey,
			 LPCTSTR lpSubKey,
			 LPCTSTR lpValue,
			 void* lpOutData);

/***
*DeleteSubKeyTree(HKEY hKey, LPCTSTR lpSubKey)
* ����: �ݹ�ɾ��ע����Ӽ�
* ��ڣ�
*      hKey :  һ��HEKY���͵Ĳ���������HKEY_CLASSES_ROOT
*      lpSubKey:������".exe"
* ����: �ɹ�ɾ��������ERROR_SUCCESS,ʧ���򷵻�һ����0ֵ��
*
* ʵ��:        LPCTSTR lpSubKey= "shile";
HKEY hKey = HKEY_CLASSES_ROOT;
long ret;
ret = DeleteSubKeyTree(hKey, lpSubKey);
if (ret == ERROR_SUCCESS)
{
SetDlgItemText(IDC_STATIC, "ɾ���Ӽ�HKEY_CLASSES_ROOT\\shile�ɹ�");
}
*     
**************************************************/
LONG DeleteSubKeyTree(HKEY hKey, LPCTSTR lpSubKey);

LONG SetAssociation(LPCTSTR FileExt,      // ��չ��, ���� ".foo"
					LPCTSTR FileTypeKey,  // �ļ����ͼ����������һ��������ͻ�ͺã����� "my_foofile"
					LPCTSTR FileTypeName, // �ļ��������������������ļ����ͣ�����Դ����������Կ��������硰�ҵ�ĳĳ�ļ����͡�
					LPCTSTR ExePath,      // ����Ŀ�꣬һ���� EXE �ļ�������·��
					LPCTSTR Parameters,   // ���� EXE �ļ�����Ĳ���
					int nDefaultIcon=0,   // �ļ�����ͼ��ID��ExePath �����ţ��� 0 ��ʼ��
					BOOL bForUser=FALSE   // TRUE: For Current User, FALSE: For All Users
);

LONG DeleteAssociation(LPCTSTR FileExt, BOOL bForUser=FALSE);

#endif // REGISTRY_H_THHYL_
