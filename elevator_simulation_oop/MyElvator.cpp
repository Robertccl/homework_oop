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


//判断当前楼层是否有要上的客人
void MyElvator::addCarryingCustomer()
{
	
	//如果空闲
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
		//检查当前楼层是否有客人的需求与当前电梯运行方向一致，有就上人
		if (i->getWitFloor() == elevator.currentFloor)
		{
			//如果不空闲，向上
			if (elevator.runningDirectionFlag)
			{
				if (i->getWaitElvatorNum() > elevator.currentFloor)
				{
						temp = i;
				}
			}
			else //如果向下
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

		//电梯上人等10 秒
		int i = 0;
		while (i < 10)
			i++;
	}
}

//乘客下电梯
void MyElvator::leaveElevator()
{

	if (elevator.runningDirectionFlag)
	{
		//按乘客目的楼层增序排序
		carryCustomers.sort(cmp12);
	}
	else
	{
		//按乘客目的楼层降序排序
		carryCustomers.sort(cmp21);
	}
	//检查当前楼层是否有要下的人
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
		//电梯上一层楼
		elevator.currentFloor++;
	else
		elevator.currentFloor--;
	//乘客下电梯
	leaveElevator();

	//如果电梯有要去接的人
	if (!waitingPickUpCustomers.empty())
	{
		addCarryingCustomer();
	}
}

