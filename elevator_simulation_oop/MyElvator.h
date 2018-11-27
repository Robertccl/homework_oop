#pragma once
class MyElvator
{
public:
	MyElvator();
	~MyElvator();

	void setMaxCarryMen(int carryCapacity);



public:
	//电梯仿真初始化
	void simulationInit();
	//电梯仿真开始
	void simulationStart();

	//电梯运行规则
	bool canArrive(int elevatorNum, int floorNum);



public:
	const int defaultCarryNum = 16;

private:
	int maxCarryMen;           //最大载客量
	bool linkageFlag[10];      //联动标志, 0-9每个电梯对应自己的标志，电梯两两一组，共五组，false表示没有接客任务
	int elevatorCarryMen[10];
};

