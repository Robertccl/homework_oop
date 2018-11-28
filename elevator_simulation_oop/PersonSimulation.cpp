#include "PersonSimulation.h"



PersonSimulation::PersonSimulation()
{
	
}


PersonSimulation::~PersonSimulation()
{
}


void PersonSimulation::initPersonSimulation(int initPersonNum)
{
	this->customerNum = initPersonNum;
	personPtr = new Person[customerNum];
	for (int i = 0; i < customerNum; i++)
	{
		personPtr->init();
	}
}
