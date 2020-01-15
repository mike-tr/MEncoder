#include "ModularEncoder.h"

long ModularEncoder::mp(long m, long q, long p)
{
	long n = q * p;
	if (p == 1)
		p = 2;
	if (q == 1)
		q = 2;

	long base = (q - 1) * (p - 1) - 1;
	return RecursiveMod(m, base, base + 1);
}

long ModularEncoder::RecursiveMod(int num, int power, int base)
{
	//cout << num << " ," << power << " ," << base << endl;
	if (power > 2) {
		// Get a smaller number!
		int tempv = power % 2;
		int mval = powerMod(num, tempv, base);

		int cpow = power - tempv;
		int sp = cpow / 2;

		long cer = RecursiveMod(num, sp, base);
		long x = RecursiveMod(cer, 2, base);

		return (x * mval) % base;
	}
	return powerMod(num, power, base);
}

long ModularEncoder::powerMod(long num, int power, long base)
{
	unsigned long long vnum = pow(num, power);
	return vnum % base;
}

long ModularEncoder::encode(int data_bit, int key, int base)
{
	return RecursiveMod(data_bit, key, base);
}

Equation ModularEncoder::findInverseMod(int num, int base)
{
	vector<int> un;
	vector<int> qn;
	map<int, Equation> equ;
	int a = base, b = num;
	if (num > base) {
		a = num;
		b = base;
	}
	int r = a % b;
	while (r != 0) {
		un.push_back(a);
		qn.push_back((int)(a / b));
		cout << "a : " << a << " b : " << b << endl;
		a = b;
		b = r;		
		r = a % b;
	}
	un.push_back(a);
	un.push_back(b);
	qn.push_back((int)(a / b));
	cout << " ------------------------ " << endl;
	for (int i = 0; i < un.size(); i++)
	{
		cout << i << " : " << un[i] << endl;
		int d = un.size() - i;
		if (d > 2) {
			cout << un[i] << " = " << un[i + 1] << "*" << qn[i] << " + " << un[i + 2] << endl;
		}
		else if (d > 1) {
			cout << un[i] << " = " << un[i + 1] << "*" << qn[i] << endl;
		}
	}
	cout << " ------------------------ " << endl;

	for (int i = 0; i < qn.size(); i++)
	{
		cout << i << " : " << qn[i] << endl;
	}
	cout << " ------------------------ " << endl;

	cout << " ------------------------ " << endl;
	for (int i = un.size() - 1; i > 1; i--)
	{
		Equation *eq = new Equation(un[i], un[i - 2], qn[i - 2], un[i - 1]);
		//eq->print();
		equ[un[i]] = *eq;
		equ[un[i]].print();

		//cout << un[i] << " = " << un[i - 2] << " * " << qn[i - 2] << " - " << un[i - 1] << endl;

	}
	cout << " ------------------------ " << endl;
	equ[b].print();
	cout << " ------------------------ " << endl;
	Equation final = equ[b].Rebuild(equ);
	final.print();
	//cout << " find x  for " << 1000 << " : " << final.findX0(1000) << endl;
	//cout << " find x  for " << 1000 << " : " << final.findY0(1000) << endl;
	return final;
}

long ModularEncoder::EuclidGcd(int a, int b)
{
	int r = a % b;
	if (r == 0) {
		return b;
	}
	return EuclidGcd(b, r);
}
