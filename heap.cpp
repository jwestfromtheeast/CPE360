// heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	//type "name", basic and stored by name
	int var;
	float y;

	//pointer: store address of another variable
	int *ptr = NULL; //ptr can store address of an integer variable
	int *floatptr; //store address of float variable
	//by default points to some bizzare location. can set to null to avoid this

	cout << "By default, my pointer points to: " << ptr << endl;

	ptr = &var;

	//var = 10;
	*ptr = 10;

	//var = var + 10
	*ptr = *ptr + 10;

	//ptr = 50; ERROR

	return 1;
}

