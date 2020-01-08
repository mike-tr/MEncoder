#pragma once
#include <iostream>

struct Equation
{
public:
	Equation(int _d, int _a, int _x0, int _r) : d(_d), a(_a), x0(_x0), r(_r) {}

	void print() {
		cout << d << " = " << a << " * " << x0 << " - " << r << endl;
	}
	// d = a*x0 - r
	int d, a, x0, r;
};