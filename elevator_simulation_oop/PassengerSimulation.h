#ifndef   MY_PASSENGER_SIMULATION       //如果没有定义这个宏  
#define   MY_PASSENGER_SIMULATION       //定义这个宏  

#include "Passenger.h"
#include "MyUtil.h"
#include <vector>
#include <queue>
#include <list>

using namespace std;

class PassengerSimulation
{

public:
	static PassengerSimulation* getInstance();



public:
	void initPassengerSimulation(int initPersonNum);


	Passenger initPassengerforNext();     //处理顾客的请求,分发至每个电梯的接客队列
	

public:
	int customerNum;             //仿真时间内出现的顾客数量

	//queue<Passenger> customerRequest;      //顾客请求乘坐电梯的请求队列

	Passenger* passengerPtr;            //指向人群的指针

	list<Passenger>  simulatingPassengers;    //还在仿真的乘客列表
	
	list<Passenger>  simulatedPassengers;  //仿真结束的乘客列表

	MyUtil* myUtil;

private:
	PassengerSimulation();
	~PassengerSimulation();
};

#endif

