#include "thcommon.h"

#define lengthof(arr) (sizeof(arr)/sizeof(arr[0]))

// Ĭ�Ϲؿ������������Ϸ���� 1~6+EX��
static LPCTSTR const common_stage_names[] = {
	_T("1"), _T("2"), _T("3"), _T("4"), _T("5"), _T("6"), _T("EX")
};


void THRPYINFO_BASE::initStageNames() {
	// ��ʼ��Ĭ�Ϲؿ���
	for ( int i = 0; i < lengthof(stagenames); ++i ) {
		if ( i < lengthof(common_stage_names) ) {
			stagenames[i] = common_stage_names[i];
		}
		else {
			stagenames[i] = _T("");
		}
	}

	this->nStageNumberForHalf = -1;
}

void THRPYINFO_BASE::setStageNames(LPCTSTR const newnames[], int start, int length)
{
	for ( int i = 0; i < length; ++i ) {
		this->stagenames[i+start] = newnames[i];
	}
}



// global functions

double CalcSlowRate(BYTE* fpsData, DWORD fpsDataSize)
{
	DWORD normalfpssum = fpsDataSize*60; //�������Ӧ��ÿ��FPS����60��
	DWORD fpssum = 0;

	for (DWORD i=0; i<fpsDataSize; ++i)
		fpssum += (DWORD)fpsData[i];

	return 100.00 - ((double)fpssum)/((double)normalfpssum)*100.00;
}

