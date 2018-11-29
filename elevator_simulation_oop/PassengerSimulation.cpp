#include "PassengerSimulation.h"



PassengerSimulation::PassengerSimulation()
{
	
}


PassengerSimulation::~PassengerSimulation()
{
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
