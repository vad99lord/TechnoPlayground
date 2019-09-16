// testTech.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <random>   // for default_random_engine & uniform_int_distribution<int>
#include <chrono>   // to provide seed to the default_random_engine
#include <ctime>

using namespace std;

default_random_engine dre(chrono::steady_clock::now().time_since_epoch().count());     // provide seed
int random(int lim)
{
	uniform_int_distribution<int> uid{ 0,lim };   // help dre to generate nos from 0 to lim (lim included);
	return uid(dre);    // pass dre as an argument to uid to generate the random no
}


vector <int> sort_squares(vector <int>& seq)
{
	int i = 0;
	int j = seq.size();
	int tmp = 0;
	//find first nonpositive element
	while (--j>=0 && seq[j] > 0) {};

	if (j < 0) {
		//all positive
		for (int i = 0; i < seq.size(); i++) {
			seq[i] *= seq[i];
		}
		return seq;
	}
	if (j == seq.size() - 1) {
		//all negative
		for (int i = 0; i < seq.size(); i++) {
			seq[i] *= seq[i];
		}
		reverse(seq.begin(), seq.end());
		return seq;
	}
	int negPointer = j;
	int posPointer = j + 1;
	vector <int> sorted;
	while (negPointer >= 0 || posPointer < seq.size()) {

		if (negPointer < 0) {
			sorted.push_back(seq[posPointer] * seq[posPointer]);
			posPointer++;
		}
		else if (posPointer >= seq.size()) {
			sorted.push_back(seq[negPointer] * seq[negPointer]);
			negPointer--;
		}
		else if (abs(seq[negPointer]) < seq[posPointer]) {
			sorted.push_back(seq[negPointer] * seq[negPointer]);
			negPointer--;
		}
		else {
			sorted.push_back(seq[posPointer] * seq[posPointer]);
			posPointer++;
		}

	}
	return sorted;
}

int main()
{
	srand(time(0));

	vector <int> vec;

	int n = 20000;
	int r = 10000;
	for (int i = 0; i < n; i++) {
		//1 or 0 random for sign of integer
		int sign = (-1 + 2 * random(1));
		//sign = 1;
		vec.push_back(random(r)*sign);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ' ';
	}


	vec = sort_squares(vec);

	cout << "\n";

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ' ';
	}

	cout << endl << "runtime = " << clock() / 1000.0 << endl; // גנולÿ נאבמעû ןנמדנאללû                  
	system("pause");
	return 0;
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
