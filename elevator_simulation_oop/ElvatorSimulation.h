#ifndef   MY_ELVATOR_SIMULATION       //���û�ж��������  
#define   MY_ELVATOR_SIMULATION       //��������� 


#include "MyElvator.h"
#include "PassengerSimulation.h"
#include <Windows.h>


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

	

	


private:
	//��Ŀ�е�ʮ�����ݣ���ʵ�����ֶ�������ݵ�������Ȼ����ר�Ž���һ����д�������й���
	//������Ƹ�������չ��������Ŀû��Ҫ�󣬾�͵����
	MyElvator myElvator[10];

	

	int totalSimulationTime;     //�ܹ��ķ���ʱ��

	//int customerNum;             //����ʱ���ڳ��ֵĹ˿�
	PassengerSimulation* ps;
	
};
#endif
