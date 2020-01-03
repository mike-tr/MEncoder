#include "ModularEncoder.h"

long ModularEncoder::mp(long m, long q, long p)
{
	long n = q * p;
	if (p == 1)
		p = 2;
	if (q == 1)
		q = 2;

	long base = (q - 1) * (p - 1) - 1;
	return CalcHugeMod(m, base, base + 1);
}

long ModularEncoder::CalcHugeMod(int num, int power, int base)
{
	//cout << num << " ," << power << " ," << base << endl;
	if (power > 2) {
		// Get a smaller number!
		int tempv = power % 2;
		int mval = powerMod(num, tempv, base);

		int cpow = power - tempv;
		int sp = cpow / 2;

		long cer = CalcHugeMod(num, sp, base);
		long x = CalcHugeMod(cer, 2, base);

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
	return CalcHugeMod(data_bit, key, base);
}

long ModularEncoder::findInverseMod(int a, int base)
{
	return 0;
}

long ModularEncoder::EuclidGcd(int a, int b)
{
	int r = a % b;
	if (r == 0) {
		return b;
	}
	return EuclidGcd(b, r);
}
