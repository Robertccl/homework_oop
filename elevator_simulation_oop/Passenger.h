#ifndef   MY_PASSENGER       //如果没有定义这个宏  
#define   MY_PASSENGER       //定义这个宏  

#include "MyUtil.h"


class Passenger
{
public:
	Passenger();
	~Passenger();

	void setWitFloor(int waitFloor);
	int getWitFloor();

	void setDstFloor(int distFloor);
	int getDstFloor();

	void setBlongingNeedSpace(int belongingNeedSpace);
	int getBlongingNeedSpace();

	void setWaitElvatorNum(int waitElvatorNum);
	int getWaitElvatorNum();

	void setWaitTimeforNext();
	int getWaitTimeforNext();

	void setTakingtimes();
	int getTakingtimes();


	Passenger& operator= (const Passenger& p);
	bool friend operator==(const Passenger& p1, const Passenger& p2);

public:
	void init();
	//下一次乘坐初始化，不改当前楼层和乘坐总次数
	void nextTakeInit();

	bool isNone();

public:
	MyUtil* myUtil = MyUtil::getInstance();


public:
	int tokentimes;             //客人要乘坐电梯的次数，文档中的要求乘坐L次，第L+1次回到一层，这个变量包含第L+1次

private:
	int waitFloor;            //客人等待电梯的楼层
	int distFloor;              //客人要去往的楼层
	int belongingNeedSpace;      //客人携带的随身物品占用的空间
	int waitElvatorNum;           //客人要等的电梯，即接客的电梯
	int takingtimes;             //客人已经乘坐电梯的次数，
	
	int waitTimeforNext;          //完成一次乘梯活动后，休息的时间，即两次乘梯之间的间隔，随机产生
};

#endif

