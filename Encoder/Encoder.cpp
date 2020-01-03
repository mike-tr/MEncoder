// Encoder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ModularEncoder.h"
#include <iostream>

using namespace std;

int main()
{
	ModularEncoder* encoder = new ModularEncoder(11, 13, 17);

	int p = 29; // 11
	int q = 23; // 7;
	int e = 19; //7; works!

	long n = p * q;
	long fi = (p - 1) * (q - 1);

	cout << " p : " << p << " q : " << " n : " << n << endl;

	int d = ModularEncoder::mp(e, q, p);

	//cout << "test : " << mp(11, 3, 5) << endl;
	cout << " d : " << d << " , e :" << e << " , fi :" << fi << endl;

	int m = 7;
	int dcoded = ModularEncoder::encode(m, e, n);
	//d = 493;
	cout << dcoded << " message : " << m << endl;
	cout << "try e? " << ModularEncoder::encode(dcoded, e, n) << endl;
	cout << "try d? " << ModularEncoder::encode(dcoded, d, n) << endl;

	cout << ModularEncoder::EuclidGcd(252, 198) << endl;
	cout << ModularEncoder::EuclidGcd(19, 616) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
