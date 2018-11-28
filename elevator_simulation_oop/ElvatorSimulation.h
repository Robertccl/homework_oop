#pragma once

#include "MyElvator.h"
#include "PersonSimulation.h"



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

	void setMaxCarryMen(int carryCapacity);


private:

	MyElvator myElvator;

	int totalSimulationTime;     //�ܹ��ķ���ʱ��

	//int customerNum;             //����ʱ���ڳ��ֵĹ˿�
	PersonSimulation personSimulation;
	
};

