#include "pch.h"
#include "compare.h"
#include <iostream>
#include <map>
#include <memory>
#include <fstream>
#include <string>
#include <iterator>
#include <utility>
#include <algorithm>
Compare::Compare(const string &ps, const string &answers) :
	strp(make_shared<string>(ps)), stranswer(make_shared<string>(answers)) {}
Compare::Compare(const Compare &c) {
	this->strp = c.strp;
	this->stranswer = c.stranswer;
	this->statistic = c.statistic;
}
Compare::Compare(Compare &&c) {
	this->strp = c.strp;
	this->stranswer = c.stranswer;
	this->statistic = c.statistic;
	c.strp = nullptr;
	c.stranswer = nullptr;
	c.statistic = nullptr;
}
Compare::~Compare() {}
Compare & Compare::operator=(const Compare &c) {
	this->strp = c.strp;
	this->stranswer = c.stranswer;
	this->statistic = c.statistic;
	return *this;
}
Compare & Compare::operator=(Compare &&c) {
	this->strp = c.strp;
	this->stranswer = c.stranswer;
	this->statistic = c.statistic;
	c.strp = nullptr;
	c.stranswer = nullptr;
	c.statistic = nullptr;
	return *this;
}
ostream & Compare::com(ostream &os) {
	ifstream fstrm;
	fstrm.open(*strp, ifstream::in);
	istream_iterator<char> iter_in(fstrm), eof;
	//��ȡ�ļ����ַ���
	string s(iter_in, eof);
	fstrm.close();
	int i = 0;
	//�Լ��𰸹�������
	for (auto e : s) {
		pair<char, vector<int>> pairr = { e, {i} };
		make(pairr);
		++i;
	}
	//����𰸹�������
	map<char, vector<int>> answer; 
	i = 0;
	for (auto e : (*stranswer)) {
		pair<char, vector<int>> pairr = { e, {i} };
		auto group = answer.insert(pairr);
		if (!group.second) (group.first->second).push_back(pairr.second[0]);
		++i;
	}
	for (auto iter = answer.cbegin(); iter != answer.cend(); ++iter) {
		//���Լ��𰸹�����������
		map<char, vector<int>>::iterator iter_s = statistic->find(iter->first);
		//����ҵ���
		if (iter_s != statistic->cend()) {
			//����������
			auto it = iter->second.begin();
			for (; it != iter->second.end(); ++it) {
                //����������ֵ���Լ���������
				auto iter_find = find(iter_s->second.cbegin(), iter_s->second.cend(), *it);
				if (iter_find != iter_s->second.cend()) {
					cout << iter->first << "ƥ��" << endl;
					break;
				}
			}
			if (it == iter->second.end()) cout << iter->first << "λ�ò�ƥ��" << endl;
		}
	}
	return os;
}
int Compare::make(const pair<char, vector<int>> &pairr) {
	auto group = statistic->insert(pairr);
	if (!group.second) (group.first->second).push_back(pairr.second[0]);
	return 0;
}