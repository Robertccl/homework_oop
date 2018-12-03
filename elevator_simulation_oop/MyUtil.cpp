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
	//蠢方法
	//srand((int)time(0));   //随机数种子，让每次生成的随机数都不一样
	//
	//cout << "普通方法" << endl;
	//cout<< min + (max-min) * rand() / RAND_MAX;
	//cout << endl;

	//C++ 随机数的高级方法
	//default_random_engine e;
	//uniform_int_distribution<unsigned> u(min, max); //随机数分布对象

	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<int> u(min, max); //随机数分布对象
	
	
	return u(rng);
}