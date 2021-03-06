// SparseArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class MatrixElement
{
public:
	int value, x, y;
	MatrixElement *next;

	MatrixElement()
	{
		value = 1;
		x = 0;
		y = 0;
		next = NULL;
	}
};

class SparseMatrix //linked list: insert or delete anywhere
{
public:
	MatrixElement * head;
	int length; //keep track of the length of your link list to help figure out where you are later

	SparseMatrix()
	{
		head = NULL;
		length = 0;
	}

	void addElement(int n, int m, int val)
	{
		MatrixElement *temp = new MatrixElement, *traverse = head;
		temp->x = n;
		temp->y = m;
		temp->value = val;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			while (traverse->next != NULL)
				traverse->next = temp;
		}
	}
	

	//generate a sparse matrix
	void generate()
	{
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				//produce a value in range 1 through 100
				int random_value = rand() % 100 + 1;
				if (random_value <= 5)
				{
					addElement(i, j, 1);
				}
			}
		}
	}

	void display()
	{
		MatrixElement *traverse = head;
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				while (traverse != NULL)
				{
					traverse = traverse->next;
					if (traverse->x == i && traverse->y == j)
					{
						cout << "1 ";
						break;
					}
				}
				if (traverse == NULL)
					cout << "0 ";
			}
			cout << " " << endl;
		}
	}
};

int main()
{
	//END GOAL: CREATE 3 SPARSE MATRICES, THE FIRST 2, AND THE SUM. THEY DON'T REALLY EXIST AND ARE ONLY REPRESENTED
	//BY THEIR LINKED LISTS, WHICH ONLY INCLUDE ELEMENTS FOR THE NONZERO VALUES.
	srand(time(NULL));
	SparseMatrix matrix1;
	int guess;
	MatrixElement *matA = NULL, *tempA = NULL;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			guess = rand() % 100 + 1;
			if (guess <= 5)
			{
				if (matA == NULL)
				{
					matA = new MatrixElement;
					matA->x = i + 1;
					matA->y = j + 1;
					matA->value = 1;
					tempA = matA;
				}
				else
				{
					tempA->next = new MatrixElement;
					tempA = tempA->next;
					tempA->x = i + 1;
					tempA->y = j + 1;
					tempA->value = 1;
				}
				cout << 1 << " ";
			}
			else
				cout << 0 << " ";
		}
		cout << endl;
	}

	int done = 0;
	tempA = matA;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//print zero or nonzero?
			if (done != 1)
			{
				if (tempA->x == i + 1 && tempA->y == j + 1)
				{
					cout << " " << tempA->value << " ";
					tempA = tempA->next;
					if (tempA == NULL)
						done = 1;
				}
				else
					cout << " " << 0 << " ";
			}
			else
				cout << " " << 0 << " ";
		}
		cout << endl;
	}
	matrix1.generate();
	matrix1.display();
	return 1;
}

