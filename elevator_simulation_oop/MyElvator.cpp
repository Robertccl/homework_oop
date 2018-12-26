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


//��������Ĵ��ӿ��˵�¥��󣬽ӿ�
void MyElvator::addCarryingCustomer()
{
	Passenger p;
	//�������
	if (!elevator.runFlag)
	{
		p = waitingPickUpCustomers.front();
	}
	else
	{
		auto temp = waitingPickUpCustomers.begin();
		for (auto i = waitingPickUpCustomers.begin(); i != waitingPickUpCustomers.end(); i++)
		{
			//��������У�����
			if (elevator.runningDirectionFlag)
			{
				if (i->getWaitElvatorNum() > elevator.stopFloor)
				{
					if(!temp->getWitFloor() || (temp->getWitFloor() > i->getWaitElvatorNum() && temp->getWitFloor()))
						temp = i;
				}
			}
			else //�������
			{
				if (i->getWaitElvatorNum() < elevator.stopFloor)
				{
					if (!temp->getWitFloor() || (temp->getWitFloor() < i->getWaitElvatorNum() && temp->getWitFloor()))
						temp = i;
				}
			}
		}
		p = *temp;
	}
	
	carryCustomers.push_back(p);
	waitingPickUpCustomers.remove(p);
	elevator.currentFloor = p.getWitFloor();
	elevator.distFloor = p.getDstFloor();
	elevator.elevatorCarryMen++;
	waitingPickUpCustomers.pop_front();

}

//�˿��µ���
void MyElvator::leaveElevator()
{

}


void MyElvator::run()
{
	//���������Ҫȥ�ӵ���
	if (waitingPickUpCustomers.empty())
	{
		//�������û�ˣ��ǿ���״̬
		if (isEmpty())
		{
			addCarryingCustomer()
		}
		else    //������ǿ���״̬
		{

		}
	}
}

