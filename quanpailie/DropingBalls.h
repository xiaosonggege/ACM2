#ifndef DROPINGBALLS_H
#define DROPINGBALLS_H
#include "pch.h"
#include "Tree.h"
#include <vector>
using namespace std;
class DropingBalls {
private:
	vector<Tree> tree_points;
	int max_deep = 1; //����������
	int count_ball = 0; //С������
public:
	DropingBalls() = default;
	DropingBalls(const int &, const int &);
	~DropingBalls();
	DropingBalls(const DropingBalls &);
	DropingBalls(DropingBalls &&);
	DropingBalls & operator=(const DropingBalls &);
	DropingBalls & operator=(DropingBalls &&);

};
#endif // !DROPINGBALLS_H

