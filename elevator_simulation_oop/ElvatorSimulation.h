#pragma once

#include "MyElvator.h"
#include "PassengerSimulation.h"



class ElvatorSimulation
{
public:
	MyUtil* myUtil = MyUtil::getInstance();

public:
	ElvatorSimulation();
	~ElvatorSimulation();


public:
	//���ݷ����ʼ��
	void simulationInit(int maxcarrier, int initPersonNum, int totalTime);
	//���ݷ��濪ʼ
	void simulationStart();

	void setMaxCarryMen(int elvatorNum, int carryCapacity);



	//�������й���   ͵��д������
	bool canArrive(int elevatorNum, int floorNum);

	//�ж�ȥĳ��¥����Գ����ĵ��ݱ��   elevatorFlagΪ10��bool���ͣ���ʼֵΪfalse
	void canTakeFloor(int floorNum, bool *elevatorFlag);

private:


	//��Ŀ�е�ʮ�����ݣ���ʵ�����ֶ�������ݵ�������Ȼ����ר�Ž���һ����д�������й���
	//������Ƹ�������չ��������Ŀû��Ҫ�󣬾�͵����
	MyElvator myElvator[10];

	int totalSimulationTime;     //�ܹ��ķ���ʱ��

	//int customerNum;             //����ʱ���ڳ��ֵĹ˿�
	PassengerSimulation passengerSimulation;
	
};

