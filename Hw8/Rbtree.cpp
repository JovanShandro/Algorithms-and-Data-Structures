#include <iostream>
#include "Rbtree.h"
using namespace std;

/*
	Initialize the tree with an empty root
*/
RedBlackTree::RedBlackTree()
{
	root = nullptr;
}

/*
	Implementation of the left rotation 
	explained in class
*/
void RedBlackTree::rotateLeft(Node *& x)
{
	Node* y = new Node;
	y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if(!x->parent)
		root = y;
	else
	{
		if( x = x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

/*
	Implementation of the right rotation 
	explained in class
*/
void RedBlackTree::rotateRight(Node *& x)
{
	Node* y = new Node;
	y = x->left;
	x->left = y->right;
	if(y->right)
		y->right->parent = x;
	y->parent = x->parent;
	if(!x->parent)
		root = y;
	else
	{
		if( x = x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

/*
	Implementation of the insert fixup
	function from the slides handling 
	all the color cases after node is added
*/
void RedBlackTree::insert_fixup(Node *& z)
{
	while(z->parent->color == RED) 
	{
		//I have used gp as a short way for grandparent
		// as a short form for z.p.p
        auto gp = z->parent->parent;
        auto y = root; 
        if(z->parent == gp->left) 
        {
            if(gp->right) 
            	y = gp->right;

            if(y->color == RED) //case 1
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                gp->color = RED;
                if(gp->data != root->data)
                	z = gp;
                else 
                	break;
            }
            else if(z == gp->left->right)//case 2 
            {
               rotateLeft(z->parent);
            }
            else //case 3
            {
                z->parent->color = BLACK;
                gp->color = RED;
                rotateRight(gp);
                if(gp->data != root->data)
                	z = gp;
                else 
                	break;
            }
        }
        else 
        {
            if(gp->left) 
            	y = gp->left;

            if(y->color == RED)//case 1
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                gp->color = RED;
            
                if(gp->data != root->data)
                	z = gp;
                else 
                	break;
            }
            else if(z == gp->right->left)//case 2
            {
                rotateLeft(z->parent);
            }
            else //case 3
            {
                z->parent->color = BLACK;
                gp->color = RED;
                rotateRight(gp);
                if(gp->data != root->data)
                	z = gp;
                else 
                	break;
            }
        }
    }
    root->color = BLACK;
}

/*
	Implementation of the insert 
	function from the slides with
	only slight changes as I am
	using nullptr instead of 
	nil node.
*/
void RedBlackTree::insert(int n)
{	
	//case tree is empty
	if(root == nullptr)
	{
	   root = new Node();
	   root->data = n;
	   root->parent = nullptr;
	   root->color = BLACK;
	}
	else 
	{
		auto x = root;
		Node* z= new Node();
		z->data = n;

		while(x != nullptr)
		{
	       if(x->data > n)
	       {
	           if(x->left == nullptr)
	           {
	               x->left = z;
	               z->color = RED;
	               z->parent = x;
	               break; 
	           }
	           else 
	           	{
	           		x = x->left; 
	           	}
	       } 
	       else 
	       {
	           if(x->right == nullptr)
	           {
	               x->right = z;
	               z->color = RED;
	               z->parent = x;
	               break; 
	           }
	           else 
	           {  
	           		x = x->right; 
	           }
	       }
	   }
	   insert_fixup(z);
	}
}
/*
	The delete function in the slides is 
	a bit unclear so I used the pseudocode 
	from the book 'Introduction to algorithms'
	which is the main textbook of the course 
	as I can not find what y-original-color is.
*/
void RedBlackTree::del(Node *& z)
{
	//a is needed to call the successor function below
	//as z is not constant
	const Node* a= z;
	Node* y, *x;

	if(z->left == nullptr || z->right == nullptr)
		y = z;
	else
		y = successor(a);
	
	if(y -> left != nullptr)
		x = y->left;
	else
		x = y->right;

	x->parent = y->parent;

	if(y->parent == nullptr)
		root = x;
	else if(y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	
	if(y != z)
		z->data = y->data;
	if(y->color == BLACK)
		delete_fixup(x);
}

/*
	Implementation of the delete fixup
	function from the slides handling 
	all the color cases after node is removed
*/
void RedBlackTree::delete_fixup(Node *& x)
{
	while(x->data != root->data && x->color == BLACK) 
	{
        auto w = root;
        if(x->parent->left == x) 
        {
            if(x->parent->right)
            	w = x->parent->right;

            if(w) {
                //First case
                if(w->color == RED) 
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                 //second case
                if(w->left == nullptr && w->right == nullptr) 
                {
                    w->color = RED;
                    x = x->parent;
                }
                else if(w->left->color == BLACK && w->right->color == BLACK) 
                {
                    w->color = RED;
                    x = x->parent;
                }
                //third case
                else if(w->right->color == BLACK) 
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(w);
                    w = x->parent->right;
                } 
                else // forth case 
                {
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if(w->right)
                    	w->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } 
        } 
        else 
        {
            if(x->parent->right == x)
            {
                if(x->parent->left)
                	w = x->parent->left;

                if(w) 
                {
                    //first case
                    if(w->color == RED)
                    {
                        w->color = BLACK;
                        x->parent->color = RED;
                        rotateRight(x->parent);
                        w = x->parent->left;
                    }
                    //second case
                    if(w->left == nullptr && w->right == nullptr) 
                    {
                        w->color = RED;
                        x = x->parent;
                    }
                    else if(w->left->color == BLACK && w->right->color == BLACK) 
                    {
                        w->color = RED;
                        x = x->parent;
                    }
                    //third case
                    else if(w->left->color == BLACK) 
                    {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = x->parent->left;
                    } 
                    else //forth case
                    {
                        w->color = x->parent->color;
                        x->parent->color = BLACK;
                        if(w->left)
                        	w->left->color = BLACK;
                        rotateLeft(x->parent);
                        x = root;
                    }
                } 
            }

        }
    }
    x->color = BLACK;
}

/*
	Implementation of the predecessor 
	function as explained in class
*/
Node * RedBlackTree::predecessor(const Node *& x)
{
	Node* y = new Node;
	if(x->left)
		return this->getMaximum(x->left);//TODO se duhet argument
	y = x->parent;
	while(y && x == y->left)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/*
	Implementation of the successor 
 	function as explained in class
*/
Node * RedBlackTree::successor(const Node *& x)
{
	Node* y = new Node;
	if(x->right)
		return this->getMinimum(x->right);//TODO se duhet argument
	y = x->parent;
	while(y && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/*
	Returns the node with the 
	smallest data out of 
	the whole tree
*/
Node * RedBlackTree::getMinimum()
{
	Node* x = new Node;
	 x = root;
	while(x->left)
		x = x->left;
	return x;
}

/*
	Returns the node with the 
	largest data out of 
	the whole tree
*/
Node * RedBlackTree::getMaximum()
{
	Node* x = new Node;
	x = root;
	while(x->right)
		x = x->right;
	return x;
}

/*
	Returns the node with the 
	smallest data out of 
	the subtree with root x
*/
Node * RedBlackTree::getMinimum(Node* x)
{
	while(x -> left)
		x = x->left;
	return x;
}

/*
	Returns the node with the 
	largest data out of 
	the subtree with root x
*/
Node * RedBlackTree::getMaximum(Node* x)
{
	while(x->right)
		x = x->right;
	return x;
}

/*
	Returns the node with the 
	data equal to the key parameter.
	Returns nullptr if no such 
	node is part of the tree
*/
Node * RedBlackTree::search(int key)
{
	Node* x = new Node;
	x = root;
	while(x && key != x->data)
	{	
		if(key < x->data)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}