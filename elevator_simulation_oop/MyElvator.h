#pragma once

#include "MyUtil.h"

typedef struct elevatorNode
{
	
	bool linkageFlag;      //������־, 0-9ÿ�����ݶ�Ӧ�Լ��ı�־����������һ�飬�����飬false��ʾû�нӿ�����
	int elevatorCarryMen;   //���ݵ�ǰ����
	int stopFloor;           //������û����ʱͣ��¥��
	int distFloor;           //���ݽӿ͵�Ŀ��¥�㣬�����˵ȴ����ݵ�¥��
	int currentFloor;          //���ݵ�ǰ���ڵ�¥��
}elevator;




class MyElvator
{
public:
	MyElvator();
	~MyElvator();

	void setMaxCarryMen(int carryCapacity);



public:
	//�������й���
	bool canArrive(int elevatorNum, int floorNum);

	void canTakeFloor(int floorNum, bool *elevatorFlag);



public:
	const int defaultCarryNum = 16;

	MyUtil* myUtil = MyUtil::getInstance();

public:
	elevator elevators[10];     //10̨����

	int maxCarryMen;           //����ؿ���

	
};

