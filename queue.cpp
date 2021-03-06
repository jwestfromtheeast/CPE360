// queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *next;

	Node()
	{
		value = 0;
		next = NULL;
	}
};

class Queue //queues follow FIFO order. elements must be added and removed from opposite sides.
{
public:
	Node *front;

	Queue()
	{
		front = NULL;
	}

	//1: add, enqueue
	void enqueue(int x)
	{
		Node *temp = new Node;
		temp->value = x;

		if (front == NULL) //if empty, our node becomes the new front node
			front = temp;
		else
		{
			temp->next = front;
			front = temp;
		}
	}

	//2: delete, dequeue
	void dequeue()
	{
		Node *temp, *target;
		temp = target = front;

		if (target == NULL) //empty
		{
			cout << "Empty queue, nothing to delete" << endl;
			return;
		}
		else if(target->next == NULL) //exactly 1 node
		{
			cout << "About to delete: " << target->value << endl;
			delete front;
			front = NULL;
		}
		else //more than one Node
		{
			while (target->next != NULL)
			{
				temp = target;
				target = target->next; //temp is now the second to last node, and target is the last node
			}
			temp->next = NULL; //ground our new last node
			cout << "About to delete: " << target->value << endl;
			delete target; //delete target node
		}
	}

	//3: display
	void printContents()
	{
		Node *traverse = front;
		while (traverse != NULL)
		{
			cout << traverse->value << endl;
			traverse = traverse->next;
		}
	}
};


int main()
{
	Queue object;
	int choice, value;

	while (1)
	{
		cout << "=================================================" << endl;
		cout << "Press 1 to enqueue (add) to queue" << endl;
		cout << "Press 2 to dequeue (delete) from queue" << endl;
		cout << "Press 3 to display" << endl;
		cout << "Anything else to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Add what?" << endl;
			cin >> value;
			object.enqueue(value);
			break;

		case 2: object.dequeue();
			break;

		case 3: cout << "Printing Queue contents:" << endl;
			object.printContents();
			break;

		default: cout << endl;
		}
	}
	return 0;

}