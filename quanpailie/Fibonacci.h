#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Fibonacci {
private:
	string s = "14";
public:
	int operator()(const int &a, const int &b) {
		int c = a + b;
		if (c / int(pow(10, s.size()-1))) {
			string s2 = to_string(c);
			string s3(s2.begin(), s2.begin() + 2);
			if (s3 == s) return c;
			else return this->operator()(b, c);
		}
		else return this->operator()(b, c);
	}
};
#endif // !FIBONACCI_H

