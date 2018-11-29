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

void Passenger::setWitElvatorNum(int waitElvatorNum)
{
	this->waitElvatorNum = waitElvatorNum;
}
int Passenger::getWitElvatorNum()
{
	return this->waitElvatorNum;
}

void Passenger::init()
{
	belongingNeedSpace = 0;
	waitFloor = 1;
	distFloor = myUtil->random(1, 40);
	waitElvatorNum = 0;

}
