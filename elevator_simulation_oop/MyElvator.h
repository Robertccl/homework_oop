#pragma once


#include <vector>
#include <queue>
#include <list>

#include "MyUtil.h"
#include "Passenger.h"

using namespace std;

typedef struct elevatorNode
{
	
	bool linkageFlag;      //联动标志, 0-9每个电梯对应自己的标志，电梯两两一组，共五组，false表示没有接客任务
	int elevatorCarryMen;   //电梯当前人数
	int stopFloor;           //电梯在没任务时停的楼层
	int distFloor;           //电梯接客的目的楼层，即客人等待电梯的楼层
	int currentFloor;          //电梯当前所在的楼层
}elevatorElement;




class MyElvator
{
public:
	MyElvator();
	~MyElvator();

	void setMaxCarryMen(int carryCapacity);



public:
	const int defaultCarryNum = 16;

	MyUtil* myUtil = MyUtil::getInstance();

public:
	elevatorElement elevator;     //电梯基本属性

	//对应已经乘坐在每部电梯中的顾客, 按楼层顺序插入，
	//每到一个新楼层检查表头元素是否下楼，元素来源于waitingCustomer变量
	list<Passenger> carryCustomers;

	/*对应正在等待每部电梯的Person集合，
	链表中的Person元素的插入位置按人的楼层排序，
	链表空则直接去接第一个请求的客户，否则按电梯运行方向的顺序接顾客
	由ElvatorSimulation类往里面填充数据
	*/
	list<Passenger> waitingPickUpCustomers;

	int maxCarryMen;           //最大载客量

	
};

