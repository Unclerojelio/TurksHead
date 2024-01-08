#include "my_functions.h"

int gcd(int a,int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

// Because uts system doesn't have sstream on it.
string convertInt(int number)
{
	string digits = "0123456789";
	string s = "";
	
	while(number != 0)
	{
		s = digits[number%10] + s;
		number = number/10;
	}
	return s;
}