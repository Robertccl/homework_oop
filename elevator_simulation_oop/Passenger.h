#ifndef   MY_PASSENGER       //���û�ж��������  
#define   MY_PASSENGER       //���������  

#include "MyUtil.h"


class Passenger
{
public:
	Passenger();
	~Passenger();

	void setWitFloor(int waitFloor);
	int getWitFloor();

	void setDstFloor(int distFloor);
	int getDstFloor();

	void setBlongingNeedSpace(int belongingNeedSpace);
	int getBlongingNeedSpace();

	void setWaitElvatorNum(int waitElvatorNum);
	int getWaitElvatorNum();

	void setWaitTimeforNext();
	int getWaitTimeforNext();

	void setTakingtimes();
	int getTakingtimes();


	Passenger& operator= (const Passenger& p);
	bool friend operator==(const Passenger& p1, const Passenger& p2);

public:
	void init();
	//��һ�γ�����ʼ�������ĵ�ǰ¥��ͳ����ܴ���
	void nextTakeInit();

	bool isNone();

public:
	MyUtil* myUtil = MyUtil::getInstance();


public:
	int tokentimes;             //����Ҫ�������ݵĴ������ĵ��е�Ҫ�����L�Σ���L+1�λص�һ�㣬�������������L+1��

private:
	int waitFloor;            //���˵ȴ����ݵ�¥��
	int distFloor;              //����Ҫȥ����¥��
	int belongingNeedSpace;      //����Я����������Ʒռ�õĿռ�
	int waitElvatorNum;           //����Ҫ�ȵĵ��ݣ����ӿ͵ĵ���
	int takingtimes;             //�����Ѿ��������ݵĴ�����
	
	int waitTimeforNext;          //���һ�γ��ݻ����Ϣ��ʱ�䣬�����γ���֮��ļ�����������
};

#endif

