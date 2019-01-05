#ifndef __Game__FishKindScrollView__aa__
#define __Game__FishKindScrollView__aa__
#include "CocosUnits.h"
#include "ConfigMgr.h"
#include "AnsString.h"
#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"


USING_NS_CC;
USING_NS_CC_EXT;
//using namespace ui;

class FishKindScrollView : public Layer,TableViewDataSource,TableViewDelegate 
{
    
public:
    FishKindScrollView();
    ~FishKindScrollView();
    virtual bool init();
    CREATE_FUNC(FishKindScrollView);

	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view);
	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view);

	//触摸事件 计算的是点击的是那个子页
	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell);
	//每一项的高度和宽度
	virtual cocos2d::Size cellSizeForTable(cocos2d::extension::TableView *table);
	//生成列表的每一项内容
	virtual TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx);
	//一共多少项
	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table);

public:
    void onEnter();
    void onExit();
    bool onTouchBegan(Touch *pTouch, Event *pEvent);
    void onTouchMoved(Touch *pTouch, Event *pEvent);
    void onTouchEnded(Touch *pTouch, Event *pEvent);
    void onTouchCancelled(Touch *pTouch, Event *pEvent);

private:
	void setFishScore(int index, LabelTTF* text);

private:
	int m_Count;	//总个数
	int m_length;	//一行多少个
	int m_itemHeigth;	
	int m_itemWidth;
	int m_pandingX;		//x 间距
	int m_pandingY;

	TableView* m_table;
};
#endif  //__Game__HelpScrollView__