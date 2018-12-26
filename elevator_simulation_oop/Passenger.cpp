#include "Passenger.h"
#include "MyUtil.h"


Passenger::Passenger()
{
}


Passenger::~Passenger()
{
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

void Passenger::init()
{
	belongingNeedSpace = 0;
	waitFloor = 1;
	distFloor = myUtil->random(1, 40);
	waitElvatorNum = 0;
	takingtimes = myUtil->random(1, 10) + 1;

}
