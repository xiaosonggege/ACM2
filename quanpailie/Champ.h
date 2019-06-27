#ifndef CHAMP_H
#define CHAMP_H
#include "pch.h"
#include "Pga.h"
#include <iostream>
#include <map>
using namespace std;
class Champ {
private:
	string p; //�ļ���ȡ·��
	double reward_all; //�ܽ�������
	vector<double> reward; //����������ռ�ܽ��������İٷֱ�
	vector<Pga> pgas; //������Ա��Ϣ�б�
public:
	Champ() = default;
	Champ(const string &);
	~Champ();
	Champ(const Champ &);
	Champ(Champ &&);
	Champ & operator=(const Champ &);
	Champ & operator=(Champ &&);
	ostream & sort_change(ostream &);
	bool static compareing(const Pga &, const Pga &);
};
#endif // !CHAMP_H

