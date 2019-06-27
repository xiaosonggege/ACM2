#ifndef SQUARES_H
#define SQUARES_H
#include "pch.h"
#include <map>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <utility>
#include <fstream>
using namespace std;
class Squares {
private:
	shared_ptr<string> p = make_shared<string>(); //文件地址
	map<string, vector<vector<int>>> f; //横竖有连线的点集合映射表
	int dots = 0, dim = 0, count = 0; //方阵点总数、方阵维度、方阵中正方形总数计数变量
public:
	Squares() = default;
	Squares(const string &, const int &, const int &counts = 0);
	Squares(const Squares &);
	Squares(Squares &&);
	Squares & operator=(const Squares &);
	Squares & operator=(Squares &&);
	~Squares();
	bool find_related(const string &, const vector<int> &); //查询指定点之间是否存在边连接
	ostream & numbering(ostream &); //数方阵中有多少个正方形
};
#endif // !SQUARES_H

