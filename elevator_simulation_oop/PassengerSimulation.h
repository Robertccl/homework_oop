#pragma once

#include "Passenger.h"
#include <vector>
#include <queue>

using namespace std;

class PassengerSimulation
{
public:
	PassengerSimulation();
	~PassengerSimulation();


public:
	void initPassengerSimulation(int initPersonNum);


	void dealCustomerRequest(Passenger p);     //处理顾客的请求,分发至每个电梯的接客队列
	


public:
	int customerNum;             //仿真时间内出现的顾客

	queue<Passenger> customerRequest;      //顾客请求乘坐电梯的请求队列

	Passenger* passengerPtr;            //指向人群的指针
};

