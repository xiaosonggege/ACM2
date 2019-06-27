#ifndef LIGHT_H
#define LIGHT_H
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>
using namespace std;
template <typename T>
ostream & fun2(vector<T> &v, const int &n, ostream &os) {
	auto fun1 = [](T &num)->T {return 1 - num; };
	for (int num1 = 1; num1 != n + 1; ++num1) {
		for (int i = 0; i != v.size(); ++i) {
			if ((i+1) % num1 == 0) v[i] = fun1(v[i]);
		}
	}
	//for_each(v.cbegin(), v.cend(), [&](T e) {if (e == 1) os << e << " "; });
	shared_ptr<map<int, int>> ptr = make_shared<map<int, int>>();
	int m = 0;
	for (const auto &e : v) {
		ptr->insert({ m, e });
		++m;
	}
	for (const auto &e : (*ptr)) {
		os << e.first << ":" << e.second << endl;
	}
	return os;
}
#endif // !LIGHT_H

