#include "ModularEncoder.h"
#include <iostream>

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

long ModularEncoder::findInverseMod(int num, int base)
{
	vector<int> un;
	vector<int> qn;
	map<int, int> unk;
	int a = base, b = num;
	if (num > base) {
		a = num;
		b = base;
	}
	int r = a % b;
	while (r != 0) {
		un.push_back(a);
		unk[a] = a;
		qn.push_back((int)(a / b));
		cout << "a : " << a << " b : " << b << endl;
		a = b;
		b = r;		
		r = a % b;
	}
	un.push_back(a);
	unk[a] = a;
	un.push_back(b);
	unk[b] = b;
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
		cout << un[i] << " = " << un[i - 2] << " * " << qn[i - 2] << " - " << un[i - 1] << endl;
	}
	cout << " ------------------------ " << endl;


	return qn[qn.size() - 1];
}

long ModularEncoder::EuclidGcd(int a, int b)
{
	int r = a % b;
	if (r == 0) {
		return b;
	}
	return EuclidGcd(b, r);
}
