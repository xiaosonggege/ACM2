#ifndef FINDING_H
#define FINDING_H
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <iterator>
#include <memory>
using namespace std;
class Finding {
private :
	string p;
	shared_ptr<map<char, vector<int>>> ptrm = make_shared<map<char, vector<int>>>();
public:
	Finding() = default;
	Finding(const string &);
	~Finding();
	int operator()(const string &);
};

#endif // !FINDING_H
