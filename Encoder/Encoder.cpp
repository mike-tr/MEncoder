// Encoder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ModularEncoder.h"
#include <iostream>

using namespace std;

string EncString(string text, int e, int n) {
	string ret = "";
	for (int i = 0; i < text.length(); i++)
	{
		int m = ModularEncoder::encode((int)text[i], e, n);
		cout << m << " : " << (int)text[i] << endl;
		ret += (char)ModularEncoder::encode((int)text[i], e, n);
	}
	return ret;
}

void testForText(int e, int d, int n) {
	string input = "";
	cin >> input;
	while (!input.empty()) {
		cout << "-------------------------------" << endl;

		//int dcoded = ModularEncoder::encode(input, e, n);
		string encoded = EncString(input, e, n);

		cout << encoded << "  - Original message : " << input << endl;
		cout << "try e? " << EncString(encoded, e, n) << endl;
		cout << "try d? " << EncString(encoded, d, n) << endl;

		cout << "-------------------------------" << endl;

		cin >> input;
	}
}

int main()
{
	ModularEncoder* encoder = new ModularEncoder(11, 13, 17);

	int p = 29; // 11
	int q = 23; // 7;
	int e = 19; //7; works!

	long n = p * q;
	long phi_n = (p - 1) * (q - 1);

	cout << " p : " << p << " q : " << " n : " << n << endl;

	int d = ModularEncoder::mp(e, q, p);

	//cout << "test : " << mp(11, 3, 5) << endl;
	cout << " d : " << d << " , e :" << e << " , fi :" << phi_n << endl;

	int m = 7;
	int dcoded = ModularEncoder::encode(m, e, n);
	d = ModularEncoder::findInverseMod(e, phi_n).x0; // e = 19 phi_n = 22 * 28, d = 227

	
	//testForText(e, d, n);

	int input = 0;
	cin >> input;
	while (input > 0) {
		cout << "-------------------------------" << endl;

		int dcoded = ModularEncoder::encode(input, e, n);

		cout << "Encoded with e : " << dcoded << " original : " << input << endl;
		cout << "try decoding with e : " << ModularEncoder::encode(dcoded, e, n) << endl;
		cout << "try decoding with d : " << ModularEncoder::encode(dcoded, d, n) << endl;

		cout << "-------------------------------" << endl;

		cin >> input;
	}


	//cout << ModularEncoder::EuclidGcd(252, 198) << endl;
	//cout << "inv test : " << ModularEncoder::findInverseMod(20, 172) << endl;
	//cout << ModularEncoder::EuclidGcd(20, 172) << endl;
	//cout << ModularEncoder::EuclidGcd(19, 616) << endl;

	//cout << "inv test : " << ModularEncoder::findInverseMod(19, phi_n) << endl;
	//cin >> d;
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
