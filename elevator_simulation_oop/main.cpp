// elevator_simulation_oop.cpp: 定义控制台应用程序的入口点。
//
#include "MyUtil.h"
#include "ElvatorSimulation.h"

int main()
{
	int maxcarrier = 0;
	int initPersonNum = 0;
	int totalTime = 0;
	cin >> maxcarrier >> initPersonNum >> totalTime;
	ElvatorSimulation e;
	e.simulationInit(maxcarrier, initPersonNum, totalTime);
	e.simulationStart();
	/*MyUtil* u = MyUtil::getInstance();

	cout << "高级方法" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout<<u->random(-10, 10);
		cout << endl;
	}*/
	cin.get();
    return 0;
}

