#pragma once

#include "Passenger.h"
#include <vector>
#include <queue>

using namespace std;

class PassengerSimulation
{
public:
	PassengerSimulation();
	~PassengerSimulation();


public:
	void initPassengerSimulation(int initPersonNum);


	void dealCustomerRequest(Passenger p);     //����˿͵�����,�ַ���ÿ�����ݵĽӿͶ���
	


public:
	int customerNum;             //����ʱ���ڳ��ֵĹ˿�

	queue<Passenger> customerRequest;      //�˿�����������ݵ��������

	Passenger* passengerPtr;            //ָ����Ⱥ��ָ��
};

