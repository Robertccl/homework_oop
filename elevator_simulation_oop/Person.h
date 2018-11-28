#pragma once
#include "MyUtil.h"


class Person
{
public:
	Person();
	~Person();

	void setWitFloor(int waitFloor);
	int getWitFloor();

	void setDstFloor(int distFloor);
	int getDstFloor();

	void setBlongingNeedSpace(int belongingNeedSpace);
	int getBlongingNeedSpace();

	void setWitElvatorNum(int waitElvatorNum);
	int getWitElvatorNum();



public:
	void init();

public:
	MyUtil* myUtil = MyUtil::getInstance();


private:
	int waitFloor;            //���˵ȴ����ݵ�¥��
	int distFloor;              //����Ҫȥ����¥��
	int belongingNeedSpace;      //����Я����������Ʒռ�õĿռ�
	int waitElvatorNum;           //����Ҫ�ȵĵ��ݣ����ӿ͵ĵ���
};

