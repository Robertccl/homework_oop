#pragma once

#include "Person.h"

class PersonSimulation
{
public:
	PersonSimulation();
	~PersonSimulation();


public:
	void initPersonSimulation(int initPersonNum);


public:
	int customerNum;             //����ʱ���ڳ��ֵĹ˿�

	Person* personPtr;            //ָ����Ⱥ��ָ��
};

