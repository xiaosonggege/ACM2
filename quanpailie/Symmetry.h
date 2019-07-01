#ifndef SYMMETRY_H
#define SYMMETRY_H
#include "pch.h"
#include <iostream>
#include <utility>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
class Symmetry {
private:
	vector<vector<T>> zuobiao;
public:
	Symmetry() = default;
	Symmetry(const vector<vector<T>> &);
	~Symmetry();
	Symmetry(const Symmetry &);
	Symmetry(Symmetry &&);
	Symmetry & operator=(const Symmetry &);
	Symmetry & operator=(Symmetry &&);
	ostream & operator()(ostream &) const; //判断是否存在此对称轴
};
template <typename T>
Symmetry<T>::Symmetry(const vector<vector<T>> &zuobiaos) : zuobiao(zuobiaos) {}
template <typename T>
Symmetry<T>::~Symmetry() {}
template <typename T>
Symmetry<T>::Symmetry(const Symmetry &s) {
	this->zuobiao = s.zuobiao;
}
template <typename T>
Symmetry<T>::Symmetry(Symmetry &&s) {
	this->zuobiao = s.zuobiao;
	s.zuobiao.clear();
}
template <typename T>
Symmetry<T> & Symmetry<T>::operator=(const Symmetry &s) {
	this->zuobiao = s.zuobiao;
	return *this;
}
template <typename T>
Symmetry<T> & Symmetry<T>::operator=(Symmetry &&s) {
	this->zuobiao = s.zuobiao;
	s.zuobiao.clear();
	return *this;
}
template <typename T>
ostream & Symmetry<T>::operator()(ostream &os) const{
	int flag = 1;
	sort(zuobiao.begin(), zuobiao.end(), [](vector<T> v1, vector<T> v2)->bool {return *v1.begin() < *v2.begin(); });
	T x_mean = (zuobiao[0][0] + zuobiao[zuobiao.size()-1][0]) / 2.0;
	for (int i = 0; i != zuobiao.size()-1; ++i) {
		for (int j = i + 1; j != zuobiao.size(); ++j) {
			if (zuobiao[i][0] + x_mean == zuobiao[j][0] && zuobiao[i][1] == zuobiao[j][1]) break;
			if (j == zuobiao.size()) {
				os << "无对称轴!" << endl;
				flag = 0;
			}
		}
	}
	if (flag) os << "有对称轴,并且坐标为:" << x_mean << endl;
	return os;
}
#endif // !SYMMETRY_H

