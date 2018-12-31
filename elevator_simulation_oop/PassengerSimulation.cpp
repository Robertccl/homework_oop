#include "PassengerSimulation.h"



PassengerSimulation::PassengerSimulation()
{
	myUtil = MyUtil::getInstance();
}


PassengerSimulation::~PassengerSimulation()
{
	delete [] passengerPtr;
	myUtil = NULL;
}

PassengerSimulation* PassengerSimulation::getInstance()
{
	static PassengerSimulation* ps;
	if (ps == NULL)
		ps = new PassengerSimulation();
	return ps;
}

Passenger PassengerSimulation::initPassengerforNext()
{
	Passenger temp;
	if (!simulatingPassengers.empty())
	{
		temp = simulatingPassengers.front();
		temp.nextTakeInit();
		simulatingPassengers.pop_front();
	}
	return temp;
}


void PassengerSimulation::initPassengerSimulation(int initPersonNum)
{
	this->customerNum = initPersonNum;
	passengerPtr = new Passenger[customerNum];
	for (int i = 0; i < customerNum; i++)
	{
		passengerPtr->init();
	}
}
