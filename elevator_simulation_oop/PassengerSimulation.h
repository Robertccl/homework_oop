#ifndef   MY_PASSENGER_SIMULATION       //���û�ж��������  
#define   MY_PASSENGER_SIMULATION       //���������  

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
	int customerNum;             //����ʱ���ڳ��ֵĹ˿�����

	queue<Passenger> customerRequest;      //�˿�����������ݵ��������

	Passenger* passengerPtr;            //ָ����Ⱥ��ָ��

	Passenger*  SimulatingPassengerPtr;
	Passenger*  SimulatedPassengerPtr;
};

#endif

