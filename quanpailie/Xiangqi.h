#ifndef XIANGQI_H
#define XIANGQI_H
#include "pch.h"
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include "omp.h"
using namespace std;
class Xiangqi {
private:
	map<string, vector<int>> positions; //棋子位置
	vector<vector<string>> qipan; //棋盘十字线
public:
	Xiangqi() = default;
	Xiangqi(const map<string, vector<int>> &);
	~Xiangqi();
	Xiangqi(const Xiangqi &);
	Xiangqi(Xiangqi &&);
	Xiangqi & operator=(const Xiangqi &);
	Xiangqi & operator=(Xiangqi &&);
	bool ju();
	bool ma();
	bool pao();
	ostream & judge(ostream &);
};
#endif // !XIANGQI_H

