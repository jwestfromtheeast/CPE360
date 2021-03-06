// chromeTab.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class chromeTab
{
public:
	int length;
	int width;
	chromeTab *next; //pointer to next chunk, keep them all connected

	chromeTab()
	{
		length = 100;
		width = 50;
		next = NULL;
	}
};

int main()
{
	//STEP1: Grab a pointer
	chromeTab *ptr;

		//our first tab in the heap
		ptr = new chromeTab; //nameless object, bt it does have an address (ptr)
		ptr->length = 200;

		//use the first tab and create a second tab
		//the first tab must point to the second tab
		//general pointer syntax: <pointer LHS> = new <TYPE>
		ptr->next = new chromeTab;

		//next lets create a third tab such that the second one points to this
		ptr->next->next = new chromeTab;

		//create a fourth tab so that the third points to the fourth.
		ptr->next->next->next = new chromeTab;

		//set 4th tab width to 80. using the ptr to get to 1st, 3 next to 4th, then width to get to the 4th width.
		//since each stores the pointer for the next, must call it from the previous.
		ptr->next->next->next->width = 80;

		//set 2nd tab length to 200
		ptr->next->length = 200;

		//set third tab width to -1
		ptr->next->next->width = -1;

		cout << ptr->next->next->next->width << endl; //print 80



    return 1;
}

