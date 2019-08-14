#include "pch.h"
#include "Treef.h"
#include "Quadtree.h"
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;
Quadtree::Quadtree(const string &ps) : p(ps) {
	ifstream ifstrm;
	ifstrm.open(this->p, ios::in);
	string s;
	getline(ifstrm, s);
	istringstream istr1(s);
	//µÝ¹é½¨Ê÷
	int pos = 0;
	this->root1 = make_shared<Treef>();
	this->built(this->root1, s, pos);
	getline(ifstrm, s);
	istringstream istr2(s);
	pos = 0;
	this->root2 = make_shared<Treef>();
	this->built(this->root2, s, pos);
	ifstrm.close();
}
Quadtree::~Quadtree() {}
Quadtree::Quadtree(const Quadtree &q) {
	this->p = q.p;
	this->root1 = q.root1;
	this->root2 = q.root2;
}
Quadtree::Quadtree(Quadtree &&q) {
	this->p = q.p;
	this->root1 = q.root1;
	this->root2 = q.root2;
	q.p.clear();
	q.root1 = nullptr;
	q.root2 = nullptr;
}
Quadtree & Quadtree::operator=(const Quadtree &q) {
	this->p = q.p;
	this->root1 = q.root1;
	this->root2 = q.root2;
	return *this;
}
Quadtree & Quadtree::operator=(Quadtree &&q) {
	this->p = q.p;
	this->root1 = q.root1;
	this->root2 = q.root2;
	q.p.clear();
	q.root1 = nullptr;
	q.root2 = nullptr;
	return *this;
}
int Quadtree::built(shared_ptr<Treef> t, const string &vs, int &pos) { //ÏÈÐò½¨Ê÷
	t->color = vs[pos];
	++pos;
	if (t->color == 'p') {
		t->c1 = make_shared<Treef>();
		this->built(t->c1, vs, pos);
		t->c2 = make_shared<Treef>();
		this->built(t->c2, vs, pos);
		t->c3 = make_shared<Treef>();
		this->built(t->c3, vs, pos);
		t->c4 = make_shared<Treef>();
		this->built(t->c4, vs, pos);
	}
	return 0;
}