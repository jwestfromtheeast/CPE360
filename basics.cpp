#include<iostream>
using namespace std;

int add(int x, int y) 
{
	int result;
	result = x + y;
	return result; //if a function returns something, can pretty much use it as that varible type. i.e. arithmetic, print, etc.
}

int main()
{
	//story of a variable
	//creation and destruction
	int var;
	int x = 10;
	int y = 50;

	var = 5;
	cout << "Value of var: " << var << endl; //value
	cout << "The address of var: " << &var << endl; //location in memory: address is different each time you run.
	//address starts with "0x" which means hexidecimal, after those 2 is the address. However, during each run, the memory
	//location will not change. Think of the memory as a giant parking lot, and programs all are cars coming and going.
	//So if you come every single day, you will always park in a different spot (old one likely occupied, shared w/ everyone).
	int result = add(x, y);
	cout << "Result: " << add(x, y) << endl;
	cout << "Result: " << result << endl;

	//each time a scope is called (i.e. the space between the curly brackets of a function), it is created only then. like, if the
	//add function is never called it is never created. When main is called, it creates a box of main, full of all variables and 
	//elements of main. when return is called, the function is "returned" and erased. So above, compiler starts in main, goes thru,
	//when it gets to add, jumps over to add box it created, runs thru add, returns the value and erases the box as if it never existed.
	//When you pass a value to a function, what actually gets passed is the value of the function. so when you call add(56, var), 
	//x gets a copy of 56, and y gets a copy of what exists inside var

	//can the same piece of code have 2 instances of x and y? i.e. create x and y in addition to the x and y in the add function.
	//think of scopes as houses.

	return 1;
}

