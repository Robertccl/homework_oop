#pragma once

#include "MyElvator.h"
#include "MyUtil.h"


typedef struct personNode
{
	int waitFloor;            //���˵ȴ����ݵ�¥��
	int distFloor;              //����Ҫȥ����¥��
	int belongingNeedSpace;      //����Я����������Ʒռ�õĿռ�
	int waitElvatorNum;
}person;

class ElvatorSimulation
{
public:
	MyUtil myUtil;

public:
	ElvatorSimulation();
	~ElvatorSimulation();


public:
	//���ݷ����ʼ��
	void simulationInit(int maxcarrier, int initPersonNum, int totalTime);
	//���ݷ��濪ʼ
	void simulationStart();

	void setMaxCarryMen(int carryCapacity);


private:

	MyElvator myElvator;

	int totalSimulationTime;     //�ܹ��ķ���ʱ��

	int customerNum;             //����ʱ���ڳ��ֵĹ˿�

	person* personHeader;
};

