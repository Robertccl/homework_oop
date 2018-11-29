#include "ElvatorSimulation.h"



ElvatorSimulation::ElvatorSimulation()
{
	
}


ElvatorSimulation::~ElvatorSimulation()
{
}

//�趨ÿ�����ݵĳ�������
void ElvatorSimulation::setMaxCarryMen(int elvatorNum, int carryCapacity)
{
	myElvator[elvatorNum].setMaxCarryMen(carryCapacity);
}



//���ݷ����ʼ��
void ElvatorSimulation::simulationInit(int maxcarrier, int initPersonNum, int totalTime)    //��ӦҪ�������k, n, m
{
	
	//this->customerNum = initPersonNum;
	this->totalSimulationTime = totalTime;

	passengerSimulation.initPassengerSimulation(initPersonNum);

	int InitFloor = 0;
	for (int i = 0; i < 10; i++)
	{
		//this->maxCarryMen = defaultCarryNum;
		myElvator[i].elevator.linkageFlag = false;
		myElvator[i].elevator.elevatorCarryMen = 0;
		myElvator[i].setMaxCarryMen(maxcarrier);
		InitFloor = myUtil->random(1, 40);
		if (canArrive(i, InitFloor))
		{
			myElvator[i].elevator.stopFloor = InitFloor;
			myElvator[i].elevator.distFloor = InitFloor;
			myElvator[i].elevator.currentFloor = InitFloor;
		}
	}

}

//���ݷ��濪ʼ
void ElvatorSimulation::simulationStart()
{

}

//�ж�ȥĳ��¥����Գ����ĵ��ݱ��   elevatorFlagΪ10��bool���ͣ���ʼֵΪfalse
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


//�������й���
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
