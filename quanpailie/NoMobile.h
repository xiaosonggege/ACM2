#ifndef NOMOBILE_H
#define NOMOBILE_H
#include "pch.h"
#include "Tnode.h"
#include <vector>
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
};
#endif // !NOMOBILE_H
