#ifndef _THKEYINFO_H_WOLEGEQU
#define _THKEYINFO_H_WOLEGEQU

// key state data structures and constants for replay files(.rpy)
// of Touhou STG series: TH6, TH7, TH8, TH9
// 
// Written by wz520
// Last Updated: 2012-02-21
//

// ----------------- THKEYSTATE DETAILS -----------------------
//
// keystate ��һ�� 16bit ��
// ���е� 9bit ���ڼ�¼ĳһ֡�İ���״̬���� 7bit ��;������Ӧ��û�ã�
//
// keystate & 0x0001 != 0: shoot
// keystate & 0x0002 != 0: bomb
// keystate & 0x0004 != 0: slow
// keystate & 0x0008 != 0: pause
// keystate & 0x0010 != 0: up
// keystate & 0x0020 != 0: down
// keystate & 0x0040 != 0: left
// keystate & 0x0080 != 0: right
// keystate & 0x0100 != 0: skip dialog
//
// ��ͣ����ESC �� KeyConfig �ж���� Pause ����Ҳ�ǻᱻ��¼������
// ������ESC����Ϸ��ͣ���ٰ�סESC�����Ǳ��ɿ�����Ϸ����������֮�� ESC ��״̬�ᱻ��¼����ֱ���ɿ���
// ��ע�⡿TH6 ���⡣TH6 �а� ��ͣ�� ���ᱻ��¼��'pause' λ���� 0 ��
//

// ------------------------- ���� THKEYSTATE ---------------------
// ���Ǹ� union ��������Ҫ����ֱ���� WORD w �������� keystate��
//   Ҳ������ s �ṹ�е�λ���������һ��������״̬��
typedef union tagTHKEYSTATE {
	WORD w;
	struct {
		WORD shoot  : 1;
		WORD bomb   : 1;
		WORD slow   : 1;
		WORD pause  : 1;
		WORD up     : 1;
		WORD down   : 1;
		WORD left   : 1;
		WORD right  : 1;
		WORD skip   : 1;
	}s;
}THKEYSTATE;

// macros for THKEYSTATE::w:
#define THKEYSTATE_SHOOT                        0x0001
#define THKEYSTATE_BOMB                         0x0002
#define THKEYSTATE_SLOW                         0x0004
#define THKEYSTATE_PAUSE                        0x0008
#define THKEYSTATE_UP                           0x0010
#define THKEYSTATE_DOWN                         0x0020
#define THKEYSTATE_RIGHT                        0x0040
#define THKEYSTATE_LEFT                         0x0080
#define THKEYSTATE_SKIP                         0x0100
#define th_getkeystate(keystate,key)            ((keystate) & (key))

/////////////////////////////////////////////////////////////////////////////
// KEYDATA �ṹ
//
// KEYDATA �ṹ�������ÿһ�ص� TH?_STAGEINFO �ṹ��thdecode1.h�����档
// �ýṹ��Ҫ���� keystate ����¼�������Ϸ��ĳһ֡����ĳ��֡���İ���״̬��
// ÿһ���� KEYDATA ���ݽṹ���в�ͬ����� STAGEINFO �ṹ��ƫ����Ҳ��ͬ��
// ������档
/////////////////////////////////////////////////////////////////////////////

// TH6 �� keydata �����Ǳ�ѹ�����ġ�
// �㷨���� RLE ѹ������������ͬ�� keystate������״̬�� ֻ��¼һ�Ρ�����
//   ��һ��ֵ(frame)����� keystate ����һ֡��ʼ��
// Ҳ���ǰ���״̬һ�б仯�ͻ�����µ����ݣ�û�仯�Ͳ��������
// ���⣬ÿһ�����һ�� keydata �� frame �ض�Ϊ 9999999(0x0098967F) ��
//   ���ǵ��� keydata ����Ľ�����־��ͬʱҲ����������� rpy �ļ�
//   �Ƿ�Ϸ���У���루���� 9999999 �Ͳ��ǺϷ��� TH06 RPY ����ģ���
//
// TH7 ֮���û��ѹ���ˣ�ÿһ֡����һ�鰴�����ݡ�������Ϊʹ����ר�ŵ�
//   ѹ���㷨���������� rpy �ļ�ѹ���ˣ������ļ���С�� TH6 ���
typedef struct tagTH6_KEYDATA {
    DWORD      frame;      // key state starts from which frame
    THKEYSTATE keystate;   // see description above
    WORD       u1;         // seems to be padding
}TH6_KEYDATA;
// TH6 �� keydata �� TH6_STAGEINFO �ṹƫ�� 0x10 ����ʼ��
// ���Ǹô��� frame �� keystate ��Ա���� 0 ��
//   �ô�ȷʵ�� keydata ���ڸô����ڴ�ϵ����µ�λ������漸�� keydata ��ͬ����
//   ������������ڸùؿ�ʼʱ��ʲô������ keydata �� frame �� keystate ���� 0 ��
// �������û�õ� keydata Ӧ�ñ����ԡ�
// �������� TH6 ��������ѹ���ģ��������ǲ������������������Ժ�Ľ�ѹ����
//
// PS: ÿһ�ص����� 2 �� keydata �� frame ֵ���Ǹùص��� frame ��
static const int OFFSET_TH6KEYDATA = 0x10; 

typedef struct tagTH7_KEYDATA {
    THKEYSTATE keystate; // see description above
    WORD u1;             // seems to be padding
}TH7_KEYDATA;
// TH7 �� keydata �� TH7_STAGEINFO �ṹƫ�� 0x2C ����ʼ��
// ����ͬ���ô��� keystate ���� 0 ��
// ���� TH6 ��������� OFFSET_TH6KEYDATA ��˵��
// �������Ǻ��������ӵڶ�����ʼ
static const int OFFSET_TH7KEYDATA = 0x2C + sizeof(TH7_KEYDATA)*1; // ����1��

typedef struct tagTH8_KEYDATA {
	THKEYSTATE keystate; // see description above
}TH8_KEYDATA;
// TH8 �� keydata �� TH8_STAGEINFO �ṹƫ�� 0x24 ����ʼ��
// ����ͬ���ô��� keystate ���� 0 ��
// ���� TH6 ��������� OFFSET_TH6KEYDATA ��˵��
// �������Ǻ��������ӵڶ�����ʼ
static const int OFFSET_TH8KEYDATA = 0x24 + sizeof(TH8_KEYDATA)*1; // ����1��

typedef TH8_KEYDATA TH9_KEYDATA; // same as TH8_KEYDATA
// TH9 �� keydata �� TH9_STAGEINFO �ṹƫ�� 0x20 ����ʼ��
// ���ǡ���û�е����� :) ��ƫ�ƴ���ֵ��ȷ��¼�˵� 1 ֡�İ���״̬��
static const int OFFSET_TH9KEYDATA = 0x20;

#endif // _THKEYINFO_H_WOLEGEQU
