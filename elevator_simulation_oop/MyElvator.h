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
	bool runningDirectionFlag;     //���ݵ�ǰ�����з���trueΪ���ϣ�falseΪ����
	int runningTimeforNextFloor;       //�����ϴι��ź��Ѿ����е�ʱ��
	int runTimeforNextFloor;           //�����ϴι��ŵ��´ο�����Ҫ���е�ʱ��
	bool runFlag;                      //�����Ƿ������еı�־��Ϊ�������У������ǿ���״̬
	bool menLeavingFlag;                //�����Ƿ������¿��˵ı�־
}elevatorElement;




class MyElvator
{
public:
	MyElvator();
	~MyElvator();

	void setMaxCarryMen(int carryCapacity);

	//�жϵ����Ƿ�Ϊ��
	bool isEmpty();

	//������͵� �˿����� �����
	void addWaitingCustommer(Passenger& p);
	//��������Ĵ��ӿ��˵�¥��󣬽ӿ�
	void addCarryingCustomer();

	//�˿��µ���
	void leaveElevator();

	//
	void run();


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

