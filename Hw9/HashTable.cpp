#include <iostream>
#include "HashTable.h"

using namespace std;
//Node class
Node::Node(int key, int value)
{
	this->key   = key;
	this->value = value;
}

//Hashtable class
HashTable::HashTable()
{
	maxSize = 7;
	currentSize = 0;
	//allocate memory for the array
	arr = new Node* [maxSize];
	//initialize all entries to nullptr
	for(int i = 0; i<maxSize; i++)
		arr[i] = nullptr;
}

int HashTable::hashCode(int key)
{
	return key % maxSize;//0 to 6 in our case
}

void HashTable::insertNode(int key, int value)
{
	/*
		check if the table if full
	*/
	if(currentSize == maxSize)
		return;
	//create new node with desired key and value
	Node *newelem = new Node (key,value);

	//search for the right place in the table
	int newelemcode = hashCode(key);
	while(arr[newelemcode] != nullptr && arr[newelemcode]->key != key)
	{
		//use linear probing in case of collision
		newelemcode++;
		if(newelemcode >= maxSize)
		{
			newelemcode  = newelemcode % maxSize;
		}
	}
	/*
		Check if we just change the value of an existing 
		node or if we are adding a node. If it is the later 
		case we increase the current size by 1.
	*/
	if(arr[newelemcode] == nullptr)
		currentSize++;
	//insert new element in desired place
	arr[newelemcode] = newelem;

}

int HashTable::get(int key)
{
	//get the code of the node with the entered key
	int code = hashCode(key);
	/*
		To keep track of how many entries we checked as 
		we may end up in an infinite loop no entries have the 
		desired key and the table is full
	*/
	int nr_of_checked_entries = 0;
	//search for the node with the given key
	while(arr[code] != nullptr)
	{
		if(nr_of_checked_entries > maxSize)
			break;
		//if node found return value
		if(arr[code]->key == key)
			return (arr[code]->value);
		//go to next entry
		code++;
		if(code >= maxSize)
			code = code % maxSize;
		//since we checked on more entry
		nr_of_checked_entries++;
	}
	//if no such node is in the table
	std::cout << "No element with the given key exists!!" << std::endl;
	return (-1);
}

bool HashTable::isEmpty()
{
	return currentSize == 0;
}
//printing entries will help us test if the class works properly
void HashTable::printTable()
{ 
	//iterate throughout the array
    for(int i=0 ; i< maxSize ; i++) 
    { 
        if(arr[i] != nullptr)
        {
        	//print the keys and the value of non empty node
        	std::cout << "For key: " << arr[i]->key;  
            std::cout <<" the value is: "<< arr[i]->value;
            std::cout << std::endl; 
        } 
    } 	
}