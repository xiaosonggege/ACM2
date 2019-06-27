#ifndef CROSSWORD_H
#define CROSSWORD_H
#include "pch.h"
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <tuple>
#include <vector>
using namespace std;
class CrossWord {
private:
	shared_ptr <vector<vector<char>>> ptrvv = nullptr;
public:
	CrossWord() = default;
	CrossWord(const vector<vector<char>> &);
	~CrossWord();
	CrossWord(const CrossWord &);
	CrossWord & operator=(const CrossWord &);
	ostream & operator()(ostream &) const;
	ostream & answer(ostream &);
	static int judge(const vector<vector<char>> &, const int &, const int &);
};

#endif // !CROSSWORD_H

