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
	static MyUtil* getInstance();
	

public:
	int random(int min, int max);  //生成指定范围的随机数

private:
	MyUtil();
	~MyUtil();
	
};

