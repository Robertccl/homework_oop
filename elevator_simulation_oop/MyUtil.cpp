#include "MyUtil.h"
#include <Windows.h>


MyUtil::MyUtil()
{
}


MyUtil::~MyUtil()
{
}


MyUtil* MyUtil::getInstance()
{
	static MyUtil* myUtil;
	if (myUtil == NULL)
		myUtil = new MyUtil();
	return myUtil;
}



int MyUtil::random(int min, int max)
{
	//������
	//srand((int)time(0));   //��������ӣ���ÿ�����ɵ����������һ��
	//
	//cout << "��ͨ����" << endl;
	//cout<< min + (max-min) * rand() / RAND_MAX;
	//cout << endl;

	//C++ ������ĸ߼�����
	//default_random_engine e;
	//uniform_int_distribution<unsigned> u(min, max); //������ֲ�����

	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<int> u(min, max); //������ֲ�����
	
	
	return u(rng);
}

void MyUtil::initElevatorFlag()
{
	for (int i = 0; i < 10; i++)
	{
		elevatorFlag[i] = false;
	}
}

//�ж�ȥĳ��¥����Գ����ĵ��ݱ��   elevatorFlagΪ10��bool���ͣ���ʼֵΪfalse
void MyUtil::canTakeFloor(int nowfloor, int distfloor)
{
	initElevatorFlag();
	for (int i = 0; i < 10; i++)
		elevatorFlag[i] = false;
	if (distfloor > 0 && distfloor <= 40)
	{
		elevatorFlag[0] = true;
		elevatorFlag[1] = true;
		if (distfloor == 1)
		{
			elevatorFlag[2] = true;
			elevatorFlag[3] = true;
			elevatorFlag[4] = true;
			elevatorFlag[5] = true;
			elevatorFlag[8] = true;
			elevatorFlag[9] = true;
		}
		if (distfloor >= 25 && distfloor <= 40)
		{
			elevatorFlag[2] = true;
			elevatorFlag[3] = true;
		}
		if (distfloor > 1 && distfloor <= 25)
		{
			elevatorFlag[4] = true;
			elevatorFlag[5] = true;
		}
		if (distfloor % 2 == 0)
		{
			elevatorFlag[6] = true;
			elevatorFlag[7] = true;
		}
		if (distfloor % 2 == 1)
		{
			elevatorFlag[8] = true;
			elevatorFlag[9] = true;
		}
	}

}


//�������й���
bool MyUtil::canArrive(int elevatorNum, int floorNum)
{
	if (floorNum > 0 && floorNum < 41)
	{
		if (elevatorNum == 0 || elevatorNum == 1)
			return true;
		else if (elevatorNum == 2 || elevatorNum == 3)
		{
			if (floorNum < 2 || floorNum > 24)
				return true;
		}
		else if (elevatorNum == 4 || elevatorNum == 5)
		{
			if (floorNum > 0 && floorNum < 26)
				return true;
		}
		else if (elevatorNum == 0 || elevatorNum == 1)
		{
			if (floorNum < 2 || floorNum % 2 == 0)
				return true;
		}
		else if (elevatorNum == 0 || elevatorNum == 1)
		{
			if (floorNum % 2 == 1)
				return true;
		}
		else
			return false;
	}
	else
		return false;
	return false;
}

