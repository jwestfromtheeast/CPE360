// simpleChrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//conceptually structure the data
class chromeTab
{
public:
	//attributes
	int length;
	int width;
	chromeTab *next;

	//constructor: all new tabs have these assigned attributes (default)
	chromeTab()
	{
		length = 100;
		width = 50;
		next = NULL;
	}
};


int main()
{
	chromeTab *head;

	//Add a bunch of chunks and create the "string of beads"
	//<Pointer> = new <structure_type>

	head = new chromeTab; //head---->tab1
	head->next = new chromeTab;
	head->next->next = new chromeTab; //head points to tab one, first tab points to tab 2, second to tab 3
	head->next->next->next = new chromeTab;
	head->next->next->next->next = new chromeTab; //tab 5 (remember not actually named, just has a known location in the heap)
	//change the third chunk: length to 30, width to 10
	head->next->next->length = 30; //head points to first tab. next to second. next to third. length to the length of the
	//third tab you are already looking at
	head->next->next->width = 10;
	//change the last chunk and change length to 200 width to 60
	head->next->next->next->next->length = 200;
	head->next->next->next->next->width = 60;
	
	//if you were to type head = NULL, would lose all the pointers (lost first, and all the rest after fall along with it)

	//delete ONE chunk
	//target to delete the second chunk. to do this,
	//must have a "temp" pointer at the chunk BEFORE (first)
	chromeTab *temp, *target;
	//get temp to point to the first chunk
	temp = head; //head has the address to the first one. this is like "copying a key", just points to same place
	target = head->next; //assign target to chunk we want to delete
	//the next point of the first one, and point to the third.
	temp->next = temp->next->next; //the pointer in the first chunk that points to the second chunk,
	//now will point to the third chunk. so now the list is knitted with the second chunk removed.
	//however, the second chunk still exists in the heap, and we have the address with target. must delete to prevent mem leak
	delete target; //get rid of the chunk whose address target has. it DOES NOT delete the target box itself

	//now, i want to get rid of the third CURRENT chunk (4th original)
	temp = head->next;
	target = head->next->next;
	temp->next = temp->next->next;
	delete target;

	return 1;
}

