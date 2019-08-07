#ifndef NODE2_H
#define NODE2_H
#include "pch.h"
#include <memory>
using namespace std;
class Node2 {
public:
	int value = 0; //结点值
	int pos = 0; //结点位置
	shared_ptr<Node2> l = nullptr;
	shared_ptr<Node2> r = nullptr;
	Node2() = default;
	Node2(const int &values, Node2 *ls = nullptr, Node2 *rs = nullptr);
	~Node2();
	Node2(const Node2 &);
	Node2(Node2 &&);
	Node2 & operator=(const Node2 &);
	Node2 & operator=(Node2 &&);
};
#endif // !NODE2_H