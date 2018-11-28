#pragma once

#include "Person.h"

class PersonSimulation
{
public:
	PersonSimulation();
	~PersonSimulation();


public:
	void initPersonSimulation(int initPersonNum);


public:
	int customerNum;             //仿真时间内出现的顾客

	Person* personPtr;            //指向人群的指针
};

