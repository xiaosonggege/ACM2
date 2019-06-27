#include "pch.h"
#include "Pga.h"
#include "Champ.h"
#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;
Champ::Champ(const string &ps) : p(ps) {
	ifstream ifstrm;
	ifstrm.open(p, ios::in);
	//读入总奖金数量
	string s;
	getline(ifstrm, s);
	this->reward_all = stod(s);
	//读入奖金百分比
	for (int num = 0; num != 5; ++num) {
		getline(ifstrm, s);
		this->reward.push_back(stod(s));
	}
	while (getline(ifstrm, s)) {
		Pga pga(s);
		this->pgas.push_back(pga);
	}
	ifstrm.close();
}
Champ::~Champ() {}
Champ::Champ(const Champ &c) {
	this->p = c.p;
	this->reward_all = c.reward_all;
	this->reward = c.reward;
	this->pgas = c.pgas;
}
Champ::Champ(Champ &&c) {
	this->p = c.p;
	this->reward_all = c.reward_all;
	this->reward = c.reward;
	this->pgas = c.pgas;
	this->p.clear();
	this->reward_all = 0;
	this->reward.clear();
	this->pgas.clear();
}
Champ & Champ::operator=(const Champ &c) {
	this->p = c.p;
	this->reward_all = c.reward_all;
	this->reward = c.reward;
	this->pgas = c.pgas;
	return *this;
}
Champ & Champ::operator=(Champ &&c) {
	this->p = c.p;
	this->reward_all = c.reward_all;
	this->reward = c.reward;
	this->pgas = c.pgas;
	this->p.clear();
	this->reward_all = 0;
	this->reward.clear();
	this->pgas.clear();
	return *this;
}
ostream & Champ::sort_change(ostream &os) {
	//排序
	sort(this->pgas.begin(), this->pgas.end(), &compareing);
	//统计职业选手的得分
	shared_ptr<map<double, int>> pga_work = make_shared<map<double, int>>();
	for (const auto &e : pgas) {
		bool work = get<2>(e.information());
		if (work) {
			auto pairr = pga_work->insert({ get<3>(e.information()), 1 });
			if (!pairr.second) ++pairr.first->second;
		}
	}
	//按排序分配奖金
	int i = 0;
	for (auto iter = pga_work->begin(); iter != pga_work->end(); ++iter) {
		auto j = iter->second;
		iter->second = 0.01 * this->reward_all * accumulate(this->reward.begin()+i, this->reward.begin()+i+iter->second, 0) / iter->second;
		i += j;
	}
	for (const auto &e : this->pgas) {
		os << "name: " << get<0>(e.information()) << " " << "score: ";
		for (const auto &s : get<1>(e.information())) os << s << " ";
		os << "total: " << get<3>(e.information()) << " ";
		if (pga_work->find(get<3>(e.information())) != pga_work->end()) os << (*pga_work)[get<3>(e.information())] << endl;
		else os << endl;
	}
	return os;
}
bool Champ::compareing(const Pga &p1, const Pga &p2) {
	if (p1.score.size() == p2.score.size())
		return p1.total > p2.total; 
	return p1.score.size() < p1.score.size();
}
