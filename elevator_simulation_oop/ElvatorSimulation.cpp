#include "ElvatorSimulation.h"
#include <process.h>


ElvatorSimulation::ElvatorSimulation()
{
	ps = PassengerSimulation::getInstance();
}


ElvatorSimulation::~ElvatorSimulation()
{
	myUtil = NULL;
}

//设定每个电梯的乘坐人数
void ElvatorSimulation::setMaxCarryMen(int elvatorNum, int carryCapacity)
{
	myElvator[elvatorNum].setMaxCarryMen(carryCapacity);
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
		if (myUtil->canArrive(i, initFloor))
		{
			myElvator[i].elevator.stopFloor = initFloor;   
			myElvator[i].elevator.distFloor =  initFloor;
			myElvator[i].elevator.currentFloor =  initFloor;
		}
	}

	//this->customerNum = initPersonNum;
	this->totalSimulationTime = totalTime;

	//初始化仿真开始时的乘客
	ps->initPassengerSimulation(initPersonNum);
	//给初始化好的每一个乘客分配要等待的电梯
	int k = 0;   //引入k可以使每次分配电梯时从上一次分配结束的位置开始，不会每一次都分配给前面的电梯
	Passenger temp;
	while(!ps->simulatingPassengers.empty())
	{
		temp = ps->simulatingPassengers.front();
		myUtil->canTakeFloor(1, temp.getDstFloor());
		if (k >= 10)
		{
			k = 0;
		}
		for (int j = k; j < 10; j++)
		{
			if (myUtil->elevatorFlag[j])
			{
				temp.setWaitElvatorNum(j);
				k = j + 1;
				if (myElvator[j].elevator.currentFloor < temp.getWitFloor())
					myElvator[j].elevator.runningDirectionFlag = true;
				myElvator[j].addWaitingCustommer(temp);
				ps->simulatingPassengers.pop_front();
				break;
			}
		}
		k++;
	}
}

//电梯仿真开始
void ElvatorSimulation::simulationStart()
{
	Passenger temp;
	int timeclock = 0;
	int tmpElevator = 0;
	int tmpFloor = 0;
	while (1)
	{
		if (ps->simulatedPassengers.size() == ps->customerNum)
			break;
		for (int i = 0; i < 10; i++)
		{
			tmpElevator = i;
			tmpFloor = myElvator[i].elevator.currentFloor;
			cout << "-------------电梯编号: " << i << "----------------" << endl;
			if (myUtil->canArrive(tmpElevator, tmpFloor))
				myElvator[i].run();
			else
				myElvator[i].goon();

			temp =  ps->initPassengerforNext();
			if (!temp.isNone())
			{
				myUtil->canTakeFloor(temp.getWitFloor(), temp.getDstFloor());
				for (int j = 0; j < 10; j++)
				{
					if (myUtil->elevatorFlag[j])
						temp.setWaitElvatorNum(j);
					myElvator[j].addWaitingCustommer(temp);
				}
			}
				
			Sleep(500);
		}
		system("cls");
		Sleep(1000);
	}
	cout << "电梯仿真结束！！！" << endl;
}

