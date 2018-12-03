#include "MyUtil.h"



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