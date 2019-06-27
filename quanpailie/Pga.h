#ifndef PGA_H
#define PGA_H
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
class Pga {
public:
	string str; //选手信息
	string name; //选手姓名
	vector<int> score; //选手分数
	bool work = 1; //选手是否是职业选手
	int total = 0; //选手总成绩
	bool fangui = 0; //选手是否犯规
	Pga() = default;
	Pga(const string &);
	~Pga();
	Pga(const Pga &);
	Pga(Pga &&);
	Pga & operator=(const Pga &);
	Pga & operator=(Pga &&);
	tuple<string, vector<int>, bool, int, bool> information() const;
};
#endif // !PGA_H
