#include "oop2_queue.h"

template <class T>
MyQueue<T>::MyQueue()
{
	index = 0;
	tail = 0;
	size = 10;
	header = new T[size];

}

template <class T>
int MyQueue<T>::getElementNum()
{
	if ((tail+1) % size == index)
		return size;
	else
		return (tail-index+size) % size;
}

template <class T>
void MyQueue<T>::push(T t)
{
	if (getElementNum() == size)
	{
		getBigSpace();                    
	}
	
	header[tail] = t;           //T类型需要实现深复制
	tail = (tail + 1) % size;
}

template <class T>
T& MyQueue<T>::pop()
{
	T temp = *(header + index);   //T类型需要实现深复制
	index = (index+1) % size;
	return temp;
}

template <class T>
T& MyQueue<T>::getElement()
{
	return *(header+index);
}

template <class T>
void MyQueue<T>::getBigSpace()
{
	int newSize = size * 2;
	T *temp = new T[newSize];
	int k = 0;
	
	for(int i=index; i != tail; i++)
	{
		i = i % size;
		temp[k++] = header[i];
	}
	delete [] header;
	header = temp;
	temp = NULL;
	size = newSize;
	index = 0;
	tail = k;
}

template <class T>
MyQueue<T>::~MyQueue()
{
	delete []header;
}


int main()
{
	MyQueue<int> q;
	for(int i=0; i<20; i++)
	q.push(i);
	cout << q.getElement() << endl;
	q.pop();
	cout << q.getElementNum() << endl;
	cout << q.getElement() << endl;
	getchar();

}