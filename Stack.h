#pragma once
#ifndef STACK_H
#define STACK_H
#include<stddef.h>
template<typename T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
public:
	Stack():head(NULL)
	{}
	bool isempty()
	{
		return head == NULL;
	}
	void push(const T &that)
	{
		Node* createnode = new Node{ that };
		createnode->next = NULL;
		if (!head)
			head = createnode;
		else
		{
			createnode->next = head;
			head = createnode;
		}
	}
	void pop() 
	{
		if (!head)
			throw"EMPTY STACK";
		else
		{
			Node* t = head;
			head=head->next;
			delete t;
		}
	}
	const T& top()const
	{
		if (!head)
			throw"EMPTY STACK";
		else
			return head->data;
	}
	~Stack()
	{
		while (head)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};
#endif // !STACK_H


