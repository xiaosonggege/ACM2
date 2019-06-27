#ifndef SLEEPING_H
#define SLEEPING_H
#include "pch.h"
#include <iostream>
using namespace std;
class Sleeping {
private:
	//声明睡觉持续时间和清醒持续时间
	int sleep_still;
	int wake_still;
	//声明睡觉计时和清醒计时
	int sleep_time = 0;
	int wake_time = 0;
	//声明当前状态
	int stateing; //1为清醒，0为睡觉
public:
	Sleeping() = default;
	Sleeping(const int &, const int &, const int &); //参数为睡觉持续时间和清醒持续时间，最后维初始状态
	~Sleeping();
	Sleeping(const Sleeping &);
	Sleeping(Sleeping &&);
	Sleeping & operator=(const Sleeping &);
	Sleeping & operator=(Sleeping &&);
	int state() const; //输出对象当前状态
	int change_state(); //改变睡觉计时和清醒计时
};
#endif // !SLEEPING_H
