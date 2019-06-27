#ifndef COMPARE_H
#define COMPARE_H
#include "pch.h"
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <utility>
using namespace std;
class Compare {
private:
	shared_ptr<string> strp = nullptr;
	shared_ptr<string> stranswer = nullptr;
	shared_ptr<map<char, vector<int>>> statistic = make_shared<map<char, vector<int>>>();
public:
	Compare() = default;
	Compare(const string &, const string &);
	Compare(const Compare &);
	Compare(Compare &&);
	~Compare();
	Compare & operator=(const Compare &);
	Compare & operator=(Compare &&);
	//ostream & operator()(ostream &) const;
	ostream & com(ostream &);
	int make(const pair<char, vector<int>>&);
};
#endif // !COMPARE_H


