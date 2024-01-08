// This is the interface file for the Knot class implementation.
// Author: Roger Banks
// Created: 11 May 2012
//
// Changes:
// 12 May 2012 added get_parts and get_bights inline declaration.

class Knot
{
		int parts, bights;
		int pl;
		int dbR, dbL, dpR, dpL;
		int PfR, PfL, BfR, BfL;
		void init(int p, int b);
		bool valid(int p, int b);
	public:
		Knot();
		Knot(int p, int b);
		~Knot();
		void set(int, int);
		int get_parts() { return parts; }
		int get_bights() { return bights; }
		Knot expand_left();
		Knot expand_right();
		friend ostream &operator<<(ostream &stream, Knot k);
		void show();
};