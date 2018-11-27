#pragma once

#include "MyElvator.h"
#include "MyUtil.h"


typedef struct personNode
{
	int waitFloor;            //客人等待电梯的楼层
	int distFloor;              //客人要去往的楼层
	int belongingNeedSpace;      //客人携带的随身物品占用的空间
	int waitElvatorNum;
}person;

class ElvatorSimulation
{
public:
	MyUtil myUtil;

public:
	ElvatorSimulation();
	~ElvatorSimulation();


public:
	//电梯仿真初始化
	void simulationInit(int maxcarrier, int initPersonNum, int totalTime);
	//电梯仿真开始
	void simulationStart();

	void setMaxCarryMen(int carryCapacity);


private:

	MyElvator myElvator;

	int totalSimulationTime;     //总共的仿真时间

	int customerNum;             //仿真时间内出现的顾客

	person* personHeader;
};

