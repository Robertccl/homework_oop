#include "ElvatorSimulation.h"



ElvatorSimulation::ElvatorSimulation()
{
	
}


ElvatorSimulation::~ElvatorSimulation()
{
}


void ElvatorSimulation::setMaxCarryMen(int carryCapacity)
{
	myElvator.setMaxCarryMen(carryCapacity);
}



//���ݷ����ʼ��
void ElvatorSimulation::simulationInit(int maxcarrier, int initPersonNum, int totalTime)    //��ӦҪ�������k, n, m
{
	setMaxCarryMen(maxcarrier);
	//this->customerNum = initPersonNum;
	this->totalSimulationTime = totalTime;

	personSimulation.initPersonSimulation(initPersonNum);

	int InitFloor = 0;
	for (int i = 0; i < 10; i++)
	{
		//this->maxCarryMen = defaultCarryNum;
		myElvator.elevators[i].linkageFlag = false;
		myElvator.elevators[i].elevatorCarryMen = 0;
		InitFloor = myUtil->random(1, 40);
		if (myElvator.canArrive(i, InitFloor))
		{
			myElvator.elevators[i].stopFloor = InitFloor;
			myElvator.elevators[i].distFloor = InitFloor;
			myElvator.elevators[i].currentFloor = InitFloor;
		}
	}

}
//���ݷ��濪ʼ
void ElvatorSimulation::simulationStart()
{

}
