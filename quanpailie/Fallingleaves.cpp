#include "pch.h"
#include "Node2.h"
#include "Fallingleaves.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <iterator>
#include <memory>
#include <utility>
using namespace std;
Fallingleaves::Fallingleaves(const string &ps) : p(ps) {
	ifstream ifstrm;
	ifstrm.open(this->p, ios::in);
	istream_iterator<int> iter_in(ifstrm), eof;
	shared_ptr<vector<int>> v = make_shared<vector<int>>();
	v->assign(iter_in, eof);
	int pos = 0;
	this->root = make_shared<Node2>();
	this->built(this->root, pos, *v, 0);
	ifstrm.close();
}
Fallingleaves::~Fallingleaves() {}
Fallingleaves::Fallingleaves(const Fallingleaves &f) {
	this->p = f.p;
	this->root = f.root;
}
Fallingleaves::Fallingleaves(Fallingleaves &&f) {
	this->p = f.p;
	this->root = f.root;
	f.p.clear();
	f.root = nullptr;
}
Fallingleaves & Fallingleaves::operator=(const Fallingleaves &f) {
	this->p = f.p;
	this->root = f.root;
	return *this;
}
Fallingleaves & Fallingleaves::operator=(Fallingleaves &&f) {
	this->p = f.p;
	this->root = f.root;
	f.p.clear();
	f.root = nullptr;
	return *this;
}
int Fallingleaves::built(shared_ptr<Node2> n, int &pos, const vector<int> &v, int flag) {
	n->value = v[pos];
	n->pos = flag;
	if (pos != v.size()-1) {
		if (!(n->l) && v[++pos] != -1) {
			shared_ptr<Node2> nn = make_shared<Node2>();
			n->l = nn;
			built(n->l, pos, v, --flag);
			++flag;
		}
		if (!(n->r) && v[++pos] != -1) {
			shared_ptr<Node2> nn = make_shared<Node2>();
			n->r = nn;
			built(n->r, pos, v, ++flag);
		}
	}
	return 0;
}
ostream & Fallingleaves::print(ostream &os) {
	map<int, int> pos_value;
	xianxu(this->root, pos_value);
	for (auto iter = pos_value.cbegin(); iter != pos_value.cend(); ++iter)
		os << iter->second << " ";
	os << endl;
	return os;
}
int Fallingleaves::xianxu(shared_ptr<Node2> n, map<int, int> &m) {
	auto pairr = m.insert({ n->pos, n->value });
	if (!pairr.second) pairr.first->second += n->value;
	if (n->l) xianxu(n->l, m);
	if (n->r) xianxu(n->r, m);
	return 0;
}