#ifndef __RPYINFO_USERBLOCK_H__55D1958B_
#     define __RPYINFO_USERBLOCK_H__55D1958B_

// ��ȡ userblock �е� REP ժҪ��Ϣ �� REP ע�͡�
//
// �� thuserblock ��ͬ���ǣ���ģ���ת�룬�������յ����(thuserblock ���ڵײ�ģ�飩
//
// ע������ķ���������ĸ����Сд��


#include "StdAfx.h"

#include "thcommon.h"
#include "thuserblock.h"


class CRpyInfoUserBlock{
public:
	// isCNVer ֻ���� th8
	CRpyInfoUserBlock(const RPYUserBlockMgr* pUBMgr, RPYMGC header, UINT codepage, BOOL isCNVer);
	~CRpyInfoUserBlock();

	int analyze();

	// ���ʧ�ܣ����ؿ��ַ���
	CString getComment(UINT codepage);
	CString getSummary() {return m_info;}
	
private:
	int GetUBRpyInfo();

	RPYUserBlockMgr* m_pUBMgr;
	RPYMGC m_header;
	UINT m_codepage;
	BOOL m_isCNVer;
	CString m_info;
};

#endif /* __RPYINFO_USERBLOCK_H__55D1958B_ */
