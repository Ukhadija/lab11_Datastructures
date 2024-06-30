#pragma once
#include <iostream>
using namespace std;
#include "Header1.h"

template <class T>
struct node
{
	T data;
	node <T>* next;

	node<T>(T d) {
		data = d;
		next = NULL;
	}
	node<T>() {
		data = 0;
		next = NULL;
	}
};

template <class T>
class Queue {
private:
	node<T>* front;
	node<T>* rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}

	void enqueue(T d)
	{
		node<T>* temp = new node<T>(d);
		/*temp->data = d;
		temp->next = NULL;*/
		if (front == NULL || rear == NULL)
		{
			front = temp;
			rear = temp;
		}
		else
		{
			//node<T>* temp1 = rear;
			rear->next = temp;
			//temp->next = NULL;
			rear = temp;
		}
	}

	T dequeue()
	{
		if (front == NULL || rear == NULL) {
			return NULL;
		}
		else {
			node <T>* temp = front;
			front = front->next;
			return temp->data;
		}
	}

	int Front()
	{
		return front->data;
	}

	bool isEmpty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}
		return false;
	}

	void Display()
	{
		node<T>* p = front;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;

		}
		cout << endl;
	}
};

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node() {
		data = 0;
		left = NULL;
		right = NULL;
	}

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BSTree
{
private:
	Node* root;

public:
	BSTree()
	{
		root = NULL;
	}
	Node* getRoot()
	{
		return root;
	}
	void insert(int d)
	{
		Node* m = new Node(d);
		Node* temp = root;
		if (root == NULL)
		{
			root = m;

		}
		else
		{
			while (temp != NULL)
			{
				if (d < temp->data)
				{
					if (temp->left == NULL)
					{
						temp->left = m;
						return;
					}
					else
					{
						temp = temp->left;
					}
				}
				else if (d > temp->data)
				{
					if (temp->right == NULL)
					{
						temp->right = m;
						return;
					}
					else
					{
						temp = temp->right;
					}
				}

			}
		}

		m = NULL;
		delete m;
	}
	bool retrieve(int d)
	{
		bool exists = false;
		Node* temp = root;
		if (root == NULL)
		{
			return false;
		}
		else
		{
			while (temp != NULL)
			{
				if (d == temp->data)
				{
					exists = true;
					return exists;
				}
				else if (d < temp->data)
				{
					if (temp->left == NULL)
					{
						return false;
					}
					else
					{
						temp = temp->left;
					}
				}
				else if (d > temp->data)
				{
					if (temp->right == NULL)
					{
						return false;
					}
					else
					{
						temp = temp->right;
					}
				}

			}
		}
	}
	bool subtree(int* arr, int size)
	{
		bool flag = true;
		for (int i = 0; i < size; i++)
		{
			flag = retrieve(arr[i]);
			if (flag == false)
			{

				return false;
			}
		}
		return true;
	}
	void PreOrderTraversal(Node* r)
	{
		if (r == NULL)
		{
			return;
		}
		cout << r->data << ",";
		PreOrderTraversal(r->left);

		PreOrderTraversal(r->right);
	}

	void InOrderTraversal(Node* r)
	{
		if (r == NULL)
		{
			return;
		}
		InOrderTraversal(r->left);
		cout << r->data << ",";
		InOrderTraversal(r->right);
	}

	void inOrderWithStack(Node* r)
	{
		stack<Node*> treeStack;

		Node* p = r;
		while (p != NULL || !treeStack.isEmpty())
		{
			while (p != NULL)
			{
				treeStack.push(p);
				p = p->left;
			}
			p = treeStack.pop();
			cout << p->data << " ";
			p = p->right;
		}

	}

	void PostOrderTraversal(Node* r)
	{
		if (r == NULL)
		{
			return;
		}
		PostOrderTraversal(r->left);
		PostOrderTraversal(r->right);
		cout << r->data << ",";
	}
	void LevelOrder(Node* n)
	{
		Queue <Node*>* q = new Queue<Node*>;
		//Node* temp = n;
		//Node* curr ;
		if (n == NULL) 
			return;
		q->enqueue(n);

		while (!q->isEmpty())
		{
			Node* curr = q->dequeue();
			if (curr == NULL)
			{
				break;
			}
			if (curr != NULL)
			{
				cout << curr->data << ",";
				if (curr->left != NULL)
				{
					q->enqueue(curr->left);
				}
				if (curr->right != NULL)
				{
					q->enqueue(curr->right);
				}
			}
		}
		delete q;
	}
	int leastAncestor(Node* r, int a, int b)
	{
		if (a < r->data && b < r->data)
		{
			return leastAncestor(r->left, a, b);
		}
		else if (a > r->data && b > r->data)
		{
			return leastAncestor(r->right, a, b);
		}
		else
		{
			return r->data;
		}

	}
	Node* getMin(Node* n)
	{
		//int min = 0;
		if (n == NULL)
		{
			return NULL;
		}
		Node* q = n->left; //left most

		while (q->left != NULL)
		{
			q = q->left;
		}
		return q;

	}
	Node* Delete(Node* currRoot, int d)
	{
		//Node* p = root;
		if (currRoot == NULL)
		{
			return currRoot;
		}
		if (currRoot->data == d)
		{
			//delete
			
			if (currRoot->left == NULL && currRoot->right == NULL)
			{
				return NULL;
			}
			else if (currRoot->left == NULL)
			{
				
				Node* p = currRoot->right;
				currRoot = NULL;
				delete currRoot;
				//free(currRoot);
				return p;
			}
			else if (currRoot->right == NULL)
			{
				Node* p = currRoot->left;
				currRoot = NULL;
				delete currRoot;
				return p;
			}
			else
			{
				Node* p = getMin(currRoot->right);
				currRoot->data = p->data;
				currRoot->right = Delete(currRoot->right, p->data);
			}
		}
		else if (d < currRoot->data)
		{
			currRoot->left = Delete(currRoot->left, d);
		}
		else if (d > currRoot->data)
		{
			currRoot->right = Delete(currRoot->right, d);
		}
		
		return currRoot;
	}
	Node* removeKeys(Node* r,Node* r1, int a, int b)
	{
		if (r == NULL)
		{
			return NULL ;
		}
		removeKeys(r->left,r1, a, b);
		removeKeys(r->right,r1, a, b);
		if (!(r->data >= a && r->data <= b))
		{
			r1= Delete(r1, r->data);

		}
		return r1;
	}

	int getHeight()
	{

	}
};

int sum(Node* r, int lvl, int& s)
{
	if (lvl == 0 || r ==NULL)
	{
		if( r==NULL)
			return 0;
		return r->data + sum(r->right, lvl,s);
	}
	else
	{
		s = sum(r->left, lvl - 1,s);
		s = sum(r->right, lvl, s);
	}
}

void DiagnolSum(Node* r)
{
	int level = 0;
	Node* p = r;
	while (p != NULL)
	{
		p = p->left;
		level++;
	}
	level = 2;
	int s = 0;
	while (!(level < 0))
	{
		cout << sum( r, level, s)<<endl;
		level--;
	}
}