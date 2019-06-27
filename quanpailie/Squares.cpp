#include "pch.h"
#include "Squares.h"
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>
#include <algorithm>
using namespace std;
Squares::Squares(const string &ps, const int &dims, const int &counts):
	p(make_shared<string>(ps)), dim(dims), count(counts){
	fstream fstrm;
	fstrm.open(*p, ios::in);
	string s;
	while (getline(fstrm, s)) {
		string name = to_string(*s.begin());
		int h = static_cast<int>(*(s.begin() + 2)) - 48, v = static_cast<int>(*(s.begin() + 4)) - 48;
		pair<string, vector<vector<int>>> point = { name, {{h, v}} };
		pair<map<string, vector<vector<int>>>::iterator, bool> pairr = f.insert(point);
		if (!pairr.second) {//���H��f��
			pairr.first->second.push_back(*point.second.begin());
		}
	}
	fstrm.close();
}
Squares::~Squares(){}
Squares::Squares(const Squares &s) {
	this->p = s.p;
	this->f = s.f;
	this->dim = s.dim;
	this->count = s.count;
}
Squares::Squares(Squares &&s) {
	this->p = s.p;
	this->f = s.f;
	this->dim = s.dim;
	this->count = s.count;
	s.p = nullptr;
	s.f.clear();
	s.dim = 0;
	s.count = 0;
}
Squares & Squares::operator=(const Squares &s) {
	this->p = s.p;
	this->f = s.f;
	this->dim = s.dim;
	this->count = s.count;
	return *this;
}
Squares & Squares::operator=(Squares &&s) {
	this->p = s.p;
	this->f = s.f;
	this->dim = s.dim;
	this->count = s.count;
	s.p = nullptr;
	s.f.clear();
	s.dim = 0;
	s.count = 0;
	return *this;
}
bool Squares::find_related(const string &name, const vector<int> &point) {
	vector<vector<int>> rank = this->f[name];
	vector<vector<int>>::const_iterator iter = find(rank.cbegin(), rank.cend(), point);
	if (iter != rank.cend()) return 1;
	else return 0;
}
ostream & Squares::numbering(ostream &os) {
	int flag = 1;
	for (int l = 1; l <= dim; ++l) {//l��1�����������α߳���
		for (int i = 0; i < dim; ++i) {//�����
			for (int j = 0; j < dim; ++j) {//�����
				for (int ll = 0; ll < (l-dim+j); ++l) {//����l���������е��H
					vector<int> po = { i, j + ll };
					vector<vector<int>>::iterator iter_h = find(f["H"].begin(), f["H"].end(), po);
					if (iter_h == f["H"].end()) {flag = 0; break;}
				}
				if (flag) {
					for (int ll = 0; ll < (l-dim+i); ++l) {
						vector<int> po = { i + ll, j };
						vector<vector<int>>::iterator iter_v = find(f["V"].begin(), f["V"].end(), po);
						if (iter_v == f["V"].end()) { flag = 0; break; }
					}
				}
				if (flag) {
					for (int ll = 0; ll < (l-dim+j); ++l) {
						vector<int> po = { i + l, j + ll };
						vector<vector<int>>::iterator iter_h = find(f["H"].begin(), f["H"].end(), po);
						if (iter_h == f["H"].end()) { flag = 0; break; }
					}
				}
				if (flag) {
					for (int ll = 0; ll < (l-dim+i); ++l) {
						vector<int> po = { i + ll, j + l };
						vector<vector<int>>::iterator iter_v = find(f["V"].begin(), f["V"].end(), po);
						if (iter_v == f["V"].end()) { flag = 0; break; }
					}
				}
				if (flag) ++count; //����ڱ���������֧ʱ���������ӣ���������һ
			}
	    }
    }
	os << "�ܵ�����������Ϊ:" << count << endl;
	return os;
}