#ifndef   MY_ELVATOR_SIMULATION       //如果没有定义这个宏  
#define   MY_ELVATOR_SIMULATION       //定义这个宏 


#include "MyElvator.h"
#include "PassengerSimulation.h"
#include <Windows.h>


class ElvatorSimulation
{
public:
	MyUtil* myUtil = MyUtil::getInstance();

public:
	ElvatorSimulation();
	~ElvatorSimulation();


public:
	//电梯仿真初始化
	void simulationInit(int maxcarrier, int initPersonNum, int totalTime);
	//电梯仿真开始
	void simulationStart(); 

	void setMaxCarryMen(int elvatorNum, int carryCapacity);

	

	


private:
	//题目中的十部电梯，其实可以手动输入电梯的数量，然后在专门建立一个类写电梯运行规则，
	//这样设计更便于扩展，但是题目没有要求，就偷懒吧
	MyElvator myElvator[10];

	

	int totalSimulationTime;     //总共的仿真时间

	//int customerNum;             //仿真时间内出现的顾客
	PassengerSimulation* ps;
	
};
#endif
