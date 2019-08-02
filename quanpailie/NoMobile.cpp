#include "pch.h"
#include "NoMobile.h"
#include "Tnode.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
NoMobile::NoMobile(const string &ps) : p(ps) {
	//���ļ�
	ifstream ifstrm;
	ifstrm.open(p, ios::in);
	string s;
	while (getline(ifstrm, s)) {
		istringstream istr(s);
		int w1, d1, w2, d2;
		istr >> w1 >> d1 >> w2 >> d2;
		this->tns.emplace_back(w1, d1, w2, d2);
	}
	ifstrm.close();
	//����������

	//�������нڵ�total
	//�ж�
}
NoMobile::~NoMobile() {}
NoMobile::NoMobile(const NoMobile &n) {
	this->p = n.p;
	this->tns = n.tns;
	this->root = n.root;
}
NoMobile::NoMobile(NoMobile &&n) {
	this->p = n.p;
	this->tns = n.tns;
	this->root = n.root;
	n.p.clear();
	n.tns.clear();
	n.root = nullptr;
}
NoMobile & NoMobile::operator=(const NoMobile &n) {
	this->p = n.p;
	this->tns = n.tns;
	this->root = n.root;
	return *this;
}
NoMobile & NoMobile::operator=(NoMobile &&n) {
	this->p = n.p;
	this->tns = n.tns;
	this->root = n.root;
	n.p.clear();
	n.tns.clear();
	n.root = nullptr;
	return *this;
}
ostream & NoMobile::judge(ostream &os) const {

	return os;
}