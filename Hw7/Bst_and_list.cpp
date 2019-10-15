#include <iostream>
#include <list>

using namespace std;

/*The linked list class definition*/
template <class T>
class LinkedList
{
	private:
		struct node
		{
			T data;
			struct node* next;
		};
		struct node* head;
	public:
		LinkedList();
		void push_back(T item);
		void print();
		LinkedList<T> operator+ (LinkedList<T> l);
};

//Linked list class methods
template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
}

template <class T>
void LinkedList<T>::push_back(T item)
{
	struct node* newel = new node;
	struct node* cursor = head;
	newel -> data = item;
	newel -> next = NULL;
	if(head == NULL)
		head = newel;
	else
	{
		while(cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = newel;
	} 
}

template <class T>
void LinkedList<T>::print()
{
	struct node* cursor = head;
	while(cursor)
	{
		cout << cursor->data;
		if(cursor->next != NULL)
			cout<<" ";
		cursor = cursor->next;
	}		
	cout<<endl;
}
//we will need the overloaded + in the conversion function
template <class T>
LinkedList<T> LinkedList<T>::operator+ (LinkedList<T> l)
{
	LinkedList<T> nl;
	if(head != NULL && l.head != NULL)
	{
		struct node* newhead = new node;
		struct node* cursor = this->head;

		newhead = this->head;
		while(cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = l.head;
		nl.head = newhead;
	}else if(head == NULL)
	{
		nl.head = l.head;
	}else if(l.head == NULL)
	{
		nl.head = head;
	}
	return nl;
}

//BINARY SEARCH TREE CLASS DEFINITION
template <class T>
class Binary_search_tree{
	private:
		struct Node
		{
			T data;
			//Node* parent;
			Node* lchild;
			Node* rchild;
			Node(T item) : data(item), lchild(NULL), rchild(NULL){}
		};
		struct Node* root;
	public:
		Binary_search_tree();
		~Binary_search_tree();
		void insert(T data);
		void insert(struct Node* r, T data);
		void print();
		void print(struct Node* node);
		LinkedList<T> toList();
		LinkedList<T> tolist(struct Node* r, LinkedList<T>& l);
		void deleteTree(Node * node);
};

//Methods of the Binary search tree class
template <class T>
Binary_search_tree<T> :: Binary_search_tree()
{
	root = NULL;
}

template <class T>
void Binary_search_tree<T>::insert(T data)
{
	insert(root, data);
}

template <class T>
void Binary_search_tree<T>::insert(struct Node* r, T data)
{
	if(!r)
	{
		r = new Node(data);
		root  = r;
	}
	else
	{
		if (data < r->data)
		{
			if(!r->lchild)
			{
				struct Node* newel = new Node(data);
				r -> lchild = newel;
			}else
				insert(r->lchild, data);
		}
		else
		{
			if(!r->rchild)
			{
				struct Node* newel = new Node(data);
				r -> rchild = newel;
			}else
				insert(r->rchild, data);
			
		}
	}
}

template <class T>
void Binary_search_tree<T>::print()
{
	print(root);
	cout<<endl;
}

template <class T>
void Binary_search_tree<T>::print(struct Node* node)
{
	if(!node)
		return;
	print(node->lchild);
	cout << node->data<<" ";
	print(node->rchild);
}

template <class T>
LinkedList<T> Binary_search_tree<T>::toList()
{
	LinkedList<T> l;

	return tolist(root, l);
}

template <class T>
LinkedList<T> Binary_search_tree<T>::tolist(struct Node* r, LinkedList<T>& l)
{
	if(!r)
		return l;
	LinkedList<T>  a = tolist(r->lchild,l); 
	a.push_back(r->data);
	a = a + tolist(r->rchild,l);
	return a;			
}

template <class T>
void Binary_search_tree<T>::deleteTree(Node * node)
{
	if(!node)
		return;
	Node * c = node;
    Node * l = node->lchild;
    Node * r = node->rchild;
    delete(c);
    deleteTree(l);
    deleteTree(r);
}

template <class T>
Binary_search_tree<T>:: ~Binary_search_tree()
{
	deleteTree(root);
}


//main function
int main()
{
	//POINT B
	cout<<"Problem 7.2 point B"<<endl;
	Binary_search_tree <int>b;
	b.insert(5);
	b.insert(10);
	b.insert(3);
	b.insert(51);
	b.insert(110);
	b.insert(13);
	b.insert(63);
	cout<<"The elements of the Binary search ";
	cout<<"tree in increasing order are: "<<endl;
	b.print();
	cout<<endl;

	LinkedList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);

	//testing the method that does the conversion
	LinkedList<int> a = b.toList();
	cout<<"The singly linked list is: "<<endl;
	a.print();

	cout<<endl;

	/*
		POINT C
		THE  ALGORITHM FOR CONVERTING SORTED LINKED LIST
		TO A BINARY SEARCH TREE
	*/
	cout<<"Problem 7.2 point C"<<endl;
	//the list that will be turned to a bst
	list<int> t;
	t.push_back(11);
	t.push_back(22);
	t.push_back(33);
	t.push_back(4);
	t.push_back(55);
	t.push_back(6);
	t.push_back(12);
	//the bst that will store the final result
	Binary_search_tree<int> c;
	//make sure list is sorted
	t.sort();
	//remove middle element and put as root data of tree
	int i = (int)t.size(); 
	list<int>::iterator it = t.begin();
	advance(it, i/2);
	c.insert(*it);
	t.erase(it);
	//pass all other elements from list to bst
	for(it = t.begin(); it!= t.end(); it++)
	{
		c.insert(*it);
	}
	cout << "The (ordered) data contained in the new tree is:\n";
	c.print();
	//since we choose the middle element to be the root
	//the tree is balanced and thus searching is performed 
	//in a better time compared to O(n) of the list.
	return 0;
}