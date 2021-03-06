// firstHeap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class Brick
{
public:
	int length;
	int width;

	Brick() 
	{
		length = 10;
		width = 5;
	}
};
int main()
{
	//NOT going to do
	//Brick var; one way to create. happens in the application space
	//STEP1: you need a pointer to go in to the heap
	Brick *ptr;

	//STEP 2: Using pointer, request for a new 'brick' from the heap
	ptr = new Brick;

	//STEP 3: Access that newly created brick in the heap
	ptr->length = 30;
	ptr->width = 40;

	//STEP 4: Let go of the chunk when you're done. return the space back to the heap like a book to the library
	delete ptr;

	return 1;
}

