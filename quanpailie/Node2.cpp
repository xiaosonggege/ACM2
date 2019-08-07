#include "pch.h"
#include "Node2.h"
using namespace std;
Node2::Node2(const int &values, Node2 *ls, Node2 *rs) : 
	value(values), l(ls), r(rs) {}
Node2::~Node2() {}
Node2::Node2(const Node2 &n) {
	this->value = n.value;
	this->pos = n.pos;
	this->l = n.l;
	this->r = n.r;
}
Node2::Node2(Node2 &&n) {
	this->value = n.value;
	this->pos = n.pos;
	this->l = n.l;
	this->r = n.r;
	n.value = 0;
	n.pos = 0;
	n.l = nullptr;
	n.r = nullptr;
}
Node2 & Node2::operator=(const Node2 &n) {
	this->value = n.value;
	this->pos = n.pos;
	this->l = n.l;
	this->r = n.r;
	return *this;
}
Node2 & Node2::operator=(Node2 &&n) {
	this->value = n.value;
	this->pos = n.pos;
	this->l = n.l;
	this->r = n.r;
	n.value = 0;
	n.pos = 0;
	n.l = nullptr;
	n.r = nullptr;
	return *this;
}