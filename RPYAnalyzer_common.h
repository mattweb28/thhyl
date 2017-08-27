#ifndef __RPYINFO_COMMON_H__55D17A39_
#     define __RPYINFO_COMMON_H__55D17A39_

#include "thdecode/thdecode1.h"
#include "thdecode/thdecode2.h"

// Error value
#define RPYINFO_THHYL_CONVCODEERROR		10	// ANSI->UNICODE error

// RPYINFO::GetResultPointers() �ķ��ؽ��
// ���ڻ�ȡRPY�����������
// Ϊ�˷�ֹ����������ݣ�ָ��ָ������Ͷ��� const ��������ת�ɷ� const ��
struct RPYINFO_POINTERS {
	const THRPYINFO  *pRPYInfo1;
	const THRPYINFO2 *pRPYInfo2;
	const BYTE       *pDecompData;
	DWORD             dwDecompDataSize;
};

#endif /* __RPYINFO_COMMON_H__55D17A39_ */


