#ifndef OOP_QUEUE_H
#define OOP_QUEUE_H

#include <iostream>

using namespace std;

/*环形队列,可动态增大存储空间
实现接口：
插入一个元素
获取当前元素
获取当前所有元素个数
*/

template <class T>
class MyQueue 
{
public:
	MyQueue();
	
	int getElementNum(); //获取元素个数
	void push(T t);         //插入一个元素
	T& pop();            //弹出当前元素，并删除
	T& getElement();      //获取当前元素不删除

	void getBigSpace(); //扩充当前数组的大小

	~MyQueue();
	
private:
	T * header;   //头
	
	int index;    //当前位置   当前位置有元素
	int tail;      //队尾   队尾没有元素

	int size;         //当前队列的最大空间
};


#endif