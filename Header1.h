#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


template <typename T>
struct Node_stack {
	T val;
	Node_stack<T>* next;

	Node_stack(T d)
	{
		val = d;
		next = NULL;
	}
};

template  <class T>
class stack
{
	Node_stack <T>* top;
	int size;
public:
	stack(int ignored = 0)
	{
		top = NULL;
		size = 0;
	}

	~stack()
	{

	}

	void push(const T DataItem)
	{
		Node_stack<T>* temp = new Node_stack<T>(DataItem);
		if (top == NULL)
		{
			top = temp;
			size++;
		}
		else
		{
			temp->next = top;
			top = temp;
			size++;
		}
	}

	T pop()
	{
		T data;
		if (top == NULL)
		{
			return NULL;
		}
		else
		{
			Node_stack<T>* p = top;
			data = top->val;
			top = top->next;
			p = NULL;
			delete p;
			size--;
		}
		return data;
	}
	Node_stack<T>* Peek()
	{
		T data;
		if (top == NULL)
		{
			return NULL;
		}
		else
		{
			return top;
		}

	}
	void clear()
	{
		while (top->next != NULL)
		{
			pop();
		}
		size = 0;
	}
	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int sizeofstack()
	{
		return size;
	}

};

