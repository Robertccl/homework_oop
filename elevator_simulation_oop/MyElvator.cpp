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

//判断去某个楼层可以乘坐的电梯编号   elevatorFlag为10个bool类型，初始值为false
void MyElvator::canTakeFloor(int floorNum, bool *elevatorFlag)
{
	for (int i = 0; i < 10; i++)
		elevatorFlag[i] = false;
	if (floorNum > 0 && floorNum <= 40)
	{
		elevatorFlag[0] = true;
		elevatorFlag[1] = true;
		if (floorNum == 1)
		{
			elevatorFlag[2] = true;
			elevatorFlag[3] = true;
			elevatorFlag[4] = true;
			elevatorFlag[5] = true;
			elevatorFlag[8] = true;
			elevatorFlag[9] = true;
		}
		if (floorNum >= 25 && floorNum <= 40)
		{
			elevatorFlag[2] = true;
			elevatorFlag[3] = true;
		}
		if (floorNum > 1 && floorNum <= 25)
		{
			elevatorFlag[4] = true;
			elevatorFlag[5] = true;
		}
		if (floorNum % 2 == 0)
		{
			elevatorFlag[6] = true;
			elevatorFlag[7] = true;
		}
		if (floorNum % 2 == 1)
		{
			elevatorFlag[8] = true;
			elevatorFlag[9] = true;
		}
	}
	
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
