#ifndef DOLEQUEUE_H
#define DOLEQUEUE_H
#include "pch.h"
#include <vector>
#include <iostream>
#include <memory>
using namespace std;
template <typename T>
class Dolequeue {
private:
	int kp, mp;
	vector<T> vp;
public:
	Dolequeue() = default;
	Dolequeue(const int &k, const int &m, const vector<T> &v);
	~Dolequeue();
	int go(int index, int instance, int orient);//index:当前索引位置, instance:移动距离, orient:移动方向
	ostream & give(ostream &os); //救助金发放函数
};
template <typename T>
Dolequeue<T>::Dolequeue(const int &k, const int &m, const vector<T> &v): kp(k), mp(m){
	vp = v;
}
template <typename T>
Dolequeue<T>::~Dolequeue() {}
template <typename T>
int Dolequeue<T>::go(int index, int instance, int orient) {
	int step = 1; //步数标记
	while (step <= instance) {
		if (orient < 0 && index <= 0) index = vp.size() - 1;
		else index = (index + orient) % vp.size();
		if (*(vp.begin() + index) != 0) ++step;
	}
	return index;
}
template <typename T>
ostream & Dolequeue<T>::give(ostream &os) {
	int index_n = -1, index_p = vp.size(), n = vp.size();
	while (n) {
		index_n = this->go(index_n, kp, 1);
		index_p = this->go(index_p, mp, -1);
		if (index_n == index_p) {
			os << *(vp.begin() + index_n) << " ";
			*(vp.begin() + index_n) = 0;
			--n;
		}
		else {
			os << *(vp.begin() + index_n) << " " << *(vp.begin() + index_p) << " ";
			*(vp.begin() + index_n) = 0;
			*(vp.begin() + index_p) = 0;
			n -= 2;
		}
	}
	return os;
}

#endif // !DOLEQUEUE_H
