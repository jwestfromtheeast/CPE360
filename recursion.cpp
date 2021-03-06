// recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//function to calculate factorial
int fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
	{
		int fact = 1;
		for (int i = 1; i <= n; i++)
			fact *= i; //fact = fact*i
		return fact; //how to improve? well, a factorial is just the previous one times the number itself.
	}
}

int factorial(int n) //ONE: EXIT value or BASE case or ANCHOR value. when using recursion, it has to stop at some point. so check
					 //your conditiion for when do you exit and make sure it is established. this is the base case.
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	int n;
	cout << "Give me a number, I'll get you its factorial" << endl;
	cin >> n;
	cout << fact(n) << endl;
	cout << factorial(n) << endl; //both work!

	return 1;
}
