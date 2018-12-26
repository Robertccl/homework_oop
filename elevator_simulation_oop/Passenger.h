#pragma once
#include "MyUtil.h"


class Passenger
{
public:
	Passenger();
	~Passenger();

	void setWitFloor(int waitFloor);
	int getWitFloor();

	void setDstFloor(int distFloor);
	int getDstFloor();

	void setBlongingNeedSpace(int belongingNeedSpace);
	int getBlongingNeedSpace();

	void setWaitElvatorNum(int waitElvatorNum);
	int getWaitElvatorNum();

	void setWaitTimeforNext();
	int getWaitTimeforNext();



public:
	void init();

public:
	MyUtil* myUtil = MyUtil::getInstance();


private:
	int waitFloor;            //客人等待电梯的楼层
	int distFloor;              //客人要去往的楼层
	int belongingNeedSpace;      //客人携带的随身物品占用的空间
	int waitElvatorNum;           //客人要等的电梯，即接客的电梯
	int takingtimes;             //客人要乘坐电梯的次数，文档中的要求乘坐L次，第L+1次回到一层，这个变量包含第L+1次
	int waitTimeforNext;          //完成一次乘梯活动后，休息的时间，即两次乘梯之间的间隔，随机产生
};

