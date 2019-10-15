#ifndef RBT_H
#define RBT_H

#include <iostream>

enum Color { RED, BLACK };
struct Node
{
	int data;
	Color color;
	Node *left, *right, *parent;
};

class RedBlackTree
{
	private:
		Node* root;
		void insert_fixup(Node *&);
		void delete_fixup(Node *&);
	protected:
		void rotateLeft(Node *&);
		void rotateRight(Node *&);
	public:
		RedBlackTree();
		void insert(int);
		void del(Node *&);
		Node * predecessor(const Node *&);
		Node * successor(const Node *&);
		Node * getMinimum();
		Node * getMaximum();
		Node * search(int);
		Node * getMinimum(Node*);
		Node * getMaximum(Node*);
};


#endif