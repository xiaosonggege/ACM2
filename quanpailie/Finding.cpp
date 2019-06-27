#include "pch.h"
#include "Finding.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <iterator>
#include <memory>
#include <algorithm>
using namespace std;
Finding::Finding(const string &ps) : p(ps) {
	fstream fstm;
	fstm.open(p, ios::in);
	istream_iterator<char> iter_in(fstm), eof;
	string s(iter_in, eof);
	fstm.close();
	for (int i = 0; i != s.size(); ++i) {
		auto pairs = ptrm->insert({ s[i], {i} });
		if (!pairs.second) (pairs.first->second).push_back(i);
	}
	//for (auto &e : *ptrm) {
	//	cout << e.first << ": ";
	//	for (auto &e1 : e.second) cout << e1 << " ";
	//	cout << endl;
	//}
}
Finding::~Finding() {}
int Finding::operator()(const string &s) {
	int flag = 1, min = -1;
	for (const auto &e : s) {
		//找到在字典散列中对应字符串的位置迭代器
		auto position = ptrm->find(e);
		if (position != ptrm->end()) {
			auto iter = position->second.cbegin();
			for (; iter != position->second.cend(); ++iter)
				if (*iter > min) {
					min = *iter;
					break;
				}
			if (iter == position->second.cend()) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
}