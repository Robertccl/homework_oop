#ifndef   MY_UTIL       //���û�ж��������  
#define   MY_UTIL      //���������  

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
	int random(int min, int max);  //����ָ����Χ�������

private:
	MyUtil();
	~MyUtil();
	
};

#endif

