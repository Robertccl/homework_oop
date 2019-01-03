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

//�趨ÿ�����ݵĳ�������
void ElvatorSimulation::setMaxCarryMen(int elvatorNum, int carryCapacity)
{
	myElvator[elvatorNum].setMaxCarryMen(carryCapacity);
}






//���ݷ����ʼ��
void ElvatorSimulation::simulationInit(int maxcarrier, int initPersonNum, int totalTime)    //��ӦҪ�������k, n, m
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

	//��ʼ�����濪ʼʱ�ĳ˿�
	ps->initPassengerSimulation(initPersonNum);
	//����ʼ���õ�ÿһ���˿ͷ���Ҫ�ȴ��ĵ���
	int k = 0;   //����k����ʹÿ�η������ʱ����һ�η��������λ�ÿ�ʼ������ÿһ�ζ������ǰ��ĵ���
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

//���ݷ��濪ʼ
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
			cout << "-------------���ݱ��: " << i << "----------------" << endl;
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
	cout << "���ݷ������������" << endl;
}

