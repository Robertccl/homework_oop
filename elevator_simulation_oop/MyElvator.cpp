#include "MyElvator.h"



MyElvator::MyElvator()
{
	ps = PassengerSimulation::getInstance();
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
bool MyElvator::addCarryingCustomer()
{
	bool flag = false;
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
	//如果接到人将人从电梯的等待接人队列删除，加入载客队列
	if (temp != waitingPickUpCustomers.end())
	{
		p = *temp;
		
		carryCustomers.push_back(p);
		waitingPickUpCustomers.remove(p);
		elevator.currentFloor = p.getWitFloor();
		elevator.distFloor = p.getDstFloor();
		elevator.elevatorCarryMen++;
		waitingPickUpCustomers.pop_front();

		//ps->simulatingPassengers.remove(p);
		//电梯上人等10 秒
		int i = 0;
		while (i < 10)
			i++;
		flag = true;

	}
	return flag;
}

//乘客下电梯
/*
下电梯将人从给电梯的载客队列删除，加入乘客仿真的仿真进行队列
*/
bool MyElvator::leaveElevator()
{
	bool flag = false;
	Passenger temp;

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
	temp = carryCustomers.front();
	if (temp.getDstFloor() == elevator.currentFloor)
	{
		temp.setTakingtimes();
		temp.setWitFloor(elevator.currentFloor);
		int i = 0;
		while (i < 5)
			i++;
		if(temp.getTakingtimes()<temp.tokentimes)
			ps->simulatingPassengers.push_back(temp);
		else
		{
			ps->simulatedPassengers.push_back(temp);
		}
		flag = true;
	}
	return flag;
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
	if(elevator.elevatorCarryMen>0)
		while(leaveElevator());

	//如果电梯有要去接的人
	if (!waitingPickUpCustomers.empty())
	{
		while(addCarryingCustomer());
	}
	printInfo();
}

void MyElvator::goon()
{
	elevator.currentFloor++;
	printInfo();
}

void MyElvator::printInfo()
{
	cout << "****************************" << endl;
	cout << "电梯现在楼层:   " << elevator.currentFloor << endl;;
	cout << "电梯内乘客数量：  " << elevator.elevatorCarryMen << endl;
	cout << "电梯运行方向： ";
	if (elevator.runningDirectionFlag)
		cout << "向上" << endl;
	else
		cout << "向下" << endl;
	cout << "电梯还需要接客的数量： " << this->waitingPickUpCustomers.size() << endl;;
	cout << "****************************" << endl;
}

