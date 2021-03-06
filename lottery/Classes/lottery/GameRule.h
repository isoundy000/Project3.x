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
	//下期期号
	virtual string GetNextExpect(int nDelta=0) = 0;
	//下期开奖时间
	virtual time_t GetNextKjShj() = 0;
	//离下次开奖时间还剩下的时间
	virtual long GetKjShjDiff();
	//离下次开奖时间还剩下的时间-字符串描述		五分彩传30	分分彩传10
	virtual string GetKjShjDiffDesc();
	//是否可撤单-离开奖时间大于两分钟
	virtual bool IsCanCancel(string qihao);
	//获取每期时间间隔,像重庆时时彩，有时候5分钟，有时候10分钟。
	virtual long GetQiSpan();

	//add by hd
	CC_SYNTHESIZE(int, fenDanDuration, FenDanDuration);
	CC_SYNTHESIZE(int, isStopSell,IsStopSell);

	int  m_nStartQihao;      //开始的期号
	time_t	m_tStartTime;	//开始的时间

	//是否在封单时间内
	bool IsFenDanDuration();

	//设置初始期号
	void SetStartQiHao(int value);
	//设置初始时间
	void SetStartTime(const char* value);
};

//////////////////////////////////////////////////////
class CChqSSCRule : public CGameRule
{
public:
	CChqSSCRule(void);
	virtual ~CChqSSCRule(void);

public:
	//下期销售期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();

	virtual bool IsCanCancel(string qihao);

	//获取每期时间间隔,像重庆时时彩，有时候5分钟，有时候10分钟。
	virtual long GetQiSpan();
private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////////////////////////
//韩国1.5分彩
//////////////////////////////////////////////////////////////////////////
class CHgydwfcRule : public CGameRule
{
public:
	CHgydwfcRule(void);
	virtual ~CHgydwfcRule(void);

public:
	//下期销售期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();

	//获取每期时间间隔,像重庆时时彩，有时候5分钟，有时候10分钟。
	virtual long GetQiSpan();
	bool IsCanCancel(string qihao);
	//virtual string GetKjShjDiffDesc(int nSecond = 60);
	void SetQihaocha(int nQihao);
	void SetStartQihao(const char* nQihao,const char* chTime);

private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
	int timespan_kj_shj;
	int timespan_ye_kj_shj;
	int nQihaocha;
};

//////////////////////////////////////////////////////////////////////////
//加拿大3.5分彩
//////////////////////////////////////////////////////////////////////////
class CCanadaSDWFRule : public CGameRule
{
public:
	CCanadaSDWFRule(void);
	virtual ~CCanadaSDWFRule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta = 0);
	//下期开奖时间
	virtual time_t GetNextKjShj();

	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();
	////是否可以撤单
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

////////////////////////////////////////////////////////////
//原江西彩 现在的天津彩
class CJxSSCRule  : public CGameRule
{
public:
	CJxSSCRule(void);
	virtual ~CJxSSCRule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj(){return GetNextFdShj();}
	//下期封单时间
	time_t GetNextFdShj();
	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();

	//string GetFdShjDiffDesc();

	//bool IsCanCancel(string qihao);
	//virtual string GetKjShjDiffDesc(int nSecond = 60);
private:
	int timespan_fd_shj;
	int timespan_kj_shj;
};


/////////////////////////////////////////////////////////
//新疆彩
class CXJSSCRule  : public CGameRule
{
public:
	CXJSSCRule(void);
	virtual ~CXJSSCRule(void);

public:
	//下期期号
	string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj(){return GetNextFdShj();}
	//下期封单时间
	time_t GetNextFdShj();
	//离下次封单时间还剩下的时间
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
	//下期销售期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();

	//获取每期时间间隔,像重庆时时彩，有时候5分钟，有时候10分钟。
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
	//下期销售期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
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
	//下期销售期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];
};

//两分彩///////////////////////////////////////////////////////
class CErFenCaiRule : public CGameRule
{
public:
	CErFenCaiRule(void);
	virtual ~CErFenCaiRule(void);

public:
	//下期销售期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	//离下次封单时间还剩下的时间
	//long GetFdShjDiff();

	//获取每期时间间隔,像重庆时时彩，有时候5分钟，有时候10分钟。
	virtual long GetQiSpan();
private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
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
	//下期销售期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();

	//获取每期时间间隔,像重庆时时彩，有时候5分钟，有时候10分钟。
	virtual long GetQiSpan();
private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

///////////////////////////////////////////////////////////////////////////
//广东11选5
class CGD11X5Rule : public CGameRule
{
public:
	CGD11X5Rule(void);
	virtual ~CGD11X5Rule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();

private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////////////////
//重庆11选5
class CCQ11X5Rule : public CGameRule
{
public:
	CCQ11X5Rule(void);
	virtual ~CCQ11X5Rule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();

private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////
//江西11选5
class CJX11X5Rule : public CGameRule
{
public:
	CJX11X5Rule(void);
	virtual ~CJX11X5Rule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();

private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//////////////////////////////////////////////////////
//黑龙江11选5
class CHlj11X5Rule : public CGameRule
{
public:
	CHlj11X5Rule(void);
	virtual ~CHlj11X5Rule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();

private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
	int m_t3_start;
	int m_t3_end;	
public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};
///////////////////////////////////////////////////////////////
//山东11选5
class CSD11X5Rule : public CGameRule
{
public:
	CSD11X5Rule(void);
	virtual ~CSD11X5Rule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//bool IsCanCancel(string qihao);
	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();

private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;	
	//时间3 22:00-24:00
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
	//下期期号
	virtual string GetNextExpect(int nDelta = 0);
	//下期开奖时间
	virtual time_t GetNextKjShj();

	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();
	////是否可以撤单
	//bool IsCanCancel(string qihao);
private:
	//时间1 00:00-02:00
	int m_t1_start;
	int m_t1_end;
	//时间2 10:00-22:00
	int m_t2_start;
	int m_t2_end;
	//时间3 22:00-24:00
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
	//下期期号
	virtual string GetNextExpect(int nDelta = 0);
	//下期开奖时间
	virtual time_t GetNextKjShj();

	//离下次封单时间还剩下的时间
	//long GetFdShjDiff();
	////是否可以撤单
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
	//下期期号
	virtual string GetNextExpect(int nDelta = 0);
	//下期开奖时间
	virtual time_t GetNextKjShj();

	//离下次封单时间还剩下的时间
	//long GetFdShjDiff();
	////是否可以撤单
	//bool IsCanCancel(string qihao);

public:
	static char m_lastExpect[KJ_QIHAO_LENGTH];
	static char m_lastKjShj[KJ_SHIJIAN_LENGTH];

	int timespan_kj_shj;
	int timespan_ye_kj_shj;
};

//七星彩
class CQiXingCaiRule : public CGameRule
{
public:
	CQiXingCaiRule(void);
	virtual ~CQiXingCaiRule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta = 0);
	//下期开奖时间
	virtual time_t GetNextKjShj();

	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();
	////是否可以撤单
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
	//下期期号
	virtual string GetNextExpect(int nDelta=0);
	//下期开奖时间
	virtual time_t GetNextKjShj();

private:

	int timespan_kj_shj;
};

//六合彩
class LiuHeCaiRule : public CGameRule
{
public:
	LiuHeCaiRule(void);
	virtual ~LiuHeCaiRule(void);

public:
	//下期期号
	virtual string GetNextExpect(int nDelta = 0);
	//下期开奖时间
	virtual time_t GetNextKjShj();
	//设置开奖时间
	static void SetNextKjShj(int wYear,int wMonth,int wDay,int wHour,int wMinute,int wSecond,int wMilliseconds);

	////离下次封单时间还剩下的时间
	//long GetFdShjDiff();
	////是否可以撤单
	//bool IsCanCancel(string qihao);

public:
	static int m_nextExpect;  //下期期号
	static time_t m_nextKjShj; //下期开奖时间

};