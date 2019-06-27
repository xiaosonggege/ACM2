#include "pch.h"
#include "Coding.h"
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cmath>
#include <iterator>
using namespace std;
Coding::Coding(const map<string, char> &dicts, fstream &fstrms, const string &ps) :
	dict(dicts), fstrm(fstrms), p(ps) {
	fstrm.open(p, ios::in);
}
Coding::~Coding() {
	fstrm.close();
}
int Coding::transform(string &s) const {
	if (s.size() == 1) return (stod(s) * pow(2, 3 - s.size()));
	else {
		string ss(s.end() - 1, s.end());
		int number =  stod(ss) * pow(2, 3 - s.size());
		s.erase(s.end() - 1);
		return this->transform(s) + number;
	}
}
string & Coding::decoding(string &str_after) {
	istream_iterator<char> iter_in(fstrm), eof;
	string str(iter_in, eof); //待解码序列
	string::iterator iter = str.begin() + 3; //迭代初始位置
	string s(str.begin(), str.begin() + 3), std(3, '0'); //生成标记序列和结束标记序列
	while (s != std) {
		int length_mark = this->transform(s); //解码标记序列
		string s_decoding(iter, iter + length_mark), standard(length_mark, '1'); //待解码字符串和标准全1字符串
		while (s_decoding != standard) {
			char letter = dict[s_decoding]; //解码
			//cout << letter << " ";
			str_after.push_back(letter);
			iter += length_mark;
			s_decoding.assign(iter, iter + length_mark);
		}
		s.assign(iter + length_mark, iter + length_mark + 3);
		iter += (length_mark + 3);
	}
	return str_after;
}