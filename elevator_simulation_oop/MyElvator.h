#pragma once
class MyElvator
{
public:
	MyElvator();
	~MyElvator();

	void setMaxCarryMen(int carryCapacity);



public:
	//���ݷ����ʼ��
	void simulationInit();
	//���ݷ��濪ʼ
	void simulationStart();

	//�������й���
	bool canArrive(int elevatorNum, int floorNum);



public:
	const int defaultCarryNum = 16;

private:
	int maxCarryMen;           //����ؿ���
	bool linkageFlag[10];      //������־, 0-9ÿ�����ݶ�Ӧ�Լ��ı�־����������һ�飬�����飬false��ʾû�нӿ�����
	int elevatorCarryMen[10];
};

