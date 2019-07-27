#include "pch.h"
#include "Tree.h"
#include <memory>
using namespace std;
Tree::Tree(const int &nums) : num(nums) {}
Tree::~Tree() {}
Tree::Tree(const Tree &t) {
	this->kaiguan = t.kaiguan;
	this->num = t.num;
	this->left = t.left;
	this->right = t.right;
}
Tree::Tree(Tree &&t) {
	this->kaiguan = t.kaiguan;
	this->num = t.num;
	this->left = t.left;
	this->right = t.right;
	t.kaiguan = 0;
	t.num = 0;
	t.left = nullptr;
	t.right = nullptr;
}
Tree & Tree::operator=(const Tree &t) {
	this->kaiguan = t.kaiguan;
	this->num = t.num;
	this->left = t.left;
	this->right = t.right;
	return *this;
}
Tree & Tree::operator=(Tree &&t) {
	this->kaiguan = t.kaiguan;
	this->num = t.num;
	this->left = t.left;
	this->right = t.right;
	t.kaiguan = 0;
	t.num = 0;
	t.left = nullptr;
	t.right = nullptr;
	return *this;
}
int Tree::change_kaiguan() {
	this->kaiguan = 1 - this->kaiguan;
	return 0;
}
