#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>

template <class T>
class Stack
{
	private:
		struct StackNode
		{
			T data;
			StackNode* next;
		};
		struct StackNode* top;  //top of the stack
		int size; 		 //-1 if not set, value otherwise
		int current_size; //unused if size = -1
	public:
		void push(T x); //if size set, check for overflow
		T pop();			//return element if not in underflow
		bool isEmpty(); //return true if empty, false otherwise
		Stack(int new_size);
		Stack();
		int getsize(){return size;}
};
//running time: O(1)
template<class T>
Stack<T>::Stack()
{
	size = -1;
	top  = NULL;
}
//running time: O(1)
template<class T>
Stack<T>::Stack(int new_size)
{
	size 		 = new_size;
	current_size = 0;
	top 		 = NULL;
}
//running time: O(1)
template<class T>
void Stack<T>::push(T x)
{
	if(size == -1)
		return;
	if(current_size == size)
	{
		std::cout << "Push can not be performed because of Overflow"<< std::endl;
		return;
	}
	struct StackNode* newel = new StackNode;
	newel -> data = x;
	current_size++;
	if(top == NULL)
	{
		newel -> next = NULL;
		top = newel;
		return;
	}
	newel->next = top;
	top = newel;
}
//running time: O(1)
template<class T>
T Stack<T>::pop()
{
	if(this -> isEmpty())
	{
		std::cout << "Pop cannot be performed because of Underflow" <<std::endl;
		exit(1);
	}
	if(size <=0)
		exit(1);
	T item = top->data;
	top = top->next;
	current_size--;
	return item;
}	
//running time: O(1)
template<class T>
bool Stack<T>::isEmpty()
{
	return (top == NULL);
}

#endif