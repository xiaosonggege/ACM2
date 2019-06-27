#ifndef CHAMP_H
#define CHAMP_H
#include "pch.h"
#include "Pga.h"
#include <iostream>
#include <map>
using namespace std;
class Champ {
private:
	string p; //文件读取路径
	double reward_all; //总奖金数量
	vector<double> reward; //比赛奖金所占总奖金数量的百分比
	vector<Pga> pgas; //比赛人员信息列表
public:
	Champ() = default;
	Champ(const string &);
	~Champ();
	Champ(const Champ &);
	Champ(Champ &&);
	Champ & operator=(const Champ &);
	Champ & operator=(Champ &&);
	ostream & sort_change(ostream &);
	bool static compareing(const Pga &, const Pga &);
};
#endif // !CHAMP_H

