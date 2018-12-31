#ifndef   MY_PASSENGER_SIMULATION       //���û�ж��������  
#define   MY_PASSENGER_SIMULATION       //���������  

#include "Passenger.h"
#include "MyUtil.h"
#include <vector>
#include <queue>
#include <list>

using namespace std;

class PassengerSimulation
{

public:
	static PassengerSimulation* getInstance();



public:
	void initPassengerSimulation(int initPersonNum);


	Passenger initPassengerforNext();     //����˿͵�����,�ַ���ÿ�����ݵĽӿͶ���
	

public:
	int customerNum;             //����ʱ���ڳ��ֵĹ˿�����

	//queue<Passenger> customerRequest;      //�˿�����������ݵ��������

	Passenger* passengerPtr;            //ָ����Ⱥ��ָ��

	list<Passenger>  simulatingPassengers;    //���ڷ���ĳ˿��б�
	
	list<Passenger>  simulatedPassengers;  //��������ĳ˿��б�

	MyUtil* myUtil;

private:
	PassengerSimulation();
	~PassengerSimulation();
};

#endif

