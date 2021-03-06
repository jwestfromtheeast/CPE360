// recurse.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
using namespace std;

//global variable: born before main even runs, and even after it dies. only dies when the program comes to an end
int var;

int main()
{
	int *friendOfX; //1: pointer: cannot store value. only points to the location of other varibles. must use *
	int x = 10;
	int y = 20;

	cout << "value of x: " << x << endl;
	cout << "address of x: " << &x << endl;
	
	y = x; //this copies the value of x into y

	//2: Grab a variable's address, do not use a *. (aka referencing a pointer)
	friendOfX = &x; //friendOfX becomes aware of the address of x, holds the address
	//if you have the address of a variable, you can act as if you were the variable. 

	x = 20; //if you do this, x just goes to its house and rearranges the contents. changes in value

	//3: get friendOfX to go change the value of x from 20 to 30 (de-referencing a pointer)
	*friendOfX = 30;
	*friendOfX = *friendOfX + y + 50; // x = x + y + 50

	friendOfX = &y; //reassigns the pointer to point at the address of y instead. loses all memory of what it did with x

	cout << "Value of x: " << x << endl;

	return 1;
}

