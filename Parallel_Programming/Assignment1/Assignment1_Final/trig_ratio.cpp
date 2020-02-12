#include <iostream>
#include <cmath>

using namespace std;

// Function to computer sin(a)/[cos(b)*tan(a+b)]

double trig_ratio(int a, int b)
{
	return sin(a)/( cos(b) * tan(a+b));
}


