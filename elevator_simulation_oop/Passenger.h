#pragma once
#include "MyUtil.h"


class Passenger
{
public:
	Passenger();
	~Passenger();

	void setWitFloor(int waitFloor);
	int getWitFloor();

	void setDstFloor(int distFloor);
	int getDstFloor();

	void setBlongingNeedSpace(int belongingNeedSpace);
	int getBlongingNeedSpace();

	void setWaitElvatorNum(int waitElvatorNum);
	int getWaitElvatorNum();

	void setWaitTimeforNext();
	int getWaitTimeforNext();



public:
	void init();

public:
	MyUtil* myUtil = MyUtil::getInstance();


private:
	int waitFloor;            //���˵ȴ����ݵ�¥��
	int distFloor;              //����Ҫȥ����¥��
	int belongingNeedSpace;      //����Я����������Ʒռ�õĿռ�
	int waitElvatorNum;           //����Ҫ�ȵĵ��ݣ����ӿ͵ĵ���
	int takingtimes;             //����Ҫ�������ݵĴ������ĵ��е�Ҫ�����L�Σ���L+1�λص�һ�㣬�������������L+1��
	int waitTimeforNext;          //���һ�γ��ݻ����Ϣ��ʱ�䣬�����γ���֮��ļ�����������
};

