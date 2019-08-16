#ifndef QUADTREE_H
#define QUADTREE_H
#include "pch.h"
#include "Treef.h"
#include <memory>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
class Quadtree {
private:
	string p; //�ļ�·��
	shared_ptr<Treef> root1 = nullptr; //��һ���ķ������ڵ�
	shared_ptr<Treef> root2 = nullptr; //�ڶ����ķ������ڵ�
	vector<vector<char>> pict1, pict2;
public:
	Quadtree() = default;
	Quadtree(const string &);
	~Quadtree();
	Quadtree(const Quadtree &);
	Quadtree(Quadtree &&);
	Quadtree & operator=(const Quadtree &);
	Quadtree & operator=(Quadtree &&);
	int built(shared_ptr<Treef>, const string &, int &);
	int builtpicture(const string &, int, int, int, int, vector<vector<char>> &pict, int &pos);
	ostream & calc(ostream &);
}; 
#endif // !QUADTREE_H

