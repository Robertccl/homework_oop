#include "ElvatorSimulation.h"



ElvatorSimulation::ElvatorSimulation()
{
}


ElvatorSimulation::~ElvatorSimulation()
{
}


void ElvatorSimulation::setMaxCarryMen(int carryCapacity)
{
	this->myElvator.setMaxCarryMen(carryCapacity);
}



//���ݷ����ʼ��
void ElvatorSimulation::simulationInit(int maxcarrier, int initPersonNum, int totalTime)    //��ӦҪ�������k, n, m
{
	setMaxCarryMen(maxcarrier);
	this->customerNum = initPersonNum;
	this->totalSimulationTime = totalTime;

	personHeader = new person[customerNum];
	for (int i = 0; i < customerNum; i++)
	{
		personHeader[i].belongingNeedSpace = 0;
		personHeader[i].waitFloor = 1;
		personHeader[i].distFloor = myUtil.random(1, 40);
		personHeader[i].waitElvatorNum;
	}

	int InitFloor = 0;
	for (int i = 0; i < 10; i++)
	{
		//this->maxCarryMen = defaultCarryNum;
		this->myElvator.elevators[i].linkageFlag = false;
		this->myElvator.elevators[i].elevatorCarryMen = 0;
		InitFloor = myUtil.random(1, 40);
		if (myElvator.canArrive(i, InitFloor))
		{
			this->myElvator.elevators[i].stopFloor = InitFloor;
			this->myElvator.elevators[i].distFloor = InitFloor;
			this->myElvator.elevators[i].currentFloor = InitFloor;
		}
	}

}
//���ݷ��濪ʼ
void ElvatorSimulation::simulationStart()
{

}
