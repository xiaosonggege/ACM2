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
	NoMobile(const string &); //��������������total
	~NoMobile();
	NoMobile(const NoMobile &);
	NoMobile(NoMobile &&);
	NoMobile & operator=(const NoMobile &);
	NoMobile & operator=(NoMobile &&);
	ostream & judge(ostream &) const;
	int build(Tnode *, int &); //���ݽڵ����еݹ齨��������
	int total_calc(Tnode *); //�Ӹ��ڵ㿪ʼ�ݹ�������нڵ��total����ֵ
};
#endif // !NOMOBILE_H
