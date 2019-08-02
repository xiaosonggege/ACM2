#ifndef TNODE_H
#define TNODE_H
#include "pch.h"
using namespace std;
class Tnode {
public:
	int total = 0; //���������
	int D1 = 0; //��۳�
	int D2 = 0; //�ұ۳�
	int W1 = 0; //����������
	int W2 = 0; //����������
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

