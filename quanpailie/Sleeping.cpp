#include "pch.h"
#include "Sleeping.h"
#include <iostream>
using namespace std;
Sleeping::Sleeping(const int &sleep_stills, const int &wake_stills, const int &stateings) :
	sleep_still(sleep_stills), wake_still(wake_stills), stateing(stateings) {}
Sleeping::~Sleeping() {}
Sleeping::Sleeping(const Sleeping &s) {
	this->sleep_still = s.sleep_still;
	this->wake_still = s.wake_still;
	this->sleep_time = s.sleep_time;
	this->wake_time = s.wake_time;
	this->stateing = s.stateing;
}
Sleeping::Sleeping(Sleeping &&s) {
	this->sleep_still = s.sleep_still;
	this->wake_still = s.wake_still;
	this->sleep_time = s.sleep_time;
	this->wake_time = s.wake_time;
	this->stateing = s.stateing;
	s.sleep_still = 0;
	s.wake_still = 0;
	s.sleep_time = 0;
	s.wake_time = 0;
	s.stateing = 0;
}
Sleeping & Sleeping::operator=(const Sleeping &s) {
	this->sleep_still = s.sleep_still;
	this->wake_still = s.wake_still;
	this->sleep_time = s.sleep_time;
	this->wake_time = s.wake_time;
	this->stateing = s.stateing;
	return *this;
}
Sleeping & Sleeping::operator=(Sleeping &&s) {
	this->sleep_still = s.sleep_still;
	this->wake_still = s.wake_still;
	this->sleep_time = s.sleep_time;
	this->wake_time = s.wake_time;
	this->stateing = s.stateing;
	s.sleep_still = 0;
	s.wake_still = 0;
	s.sleep_time = 0;
	s.wake_time = 0;
	s.stateing = 0;
	return *this;
}
int Sleeping::state() const {
	return this->stateing;
}
int Sleeping::change_state() {
	//×´Ì¬ÇÐ»»Ê±
	if (sleep_time % sleep_still == 0 && wake_time % wake_still == 0) {
		if (this->stateing == 0) {
			this->stateing = 1;
			++this->wake_time;
		}
		else {
			this->stateing = 0;
			++this->sleep_time;
		}
	}
	//ÎÞÐè×´Ì¬ÇÐ»»Ê±
	else if (sleep_time % sleep_still == 0 && wake_time % wake_still != 0)
		++this->wake_time;
	else if (sleep_time % sleep_still != 0 && wake_time % wake_still == 0)
		++this->sleep_time;
	return 0;
}