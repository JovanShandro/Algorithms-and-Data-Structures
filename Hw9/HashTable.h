#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

class Node
{
	public:
		int key;
		int value;
		Node(int key, int value);
};

class HashTable
{
	private:
		Node **arr;
		int maxSize;
		int currentSize;
	public:
		HashTable();
		int hashCode(int key);
		void insertNode(int key, int value);
		int get(int key);
		bool isEmpty();
		//additional method to print entries
		void printTable();
};

#endif