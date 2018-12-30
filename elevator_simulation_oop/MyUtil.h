#ifndef   MY_UTIL       //���û�ж��������  
#define   MY_UTIL      //���������  

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <memory.h>
#include <random>
#include <Windows.h>

using namespace std;


class MyUtil
{
public:
	static MyUtil* getInstance();
	

public:
	int random(int min, int max);  //����ָ����Χ�������
	//��Ӧ��ʮ�����ݵ�ʱ���ܳ����ı�־
	bool elevatorFlag[10];
	//��ʼ��ʮ�������ܳ����ı�־��Ĭ�϶�����
	void initElevatorFlag();

	//�������й���   ͵��д������
	bool canArrive(int elevatorNum, int floorNum);

	//�ж�ȥĳ��¥����Գ����ĵ��ݱ��   elevatorFlagΪ10��bool���ͣ���ʼֵΪfalse
	void canTakeFloor(int nowfloor, int distfloor);

private:
	MyUtil();
	~MyUtil();
	
};

#endif

