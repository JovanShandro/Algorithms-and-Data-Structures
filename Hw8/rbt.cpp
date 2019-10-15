//https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
/*
	Please use the above linke to test
	the generated tree with the insertions
	I have made below and how everything
	works when being tested, the min, max,
	successor, predecessor, insert and del.
*/

#include <iostream>
#include "Rbtree.h"

using namespace std;

void printcolor(Node *n)
{
	if(n->color == BLACK)
		cout << "BLACK" << endl;
	else
		cout <<"RED"<<endl;
}

int main()
{
	Node* n = new Node;
	RedBlackTree a;
	a.insert(3);
	a.insert(2);
	a.insert(5);
	a.insert(7);
	//printing empty line
	cout<<endl;
	//testing minimum	
	n = a.getMinimum();
	cout << "The smallest data is :" << n->data << endl;
	cout <<"Color of node: ";
	printcolor(n);

	//testing successor
	const Node* m = n;
	 n = a.successor(m);
	cout << "The successor of the previous node is " 
	     << n->data << endl;
	cout <<"Color of node: ";   
	printcolor(n);

	//test max
	n = a.getMaximum();
	cout << "The largest data is :" << n->data << endl;
	cout <<"Color of node: ";
	printcolor(n);
	
	//test predecessor
	const Node* y =n;
	 n = a.predecessor(y);
	cout << "The predecessor of the largest value node is :" 
	     << n->data << endl;
	cout <<"Color of node: ";
	printcolor(n);
	
	//test search
	n = a.search(5);
	cout<<"This should print 5 and its color:"<<endl;
	cout << n->data <<" ";
	printcolor(n);
	
	//test delete
	a.del(n);
	cout<<"We see if 5 is deleted"<<endl;
	n = a.predecessor(y);
	cout << "Now the predecessor of the largest value node is :" 
	     << n->data << endl;
	cout<< "Color of node: ";
	printcolor(n);
	//empty line
	cout<<endl;
	return 0;
}