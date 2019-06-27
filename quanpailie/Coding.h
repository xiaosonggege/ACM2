#ifndef CODING_H
#define CODING_H
#include "pch.h"
#include <map>
#include <string>
#include <fstream>
using namespace std;
class Coding {
private:
	map<string, char> dict;
	fstream &fstrm;
	string p;
public:
	Coding() = default;
	Coding(const map<string, char> &, fstream &, const string &);
	~Coding();
	int transform(string &) const; //��������01�ַ���ת��Ϊ��Ӧʮ�������ֲ����
	string & decoding(string &str_after); //�����������
};

#endif // !CODING_H


