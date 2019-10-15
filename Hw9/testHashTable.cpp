#include <iostream>
#include "HashTable.h"

using namespace std;

/*
	Just to ilustrate the insertNode function
	when we enter more values than the maxSize, 
	I chose maxSize to be 7. Otherwise in real 
	implementations we would choose a bigger 
	maxSize depending on how many values do we
	need to store in the hash table.
	The hashcode function I chose is basicly the 
	most simply hashcode we can think of, which 
	takes the key in modulo maxSize, and as required
	we use linear probing to handle collisions and
	I chose this hashcode as we get linear time only
	if all the numbers have same remainder modulo maxSize,
	but this is unprobable as we can choose maxSize to 
	be a prime number for example not 7 but 37 (if we
	need more values to store)
*/

int main()
{
	cout << "\nRunning hashtable implementation:\n"<<endl;

	HashTable ht;
	ht.insertNode(1,76);
	ht.insertNode(2,93);
	ht.insertNode(3,40);
	ht.insertNode(4,47);
	ht.insertNode(5,10);
	ht.insertNode(6,55);
	ht.insertNode(7,55);
	//these will not do anything
	ht.insertNode(8,55);
	ht.insertNode(9,55);
	ht.insertNode(10,55);

	int a = ht.get(7);
	cout << "Testing get:"<<endl;
	cout << "The value with key 7 is: " << a <<endl << endl;
	//print the table entries
	ht.printTable();

	return 0;
}
