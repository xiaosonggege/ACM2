#ifndef QUADTREE_H
#define QUADTREE_H
#include "pch.h"
#include "Treef.h"
#include <memory>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class Quadtree {
private:
	string p; //�ļ�·��
	shared_ptr<Treef> root1 = nullptr; //��һ���ķ������ڵ�
	shared_ptr<Treef> root2 = nullptr; //�ڶ����ķ������ڵ�
public:
	Quadtree() = default;
	Quadtree(const string &);
	~Quadtree();
	Quadtree(const Quadtree &);
	Quadtree(Quadtree &&);
	Quadtree & operator=(const Quadtree &);
	Quadtree & operator=(Quadtree &&);
	int built(shared_ptr<Treef>, const string &, int &);
};
#endif // !QUADTREE_H

