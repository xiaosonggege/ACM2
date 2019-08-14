#ifndef TREEF_H
#define TREEF_H
#include "pch.h"
#include <string>
#include <memory>
using namespace std;
class Treef {
public:
	char color;
	shared_ptr<Treef> c1 = nullptr;
	shared_ptr<Treef> c2 = nullptr;
	shared_ptr<Treef> c3 = nullptr;
	shared_ptr<Treef> c4 = nullptr;
	Treef() = default;
	Treef(const char &);
	~Treef();
	Treef(const Treef &);
	Treef(Treef &&);
	Treef & operator=(const Treef &);
	Treef & operator=(Treef &&);
};
#endif // !TREEF_H

