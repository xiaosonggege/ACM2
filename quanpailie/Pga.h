#ifndef PGA_H
#define PGA_H
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
class Pga {
public:
	string str; //ѡ����Ϣ
	string name; //ѡ������
	vector<int> score; //ѡ�ַ���
	bool work = 1; //ѡ���Ƿ���ְҵѡ��
	int total = 0; //ѡ���ܳɼ�
	bool fangui = 0; //ѡ���Ƿ񷸹�
	Pga() = default;
	Pga(const string &);
	~Pga();
	Pga(const Pga &);
	Pga(Pga &&);
	Pga & operator=(const Pga &);
	Pga & operator=(Pga &&);
	tuple<string, vector<int>, bool, int, bool> information() const;
};
#endif // !PGA_H
