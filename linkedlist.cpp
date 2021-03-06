// linkedlist.cpp : Defines the entry point for the console application.
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

class LL //linked list: insert or delete anywhere
{
public:
	Node *head;
	int length; //keep track of the length of your link list to help figure out where you are later

	LL()
	{
		head = NULL;
		length = 0;
	}

	//add at the start
	void insertAtHead(int x)
	{
		Node *temp = new Node;
		temp->value = x;
		if (length == 0) //if empty
			head = temp;
		else
		{
			temp->next = head; //set our temp node to point to the first node of the list
			head = temp; //make our temp node the new first node of the list
		}
		length++;
	}

	//add anywhere, be sure to increment your length
	void insertAtPosition(int x, int pos) //first thing, compare position with length + 1
	{
		if (pos <= length + 1 && pos > 0)
		{
			if (pos == 1)
			{
				insertAtHead(x);
				length++;
			}
			else if (pos == length + 1) //pointers: one for new chunk, other to go to the end
			{
				Node *temp = new Node;
				Node *traverse = head;
				temp->value = x;
				for (int i = 1; i <= length; i++) //move traverse to the last current node
					traverse = traverse->next;
				traverse->next = temp; //insert our new node after the last node

				length++;
			}
			else
			{
				Node *temp = new Node;
				temp->value = x;

				Node *traverse = head;
				for (int i = 1; i < pos-1; i++) //this will stop traverse at our desired position.
				{
					traverse = traverse->next;
				}
				temp->next = traverse->next; //our new node now links to what traverse node links to (the old node in spot)
				traverse->next = temp; //traverse node now links to our node. successfully threaded in after traverse
				length++;
			}
		}
		else
		{
			cout << "Invalid position" << endl;
			return;
		}
	}

	//remove: delete anything anywhere, be sure to decrement your length
	void removeFromPosition(int pos)
	{
		if (pos <= length && pos > 0)
		{
			if (pos == 1)
			{
				if (length == 0)
				{
					cout << "Linked List empty, nothing to delete." << endl;
				}
				else
				{
					Node *temp = head;
					head = head->next; //head now points to second node so we can delete first
					cout << "About to delete " << temp->value << endl;
					delete temp;
					length--;
				}
			}
			else if (pos == length) //delete last node
			{
				Node *traverse = head;
				for (int i = 1; i < length; i++) //get traverse to point to the last node
					traverse = traverse->next;
				cout << "About to delete " << traverse->value << endl;
				delete traverse;
				length--;
			}
			else
			{
				Node *temp, *traverse;
				temp = traverse = head;
				for (int i = 1; i < pos; i++)
				{
					temp = traverse; //we keep temp one node behind traverse. so, temp can be threaded to the node after traverse
					traverse = traverse->next; //and we can delete traverse
				}
				temp->next = traverse->next;
				delete traverse;
				length--;
			}
		}
		else
		{
			cout << "Invalid position" << endl;
			return;
		}
	}

	void searchAndDelete(int x) //have a pointer traverse to find a chunk with this value. have a second
	{							//behind it at all times so it is ready to link to the one after the target
		Node *fast, *slow;
		fast = slow = head;
		while (fast != NULL)
		{
			if (head->value == x)
			{
				slow = head;
				head = head->next;
				cout << "About to delete" << slow->value << endl;
				delete slow;
				length--;
				return;
			}
			else if (fast->value == x) //found it, delete, length--, return
			{
				slow->next = fast->next;
				cout << "About to delete " << fast->value << endl;
				delete fast;
				length--;
				return;
			}
			slow = fast;
			fast = fast->next;
		}
		if (fast == NULL)
		{
			cout << "Desired element does not exist in the list" << endl;
			return;
		}

	}

	//display
	void displayContents()
	{
		Node *traverse = head;
		while (traverse != NULL)
		{
			cout << traverse->value << endl;
			traverse = traverse->next;
		}
	}
};

int main()
{
	LL object;
	int choice, value, pos;

	while (1)
	{
		cout << "=================================================" << endl;
		cout << "Press 1 to insert at the start of the Linked List" << endl;
		cout << "Press 2 to insert a Node at a specified position" << endl;
		cout << "Press 3 to remove a Node from a specified position" << endl;
		cout << "Press 4 to remove the first instance of a Node with a given value" << endl;
		cout << "Press 5 to display the Linked List" << endl;
		cout << "Anything else to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Add what?" << endl;
			cin >> value;
			object.insertAtHead(value);
			break;

		case 2: cout << "Add what?" << endl;
			cin >> value;
			cout << "Add where?" << endl;
			cin >> pos;
			object.insertAtPosition(value, pos);
			break;

		case 3: cout << "Remove where?" << endl;
			cin >> pos;
			object.removeFromPosition(pos);
			break;

		case 4: cout << "Remove what?" << endl;
			cin >> value;
			object.searchAndDelete(value);
			break;

		case 5: cout << "Printing Linked List:" << endl;
			object.displayContents();
			break;

		default: exit(1);
		}
	}
	return 1;
}

