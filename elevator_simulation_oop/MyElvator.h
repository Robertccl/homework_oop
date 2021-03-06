#ifndef   MY_ELVATOR       //如果没有定义这个宏  
#define   MY_ELVATOR       //定义这个宏  

#include <vector>
#include <queue>
#include <list>

#include "MyUtil.h"
#include "Passenger.h"
#include "PassengerSimulation.h"

using namespace std;

typedef struct elevatorNode
{
	
	bool linkageFlag;      //联动标志, 0-9每个电梯对应自己的标志，电梯两两一组，共五组，false表示没有接客任务
	int elevatorCarryMen;   //电梯当前人数
	int stopFloor;           //电梯在没任务时停的楼层
	int distFloor;           //电梯接客的目的楼层，即客人等待电梯的楼层
	int currentFloor;          //电梯当前所在的楼层
	bool runningDirectionFlag;     //电梯当前的运行方向，true为向上，false为向下
	int runningTimeforNextFloor;       //电梯上次关门后已经运行的时间
	int runTimeforNextFloor;           //电梯上次关门到下次开门需要运行的时间
	bool runFlag;                      //电梯是否在运行的标志，为真在运行，否则是空闲状态
	bool menLeavingFlag;                //电梯是否在上下客人的标志
}elevatorElement;

inline bool cmp21(Passenger& p1, Passenger& p2)
{
	return p1.getDstFloor() > p2.getDstFloor();
};

inline bool cmp12(Passenger& p1, Passenger& p2)
{
	return p1.getDstFloor() < p2.getDstFloor();
};


class MyElvator
{
public:
	MyElvator();
	~MyElvator();

	void setMaxCarryMen(int carryCapacity);

	//判断电梯是否为空
	bool isEmpty();

	//向待接送的 乘客链表 添加人
	void addWaitingCustommer(Passenger& p);
	//到达最近的待接客人的楼层后，接客
	bool addCarryingCustomer();

	//乘客下电梯
	bool leaveElevator();

	//如果这一层电梯可以停，就判断有没有人要上，有没有人要下
	void run();

	//如果这一层没有不能停，就直接继续下去，不停
	void goon();

	void printInfo();


public:
	const int defaultCarryNum = 16;

	//friend class PassengerSimulation;

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

	PassengerSimulation* ps;
};

#endif

 