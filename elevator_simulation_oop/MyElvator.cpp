#include "MyElvator.h"



MyElvator::MyElvator()
{
}


MyElvator::~MyElvator()
{
}

bool MyElvator::isEmpty()
{
	return elevator.elevatorCarryMen;
}


void MyElvator::setMaxCarryMen(int carryCapacity)
{
	this->maxCarryMen = carryCapacity;
}

//������͵� �˿����� �����
void MyElvator::addWaitingCustommer(Passenger& p)
{
	waitingPickUpCustomers.push_back(p);
}


//�жϵ�ǰ¥���Ƿ���Ҫ�ϵĿ���
void MyElvator::addCarryingCustomer()
{
	
	//�������
	/*if (!elevator.runFlag)
	{
		p = waitingPickUpCustomers.front();
	}
	else
	{
	}
	*/

	Passenger p;
	list<Passenger>::iterator temp = waitingPickUpCustomers.end();
	for (auto i = waitingPickUpCustomers.begin(); i != waitingPickUpCustomers.end(); i++)
	{
		//��鵱ǰ¥���Ƿ��п��˵������뵱ǰ�������з���һ�£��о�����
		if (i->getWitFloor() == elevator.currentFloor)
		{
			//��������У�����
			if (elevator.runningDirectionFlag)
			{
				if (i->getWaitElvatorNum() > elevator.currentFloor)
				{
						temp = i;
				}
			}
			else //�������
			{
				if (i->getWaitElvatorNum() < elevator.stopFloor)
				{
					//if (!temp->getWitFloor() || (temp->getWitFloor() < i->getWaitElvatorNum() && temp->getWitFloor()))
						temp = i;
				}
			}

		}
		
	}
	if (temp != waitingPickUpCustomers.end())
	{
		p = *temp;

		carryCustomers.push_back(p);
		waitingPickUpCustomers.remove(p);
		elevator.currentFloor = p.getWitFloor();
		elevator.distFloor = p.getDstFloor();
		elevator.elevatorCarryMen++;
		waitingPickUpCustomers.pop_front();

		//�������˵�10 ��
		int i = 0;
		while (i < 10)
			i++;
	}
}

//�˿��µ���
void MyElvator::leaveElevator()
{

	if (elevator.runningDirectionFlag)
	{
		//���˿�Ŀ��¥����������
		carryCustomers.sort(cmp12);
	}
	else
	{
		//���˿�Ŀ��¥�㽵������
		carryCustomers.sort(cmp21);
	}
	//��鵱ǰ¥���Ƿ���Ҫ�µ���
	if (carryCustomers.front().getDstFloor() == elevator.currentFloor)
	{
		int i = 0;
		while (i < 5)
			i++;
	}
}


void MyElvator::run()
{
	if (40 == elevator.currentFloor)
	{
		elevator.runningDirectionFlag = false;
	}
	if (1 == elevator.currentFloor)
	{
		elevator.runningDirectionFlag = true;
	}

	if (elevator.runningDirectionFlag)
		//������һ��¥
		elevator.currentFloor++;
	else
		elevator.currentFloor--;
	//�˿��µ���
	leaveElevator();

	//���������Ҫȥ�ӵ���
	if (!waitingPickUpCustomers.empty())
	{
		addCarryingCustomer();
	}
}

