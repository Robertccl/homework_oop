#include "MyElvator.h"



MyElvator::MyElvator()
{
}


MyElvator::~MyElvator()
{
}


void MyElvator::setMaxCarryMen(int carryCapacity)
{
	this->maxCarryMen = carryCapacity;
}


//电梯仿真初始化
void MyElvator::simulationInit()
{
	for (int i = 0; i < 10; i++)
	{
		//this->maxCarryMen = defaultCarryNum;
		this->linkageFlag[i] = false;
		this->elevatorCarryMen[i] = 0;

	}

}
//电梯仿真开始
void MyElvator::simulationStart()
{

}


//电梯运行规则
bool MyElvator::canArrive(int elevatorNum, int floorNum)
{
	if (floorNum > 0 && floorNum < 41)
	{
		if (elevatorNum == 0 || elevatorNum == 1)
			return true;
		else if (elevatorNum == 2 || elevatorNum == 3)
		{
			if (floorNum < 2 || floorNum > 24)
				return true;
		}
		else if (elevatorNum == 4 || elevatorNum == 5)
		{
			if (floorNum > 0 && floorNum < 26)
				return true;
		}
		else if (elevatorNum == 0 || elevatorNum == 1)
		{
			if (floorNum < 2 || floorNum%2 == 0)
				return true;
		}
		else if (elevatorNum == 0 || elevatorNum == 1)
		{
			if (floorNum%2 == 1)
				return true;
		}
		else
			return false;
	}
	else
		return false;
	return false;
}
