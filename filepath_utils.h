#ifndef __FILEPATH_UTILS_H__55DD7E27_
#     define __FILEPATH_UTILS_H__55DD7E27_

namespace filepath_utils {

CString& ChangeFileExtension(CString& inoutFilePath, LPCTSTR Extension);
CString& ChangeFilename(CString& inoutFilePath, LPCTSTR filename);
CString& GetFilename(const CString& inFilePath, CString& outFilename);
CString& GetDir(const CString& inFilePath, CString& outDirname, bool bIncludeLastBackSlash=true);
CString& GetBasename(const CString& inFilePath, CString& outFilename);

// ������Է�б�ܽ�β����ӷ�б��
CString& AddDirBkSlash(CString& str);

}

// ----- �� CString �������� ------

// ʹ��·���ָ�������CString
CString& operator /= (CString& lhs, const CString& rhs);
CString operator / (const CString& lhs, const CString& rhs);


#endif /* __FILEPATH_UTILS_H__55DD7E27_ */
