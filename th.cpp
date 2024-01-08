// This program calculates all of the possible expansions for a
// given Turks Head Knot up to 100 bights or parts, whichever value
// is reached first.
// Algorithm: Create linked list of all possible added bights and then
//. 	 	  create binary tree of all possible left and right
// 	 	 	  expansions until either parts or bights reaches 100
// Start Date: 8 May 2012
// Author: Roger Banks
// Input example:
//
// 5
// 3 5
// 5 4
// 3 4
// 7 6
// 7 5
//
// Output:
// CSV file where columns equal parts and rows equal bights. For each
// possible pxb cell, display predecessor pxb followed by 'L' or
// 'R' for type of expansion required.
// Changes:
// 10 May 12 specified variables.
// 10 May 12 expansion calculations and possibility check working.
//           Next step, create an object 'knot' with properties of
//           parts and bights, each knot has two children, left and
//           right expansions.
// 11 May 12 Tested knot.cpp additions
// 12 May 12 Tested get_parts() and get_bights()
// 23 May 12 Added queue and matrix, mostly working.3x2 doesn't expand properly.
//           Need to go back and test.
// 24 May 12 All working now.

// ToDo:
// 12 May 12 Add unit++ test framework
// 23 May 12 New Plan:
//				insert foundation knots into queue q
//				while !q.empty()
//					knot = q.front()
//					q.pop()
//					knot_left = knot.expand_left()
//					knot_right = knot.expand_right()
//					if knot_left.parts <= 48 and knot_left.bights <= 48
//						q.push(knot_left)
//						array(knot_left.parts, knot_left.bights) = "pxbL"
//					if knot_right.parts <= 48 and knot_right.bights <= 48
//						q.push(knot_right)
//						array(knot_right.parts, knot_right.bights) = "pxbL"
// 23 May 12 Add extra bights to foundation knots. Export csv file of matrix.
// 24 May 12 Insert '*' into matrix where gcd(i,j) != 1. Later, Excel can highlight
//           those cells in red.

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "knot.h"
#include "my_functions.h"

#define SIZE 64

using namespace std;

int main(void)
{
	queue<Knot> q;
	vector<vector<string> > matrix;
	
	matrix.resize(SIZE);
	for(int i = 0; i < SIZE; i++)
		matrix[i].resize(SIZE);
	
	// initialize matrix and insert headers
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
		{
			matrix[j][i] = "";
			if(gcd(i,j) != 1) matrix[j][i] = "*";
			if(i == 0) matrix[j][i] = convertInt(j);
			if(j == 0) matrix[j][i] = convertInt(i);
		}	
	
	string name;
	Knot k, left, right; //k(2,3)
	Knot k6(2,5);
	Knot k7(2,7);
	Knot k11(2,9);
	Knot k3(3,2);
	Knot k2(3,4);
	Knot k4(3,5);
	Knot k5(3,7);
	Knot k8(3,8);
	Knot k9(3,10);
	Knot k12(3,11);
	Knot k13(3,13);
	Knot k10(4,3);
	Knot k16(5,3);
	Knot k17(7,3);
	Knot k14(7,5);
	Knot k15(8,5);
	Knot k18(13,5);
	q.push(k);
	q.push(k2);
	q.push(k3);
	q.push(k4);
	q.push(k5);
	q.push(k6);
	q.push(k7);
	q.push(k8);
	q.push(k9);
	q.push(k10);
	q.push(k11);
	q.push(k12);
	q.push(k13);
	q.push(k14);
	q.push(k15);
	q.push(k16);
	while(!q.empty())
	{
		k = q.front();
		//for(int i = 0; i < q.size(); i++)
		//	cout << "*";
		//cout << endl;
		q.pop();
		left = k.expand_left();
		right = k.expand_right();
		//cout << k << '\t' << left << "L \t" << right << "R" << endl;
		if(left.get_parts() < SIZE && left.get_bights() < SIZE)
		{
			q.push(left);
			name = convertInt(k.get_parts()) + "x" + convertInt(k.get_bights()) + "L";
			matrix[left.get_parts()][left.get_bights()] = name;
		}
		if(right.get_parts() < SIZE && right.get_bights() < SIZE)
		{
			q.push(right);
			name = convertInt(k.get_parts()) + "x" + convertInt(k.get_bights()) + "R";
			matrix[right.get_parts()][right.get_bights()] = name;
		}
	}
	
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
			cout << matrix[j][i] << '\t';
		cout << endl;
	}

	return 0;
}