#include "pch.h"
#include "NoMobile.h"
#include "Tnode.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
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
		this->tns.emplace_back(d1, d2, w1, w2);
	}
	ifstrm.close();
	//����������
	this->root = &(*this->tns.begin());
	int pos = 1;
	this->build(this->root, pos);
	//�������нڵ�total
	this->total_calc(this->root);
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
int NoMobile::build(Tnode *t, int &pos) {
	if (t->W1 == 0) {
		t->lchild = &tns[pos];
		this->build(t->lchild, ++pos);
	}
	if (t->W2 == 0) {
		t->rchild = &tns[pos];
		this->build(t->rchild, ++pos);
	}
	return 0;
}
int NoMobile::total_calc(Tnode *t) {
	if (t->W1 && t->W2) t->total = t->W1 + t->W2;
	else if (t->W1 && (!t->W2)) t->total = t->W1 + this->total_calc(t->lchild);
	else if ((!t->W1) && t->W2) t->total = this->total_calc(t->rchild) + t->W2;
	else t->total = this->total_calc(t->lchild) + this->total_calc(t->rchild);
	return t->total;
}