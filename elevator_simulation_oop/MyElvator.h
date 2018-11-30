#pragma once


#include <vector>
#include <queue>
#include <list>

#include "MyUtil.h"
#include "Passenger.h"

using namespace std;

typedef struct elevatorNode
{
	
	bool linkageFlag;      //������־, 0-9ÿ�����ݶ�Ӧ�Լ��ı�־����������һ�飬�����飬false��ʾû�нӿ�����
	int elevatorCarryMen;   //���ݵ�ǰ����
	int stopFloor;           //������û����ʱͣ��¥��
	int distFloor;           //���ݽӿ͵�Ŀ��¥�㣬�����˵ȴ����ݵ�¥��
	int currentFloor;          //���ݵ�ǰ���ڵ�¥��
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
	elevatorElement elevator;     //���ݻ�������

	//��Ӧ�Ѿ�������ÿ�������еĹ˿�, ��¥��˳����룬
	//ÿ��һ����¥�����ͷԪ���Ƿ���¥��Ԫ����Դ��waitingCustomer����
	list<Passenger> carryCustomers;

	/*��Ӧ���ڵȴ�ÿ�����ݵ�Person���ϣ�
	�����е�PersonԪ�صĲ���λ�ð��˵�¥������
	�������ֱ��ȥ�ӵ�һ������Ŀͻ������򰴵������з����˳��ӹ˿�
	��ElvatorSimulation���������������
	*/
	list<Passenger> waitingPickUpCustomers;

	int maxCarryMen;           //����ؿ���

	
};

