// QueueLine1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
const int DAY = 1020; //a work day is 17 hours. 17 hours * 60 minutes is 1020 minutes in a day
int timeDay, orderTime, waitAvg, serviceAvg, queueAvg, waitBest, serviceBest, queueBest, waitWorst, serviceWorst, queueWorst;
bool emptyLine = true, singleLine = false;

class Customer
{
public:
	int order, waitTime, serviceTime; //track wait time and service time, use before customer leaves
	Customer *next;

	Customer()
	{
		order = rand() % 6 + 1;
		waitTime = serviceTime = 0;
		next = NULL;
	}
};

class QueueLine //QueueLines follow FIFO order. elements must be added and removed from opposite sides.
{
public:
	Customer * back;

	QueueLine()
	{
		back = NULL;
	}

	//1: add to back
	void enqueue()
	{
		Customer *temp = new Customer;

		if (back == NULL) //if empty, our Customer becomes the new back Customer
			back = temp;
		else
		{
			temp->next = back;
			back = temp;
		}
	}

	//2: delete from front
	void dequeue()
	{
		Customer *temp, *target;
		temp = target = back;

		if (target == NULL) //empty
		{
			return;
		}
		else if (target->next == NULL) //exactly 1 Customer
		{
			delete back;
			back = NULL;
		}
		else //more than one Customer
		{
			while (target->next != NULL)
			{
				temp = target;
				target = target->next; //temp is now the second to last Customer, and target is the last Customer
			}
			temp->next = NULL; //ground our new last Customer
			delete target; //delete target Customer
		}
	}

	//3: display
	void printContents()
	{
		Customer *traverse = back;
		while (traverse != NULL)
		{
			cout << traverse->order << endl;
			traverse = traverse->next;
		}
	}

	//goes through the day's clock. at each minute, check if a customer will arrive.
	//then, check the status of the current customer's order. if it is done, place the next order.
	void simulateDay()
	{
		timeDay = orderTime = waitAvg = serviceAvg = queueAvg = waitBest = //init all to 0
		serviceBest = queueBest = waitWorst = serviceWorst = queueWorst = 0;
		//events 1: someone walks in, 2: someone is done and walks out (both, 1, or neither can happen in any min)

		while (timeDay < DAY) //simulate a day one minute at a time
		{
			if (willCustomerArrive()) //every minute, first check if a customer will join the line
			{
				if (getLength() == 0) //if line is empty, then someone joins, it creates a special case.
					emptyLine = true;
				else
					emptyLine = false;
				enqueue();
				if (getLength() == 1)
					singleLine = true;
				else
					singleLine = false;
			}
			if (orderTime == 0) //if current order is done, customer can leave. place new order
			{
				if (emptyLine && singleLine) //if one person just joined the line and is the only one,
				{							//don't make them leave the queue.
					orderTime = getOrder();
				}
				else
				{ 
					dequeue(); //else, this means the previous order is done and the next customer can step up
					orderTime = getOrder();
				}
				
			}
			timeDay++;
			if(orderTime > 0)
				orderTime--;
			cout << getLength() << endl;
		}
	}

	//determine if a customer will arrive at the given minute
	bool willCustomerArrive()
	{
		int prob = rand() % 100;
		if (timeDay < 120) //8:00 to 10:00
		{
			if (prob <= 30)
				return true;
		}
		else if (timeDay < 210) //10:00 to 11:30
		{
			if (prob <= 10)
				return true;
		}
		else if (timeDay < 330) //11:30 to 1:30
		{
			if (prob <= 40)
				return true;
		}
		else if (timeDay < 570) //1:30 to 5:30
		{
			if (prob <= 10)
				return true;
		}
		else if (timeDay < 720) //5:30 to 8:00
		{
			if (prob <= 25)
				return true;
		}
		else if (timeDay < 900) //8:00 to 11:00
		{
			if (prob <= 20)
				return true;
		}
		else if (timeDay < DAY) //11:00 to 1:00 (close)
		{
			if (prob <= 10)
				return true;
		}
		return false;
	}

	int getOrder()
	{
		Customer *traverse = back;
		if (traverse == NULL)
			return 0;
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		return traverse->order;
	}

	int getLength()
	{
		int queueLength = 0;
		Customer *traverse = back;
		while (traverse != NULL)
		{
			traverse = traverse->next;
			queueLength++;
		}
		return queueLength;
	}

};

int main()
{
	srand(time(NULL));
	QueueLine init;
	init.simulateDay();
    return 0;
}

