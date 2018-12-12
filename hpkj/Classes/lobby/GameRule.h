#pragma once
#include "EntityMgr.h"
#include <string>
#include "cocos2d.h"
using namespace std;

#define		KJ_QIHAO_LENGTH		255
#define		KJ_SHIJIAN_LENGTH		255

#define IN 
#define OUT

const int delay_chqssc = 10;
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
	virtual string GetKjShjDiffDesc(int nSecond = 60);
	//�Ƿ�ɳ���-�뿪��ʱ�����������
	virtual bool IsCanCancel(string qihao);
	//��ȡÿ��ʱ����,������ʱʱ�ʣ���ʱ��5���ӣ���ʱ��10���ӡ�
	virtual long GetQiSpan();
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

////////////////////////////////////////////////////////////
//������
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
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();

	string GetFdShjDiffDesc();

	bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

private:
	int timespan_fd_shj;
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
	long GetFdShjDiff();
	string GetFdShjDiffDesc();

	bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

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
	bool IsCanCancel(string qihao);
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();

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
	bool IsCanCancel(string qihao);
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();

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
	bool IsCanCancel(string qihao);
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();

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
	bool IsCanCancel(string qihao);
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();

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
	bool IsCanCancel(string qihao);
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();

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
	bool IsCanCancel(string qihao);
	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();

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

	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();
	//�Ƿ���Գ���
	bool IsCanCancel(string qihao);
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



class CFC3DPL3Rule : public CGameRule
{
public:
	CFC3DPL3Rule(void);
	virtual ~CFC3DPL3Rule(void);

public:
	//�����ں�
	virtual string GetNextExpect(int nDelta = 0);
	//���ڿ���ʱ��
	virtual time_t GetNextKjShj();

	//���´ηⵥʱ�仹ʣ�µ�ʱ��
	long GetFdShjDiff();
	//�Ƿ���Գ���
	bool IsCanCancel(string qihao);
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