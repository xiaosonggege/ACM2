#ifndef PRINTER_H
#define PRINTER_H
#include "pch.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <sstream>
using namespace std;
template <typename T>
class Printer {
private:
	const string &p = ""; //�ļ�·�����ɸ��ƺ��ƶ�
	vector<pair<string, int>> v;
	string name; //��ע���ļ���
	T time = 0;//��ע���ļ���ӡ�ȴ�ʱ��
public:
	Printer() = default;
	Printer(const string &, const string &);
	~Printer();
	Printer(const Printer &);
	Printer(Printer &&);
	Printer & operator=(const Printer &);
	Printer & operator=(Printer &&);
	ostream & operator()(ostream &) const; //��ӡ��ע���ļ���ӡ�ȴ�ʱ��
	int payattention(); //����ȴ������й�ע���ļ���ӡ�ȴ�ʱ��
};
template <typename T>
Printer<T>::Printer(const string &ps, const string &names) :
	p(ps), name(names) {
	//��ȡ�ļ��е���Ϣ
	ifstream ifstrm;
	ifstrm.open(this->p, ios::in);
	string s, namep;
	int level;
	while (getline(ifstrm, s)) {
		istringstream istr(s);
		istr >> namep >> level;
		pair<string, int> pairr = { namep, level };
		this->v.push_back(pairr);
	}
	ifstrm.close();
}
template <typename T>
Printer<T>::~Printer() {}
template <typename T>
Printer<T>::Printer(const Printer &pr) {
	this->v = pr.v;
	this->name = pr.name;
	this->time = pr.time;
}
template <typename T>
Printer<T>::Printer(Printer &&pr) {
	this->v = pr.v;
	this->name = pr.name;
	this->time = pr.time;
	pr.v.clear();
	pr.name.clear();
	pr.time = 0;
}
template <typename T>
Printer<T> & Printer<T>::operator=(const Printer &pr) {
	this->v = pr.v;
	this->name = pr.name;
	this->time = pr.time;
	return *this;
}
template <typename T>
Printer<T> & Printer<T>::operator=(Printer &&pr) {
	this->v = pr.v;
	this->name = pr.name;
	this->time = pr.time;
	pr.v.clear();
	pr.name.clear();
	pr.time = 0;
	return *this;
}
template <typename T>
ostream & Printer<T>::operator()(ostream &os) const {
	os << "��ע���ļ�" << this->name << " ��ӡ�ȴ�ʱ��Ϊ: " << this->time << endl;
	return os;
}
template <typename T>
int Printer<T>::payattention() {
	int flag = 0;
	while (!flag) {
		int flag_1 = 0;
		auto iter_l = this->v.begin() + 1;
		for (; iter_l != this->v.end(); ++iter_l) {
			if (iter_l->second > v.begin()->second) { //������ļ�����ļ��бȸ��ļ����ȼ��ߵ�
				this->v.push_back(*v.begin());
				this->v.erase(this->v.begin());
				flag_1 = 1;
				break;
			}
		}
		if (!flag_1) {
			++this->time;
			if (this->v.begin()->first == this->name)  flag = 1;
			else this->v.erase(this->v.begin());
		}
	}
	return 0;
}
#endif // !PRINTER_H
