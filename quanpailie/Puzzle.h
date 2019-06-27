#ifndef PUZZLE_H
#define PUZZLE_H
#include "pch.h"
#include <vector>
#include <functional>
#include <memory>
#include <utility>
#include <iostream>
#include <string>
#include <map>
using namespace std;
using F = map<string, function<pair<int, int>(pair<int, int> &, vector<vector<char>> &)>>;
using Vc = vector<vector<char>>;
class Puzzle {
private:
	shared_ptr<Vc> metricp = nullptr;
	shared_ptr<pair<int, int>> position = nullptr;
public:
	Puzzle() = default;
	Puzzle(Vc &);
	~Puzzle();
	Puzzle(const Puzzle &);
	Puzzle(Puzzle &&);
	Puzzle & operator=(const Puzzle &);
	Puzzle & operator=(Puzzle &&);
	ostream & action(const string &, ostream &);
	static F act;
};

#endif // !PUZZLE_H

