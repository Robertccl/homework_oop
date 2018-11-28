#include "Person.h"
#include "MyUtil.h"


Person::Person()
{
}


Person::~Person()
{
}

void Person::setWitFloor(int waitFloor)
{
	this->waitFloor = waitFloor;
}
int Person::getWitFloor()
{
	return this->waitFloor;
}

void Person::setDstFloor(int distFloor)
{
	this->distFloor = distFloor;
}
int Person::getDstFloor()
{
	return this->distFloor;
}

void Person::setBlongingNeedSpace(int belongingNeedSpace)
{
	this->belongingNeedSpace = belongingNeedSpace;
}
int Person::getBlongingNeedSpace()
{
	return this->belongingNeedSpace;
}

void Person::setWitElvatorNum(int waitElvatorNum)
{
	this->waitElvatorNum = waitElvatorNum;
}
int Person::getWitElvatorNum()
{
	return this->waitElvatorNum;
}

void Person::init()
{
	belongingNeedSpace = 0;
	waitFloor = 1;
	distFloor = myUtil->random(1, 40);
	waitElvatorNum = 0;

}
