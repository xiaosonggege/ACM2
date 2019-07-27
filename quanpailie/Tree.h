#ifndef TREE_H
#define TREE_H
#include "pch.h"
#include <memory>
using namespace std;
class Tree {
public:
	int kaiguan = 0; //������ʼ״̬�ǹرյ�
	int num; //������
	shared_ptr<Tree> left = nullptr; //��������ָ��
	shared_ptr<Tree> right = nullptr; //��������ָ��
	Tree() = default;
	Tree(const int &);
	Tree(const Tree &);
	Tree(Tree &&);
	Tree & operator=(const Tree &);
	Tree & operator=(Tree &&);
	~Tree();
	int change_kaiguan(); //�ı俪��״̬
};
#endif // !TREE_H

