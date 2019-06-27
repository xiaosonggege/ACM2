#ifndef QUANPAI_H
#define QUANPAI_H
#include "pch.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template <typename T>
auto swap_s = [](T &a, T &b) {T temp = a; a = b; b = temp; };
template <typename T>
int rankf(const vector<T> &v, typename vector<T>::iterator low, typename vector<T>::iterator high) {
	if (low == high) {
		for (const auto &e : v) cout << e;
		cout << endl;
	}
	else {
		for (typename vector<T>::iterator iter = low; iter != high+1; ++iter) {
			swap_s<T>(*low, *iter);
			rankf(v, low + 1, high);
			swap_s<T>(*low, *iter);
		}
	}
	return 0;
}
#endif // !QUANPAI_H

