#include "pch.h"
#include "Puzzle.h"
#include <vector>
#include <string>
#include <functional>
#include <memory>
#include <utility>
#include <iostream>
#include <map>
using namespace std;
Puzzle::Puzzle(Vc &vc) :
	metricp(make_shared<Vc>()), position(make_shared < pair<int, int>>()) {
	*metricp = vc;
	for (int i = 0; i != vc.size(); ++i) {
		for (int j = 0; j != vc[0].size(); ++j) {
			if (vc[i][j] == ' ') {
				*position = { i, j };
				break;
			}
		}
	}
}
Puzzle::~Puzzle() {}
Puzzle::Puzzle(const Puzzle &p) {
	this->metricp = p.metricp;
	this->position = p.position;
}
Puzzle::Puzzle(Puzzle &&p) {
	this->metricp = p.metricp;
	this->position = p.position;
	p.metricp = nullptr;
	p.position = nullptr;
}
Puzzle & Puzzle::operator=(const Puzzle &p) {
	this->metricp = p.metricp;
	this->position = p.position;
	return *this;
}
Puzzle & Puzzle::operator=(Puzzle &&p) {
	this->metricp = p.metricp;
	this->position = p.position;
	p.metricp = nullptr;
	p.position = nullptr;
	return *this;
}
ostream & Puzzle::action(const string &s, ostream &os) {
	for (const auto &e : *metricp) {
		for (const auto &m : e) os << m << " ";
		os << endl;
	}
	os << endl;
	pair<int, int> pos = *position;
	for (const auto &e : s) {
		if (e == 'A') pos = act["A"](pos, *metricp);
		else if (e == 'B') pos = act["B"](pos, *metricp);
		else if (e == 'L') pos = act["L"](pos, *metricp);
		else pos = act["R"](pos, *metricp);
	}
	for (const auto &e : *metricp) {
		for (const auto &m : e) os << m << " ";
		os << endl;
	}
	return os;
}
F Puzzle::act = {
 {"A", [](pair<int, int> &pos, Vc &v)->pair<int, int> {
	  char temp = v[pos.first][pos.second]; 
	  v[pos.first][pos.second] = v[pos.first-1][pos.second];
	  v[pos.first - 1][pos.second] = temp;
	  pair<int, int> pos_new = { pos.first-1, pos.second };
	  return pos_new;
     } 
 },
 {"B", [](pair<int, int> &pos, Vc &v)->pair<int, int> {
	  char temp = v[pos.first][pos.second];
	  v[pos.first][pos.second] = v[pos.first + 1][pos.second];
	  v[pos.first + 1][pos.second] = temp;
	  pair<int, int> pos_new = { pos.first + 1, pos.second };
	  return pos_new;
	}
 },
 {"L", [](pair<int, int> &pos, Vc &v)->pair<int, int> {
	  char temp = v[pos.first][pos.second];
	  v[pos.first][pos.second] = v[pos.first][pos.second - 1];
	  v[pos.first][pos.second - 1] = temp;
	  pair<int, int> pos_new = { pos.first, pos.second - 1};
	  return pos_new;
	}
 },
 {"R", [](pair<int, int> &pos, Vc &v)->pair<int, int> {
	  char temp = v[pos.first][pos.second];
	  v[pos.first][pos.second] = v[pos.first][pos.second + 1];
	  v[pos.first][pos.second + 1] = temp;
	  pair<int, int> pos_new = { pos.first, pos.second + 1 };
	  return pos_new;
	 }
 }
};