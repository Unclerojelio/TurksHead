// This class represents a Turks Head knot and the results of expanding it on the
// left and the right. The class only constructs valid knots i.e., ones where the
// number of parts and bights are coprime.

// Author: Roger Banks
// Date: 5/11/2012

// Changes:
// 5/11/12 Created

// Todo:
// 1. Validate knot before construction
// 2. Generate pin list as part of constructor
// 3. Calculate left and right expansions

#include <iostream>
#include "knot.h"
#include "my_functions.h"

using namespace std;

Knot::Knot()
{
	init(2,3);
}

Knot::Knot(int p, int b)
{
	init(p,b);
}

Knot::~Knot()
{
//	if (left != NULL) delete left;
//	if (right != NULL) delete right;
}

void Knot::init(int p, int b)
{
	parts = p;
	bights = b;
	
	for(int m = 0; m < bights; m++)
	{
		pl = (1+m*parts)%bights;
		if(pl == 2)
		{
			dbR = 2 * m;
			dpR = 2 * ((parts * m - 1)/bights);
		}
		if(pl == 0)
		{
			dbL = 2 * m;
			dpL = 2 * ((parts * m + 1)/bights);
		}
	}
	PfR = parts + dpR;
	BfR = bights + dbR;
	PfL = parts + dpL;
	BfL = bights + dbL;
	
	// Special case for 3x2, above agorithm fails to find right side expansion
	if(parts == 3 && bights == 2)
	{
		PfR = 5;
		BfR = 4;
	}
}

bool Knot::valid(int p, int b)
{
	if (gcd(p,b) == 1) return true;
	return false;
}

void Knot::set(int p, int b)
{
	parts = p;
	bights = b;
}

Knot Knot::expand_left()
{
	return Knot(PfL, BfL);
}

Knot Knot::expand_right()
{
	return Knot(PfR, BfR);
}

void Knot::show()
{
	cout << parts << 'x' << bights;
}

ostream &operator<<(ostream &stream, Knot k)
{
	stream << k.parts << "x" << k.bights;
	return stream;
}
	
