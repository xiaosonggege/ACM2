#include "pch.h"
#include "Updating.h"
#include <iostream>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
Updating::Updating(const string &ps): p(ps){
	ifstream ifstrm;
	string s;
	ifstrm.open(this->p, ios::in);
	getline(ifstrm, s);
	string key, value;
	for (const auto &e : s) {
		if (e >= 'a' && e <= 'z') key.push_back(e);
		if (e >= '0' && e <= '9') value.push_back(e);
		if (e == ',' || e == '}') {
			dict1[key] = value;
			key.clear();
			value.clear();
		}
	}
	getline(ifstrm, s);
	for (const auto &e : s) {
		if (e >= 'a' && e <= 'z') key.push_back(e);
		if (e >= '0' && e <= '9') value.push_back(e);
		if (e == ',' || e == '}') {
			dict2[key] = value;
			key.clear();
			value.clear();
		}
	}
	ifstrm.close();
}
Updating::~Updating() {}
Updating::Updating(const Updating &u) {
	this->dict1 = u.dict1;
	this->dict2 = u.dict2;
}
Updating::Updating(Updating &&u) {
	this->dict1 = u.dict1;
	this->dict2 = u.dict2;
	u.dict1.clear();
	u.dict2.clear();
}
Updating & Updating::operator=(const Updating &u) {
	this->dict1 = u.dict1;
	this->dict2 = u.dict2;
	return *this;
}
Updating & Updating::operator=(Updating &&u) {
	this->dict1 = u.dict1;
	this->dict2 = u.dict2;
	u.dict1.clear();
	u.dict2.clear();
	return *this;
}
ostream & Updating::operator()(ostream &os) {
	vector<vector<string>> outstyle;
	//分离出键
	vector<string> keys1, keys2;
	for (map<string, string>::iterator iter1 = dict1.begin(); iter1 != dict1.end(); ++iter1)
		keys1.push_back(iter1->first);
	for (auto iter2 = dict2.begin(); iter2 != dict2.end(); ++iter2)
		keys2.push_back(iter2->first);
	for (const auto &e : keys2) {
		if (find(keys1.begin(), keys1.end(), e) == keys1.end()) //如果元素不在旧字典中
			outstyle.push_back({ "+", e, dict2[e] });
		else {
			if (dict1[e] != dict2[e]) {//如果元素键相同值不同
				outstyle.push_back({ "*", e, dict2[e] });
			}
			dict1.erase(e); //删除原始字典中键
		}
	}
	if (dict1.size()) {
		for (auto iter = dict1.begin(); iter != dict1.end(); ++iter)
			outstyle.push_back({ "-", iter->first, iter->second });
	}
	//将待打印序列排序
	sort(outstyle.begin(), outstyle.end(), [](vector<string> &v1, vector<string> &v2)->bool {return v1[1] < v2[1]; });
	for (const auto &e : outstyle) {
		os << e[0] << e[1] << e[2] << " ";
	}
	return os;
}