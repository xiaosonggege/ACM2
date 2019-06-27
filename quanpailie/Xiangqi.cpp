#include "pch.h"
#include "Xiangqi.h"
#include "omp.h"
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <tuple>
using namespace std;
Xiangqi::Xiangqi(const map<string, vector<int>> &positionss) :
	positions(positionss) {
	//将棋盘初始化为所有十字位置均为'*'
	vector<string> vc(9, "*");
	qipan.assign(10, vc);
	//将红黑方棋子位置放如棋盘十字位置
	for (auto iter = positions.cbegin(); iter != positions.cend(); ++iter) {
		int i = iter->second[0], j = iter->second[1];
		qipan[i][j] = iter->first;
	}
}
Xiangqi::~Xiangqi() {}
Xiangqi::Xiangqi(const Xiangqi &x) {
	this->qipan = x.qipan;
}
Xiangqi::Xiangqi(Xiangqi &&x) {
	this->qipan = x.qipan;
	x.qipan.clear();
}
Xiangqi & Xiangqi::operator=(const Xiangqi &x) {
	this->qipan = x.qipan;
	return *this;
}
Xiangqi & Xiangqi::operator=(Xiangqi &&x) {
	this->qipan = x.qipan;
	x.qipan.clear();
	return *this;
}
bool Xiangqi::ju() {
	//获得敌方帅的横纵位置
	int i = positions["0"][0], j = positions["0"][1];
	int flag_ju = 0, flag_shuai = 0;
	for (auto iter = qipan[i].begin(); iter != qipan[i].end(); ++iter) {
		if (*iter == "2" && !flag_ju) ++flag_ju;
		else if (*iter == "0" && !flag_shuai) ++flag_shuai;
		else if ((*iter != "*" && !flag_ju && flag_shuai) || (*iter != "*" && flag_ju && !flag_shuai))
			return 0;
	}
	flag_ju = 0, flag_shuai = 0;
	//判断和敌方帅同列有无车
	for (int num = 0; num != qipan.size(); ++num) {
		if (qipan[num][j] == "2" && !flag_ju) ++flag_ju;
		else if (qipan[num][j] == "0" && !flag_shuai) ++flag_shuai;
		else if ((qipan[num][j] != "*" && !flag_ju && flag_shuai) || (qipan[num][j] != "*" && flag_ju && !flag_shuai))
			return 0;
	}
	return 1;
}
bool Xiangqi::ma() {
	//获得敌方帅的横纵位置
	int i = positions["0"][0], j = positions["0"][1], flag = 1;
	if (i >= 2) {
		//判断左上上角
		if (qipan[i - 2][j - 1] == "3") {
			if (qipan[i - 1][j - 1] != "*") flag = 0;
		}
		//判断右上上角
		if (qipan[i - 2][j + 1] == "3") {
			if (qipan[i - 1][j + 1] != "*") flag = 0;
		}
	}
	else if (i >= 1) {
		//判断左上角
		if (qipan[i - 1][j - 2] == "3") {
			if (qipan[i - 1][j - 1] != "*") flag = 0;
		}
		//判断右上角
		if (qipan[i - 1][j + 2] == "3") {
			if (qipan[i - 1][j + 1] != "*") flag = 0;
		}
	}
	//判断左下下角
	if (qipan[i + 2][j - 1] == "3") {
		if (qipan[i + 1][j - 1] != "*") flag = 0;
	}
	//判断左下角
	if (qipan[i + 1][j - 2] == "3") {
		if (qipan[i + 1][j - 1] != "*") flag = 0;
	}
	//判断右下下角
	if (qipan[i + 2][j + 1] == "3") {
		if (qipan[i + 1][j + 1] != "*") flag = 0;
	}
	//判断右下角
	if (qipan[i + 1][j + 2] == "3") {
		if (qipan[i + 1][j + 1] != "*") flag = 0;
	}
	return flag;
}
bool Xiangqi::pao() {
	//获得敌方帅的横纵位置
	int i = positions["0"][0], j = positions["0"][1];
	int flag_pao = 0, flag_shuai = 0, flag = 0;
	//判断和敌方帅同行有无炮
	for (auto iter = qipan[i].begin(); iter != qipan[i].end(); ++iter) {
		if (*iter == "4" && !flag_pao) ++flag_pao;
		else if (*iter == "0" && !flag_shuai) ++flag_shuai;
		else if ((*iter != "*" && !flag_pao && flag_shuai && flag==1) || (*iter != "*" && flag_pao && !flag_shuai && flag ==1))
			return 0;
		else if ((*iter != "*" && !flag_pao && flag_shuai && flag == 0) || (*iter != "*" && flag_pao && !flag_shuai && flag == 0))
			++flag;
	}
	flag_pao = 0, flag_shuai = 0, flag = 0;
	//判断和敌方帅同列有无炮
	for (int num = 0; num != qipan.size(); ++num) {
		if (qipan[num][j] == "4" && !flag_pao) ++flag_pao;
		else if (qipan[num][j] == "0" && !flag_shuai) ++flag_shuai;
		else if ((qipan[num][j] != "*" && !flag_pao && flag_shuai && flag == 1) || (qipan[num][j] != "*" && flag_pao && !flag_shuai && flag == 1))
			return 0;
		else if ((qipan[num][j] != "*" && !flag_pao && flag_shuai && flag == 0) || (qipan[num][j] != "*" && flag_pao && !flag_shuai && flag == 0))
			++flag;
	}
	return 1;
}
ostream & Xiangqi::judge(ostream &os) {
	if (this->ju() && this->ma() && this->pao()) cout << "将军!" << endl;
	else cout << "没有将军" << endl;
	return os;
}