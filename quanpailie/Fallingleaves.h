#ifndef FALLINGLEAVES_H
#define FALLINGLEAVES_H
#include "pch.h"
#include "Node2.h"
#include <vector>
#include <string>
#include <memory>
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
};
#endif // !FALLINGLEAVES_H
