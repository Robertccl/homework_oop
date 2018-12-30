#include "ElvatorSimulation.h"



ElvatorSimulation::ElvatorSimulation()
{
	
}


ElvatorSimulation::~ElvatorSimulation()
{
}

//设定每个电梯的乘坐人数
void ElvatorSimulation::setMaxCarryMen(int elvatorNum, int carryCapacity)
{
	myElvator[elvatorNum].setMaxCarryMen(carryCapacity);
}


void ElvatorSimulation::initElevatorFlag()
{
	for (int i = 0; i < 10; i++)
	{
		elevatorFlag[i] = false;
	}
}



//电梯仿真初始化
void ElvatorSimulation::simulationInit(int maxcarrier, int initPersonNum, int totalTime)    //对应要求输入的k, n, m
{
	int initFloor = 0;
	for (int i = 0; i < 10; i++)
	{
		//this->maxCarryMen = defaultCarryNum;
		myElvator[i].elevator.linkageFlag = false;
		myElvator[i].elevator.elevatorCarryMen = 0;
		myElvator[i].elevator.runFlag = false;
		myElvator[i].elevator.runningDirectionFlag = false;
		myElvator[i].setMaxCarryMen(maxcarrier);
		initFloor = myUtil->random(1, 40);
		if (canArrive(i, initFloor))
		{
			myElvator[i].elevator.stopFloor = initFloor;   
			myElvator[i].elevator.distFloor =  initFloor;
			myElvator[i].elevator.currentFloor =  initFloor;
		}
	}

	//this->customerNum = initPersonNum;
	this->totalSimulationTime = totalTime;

	//初始化仿真开始时的乘客
	passengerSimulation.initPassengerSimulation(initPersonNum);
	//给初始化好的每一个乘客分配要等待的电梯
	int k = 0;   //引入k可以使每次分配电梯时从上一次分配结束的位置开始，不会每一次都分配给前面的电梯
	for (int i = 0; i < initPersonNum; i++)
	{
		initElevatorFlag();
		canTakeFloor(passengerSimulation.passengerPtr[i].getDstFloor(), elevatorFlag);
		if (k < 10)
		{
			for (int j = k; j < 10; j++)
			{
				if (elevatorFlag[j])
					passengerSimulation.passengerPtr[i].setWaitElvatorNum(j);
				k = j;
				myElvator[j].addWaitingCustommer(passengerSimulation.passengerPtr[i]);
			}
		}
		else
		{
			k = 0;
			for (int j = k; j < 10; j++)
			{
				if (elevatorFlag[j])
					passengerSimulation.passengerPtr[i].setWaitElvatorNum(j);
				k = j;
				myElvator[j].addWaitingCustommer(passengerSimulation.passengerPtr[i]);
			}
		}	
	}
}

//电梯仿真开始
void ElvatorSimulation::simulationStart()
{
	int timeclock = 0;
	int tmpElevator = 0;
	int tmpFloor = 0;
	while (1)
	{
		for (int i = 0; i < 10; i++)
		{

			tmpElevator = i;
			tmpFloor = myElvator[i].elevator.currentFloor;
			cout << "-------------电梯编号: " << i << "----------------" << endl;
			if (canArrive(tmpElevator, tmpFloor))
				myElvator[i].run();
			else
				myElvator[i].goon();
			
		}
	}

}

//判断去某个楼层可以乘坐的电梯编号   elevatorFlag为10个bool类型，初始值为false
void ElvatorSimulation::canTakeFloor(int floorNum, bool *elevatorFlag)
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
bool ElvatorSimulation::canArrive(int elevatorNum, int floorNum)
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
			if (floorNum < 2 || floorNum % 2 == 0)
				return true;
		}
		else if (elevatorNum == 0 || elevatorNum == 1)
		{
			if (floorNum % 2 == 1)
				return true;
		}
		else
			return false;
	}
	else
		return false;
	return false;
}

