#ifndef   MY_UTIL       //如果没有定义这个宏  
#define   MY_UTIL      //定义这个宏  

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <memory.h>
#include <random>
#include <Windows.h>

using namespace std;


class MyUtil
{
public:
	static MyUtil* getInstance();
	

public:
	int random(int min, int max);  //生成指定范围的随机数
	//对应的十部电梯的时候能乘坐的标志
	bool elevatorFlag[10];
	//初始化十部电梯能乘坐的标志，默认都不能
	void initElevatorFlag();

	//电梯运行规则   偷懒写在这里
	bool canArrive(int elevatorNum, int floorNum);

	//判断去某个楼层可以乘坐的电梯编号   elevatorFlag为10个bool类型，初始值为false
	void canTakeFloor(int nowfloor, int distfloor);

private:
	MyUtil();
	~MyUtil();
	
};

#endif

