#include "pch.h"
#include "Tree.h"
#include "DropingBalls.h"
#include <vector>
#include <cmath>
using namespace std;
DropingBalls::DropingBalls(const int &D, const int &count) :
	max_deep(D), count_ball(count) {
	int count_max = pow(2, max_deep) - 1; //结点序号最大值
	for (int count = 1; count != count_max + 1; ++count) 
		this->tree_points.push_back(Tree(count));//初始所有子树左右结点均为空指针
}
DropingBalls::~DropingBalls() {}
DropingBalls::DropingBalls(const DropingBalls &d) {
	this->tree_points = d.tree_points;
	this->max_deep = d.max_deep;
	this->count_ball = d.count_ball;
}
DropingBalls::DropingBalls(DropingBalls &&d) {
	this->tree_points = d.tree_points;
	this->max_deep = d.max_deep;
	this->count_ball = d.count_ball;
	d.tree_points.clear();
	d.max_deep = 0;
	d.count_ball = 0;
}
DropingBalls & DropingBalls::operator=(const DropingBalls &d) {
	this->tree_points = d.tree_points;
	this->max_deep = d.max_deep;
	this->count_ball = d.count_ball;
	return *this;
}
DropingBalls & DropingBalls::operator=(DropingBalls &&d) {
	this->tree_points = d.tree_points;
	this->max_deep = d.max_deep;
	this->count_ball = d.count_ball;
	d.tree_points.clear();
	d.max_deep = 0;
	d.count_ball = 0;
	return *this;
}
int DropingBalls::number() {
	//建立二叉树
	int i = 1; //记录叶子结点绑定所在的位置
	for (auto iter = tree_points.begin(); iter != tree_points.end(); ++iter) {
		if (i != pow(2, max_deep)-1) {
			iter->left = &tree_points[i];
			++i;
			iter->right = &tree_points[i];
			++i;
		}
		else break;
	}
	Tree *root = &tree_points[0];
	//构建小球依次向下运动模型
	int finally_num;
	for (int n = 0; n != this->count_ball; ++n) finally_num = this->sporting(root);
	return finally_num;
}
int DropingBalls::sporting(Tree *node) {
	if (!node->kaiguan) { //如果当前结点开关关闭
		node->change_kaiguan();
		if (node->left) return sporting(node->left);
		else return node->num;
	}
	else {
		node->change_kaiguan();
		if (node->right) return sporting(node->right);
		else return node->num;
	}
}