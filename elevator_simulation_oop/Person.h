#pragma once
#include "MyUtil.h"


class Person
{
public:
	Person();
	~Person();

	void setWitFloor(int waitFloor);
	int getWitFloor();

	void setDstFloor(int distFloor);
	int getDstFloor();

	void setBlongingNeedSpace(int belongingNeedSpace);
	int getBlongingNeedSpace();

	void setWitElvatorNum(int waitElvatorNum);
	int getWitElvatorNum();



public:
	void init();

public:
	MyUtil* myUtil = MyUtil::getInstance();


private:
	int waitFloor;            //客人等待电梯的楼层
	int distFloor;              //客人要去往的楼层
	int belongingNeedSpace;      //客人携带的随身物品占用的空间
	int waitElvatorNum;           //客人要等的电梯，即接客的电梯
};

