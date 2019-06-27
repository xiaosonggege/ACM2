#include "pch.h"
#include "CrossWord.h"
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <tuple>
#include <vector>
using namespace std;
CrossWord::CrossWord(const vector<vector<char>> &vv) :
	ptrvv(make_shared<vector<vector<char>>>()) {
	*ptrvv = vv;
}
CrossWord::~CrossWord() {}
CrossWord::CrossWord(const CrossWord &c) {
	this->ptrvv = c.ptrvv;
}
CrossWord & CrossWord::operator=(const CrossWord &c) {
	this->ptrvv = c.ptrvv;
	return *this;
}
ostream & CrossWord::operator()(ostream &os) const {
	for (const auto &d1 : *ptrvv) {
		for (const auto &d2 : d1)
			os << d2 << " ";
		os << endl;
	}
	return os;
}
ostream & CrossWord::answer(ostream &os) {
	int number = 1; //对符合条件的位置标记序号
	string s = "";
	shared_ptr<map<int, vector<string>>> ptrmap = make_shared<map<int, vector<string>>>();
	for (int i = 0; i != (*ptrvv).size(); ++i) {
		for (int j = 0; j != (*ptrvv)[0].size(); ++j) {
			if (judge(*ptrvv, i, j) && (*ptrvv)[i][j] != '*') {
				//向字典散列中存入序号对应的单词
				//读取横向单词
				for (int m = j; m != (*ptrvv)[0].size(); ++m) {
					if ((*ptrvv)[i][m] != '*') s += (*ptrvv)[i][m];
					if ((*ptrvv)[i][m] == '*' || m == (*ptrvv)[0].size() - 1) {
						auto group = ptrmap->insert({ number, {s} });
						if (!group.second) (group.first->second).push_back(s);
						s.clear(); //清空临时字符串中所有字符
						break;
					}
				}
				//读取竖向单词
				for (int m = i; m != (*ptrvv).size(); ++m) {
					if ((*ptrvv)[m][j] != '*') s += (*ptrvv)[m][j];
					if ((*ptrvv)[m][j] == '*' || m == (*ptrvv).size() - 1) {
						auto group = ptrmap->insert({ number, {s} });
						if (!group.second) (group.first->second).push_back(s);
						s.clear(); //清空临时字符串中所有字符
						break;
					}
				}
				++number;
			}
		}
	}
	for (const auto &e : *ptrmap) {
		os << e.first << ": ";
		for (const auto &e2 : e.second)
			os << e2 << " ,";
		os << endl;
	}
	return os;
}
int CrossWord::judge(const vector<vector<char>> &vv, const int &i, const int &j) {
	if (i == 0 || j == 0) return 1;
	else if (vv[i - 1][j] == '*' || vv[i][j - 1] == '*') return 1;
	else return 0;
}