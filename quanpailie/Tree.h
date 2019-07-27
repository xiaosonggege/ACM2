#ifndef TREE_H
#define TREE_H
#include "pch.h"
#include <memory>
using namespace std;
class Tree {
public:
	int kaiguan = 0; //开关起始状态是关闭的
	int num; //结点序号
	shared_ptr<Tree> left = nullptr; //左子树空指针
	shared_ptr<Tree> right = nullptr; //右子树空指针
	Tree() = default;
	Tree(const int &);
	Tree(const Tree &);
	Tree(Tree &&);
	Tree & operator=(const Tree &);
	Tree & operator=(Tree &&);
	~Tree();
	int change_kaiguan(); //改变开关状态
};
#endif // !TREE_H

