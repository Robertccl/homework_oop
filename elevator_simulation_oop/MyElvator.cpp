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

//向待接送的 乘客链表 添加人
void MyElvator::addWaitingCustommer(Passenger& p)
{
	waitingPickUpCustomers.push_back(p);
}


//到达最近的待接客人的楼层后，接客
void MyElvator::addCarryingCustomer()
{
	Passenger p;
	//如果空闲
	if (!elevator.runFlag)
	{
		p = waitingPickUpCustomers.front();
	}
	else
	{
		auto temp = waitingPickUpCustomers.begin();
		for (auto i = waitingPickUpCustomers.begin(); i != waitingPickUpCustomers.end(); i++)
		{
			//如果不空闲，向上
			if (elevator.runningDirectionFlag)
			{
				if (i->getWaitElvatorNum() > elevator.stopFloor)
				{
					if(!temp->getWitFloor() || (temp->getWitFloor() > i->getWaitElvatorNum() && temp->getWitFloor()))
						temp = i;
				}
			}
			else //如果向下
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

//乘客下电梯
void MyElvator::leaveElevator()
{

}


void MyElvator::run()
{
	//如果电梯有要去接的人
	if (waitingPickUpCustomers.empty())
	{
		//如果电梯没人，是空闲状态
		if (isEmpty())
		{
			addCarryingCustomer()
		}
		else    //如果不是空闲状态
		{

		}
	}
}

