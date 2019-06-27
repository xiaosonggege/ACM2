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
	//�����̳�ʼ��Ϊ����ʮ��λ�þ�Ϊ'*'
	vector<string> vc(9, "*");
	qipan.assign(10, vc);
	//����ڷ�����λ�÷�������ʮ��λ��
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
	//��õз�˧�ĺ���λ��
	int i = positions["0"][0], j = positions["0"][1];
	int flag_ju = 0, flag_shuai = 0;
	for (auto iter = qipan[i].begin(); iter != qipan[i].end(); ++iter) {
		if (*iter == "2" && !flag_ju) ++flag_ju;
		else if (*iter == "0" && !flag_shuai) ++flag_shuai;
		else if ((*iter != "*" && !flag_ju && flag_shuai) || (*iter != "*" && flag_ju && !flag_shuai))
			return 0;
	}
	flag_ju = 0, flag_shuai = 0;
	//�жϺ͵з�˧ͬ�����޳�
	for (int num = 0; num != qipan.size(); ++num) {
		if (qipan[num][j] == "2" && !flag_ju) ++flag_ju;
		else if (qipan[num][j] == "0" && !flag_shuai) ++flag_shuai;
		else if ((qipan[num][j] != "*" && !flag_ju && flag_shuai) || (qipan[num][j] != "*" && flag_ju && !flag_shuai))
			return 0;
	}
	return 1;
}
bool Xiangqi::ma() {
	//��õз�˧�ĺ���λ��
	int i = positions["0"][0], j = positions["0"][1], flag = 1;
	if (i >= 2) {
		//�ж������Ͻ�
		if (qipan[i - 2][j - 1] == "3") {
			if (qipan[i - 1][j - 1] != "*") flag = 0;
		}
		//�ж������Ͻ�
		if (qipan[i - 2][j + 1] == "3") {
			if (qipan[i - 1][j + 1] != "*") flag = 0;
		}
	}
	else if (i >= 1) {
		//�ж����Ͻ�
		if (qipan[i - 1][j - 2] == "3") {
			if (qipan[i - 1][j - 1] != "*") flag = 0;
		}
		//�ж����Ͻ�
		if (qipan[i - 1][j + 2] == "3") {
			if (qipan[i - 1][j + 1] != "*") flag = 0;
		}
	}
	//�ж������½�
	if (qipan[i + 2][j - 1] == "3") {
		if (qipan[i + 1][j - 1] != "*") flag = 0;
	}
	//�ж����½�
	if (qipan[i + 1][j - 2] == "3") {
		if (qipan[i + 1][j - 1] != "*") flag = 0;
	}
	//�ж������½�
	if (qipan[i + 2][j + 1] == "3") {
		if (qipan[i + 1][j + 1] != "*") flag = 0;
	}
	//�ж����½�
	if (qipan[i + 1][j + 2] == "3") {
		if (qipan[i + 1][j + 1] != "*") flag = 0;
	}
	return flag;
}
bool Xiangqi::pao() {
	//��õз�˧�ĺ���λ��
	int i = positions["0"][0], j = positions["0"][1];
	int flag_pao = 0, flag_shuai = 0, flag = 0;
	//�жϺ͵з�˧ͬ��������
	for (auto iter = qipan[i].begin(); iter != qipan[i].end(); ++iter) {
		if (*iter == "4" && !flag_pao) ++flag_pao;
		else if (*iter == "0" && !flag_shuai) ++flag_shuai;
		else if ((*iter != "*" && !flag_pao && flag_shuai && flag==1) || (*iter != "*" && flag_pao && !flag_shuai && flag ==1))
			return 0;
		else if ((*iter != "*" && !flag_pao && flag_shuai && flag == 0) || (*iter != "*" && flag_pao && !flag_shuai && flag == 0))
			++flag;
	}
	flag_pao = 0, flag_shuai = 0, flag = 0;
	//�жϺ͵з�˧ͬ��������
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
	if (this->ju() && this->ma() && this->pao()) cout << "����!" << endl;
	else cout << "û�н���" << endl;
	return os;
}