#include "pch.h"
#include "Pga.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <tuple>
using namespace std;
Pga::Pga(const string &strs) : str(strs) {
	istringstream istrm(this->str);
	istrm >> this->name;
	istream_iterator<int> in_iter(istrm), eof;
	this->score.assign(in_iter, eof);
	if (this->name.back() == '*') this->work = 0;
	if (this->score.size() < 4) this->fangui = 1;
	this->total = accumulate(score.begin(), score.end(), 0);
}
Pga::~Pga() {}
Pga::Pga(const Pga &pga) {
	this->str = pga.str;
	this->name = pga.name;
	this->score = pga.score;
	this->total = pga.total;
	this->work = pga.work;
	this->fangui = pga.fangui;
}
Pga::Pga(Pga &&pga) {
	this->str = pga.str;
	this->name = pga.name;
	this->score = pga.score;
	this->total = pga.total;
	this->work = pga.work;
	this->fangui = pga.fangui;
	pga.str.clear();
	pga.name = "";
	pga.score.clear();
	pga.total = 0;
	pga.work = 1;
	pga.fangui = 0;
}
Pga & Pga::operator=(const Pga &pga) {
	this->str = pga.str;
	this->name = pga.name;
	this->score = pga.score;
	this->total = pga.total;
	this->work = pga.work;
	this->fangui = pga.fangui;
	return *this;
}
Pga & Pga::operator=(Pga &&pga) {
	this->str = pga.str;
	this->name = pga.name;
	this->score = pga.score;
	this->total = pga.total;
	this->work = pga.work;
	this->fangui = pga.fangui;
	pga.str.clear();
	pga.name = "";
	pga.score.clear();
	pga.total = 0;
	pga.work = 1;
	pga.fangui = 0;
	return *this;
}
tuple<string, vector<int>, bool, int, bool> Pga::information() const {
	tuple<string, vector<int>, bool, int, bool> info(this->name, this->score, this->work, this->total, this->fangui);
	return info;
}