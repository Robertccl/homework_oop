#pragma once

#include "MyElvator.h"
#include "PersonSimulation.h"



class ElvatorSimulation
{
public:
	MyUtil* myUtil = MyUtil::getInstance();

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

	//int customerNum;             //仿真时间内出现的顾客
	PersonSimulation personSimulation;
	
};

