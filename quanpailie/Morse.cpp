#include "pch.h"
#include "Morse.h"
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
using namespace std;
Morse::Morse(const string &p) : p(p) {
	string line;
	ifstream fstrm;
	fstrm.open(p, ios::in);
	while (getline(fstrm, line)) {
		if (line == "*") break;
		char little = *line.begin();
		string encode(line.begin() + 2, line.end());
		dict[little] = encode;
	}
	while (getline(fstrm, line)) {
		if (line == "*") break;
		dictionary.push_back(line);
	}
	while (getline(fstrm, line)) {
		if (line == "*") break;
		decoding.push_back(line);
	}
	fstrm.close();
}
Morse::~Morse() {}
Morse::Morse(const Morse &m) {
	this->p = m.p;
	this->dict = m.dict;
	this->dictionary = m.dictionary;
}
Morse::Morse(Morse &&m) {
	this->p = m.p;
	this->dict = m.dict;
	this->dictionary = m.dictionary;
	m.p.clear();
	m.dict.clear();
	m.dictionary.clear();
}
Morse & Morse::operator=(const Morse &m) {
	this->p = m.p;
	this->dict = m.dict;
	this->dictionary = m.dictionary;
	return *this;
}
Morse & Morse::operator=(Morse &&m) {
	this->p = m.p;
	this->dict = m.dict;
	this->dictionary = m.dictionary;
	m.p.clear();
	m.dict.clear();
	m.dictionary.clear();
	return *this;
}
char Morse::find_s(const string &s) {
	for (map<char, string>::const_iterator iter = this->dict.begin(); iter != dict.end(); ++iter) {
		if (s == iter->second) return iter->first; //已找到该单词 
	}
}
vector<string> Morse::find_str(const char &str) {
	vector<string> v_str;
	for (vector<string>::const_iterator iter = this->dictionary.begin(); iter != this->dictionary.end(); ++iter) {
		if ((*iter)[0] == str) v_str.push_back(*iter);
	}
	return v_str;
}
string Morse::finding(const string &s) { //s为待解码字符串
	vector<string> look; //存储所有字典中首字母符合当前编码中前部分的词
	for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
		string temp(s.begin(), iter+1); //临时存储单行电码从起始位置直到当前迭代器位置之间的所有电码
		char ls = this->find_s(temp); //从字符和电码对应表中找到当前temp对应的字符
		vector<string> v_str = this->find_str(ls);
		look.insert(look.end(), v_str.begin(), v_str.end()); //向look中存入所有待比较的单词
	}
	//定义并初始化候选单词关联容器
	map<string, string> look_map;
	for (auto &e : look) {
		//将e中各个字符对应的摩尔斯电码符号连接在一起
		string code = "";
		for (auto e1 : e) code += this->dict[e1];
		look_map[e] = code;
	}
    //将候选关联容器中的所有pair均与待解码序列比较
	string word_real = "ZZZZZZZZZZ", word_real_2 = "";
	int flag = 0, dis_diff = 10;
	for (auto iter = look_map.begin(); iter != look_map.end(); ++iter) {
		if (s == iter->second) { //有直接相等的，最终在所有相等的单词中选取字典序最小的
			if (iter->first < word_real) word_real = iter->first;
			++flag;
		}
		else { //检测不一致字符部分的长度
			int i = 0;
			for (i = 0; i != s.size(); ++i) {
				if (s[i] != iter->second[i]) {
					//比较出两个字符中较长字符
					string s_temp = (s.size() > iter->second.size()) ? s : iter->second;
					if ((s_temp.size() - i) < dis_diff) {
						word_real_2 = iter->first;
						dis_diff = s_temp.size() - i;
					}
					break;
				}
			}
			if (i == s.size()) {
				if (iter->second.size() - i < dis_diff) {
					word_real_2 = iter->first;
					dis_diff = iter->second.size() - i;
				}
			}
		}
	}
	if (flag == 1) return word_real;
	else if (flag > 1) {
		word_real.push_back('!');
		return word_real;
	}
	else {
		word_real_2.push_back('?');
		return word_real_2;
	}
}
ostream & Morse::reading(ostream &os) {
	for (auto &e : this->decoding) {
		string decode = this->finding(e);
		os << decode << endl;
	}
	return os;
}