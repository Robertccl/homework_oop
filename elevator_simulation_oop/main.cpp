// elevator_simulation_oop.cpp: 定义控制台应用程序的入口点。
//
#include "MyUtil.h"
#include "ElvatorSimulation.h"

int main()
{
	int maxcarrier = 12;  //最大载客量 对应K
	int initPersonNum = 10;  //参与仿真的乘客人数，对应N
	int initTime = 10;       //所有人陆续到达地点，都开始乘坐时间的时长，对应M
	int runSpeed = 0; //电梯运行速度    对应S秒/层
	int intotime = 0 ;   //每人上下电梯的时间   对应T秒
	/*cout << "请输入电梯最大载客量K: " << endl;
	cin >> maxcarrier;
	cout << "请输入参与仿真的乘客人数N: " << endl;
	cin >> initPersonNum;
	cout << "请输入所有乘客都开始乘坐电梯的时间M: " << endl;
	cin >> initTime;
	cout << "请输入电梯运行速度S: " << endl;
	cin >> runSpeed;
	cout << "请输入乘客上下电梯的时间T: " << endl;
	cin >> intotime;*/
	ElvatorSimulation e;
	e.simulationInit(maxcarrier, initPersonNum, initTime);
	e.simulationStart();
	/*
	MyUtil* u = MyUtil::getInstance();
	
	cout << "高级方法" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout<<u->random(-10, 10);
		cout << endl;
	}
	cout << "电梯仿真结束共耗时 73 分钟" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << " 号电梯 "<<endl;
		cout << "运行时间为：" << u->random(i%5*2, 18) << endl;
		cout << "空闲时间为：" << u->random(i%5 * 2, 11) << endl;
	}

	for (int i = 0; i < initPersonNum; i++)
	{
		cout << "乘客 " << i << endl;
		cout << "等待时间为：" << u->random(3, 15)<< endl;
	}
	*/

	cin.get();
    return 0;
}

