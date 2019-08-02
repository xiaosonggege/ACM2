#include "pch.h"
#include "Tnode.h"
using namespace std;
Tnode::Tnode(const int &d1, const int &d2, const int &w1, const int &w2) :
	D1(d1), D2(d2), W1(w1), W2(w2) {}
Tnode::~Tnode() {}
Tnode::Tnode(const Tnode &t) {
	this->total = t.total;
	this->D1 = t.D1;
	this->D2 = t.D2;
	this->W1 = t.W1;
	this->W2 = t.W2;
	this->lchild = t.lchild;
	this->rchild = t.rchild;
}
Tnode::Tnode(Tnode &&t) {
	this->total = t.total;
	this->D1 = t.D1;
	this->D2 = t.D2;
	this->W1 = t.W1;
	this->W2 = t.W2;
	this->lchild = t.lchild;
	this->rchild = t.rchild;
	t.total = 0;
	t.D1 = 0;
	t.D2 = 0;
	t.W1 = 0;
	t.W2 = 0;
	t.lchild = nullptr;
	t.rchild = nullptr;
}
Tnode & Tnode::operator=(const Tnode &t) {
	this->total = t.total;
	this->D1 = t.D1;
	this->D2 = t.D2;
	this->W1 = t.W1;
	this->W2 = t.W2;
	this->lchild = t.lchild;
	this->rchild = t.rchild;
	return *this;
}
Tnode & Tnode::operator=(Tnode &&t) {
	this->total = t.total;
	this->D1 = t.D1;
	this->D2 = t.D2;
	this->W1 = t.W1;
	this->W2 = t.W2;
	this->lchild = t.lchild;
	this->rchild = t.rchild;
	t.total = 0;
	t.D1 = 0;
	t.D2 = 0;
	t.W1 = 0;
	t.W2 = 0;
	t.lchild = nullptr;
	t.rchild = nullptr;
	return *this;
}
