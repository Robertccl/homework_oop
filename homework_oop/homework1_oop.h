#include <iostream>

using namespace std;

class BaseRemoteControl
{

};

class BasePower
{

};

class Lamp
{

};

class BaseButton
{

};

class BaseBulb
{

};

class LampBody
{

};

class Lampshade
{

};

enum TVControlType { smart, common, SetTopBox, Special };

class TVRemoteControl : public BaseRemoteControl
{
public:
	TVRemoteControl();
	TVRemoteControl(BaseRemoteControl &base);
	~TVRemoteControl();


	bool ChangeBattery(BasePower &powerBattery);   //������� 
	bool IsUsable();   //����Ƿ���� 
	bool Reset();     //��������ã���������ѧϰ

	bool TakeOn(int buttonNum);   //ʹ��ң���� 


private:
	int buttonNum;             //�����ı��� ����Ӧ��ͬ�Ĺ��ܺ��л�Ƶ�� 
	BasePower powerBattery;   //��Դ���� ,�ɳ������BasePower�̳еõ���ʹ��ص�Դ
	BaseButton TVCurrencyButton;    //ָ���������͵�ͨ�ð��� 

	TVControlType type; //���ֳ����ĵ���ң���������ͣ� ���ܵ��ӣ�һ����ͨ���ӣ������У�ר�� 
};


class AdjustableLamp : public Lamp
{

public:
	AdjustableLamp();
	AdjustableLamp(Lamp &lamp);
	~AdjustableLamp();


	bool PowerOn();   //�ϵ� 
	bool PowerOff();    //�ϵ�

	int LightAdjust(int strength);

	bool ChangeBulb(BaseBulb &lampBulb);

	bool ChangePower(BasePower &powerAdapter);



private:
	int lightStrength;   //0-10    <=0�صƣ�>=10���� 
	BasePower powerAdapter;       //��Դ���� ,�ɳ������BasePower�̳еõ���ʹ�ý�����ĵ�Դ������ 
	BaseBulb  lampBulb; 	//���ݶ���   �������BasBulb�̳еõ��������ͺŵ�̨�ƿ���ʹ�õĵ���ݣ���Ϊ��ͨ�ͽ��ܵ� 
	LampBody lampBody;    //001�͵��� 
	Lampshade lampshade;    //001�͵��� 
};