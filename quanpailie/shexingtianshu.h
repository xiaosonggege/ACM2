#ifndef SHEXINGTIANSHU_H
#define SHEXINGTIANSHU_H
#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
template <typename T>
ostream & she(ostream &os, vector<typename vector<T>> &num, const T &size) {
	int i = 0, j = size - 1, number = 1, c = j;
	for (; i !=size; ++i) {
		num[i][j] = number;
		++number;
	}
	i -= 1;
	while (number != size*size + 1) { //以数字记录完毕作为退出条件
		for (int flag = 0; flag != c; ++flag) {
			j += pow(-1, c+1);
			num[i][j] = number;
			++number;
		}
		for (int flag = 0; flag != c; ++flag) {
			i += pow(-1, c+1);
			num[i][j] = number;
			++number;
		}
		--c;
	}
	for (const auto &e1 : num) {
		for (const auto &e2 : e1) {
			os << e2 << " ";
		}
		os << endl;
	}
	return os;
}
#endif // !SHEXINGTIANSHU_H

