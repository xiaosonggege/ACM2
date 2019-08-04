#ifndef NOMOBILE_H
#define NOMOBILE_H
#include "pch.h"
#include "Tnode.h"
#include <vector>
#include <iterator>
using namespace std;
class NoMobile {
private:
	string p;
	vector<Tnode> tns;
	Tnode *root = nullptr;
public:
	NoMobile() = default;
	NoMobile(const string &); //建树并计算各结点total
	~NoMobile();
	NoMobile(const NoMobile &);
	NoMobile(NoMobile &&);
	NoMobile & operator=(const NoMobile &);
	NoMobile & operator=(NoMobile &&);
	ostream & judge(ostream &) const;
	int build(Tnode *, int &); //根据节点序列递归建立二叉树
	int total_calc(Tnode *); //从根节点开始递归计算所有节点的total属性值
};
#endif // !NOMOBILE_H
