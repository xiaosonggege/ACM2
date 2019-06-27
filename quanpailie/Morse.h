#ifndef  MORSE_H
#define MORSE_H
#include "pch.h"
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Morse {
private:
	string p;
	map<char, string> dict;
	vector<string> dictionary;
	vector<string> decoding;
public:
	Morse() = default;
	Morse(const string &);
	~Morse();
	Morse(const Morse &);
	Morse(Morse &&);
	Morse & operator=(const Morse &);
	Morse & operator=(Morse &&);
	char find_s(const string &);
	vector<string> find_str(const char &);
	string finding(const string &);
	ostream & reading(ostream &);
};
#endif // ! MORSE_H

