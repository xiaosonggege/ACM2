#ifndef CIRCULARSEQ_H
#define CIRDULARSEQ_H
#include "pch.h"
#include <memory>
#include <string>
#include <tuple>
#include <iostream>
#include <iterator>
using namespace std;
class Circularseq {
private:
	shared_ptr<string> strp = make_shared<string>();
public:
	using t = tuple<ostream &, string &>;
	Circularseq() = default;
	Circularseq(const string&);
	~Circularseq();
	t operator()(ostream &) const;
	static int compare(string::iterator , string::iterator,
		string::iterator, string::iterator);
};
#endif // !CIRCULARSEQ_H

