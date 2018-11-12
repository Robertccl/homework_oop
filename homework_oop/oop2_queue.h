#ifndef OOP_QUEUE_H
#define OOP_QUEUE_H

#include <iostream>

using namespace std;

/*���ζ���,�ɶ�̬����洢�ռ�
ʵ�ֽӿڣ�
����һ��Ԫ��
��ȡ��ǰԪ��
��ȡ��ǰ����Ԫ�ظ���
*/

template <class T>
class MyQueue 
{
public:
	MyQueue();
	
	int getElementNum(); //��ȡԪ�ظ���
	void push(T t);         //����һ��Ԫ��
	T& pop();            //������ǰԪ�أ���ɾ��
	T& getElement();      //��ȡ��ǰԪ�ز�ɾ��

	void getBigSpace(); //���䵱ǰ����Ĵ�С

	~MyQueue();
	
private:
	T * header;   //ͷ
	
	int index;    //��ǰλ��   ��ǰλ����Ԫ��
	int tail;      //��β   ��βû��Ԫ��

	int size;         //��ǰ���е����ռ�
};


#endif