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


	bool ChangeBattery(BasePower &powerBattery);   //更换电池 
	bool IsUsable();   //检测是否可用 
	bool Reset();     //如果不可用，可以重置学习

	bool TakeOn(int buttonNum);   //使用遥控器 


private:
	int buttonNum;             //按键的编码 ，对应不同的功能和切换频道 
	BasePower powerBattery;   //电源对象 ,由抽象基类BasePower继承得到的使电池电源
	BaseButton TVCurrencyButton;    //指定电视类型的通用按键 

	TVControlType type; //几种常见的电视遥控器的类型， 智能电视，一般普通电视，机顶盒，专用 
};


class AdjustableLamp : public Lamp
{

public:
	AdjustableLamp();
	AdjustableLamp(Lamp &lamp);
	~AdjustableLamp();


	bool PowerOn();   //上电 
	bool PowerOff();    //断电

	int LightAdjust(int strength);

	bool ChangeBulb(BaseBulb &lampBulb);

	bool ChangePower(BasePower &powerAdapter);



private:
	int lightStrength;   //0-10    <=0关灯，>=10最亮 
	BasePower powerAdapter;       //电源对象 ,由抽象基类BasePower继承得到的使用交流电的电源适配器 
	BaseBulb  lampBulb; 	//灯泡对象   抽象基类BasBulb继承得到的这种型号的台灯可以使用的电灯泡，分为普通和节能灯 
	LampBody lampBody;    //001型灯座 
	Lampshade lampshade;    //001型灯罩 
};