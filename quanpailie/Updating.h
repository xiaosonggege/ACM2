#ifndef UPDATING
#define UPDATING
#include "pch.h"
#include <map>
#include <utility>
#include <string>
#include <iostream>
using namespace std;
class Updating {
private:
	const string &p = ""; //�ļ�·�����ɸ���/�ƶ�
	map<string, string> dict1;
	map<string, string> dict2;
public:
	Updating() = default;
	Updating(const string &);
	~Updating();
	Updating(const Updating &);
	Updating(Updating &&);
	Updating & operator=(const Updating &);
	Updating & operator=(Updating &&);
	ostream & operator()(ostream &);
};
#endif // !UPDATING

