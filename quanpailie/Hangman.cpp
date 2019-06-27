#include "pch.h"
#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <random>
#include <iterator>
using namespace std;
Hangman::Hangman(const string &ps) :
	p(ps) {
	//�������������
	default_random_engine e;
	//������0~9���ڵľ��ȷֲ�
	uniform_int_distribution<int> u(0, 9);
	e.seed(0);
	//�����������
	int i = 0, choice = u(e);
	ifstream fstrm;
	fstrm.open(p, ios::in);
	while (getline(fstrm, this->word)) {
		if (i == choice) break;
		++i;
	}
	fstrm.close();
}
Hangman::~Hangman() {}
Hangman::Hangman(const Hangman &h) {
	this->p = h.p;
	this->word = h.word;
	this->letter = h.letter;
	this->count = h.count;
}
Hangman::Hangman(Hangman &&h) {
	this->p = h.p;
	this->word = h.word;
	this->letter = h.letter;
	this->count = h.count;
	h.p = "";
	h.word = "";
	h.letter = ' ';
	h.count = 0;
}
Hangman & Hangman::operator=(const Hangman &h) {
	this->p = h.p;
	this->word = h.word;
	this->letter = h.letter;
	this->count = h.count;
	return *this;
}
Hangman & Hangman::operator=(Hangman &&h) {
	this->p = h.p;
	this->word = h.word;
	this->letter = h.letter;
	this->count = h.count;
	return *this;
}
Hangman & Hangman::operator+() {
	if (this->count < 7)
		++(this->count);
	return *this;
}
ostream & Hangman::gess(ostream &os) {
	string s = ""; //���ڴ洢�Ѿ��¶Ե���ĸ
	int flag = 0;
	while (1) {
		os << "������һ����ĸ:" << endl;
		cin >> letter;
		for (const auto &e : word) {
			if (e == letter) {
				s.push_back(letter);
				cout << letter;
				flag = 1;
			}
			else cout << "$";
		}
		if (!flag) this->operator+(); //ͬһ����ĸ���ֶ�β��ۻ�count��
		if (this->count == 7) {
			os << "������!" << endl;
			break;
		}
		else if (s.size() == this->word.size()) {
			os << "��Ӯ�ˣ�" << endl;
			break;
		}
		flag = 0;
	}
	return os;
}