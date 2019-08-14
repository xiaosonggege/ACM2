#include "pch.h"
#include "Treef.h"
#include <string>
#include <memory>
using namespace std;
Treef::Treef(const char &colors): color(colors){}
Treef::~Treef() {}
Treef::Treef(const Treef &t) {
	this->color = t.color;
	this->c1 = t.c1;
	this->c2 = t.c2;
	this->c3 = t.c3;
	this->c4 = t.c4;
}
Treef::Treef(Treef &&t) {
	this->color = t.color;
	this->c1 = t.c1;
	this->c2 = t.c2;
	this->c3 = t.c3;
	this->c4 = t.c4;
	t.color = ' ';
	t.c1 = nullptr;
	t.c2 = nullptr;
	t.c3 = nullptr;
	t.c4 = nullptr;
}
Treef & Treef::operator=(const Treef &t) {
	this->color = t.color;
	this->c1 = t.c1;
	this->c2 = t.c2;
	this->c3 = t.c3;
	this->c4 = t.c4;
	return *this;
}
Treef & Treef::operator=(Treef &&t) {
	this->color = t.color;
	this->c1 = t.c1;
	this->c2 = t.c2;
	this->c3 = t.c3;
	this->c4 = t.c4;
	t.color = ' ';
	t.c1 = nullptr;
	t.c2 = nullptr;
	t.c3 = nullptr;
	t.c4 = nullptr;
	return *this;
}