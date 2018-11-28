#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <memory.h>
#include <random>


using namespace std;


class MyUtil
{
public:
	
	~MyUtil();
	static MyUtil *myUtil;
public:
	static MyUtil* getInstance()
	{
		if (myUtil == NULL)
			myUtil = new MyUtil();
		return myUtil;
	}

public:
	int random(int min, int max);  //����ָ����Χ�������

private:
	MyUtil();
};

