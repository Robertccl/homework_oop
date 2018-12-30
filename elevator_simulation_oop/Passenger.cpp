

#include "Passenger.h"
#include "MyUtil.h"


Passenger::Passenger()
{
}


Passenger::~Passenger()
{
}


Passenger& Passenger::operator= (const Passenger& p)
{
	Passenger *tmp = new Passenger();
	tmp->belongingNeedSpace = p.belongingNeedSpace;
	tmp->distFloor = p.distFloor;
	tmp->takingtimes = p.takingtimes;
	tmp->waitElvatorNum = p.waitElvatorNum;
	tmp->waitFloor = p.waitFloor;
	tmp->waitTimeforNext = p.waitTimeforNext;
	return *tmp;
}

bool operator==(const Passenger& p1, const Passenger& p2)
{
	bool flag = false;
	if (p1.distFloor == p2.distFloor)
		if (p1.takingtimes == p2.takingtimes)
			if (p1.waitElvatorNum == p2.waitElvatorNum)
				if (p1.waitFloor == p2.waitFloor)
					flag = true;
	return false;
}

void Passenger::setWitFloor(int waitFloor)
{
	this->waitFloor = waitFloor;
}
int Passenger::getWitFloor()
{
	return this->waitFloor;
}

void Passenger::setDstFloor(int distFloor)
{
	this->distFloor = distFloor;
}
int Passenger::getDstFloor()
{
	return this->distFloor;
}

void Passenger::setBlongingNeedSpace(int belongingNeedSpace)
{
	this->belongingNeedSpace = belongingNeedSpace;
}
int Passenger::getBlongingNeedSpace()
{
	return this->belongingNeedSpace;
}

void Passenger::setWaitElvatorNum(int waitElvatorNum)
{
	this->waitElvatorNum = waitElvatorNum;
}
int Passenger::getWaitElvatorNum()
{
	return this->waitElvatorNum;
}


void Passenger::setWaitTimeforNext()
{
	waitTimeforNext = myUtil->random(10, 120);
}

int Passenger::getWaitTimeforNext()
{
	return waitTimeforNext;
}


void Passenger::setTakingtimes()
{
	takingtimes++;
}
int Passenger::getTakingtimes()
{
	return takingtimes;
}

void Passenger::init()
{
	belongingNeedSpace = 0;
	waitFloor = 1;
	distFloor = myUtil->random(1, 40);
	waitElvatorNum = 0;
	takingtimes = myUtil->random(1, 10) + 1;

}

//下一次乘坐初始化，不改当前楼层和乘坐总次数
void Passenger::nextTakeInit()
{
	belongingNeedSpace = 0;
	distFloor = myUtil->random(1, 40);
	waitElvatorNum = 0;
	//随机停留10-120秒
	waitTimeforNext = myUtil->random(10, 120);
	Sleep(waitTimeforNext);
	
}
