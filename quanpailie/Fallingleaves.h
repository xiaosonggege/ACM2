#ifndef FALLINGLEAVES_H
#define FALLINGLEAVES_H
#include "pch.h"
#include "Node2.h"
#include <vector>
#include <string>
#include <memory>
#include <map>
using namespace std;
class Fallingleaves {
private:
	string p;
	shared_ptr<Node2> root = nullptr;
public:
	Fallingleaves() = default;
	Fallingleaves(const string &);
	~Fallingleaves();
	Fallingleaves(const Fallingleaves &);
	Fallingleaves(Fallingleaves &&);
	Fallingleaves & operator=(const Fallingleaves &);
	Fallingleaves & operator=(Fallingleaves &&);
	int built(shared_ptr<Node2> , int &pos, const vector<int> &v, int flag);
	ostream & print(ostream &);
	int xianxu(shared_ptr<Node2>, map<int, int> &);
};
#endif // !FALLINGLEAVES_H
