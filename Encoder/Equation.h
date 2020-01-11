#pragma once
#include <iostream>
#include <map>

struct Equation
{
public:
	Equation() : d(-1), a(0), x0(1), b(0), y0(1) {}
	Equation(int _d, int _a, int _y0, int _b) : d(_d), a(_a), x0(1), b(_b), y0(_y0) {}

	void print() {
		cout << d << " = " << a << " * " << x0 << " - " << b << " * " << y0 << endl;
	}

	Equation Rebuild(map<int, Equation> equations, int y = 0, int x = 0) {
		cout << endl << "calculating " << x << " ," << y << endl;
		cout << "input : ";
		this->print();

		int d = this->d;
		int a = this->a;
		Equation fa = Equation();
		if (equations.count(a) && this->x0 > 0) {
			cout << "creating fa (" << x << " ," << y << ")" << endl;
			Equation ea = equations[a];

			fa.d = ea.d;
			a = ea.a;
			fa.a = ea.a;
			fa.b = ea.b;
			fa.x0 = ea.x0 * this->x0;
			fa.y0 = ea.y0 * this->x0;
			
			fa = fa.Rebuild(equations, y, x+1);
		}
		else {
			cout << "No need for calculating! ( a : " << this->a << ", is final)" << endl;
			fa.d = 1;
			fa.a = this->a;
			fa.x0 = this->x0;
			fa.b = -1;
			fa.y0 = 0;
		}

		int b = this->b;
		Equation fb = Equation();
		if (equations.count(b) && this->y0 > 0) {
			cout << "creating fb (" << x << " ," << y << ")" << endl;
			Equation ea = equations[b];
			fb.d = ea.d;
			
			b = ea.a;
			fb.a = ea.a;
			fb.b = ea.b;
			fb.x0 = ea.x0 * this->y0;
			fb.y0 = ea.y0 * this->y0;

			fb = fb.Rebuild(equations, y+1, x);		
		}
		else {
			cout << "No need for calculating! ( b : " << this->b << ", is final)" << endl;
			fb.d = -1;
			fb.a = this->b;
			fb.x0 = this->y0;
			fb.b = this->a;
			fb.y0 = 0;
		}

		cout << "Fa,Fb (" << x << " ," << y << ")" << endl;
		cout << "Fa (" << x + 1 << " ," << y << ") : ";
		fa.print();
		cout << "Fb (" << x << " ," << y + 1 << ") : ";
		fb.print();

		int type = fb.b == fa.a ? 1 : fb.a == fa.a ? 2 : -1;
		if (type == -1) {
			cout << "ERRRORRRR at : " << x << " , " << y << endl;
			fa.print();
			fb.print();
			cout << "How dafuk?!";
		}
		else if (type == 1) {
			fa.x0 += fb.y0;
			fa.y0 += fb.x0;
			fa.b = fb.a;
		}
		else {
			fa.x0 -= fb.x0;
			fa.y0 -= fb.y0;
			fa.b = fb.b;
		}
		fa.d = d;

		cout << "final (" << x << " ," << y << ") :";
		fa.print();
		cout << endl;
		return fa;
	}

	int findX0(int c) {
		if (c % d != 0) {
			cout << "Equation has no solution!";
			return -1;
		}
		else {
			return x0 * c / d;
		}
	}

	int findY0(int c) {
		if (c % d != 0) {
			cout << "Equation has no solution!";
			return -1;
		}
		else {
			return -y0 * c / d;
		}
	}
	// d = a*x0 - r
	//d = a*x0-b*y0
	int d, a, x0, b, y0;
};