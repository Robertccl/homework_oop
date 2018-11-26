#include "MyElvator.h"



MyElvator::MyElvator()
{
}


MyElvator::~MyElvator()
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
