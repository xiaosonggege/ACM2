#include "pch.h"
#include "Circularseq.h"
#include <memory>
#include <string>
#include <tuple>
#include <iostream>
#include <iterator>
using t = tuple<ostream &, string &>;
Circularseq::Circularseq(const string &s) :
	strp(make_shared<string>(s)) {}
Circularseq::~Circularseq() {}
t Circularseq::operator()(ostream &os) const {
	string s, s1;
	for (auto iter = strp->begin(); iter != strp->end(); ++iter) {
		//循环读取字符串
		if (strp->end() - iter < strp->size()) {
			string s1(iter, strp->end()), s2(strp->begin(), (strp->begin()) + (strp->size() - s1.size()));
			s = s1 + s2;
		}
		else s = *strp;
		if (iter == strp->begin()) s1 = s;
		else {
			int flag = compare(s1.begin(), s1.end() - 1, s.begin(), s.end() - 1);
			if (flag) s1 = s;
		}
	}
	os << "最小字符串为:" << s1;
	t tup(os, s1);
	return tup;
}
int Circularseq::compare(string::iterator low1, string::iterator high1,
	string::iterator low2, string::iterator high2) {
	if (*low1 != *low2) { //字符串单个字母相比结果
		if (*low1 > *low2) return 1;
		else return 0;
	}
	else {
		if (low1 != high1 && low2 != high2) return compare(++low1, high1, ++low2, high2);
		else if (low1 == high1 && low2 != high2) return 0;
		else if (low1 != high1 && low2 == high2) return 1;
		else return 0;
	}
}