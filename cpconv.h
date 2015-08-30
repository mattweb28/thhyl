#ifndef __CPCONV_H__5387D040_
#     define __CPCONV_H__5387D040_

// Win32 Codepage conversion functions

#include <windows.h>

/*
 * outSizeW: ��ȡת����ĳ��ȣ����ջ�ΪNULL�򲻻�ȡ�����Ȱ���\0
 * cbMultiByte: Ҫת�����ַ������ȡ�
 *		-1 ��ʾ \0 ��ֹ������ֻת��ָ�����ȵ��ֽڡ�
 *		������Σ�ת����� Unicode �ַ������ǿ���ֹ�ġ�
 * HINT: ����ֵ����new�����LPWSTR�������˱�����delete��
 */
LPWSTR Ansi2Unicode(LPCSTR lpszSrc, UINT CodePage, int* outSizeW, int cbMultiByte);

LPSTR Unicode2Ansi(LPCWSTR lpszSrcW, UINT CodePage, size_t *outSize, BOOL* bUsedDefaultChar);

#endif /* __CPCONV_H__5387D040_ */
