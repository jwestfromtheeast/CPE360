// stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//first we create the idea of a "chunk"
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

//second we create the idea of a "stack of chunks"
class Stack
{
public:
	//stack of chunks
	//three operations: add (push), delete (pop), display

	//one attribute you need:
	Node *top; //the "top" of our "stack"

	//constructor
	Stack()
	{
		top = NULL;
	}

	void push(int x) //purpose: add this value 'x' all the way to the front
	{
		Node *temp = new Node;
		temp->value = x; //this chunk is now ready to be added to the stack

		//is my stack empty?
		if (top == NULL)
		{
			top = temp;
		}
		else //if not do something else
		{
			temp->next = top; //1
			top = temp; //2
		}
	}

	void pop() //purpose: to delete an element from the stack (the first one since it is a stack)
	{
		Node *temp;

		//is the stack empty?
		if (top == NULL)
		{
			cout << "Empty stack, nothing to delete" << endl;
		}
		else //if not, then you actually have something to delete
		{
			temp = top; //1: point our temp to the chunk we are deleting
			top = top->next; //2: top now points to the second chunk
			cout << "About to delete: " << temp->value << endl;
			delete temp;
		}
	}

	void displayContents()
	{
		Node *traverse;

		traverse = top; //start at beginning
		while (traverse != NULL) //if you did while(traverse), would do the same thing. compiler is smart
		{
			cout << traverse->value << endl; //print value of chunk traverse points to
			traverse = traverse->next; //point to next chunk
		}
	}

};

int main()
{
	Stack object;
	int choice, value;

	while (1)
	{
		cout << "=================================================" << endl;
		cout << "Press 1 to push (add) to Stack" << endl;
		cout << "Press 2 to pop (delete) from Stack" << endl;
		cout << "Press 3 to display" << endl;
		cout << "Anything else to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Add what?" << endl;
			cin >> value;
			object.push(value);
			break;

		case 2: object.pop();
			break;

		case 3: cout << "Printing Stack contents:" << endl;
			object.displayContents();
			break;

		default: exit(1);
		}
	}
	return 1;
}

