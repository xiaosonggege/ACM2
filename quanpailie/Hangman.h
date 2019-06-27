#ifndef HANGMAN_H
#define HANGMAN_H
#include "pch.h"
#include <iostream>
#include <string>
#include <memory>
#include <random>
using namespace std;
class Hangman {
private:
	string p;
	string word = "";
	char letter;
	int count = 0;
public:
	Hangman() = default;
	Hangman(const string &ps);
	~Hangman();
	Hangman(const Hangman &h);
	Hangman(Hangman &&h);
	Hangman & operator=(const Hangman &h);
	Hangman & operator=(Hangman &&h);
	Hangman & operator+();
	ostream & gess(ostream &os);
};

#endif // !HANGMAN_H

