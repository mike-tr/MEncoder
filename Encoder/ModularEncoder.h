#pragma once
#include "math.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class ModularEncoder
{
public:	
	// How does the encoder works?
	// Get Q, P natural prime numbers
	// create n = q*p
	// Get e, that holds gcd(e, Φ(n))
	// generate the inverse modular of E in base Φ(n) equal to d,
	// And that it as now we hold true that, any given number m, 0 <= m < n
	// we get that Encode(m, key) => m^key mod n

	// and we hold true that => Encode(Encode(m, e), d) = m and 
	// Encode(Encode(m, d), e) = m for every m!

	// we also get that, Encode(Encode(m, e), e) != m, (for most m values);
	// and we also get that Encode(Encode(m, d), d) != m, (for most m values);
	ModularEncoder(int p, int q, int e) {
		this->p = p;
		this->q = q;
		this->e = e;
	}

	static long mp(long m, long q, long p);
	static long RecursiveMod(int num, int power, int base);
 	static long powerMod(long num, int power, long base);
	static long encode(int data_bit, int key, int base);

	static long findInverseMod(int a, int base);

	static long EuclidGcd(int a, int b);
private:
	int p, q, e;
};

