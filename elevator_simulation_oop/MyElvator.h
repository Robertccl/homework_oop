#pragma once

#include "MyUtil.h"

typedef struct elevatorNode
{
	
	bool linkageFlag;      //联动标志, 0-9每个电梯对应自己的标志，电梯两两一组，共五组，false表示没有接客任务
	int elevatorCarryMen;   //电梯当前人数
	int stopFloor;           //电梯在没任务时停的楼层
	int distFloor;           //电梯接客的目的楼层，即客人等待电梯的楼层
	int currentFloor;          //电梯当前所在的楼层
}elevator;




class MyElvator
{
public:
	MyElvator();
	~MyElvator();

	void setMaxCarryMen(int carryCapacity);



public:
	//电梯运行规则
	bool canArrive(int elevatorNum, int floorNum);

	void canTakeFloor(int floorNum, bool *elevatorFlag);



public:
	const int defaultCarryNum = 16;

	MyUtil* myUtil = MyUtil::getInstance();

public:
	elevator elevators[10];     //10台电梯

	int maxCarryMen;           //最大载客量

	
};

