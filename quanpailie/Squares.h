#ifndef SQUARES_H
#define SQUARES_H
#include "pch.h"
#include <map>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <utility>
#include <fstream>
using namespace std;
class Squares {
private:
	shared_ptr<string> p = make_shared<string>(); //�ļ���ַ
	map<string, vector<vector<int>>> f; //���������ߵĵ㼯��ӳ���
	int dots = 0, dim = 0, count = 0; //���������������ά�ȡ�������������������������
public:
	Squares() = default;
	Squares(const string &, const int &, const int &counts = 0);
	Squares(const Squares &);
	Squares(Squares &&);
	Squares & operator=(const Squares &);
	Squares & operator=(Squares &&);
	~Squares();
	bool find_related(const string &, const vector<int> &); //��ѯָ����֮���Ƿ���ڱ�����
	ostream & numbering(ostream &); //���������ж��ٸ�������
};
#endif // !SQUARES_H

