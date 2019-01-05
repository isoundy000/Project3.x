﻿#include "RoomLayer.h"
#include "ChongQingBetArea.h"
#include "VersionControl.h"

using namespace cocos2d;
ChongQingBetArea::ChongQingBetArea()
{
	winSize = Director::getInstance()->getWinSize();
	betZhuShu = 1;
	areaBkHeight = 40;
	ballRadius = BALL_RADDIUS;
	ballGapX = (SCREEN_WIDTH - 34 * 2 - ballRadius*7.0) / 6.0;
	ballStartX = 34 + ballRadius / 2;//ballGapX+ballRadius/2;
	areaTitlePosX = 67;//42;
	areaGapY = 15;
	areaHeight = ballRadius*2+areaBkHeight+4*areaGapY;
	areaMenuPosX = 330;
	fontSize = 27;
	this->addRandSeed();
}

ChongQingBetArea::~ChongQingBetArea()
{

}

String *ChongQingBetArea::getBetNumber()
{
	return String::createWithFormat("%s","ChongQingBetArea");
}

void ChongQingBetArea::clearNumbers()
{
	CCLOG("ChongQingBetArea::clearNumbers");
}

void ChongQingBetArea::createRandomNumbers()
{
	CCLOG("ChongQingBetArea::createRandomNumbers");
}

void ChongQingBetArea::addRandSeed()
{
	timeval psv;	
	gettimeofday(&psv, NULL);
	unsigned long int rand_seed = psv.tv_sec*1000+psv.tv_usec;
	srand(rand_seed);
}

void ChongQingBetArea::setBetKind(SSCWanFaKind kind)
{
	CCLOG("ChongQingBetArea::setBetKind");
}

int ChongQingBetArea::combo(int base, int up)
{
	//此方案容易溢出
	//return factorial(base)/(factorial(up)*factorial(base-up));
	int tempUp = factorial(up);
	int tempInt = 1;
	for(int i = 0;i < up;i ++)
	{
		tempInt *= base - i;
	}
	return tempInt / tempUp;
}

int ChongQingBetArea::factorial(int number)
{
	int total = 1;
	for(int i = 1 ; i <= number; i++){
		total *= i;
	}
	return total;
}

int ChongQingBetArea::heZhiZhuShu(int heZhi)
{
	int totalNum = 0;
	for(int i = 0 ; i <= 9 ; i++){
		for(int j = 0 ; j <= 9 ; j++){
			for(int k = 0 ; k <= 9 ; k++){
				if(i+j+k == heZhi){
					totalNum++;
				}
			}
		}
	}
	return totalNum;
}