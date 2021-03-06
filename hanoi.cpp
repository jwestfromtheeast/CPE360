// hanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//say you wanted to make a move counter. if you just created it at the top of hanoi, and added count++ each time you made
//a move, this wouldn't work because with recursion the hanoi method is running repeatedly, and your count would get reset.
void hanoi(int N, char S, char I, char D)
{
	static int count = 0; //essentially only one copy of this variable is created, and will be used for all future versions.
	//base case o anchor value
	if (N == 1) {
		cout << "move # " << ++count << endl;
		cout << "Move disc " << N << "from " << S << "to " << D << endl;
	}
	else {
		//move to smaller instance of the problem
		hanoi(N - 1, S, I, D); //move N-1 from S to I, using D
		cout << "move # " << ++count << endl;
		cout << "Move disc " << N << "from " << S << "to " << D << endl;
		hanoi(N - 1, I, D, S); //move N-1 from I to D, using S
	}
}

int main()
{
	int N;
	char S = 'S', D = 'D', I = 'I';

	cout << "Give me the number of discs" << endl;
	cin >> N;
	hanoi(N, S, I, D);
	return 1;
}

