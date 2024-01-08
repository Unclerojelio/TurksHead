// This is the interface file for the THMatrix class implementation.
// Author: Roger Banks
// Created: 28 May 2012
//
// Changes:
// 28 May 12 Start

#include "Knot.h"

class THMatrix
{
		int size = 64;
	public:
		THMatix();
		THMarix(int s);
		~THMatrix();
		int get_size() { return size; }
		void insert(Knot k);
		friend ostream &operator<<(ostream &stream, THMatrix m);
};