// oop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//class
class Shoe
{
public: //call public to give access priviledge
	//attributes of a class
	float price;
	float size;
	char color;

	//constructor: helps to create default items of said type. when i create a shoe, what is the default value for the attributes?
	//implicitly called when creating an object of this type
	Shoe()
	{
		price = 100.0;
		size = 6.5;
		color = 'b';
	}

	//can come built in with said functions, and can be called from those objects
	void itemOnSale() {
		price = price / 2;
	}
};

int main()
{
	//instead of just creating variables in the main function, create class representing your unique kind of data
	Shoe item1, item2; //create new class of objects that reflect your definition above
	int x;

	x = 10;
	//use the objects you created and access the attributes and functions
	//use the DOT operator
	cout << "Price of item1: " << item1.price << endl;
	item1.price = 500.0;

	item1.itemOnSale();
	cout << "Price after sale: " << item1.price << endl;

	//address of item2 and x
	cout << "Address of item: " << &item2 << endl;
	cout << "Address of x: " << &x << endl;

	//pointers
	int *ptr; //integer pointer
	Shoe *shoeptr; //shoe pointer

	//get our pointers to point to the boxes
	ptr = &x;
	shoeptr = &item2;

	//lets get these pointers to go change the variable values
	*ptr = 20; //change x to 20
	shoeptr->price = 500.0; //item.price = 500.0;
	shoeptr->size = 10.5; //item.size = 10.5

	cout << "Item's new price: " << item2.price << endl;

	return 1;
}

