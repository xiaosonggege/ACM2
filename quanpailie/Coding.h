#ifndef CODING_H
#define CODING_H
#include "pch.h"
#include <map>
#include <string>
#include <fstream>
using namespace std;
class Coding {
private:
	map<string, char> dict;
	fstream &fstrm;
	string p;
public:
	Coding() = default;
	Coding(const map<string, char> &, fstream &, const string &);
	~Coding();
	int transform(string &) const; //将二进制01字符串转化为对应十进制数字并输出
	string & decoding(string &str_after); //输出解码序列
};

#endif // !CODING_H


