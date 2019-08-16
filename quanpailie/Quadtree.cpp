#include "pch.h"
#include "Treef.h"
#include "Quadtree.h"
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;
Quadtree::Quadtree(const string &ps) : p(ps) {
	ifstream ifstrm;
	ifstrm.open(this->p, ios::in);
	string s;
	getline(ifstrm, s);
	//递归建树
	int pos = 0;
	this->root1 = make_shared<Treef>();
	this->built(this->root1, s, pos);
	//还原黑白图像
	pos = 0;
	vector<char> vc(4, 'n');
	this->pict1.assign(4, vc);
	this->builtpicture(s, 0, 3, 0, 3, this->pict1, pos);

	getline(ifstrm, s);
	pos = 0;
	this->root2 = make_shared<Treef>();
	this->built(this->root2, s, pos);
	//还原黑白图像
	pos = 0;
	this->pict2.assign(4, vc);
	this->builtpicture(s, 0, 3, 0, 3, this->pict2, pos);
	ifstrm.close();
}
Quadtree::~Quadtree() {}
Quadtree::Quadtree(const Quadtree &q) {
	this->p = q.p;
	this->root1 = q.root1;
	this->root2 = q.root2;
	this->pict1 = q.pict1;
	this->pict2 = q.pict2;
}
Quadtree::Quadtree(Quadtree &&q) {
	this->p = q.p;
	this->root1 = q.root1;
	this->root2 = q.root2;
	this->pict1 = q.pict1;
	this->pict2 = q.pict2;
	q.p.clear();
	q.root1 = nullptr;
	q.root2 = nullptr;
	q.pict1.clear();
	q.pict2.clear();
}
Quadtree & Quadtree::operator=(const Quadtree &q) {
	this->p = q.p;
	this->root1 = q.root1;
	this->root2 = q.root2;
	this->pict1 = q.pict1;
	this->pict2 = q.pict2;
	return *this;
}
Quadtree & Quadtree::operator=(Quadtree &&q) {
	this->p = q.p;
	this->root1 = q.root1;
	this->root2 = q.root2;
	this->pict1 = q.pict1;
	this->pict2 = q.pict2;
	q.p.clear();
	q.root1 = nullptr;
	q.root2 = nullptr;
	q.pict1.clear();
	q.pict2.clear();
	return *this;
}
int Quadtree::built(shared_ptr<Treef> t, const string &vs, int &pos) { //先序建树
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
int Quadtree::builtpicture(const string &vs, int r1, int r2, int l1, int l2, vector<vector<char>> &pict, int &pos) {
	if (*(vs.begin() + pos) != 'p') {
		for (int i = r1; i != r2+1; ++i) {
			for (int j = l1; j != l2+1; ++j)
				pict[i][j] = *(vs.begin() + pos);
		}
	}
	else {
		this->builtpicture(vs, r1, (r1+r2-1)/2, (l1+l2+1) / 2 , l2, pict, ++pos);
		this->builtpicture(vs, r1, (r1 + r2 - 1) / 2, l1, (l1 + l2 - 1) / 2, pict, ++pos);
		this->builtpicture(vs, (r1 + r2 + 1) / 2, r2, l1, (l1 + l2 - 1) / 2, pict, ++pos);
		this->builtpicture(vs, (r1 + r2 + 1) / 2, r2, (l1 + l2 + 1) / 2, l2, pict, ++pos);
	}
	return 0;
}
ostream & Quadtree::calc(ostream &os) {
	int count = 0;
	for (int i = 0; i != 4; ++i) {
		for (int j = 0; j != 4; ++j) {
			if (this->pict1[i][j] == 'f' || this->pict2[i][j] == 'f') ++count;
		}
	}
	count *= 64;
	os << "合并后的图像总灰度值为:" << count << endl;
	return os;
}