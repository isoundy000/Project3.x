#pragma once
#include "EntityMgr.h"
#include "comm.h"
#include <string>
#include "cocos2d.h"
using namespace std;

//#define		KJ_QIHAO_LENGTH		255
//#define		KJ_SHIJIAN_LENGTH		255

#define IN 
#define OUT

const int delay_chqssc = 0;
const int delay_xjssc = 0;
const int delay_wfc = 0;

class CGameRule:public Node
{
public:
	virtual ~CGameRule(void);
protected:
	CGameRule(void);
	MsgDispatch *theApp;
public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0) = 0;
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj() = 0;
	//���´ο���ʱ�仹ʣ�µ�ʱ��
	virtual long GetKjShjDiff();
	//���´ο���ʱ�仹ʣ�µ�ʱ��-�ַ�������		��ֲʴ�30	�ֲַʴ�10
	virtual string GetKjShjDiffDesc();
	//�Ƿ�ɳ���-�뿪��ʱ�����������
	virtual bool IsCanCancel(string qihao);
	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();

	//add by hd
	CC_SYNTHESIZE(int, fenDanDuration, FenDanDuration);
	CC_SYNTHESIZE(int, isStopSell,IsStopSell);

	int  m_nStartQihao;      //��ʼ���ں�
	time_t	m_tStartTime;	//��ʼ��ʱ��

	//�Ƿ��ڷⵥʱ����
	bool IsFenDanDuration();

	//���ó�ʼ�ں�
	void SetStartQiHao(int value);
	//���ó�ʼʱ��
	void SetStartTime(const char* value);
};

//////////////////////////////////////////////////////
class CChqSSCRule : public CGameRule
{
public:
	CChqSSCRule(void);
	virtual ~CChqSSCRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	virtual bool IsCanCancel(string qihao);

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////////////////////////
//����1.5�ֲ�
//////////////////////////////////////////////////////////////////////////
class CHgydwfcRule : public CGameRule
{
public:
	CHgydwfcRule(void);
	virtual ~CHgydwfcRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
	bool IsCanCancel(string qihao);
	//virtual string GetKjShjDiffDesc(int nSecond = 60);
	void SetQihaocha(int nQihao);
	void SetStartQihao(const char* nQihao,const char* chTime);

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
	int timespan_kj_shj;
	int timespan_ye_kj_shj;
	int nQihaocha;
};

//////////////////////////////////////////////////////////////////////////
//���ô�3.5�ֲ�
//////////////////////////////////////////////////////////////////////////
class CCanadaSDWFRule : public CGameRule
{
public:
	CCanadaSDWFRule(void);
	virtual ~CCanadaSDWFRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

////////////////////////////////////////////////////////////
//ԭ������ ���ڵ�����
class CJxSSCRule  : public CGameRule
{
public:
	CJxSSCRule(void);
	virtual ~CJxSSCRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj(){return GetNextFdShj();}
	//���ڷⵥʱ��
	time_t GetNextFdShj();
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

	//string GetFdShjDiffDesc();

	//bool IsCanCancel(string qihao);
	//virtual string GetKjShjDiffDesc(int nSecond = 60);
private:
	int timespan_fd_shj;
	int timespan_kj_shj;
};


/////////////////////////////////////////////////////////
//�½���
class CXJSSCRule  : public CGameRule
{
public:
	CXJSSCRule(void);
	virtual ~CXJSSCRule(void);

public:
	//�����ں�
	string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj(){return GetNextFdShj();}
	//���ڷⵥʱ��
	time_t GetNextFdShj();
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	//string GetFdShjDiffDesc();

	//bool IsCanCancel(string qihao);
private:
	int timespan_fd_shj;
};

////////////////////////////////////////////////////////////////////////
class CFenFenCaiRule : public CGameRule
{
public:
	CFenFenCaiRule(void);
	virtual ~CFenFenCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
private:	

	int timespan_kj_shj;

};

////////////////////////////////////////////////////////////////////////
class CTentcentCaiRule : public CGameRule
{
public:
	CTentcentCaiRule(void);
	virtual ~CTentcentCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];
};

////////////////////////////////////////////////////////////////////////
class CQQCaiRule : public CGameRule
{
public:
	CQQCaiRule(void);
	virtual ~CQQCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];
};

//���ֲ�///////////////////////////////////////////////////////
class CErFenCaiRule : public CGameRule
{
public:
	CErFenCaiRule(void);
	virtual ~CErFenCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

/////////////////////////////////////////////////////////////////////
class CWuFenCaiRule : public CGameRule
{
public:
	CWuFenCaiRule(void);
	virtual ~CWuFenCaiRule(void);

public:
	//���������ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

///////////////////////////////////////////////////////////////////////////
//�㶫11ѡ5
class CGD11X5Rule : public CGameRule
{
public:
	CGD11X5Rule(void);
	virtual ~CGD11X5Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////////////////
//����11ѡ5
class CCQ11X5Rule : public CGameRule
{
public:
	CCQ11X5Rule(void);
	virtual ~CCQ11X5Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////
//����11ѡ5
class CJX11X5Rule : public CGameRule
{
public:
	CJX11X5Rule(void);
	virtual ~CJX11X5Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////
//������11ѡ5
class CHlj11X5Rule : public CGameRule
{
public:
	CHlj11X5Rule(void);
	virtual ~CHlj11X5Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};
///////////////////////////////////////////////////////////////
//ɽ��11ѡ5
class CSD11X5Rule : public CGameRule
{
public:
	CSD11X5Rule(void);
	virtual ~CSD11X5Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();

private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};


//PK10:
class  CBJPK10Rule : public CGameRule
{
public:
	CBJPK10Rule(void);
	virtual ~CBJPK10Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);
private:
	//ʱ��1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//ʱ��2 10:00-22:00
	int m_t2_start;
	int m_t2_end;
	//ʱ��3 22:00-24:00
	int m_t3_start;
	int m_t3_end;
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

class CFC3DRule : public CGameRule
{
public:
	CFC3DRule(void);
	virtual ~CFC3DRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

class CPL3Rule : public CGameRule
{
public:
	CPL3Rule(void);
	virtual ~CPL3Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//���ǲ�
class CQiXingCaiRule : public CGameRule
{
public:
	CQiXingCaiRule(void);
	virtual ~CQiXingCaiRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

class CKuaiLe8Rule : public CGameRule
{
public:
	CKuaiLe8Rule(void);
	virtual ~CKuaiLe8Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta=0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

private:

	int timespan_kj_shj;
};

//���ϲ�
class LiuHeCaiRule : public CGameRule
{
public:
	LiuHeCaiRule(void);
	virtual ~LiuHeCaiRule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();
	//���ÿ���ʱ��
	static void SetNextKjShj(int wYear,int wMonth,int wDay,int wHour,int wMinute,int wSecond,int wMilliseconds);

	////���´ηⵥʱ�仹ʣ�µ�ʱ��
	//long GetFdShjDiff();
	////�Ƿ���Գ���
	//bool IsCanCancel(string qihao);

public:
	static int m_nextExpect;  //�����ں�
	static time_t m_nextKjShj; //���ڿ���ʱ��

};