/*  
	Implementing a queue out of 2 stacks
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include "Stack.h"

template <class T>
class Queue
{
	private:
		Stack<T>* s1, *s2;
		int size;
		int current_size=0;
	public:
		Queue(int size);
		void enqueue(T x);
		T dequeue();
		bool isEmpty();
};

template<class T>
Queue<T>::Queue(int size)
{
	this->size = size;
	s1 = new Stack<T>(size);
	s2 = new Stack<T>(size);
}

template<class T>
void Queue<T>::enqueue(T x)
{
	//take all data from s1 to s2
	if(current_size == size)
	{
		std::cout<<"Queue is full. Enqueue cannot be performed!"
				 << std::endl;
		return;
	}
	current_size++;
	while(!s1->isEmpty())
		s2->push(s1->pop());
	//push data x in the s1 stack
	s1->push(x);
	//push everything back to s1
	while(!s2->isEmpty())
		s1->push(s2->pop());
}

template<class T>
T Queue<T>::dequeue()
{
	if(isEmpty())
	{
		std::cout << "Queue is empty!" << std::endl;
		exit(0);
	}	
	current_size--;
	T data = s1->pop();
	return data;
}

template<class T>
bool Queue<T>::isEmpty()
{
	//as s2 is only used as additional
	//help to enqueue and dequeue
	return (s1->isEmpty());
}

#endif