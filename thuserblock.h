#ifndef __THUSERBLOCK_H__537E773A_
#     define __THUSERBLOCK_H__537E773A_

#include "thcommon.h"

// Touhou replay file's userblock management class for
// TH8, TH9, TH95, TH10, TH11, TH12, TH125, TH128, TH13, TH14, alcostg, TH143
//
// written by wz520
// Last Update: 2015-08-17

enum RPYUBID {
	ubid_info,
	ubid_comment
};

struct RPYUBHeader {
	DWORD marker; // must be 'USER'
	DWORD length;

	// 0=rpyinfo, 1=comment
	// NOTE: only the first byte(8 bits) is used.
	// RPYUBID is defined as enum to ensure that sizeof(RPYUBHeader) == 12
	RPYUBID id : 8;
};

// ����һ�� UserBlock
class RPYUserBlock {
public:
	// pData �ᱻ����
	RPYUserBlock(const BYTE* pData, size_t datasize, RPYUBID id);
	RPYUserBlock(const RPYUBHeader* pHeader);
	~RPYUserBlock();

	const RPYUBHeader* getHeader() const { return m_pHeader; }
	const BYTE* getRaw() const { return (const BYTE*)m_pHeader; }
	// to get rawsize, use getHeader()->length;
	const BYTE* getData() const { return this->getRaw() + sizeof(RPYUBHeader); }
	DWORD getDataSize() const { return m_pHeader->length - sizeof(RPYUBHeader); }
	bool isValid() const { return m_pHeader->length >= sizeof(RPYUBHeader); }

private:
	void init(const BYTE* pData, size_t datasize, RPYUBID id);

	RPYUBHeader* m_pHeader;
};


// �� rpy �ļ���ȡ UserBlock ���ݲ����й���������ӡ�ɾ���������ȵ�...
// NOTE: Ŀǰ���ֻ�ܴ��� MAXUSERBLOCKCOUNT �� UserBlock ��
// ���з����� index ����������ϣ� 0 <= index < MAXUSERBLOCKCOUNT ��
#define MAXUSERBLOCKCOUNT 10

class RPYUserBlockMgr {
public:
	RPYUserBlockMgr();

	// pData ����ָ�� rpy �ļ����ݡ�
	// �ڲ�ֻ�洢 UserBlock ������ݣ�����洢�������ݡ�
	RPYUserBlockMgr(const BYTE* pRPYData, size_t sz);

	// ��������
	RPYUserBlockMgr(const RPYUserBlockMgr &other);

	~RPYUserBlockMgr();
	
	// �������� block ��һ�� rpy �ļ����ݿ��С�
	// ��ע�⡿��rpy �ļ���ԭ�е� user block �ᱻȫ�����ǣ�
	// ����ʹ�� malloc() ��������ڴ棬��������Ҫʹ�� free() �ͷŷ��ص�ָ�롣
	// ��� pRPYData ������ݲ��ǺϷ��� TH8+ rpy������ NULL��
	BYTE* saveToRPY(const BYTE* pRPYData, size_t sz, size_t* pNewSize);
	
	bool append(const RPYUserBlock* pBlock);
	bool remove(int index);

	// ���ص�ָ�������ͷţ������������� RPYUserBlockMgr �����ͷţ��򲻿���ʹ�á�
	// ���޷���ȡ������ NULL
	const RPYUserBlock* get(int index) const;
	
	// �����µ� userblock ��ָ����λ���ϡ�
	// ����޷����ã����� index ������Χ�������� false
	// NOTE: pBlock ���벻Ϊ NULL
	bool set(int index, const RPYUserBlock* pBlock);

	const RPYUserBlock* getFirstBlockByID(RPYUBID id) const;
	// get first info block
	const RPYUserBlock* getInfo() const { return getFirstBlockByID(ubid_info); }
	// get first comment block
	const RPYUserBlock* getComment() const { return getFirstBlockByID(ubid_comment); }

	int getFirstIndexByID(RPYUBID id) const;
	// get index of first info block, -1 if not found
	int getInfoIndex() const { return getFirstIndexByID(ubid_info); }
	// get index of first comment block, -1 if not found
	int getCommentIndex() const { return getFirstIndexByID(ubid_comment); }

	size_t size() const; // ��ȡ���� User Block �ĺϼƳ��ȣ�����ͷ�������ֽ�Ϊ��λ
	DWORD count() const;  // ��ȡ user blocks �ĸ���

	// ���� true �������������򷵻� false
	// typedef bool (*Traverser)(RPYUBID id, const BYTE* pBlock, size_t sz, void* pCustom);
	
	// int traverse(Traverser traverser, void* pCustom); // ������������ index

private:
	RPYUserBlock* newuserblock(int i, const RPYUBHeader* pHeader);
	RPYUserBlock* m_pUserBlocks[MAXUSERBLOCKCOUNT];
};

#endif /* __THUSERBLOCK_H__537E773A_ */
