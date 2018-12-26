#pragma once

#include "MyElvator.h"
#include "PassengerSimulation.h"



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

	void setMaxCarryMen(int elvatorNum, int carryCapacity);

	//初始化十部电梯能乘坐的标志，默认都不能
	void initElevatorFlag();

	//电梯运行规则   偷懒写在这里
	bool canArrive(int elevatorNum, int floorNum);

	//判断去某个楼层可以乘坐的电梯编号   elevatorFlag为10个bool类型，初始值为false
	void canTakeFloor(int floorNum, bool *elevatorFlag);




private:


	//题目中的十部电梯，其实可以手动输入电梯的数量，然后在专门建立一个类写电梯运行规则，
	//这样设计更便于扩展，但是题目没有要求，就偷懒吧
	MyElvator myElvator[10];

	//对应的十部电梯的时候能乘坐的标志
	bool elevatorFlag[10];

	int totalSimulationTime;     //总共的仿真时间

	//int customerNum;             //仿真时间内出现的顾客
	PassengerSimulation passengerSimulation;
	
};

