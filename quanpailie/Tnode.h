#ifndef TNODE_H
#define TNODE_H
#include "pch.h"
using namespace std;
class Tnode {
public:
	int total = 0; //结点总重量
	int D1 = 0; //左臂长
	int D2 = 0; //右臂长
	int W1 = 0; //左砝码重量
	int W2 = 0; //右砝码重量
	Tnode *lchild = nullptr;
	Tnode *rchild = nullptr;
	Tnode() = default;
	Tnode(const int &, const int &, const int &, const int &);
	~Tnode();
	Tnode(const Tnode &);
	Tnode(Tnode &&);
	Tnode & operator=(const Tnode &);
	Tnode & operator=(Tnode &&);
};
#endif // !TNODE_H

