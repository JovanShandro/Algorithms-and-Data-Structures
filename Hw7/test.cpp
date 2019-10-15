#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	cout << "Problem 7.1 "<<endl;
	Stack<int> s(6);
	Queue<int> q(5);
	//testing stack
	s.push(1);
	s.push(5);
	s.push(4);
	s.push(2);
	s.push(11);
	s.push(19);
	cout<<"Size is "<<s.getsize()<<endl;
	for(int i = 0; i<3; i++)
	{
		int a = s.pop();
			cout<<"Popping : "<< a <<endl;
	}
	cout<<endl;

	//testing queue
	q.enqueue(4);
	q.enqueue(9);
	q.enqueue(-2);
	q.enqueue(7);
	q.enqueue(48);
	q.enqueue(14);//14 will not be added 


	for(int i = 0; i<7; i++)
	{
		int a = q.dequeue();
		cout << "Just removed : " << a << endl; 
	}

	return 0;
}

